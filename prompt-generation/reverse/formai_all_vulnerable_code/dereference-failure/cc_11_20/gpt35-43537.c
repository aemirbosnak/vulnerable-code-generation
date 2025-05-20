//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: energetic
#include<arpa/inet.h>
#include<errno.h>
#include<fcntl.h>
#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

/* Size of buffer used to read and write to and from the socket */
#define BUFFER_SIZE 65536

/* Struct to represent a client connection */
typedef struct client {
    int sock;
    struct sockaddr_in addr;
} client_t;

/* Function to process requests from the client and send them to the server */
void process_request(client_t *client) {
    char buf[BUFFER_SIZE], hostname[256], port[6];
    int n;

    /* Read request data from the socket */
    if((n = read(client->sock, buf, BUFFER_SIZE)) < 0) {
        perror("Error reading from socket");
        return;
    }

    /* Parse the request to find the hostname and port */
    if(sscanf(buf, "CONNECT %255[^:]:%5[0-9]", hostname, port) == 2) {
        /* Connect to the requested server */
        struct hostent *he = gethostbyname(hostname);
        if(!he) {
            perror("Error resolving hostname");
            return;
        }
        struct sockaddr_in server_addr = {0};
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(atoi(port));
        memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);
        int server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if(server_sock < 0) {
            perror("Error creating socket");
            return;
        }
        if(connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Error connecting to server");
            return;
        }

        /* Send a success response to the client */
        if(write(client->sock, "HTTP/1.0 200 OK\r\n\r\n", 19) < 0) {
            perror("Error writing to socket");
            return;
        }

        /* Start relaying data between the client and server */
        fd_set read_fds;
        FD_ZERO(&read_fds);
        while(1) {
            FD_SET(client->sock, &read_fds);
            FD_SET(server_sock, &read_fds);
            if(select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) < 0) {
                perror("Error selecting file descriptors");
                return;
            }
            if(FD_ISSET(client->sock, &read_fds)) {
                if((n = read(client->sock, buf, BUFFER_SIZE)) <= 0) {
                    break;
                }
                if(write(server_sock, buf, n) < 0) {
                    perror("Error writing to socket");
                    return;
                }
            }
            if(FD_ISSET(server_sock, &read_fds)) {
                if((n = read(server_sock, buf, BUFFER_SIZE)) <= 0) {
                    break;
                }
                if(write(client->sock, buf, n) < 0) {
                    perror("Error writing to socket");
                    return;
                }
            }
        }

        /* Close the server socket */
        close(server_sock);
    } else {
        /* This is not a CONNECT request, so we can't proxy it */
        if(write(client->sock, "HTTP/1.0 400 Bad Request\r\n\r\n", 28) < 0) {
            perror("Error writing to socket");
            return;
        }
    }
}

int main(int argc, char **argv) {
    int listen_sock, client_sock;
    struct sockaddr_in addr = {0};

    /* Create the listening socket */
    if((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        return 1;
    }

    /* Set the socket options to allow reuse of the address */
    int optval = 1;
    if(setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("Error setting socket options");
        return 1;
    }

    /* Bind the socket to the specified address and port */
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listen_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    /* Listen for incoming connections */
    if(listen(listen_sock, 5) < 0) {
        perror("Error listening on socket");
        return 1;
    }

    /* Loop indefinitely, accepting connections and spawning new threads to handle them */
    while(1) {
        socklen_t addrlen = sizeof(client_t);
        client_t *client = malloc(sizeof(client_t));
        if(!client) {
            perror("Error allocating memory for client");
            return 1;
        }
        if((client->sock = accept(listen_sock, (struct sockaddr *)&client->addr, &addrlen)) < 0) {
            free(client);
            perror("Error accepting connection");
            continue;
        }
        /* At this point we have a new connection, so we spawn a new thread to handle it */
        if(!fork()) {
            /* In the child process, we process the request */
            process_request(client);
            /* Close the client socket and exit the child process */
            close(client->sock);
            free(client);
            exit(0);
        } else {
            /* In the parent process, we close the client socket and free the memory */
            close(client->sock);
            free(client);
        }
    }

    /* We should never reach this point */
    close(listen_sock);
    return 0;
}