//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: irregular
/* Oh, hello there! I am a simple HTTP proxy program */
/* Let me start off by including some essential libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <arpa/inet.h>

/* Let me define some constants */
#define MAX_BUFFER_SIZE 8192  /* Maximum size of buffer to receive data */
#define BACKLOG 128           /* Maximum number of pending connections */
#define SERVER_PORT 8080      /* Port number on which server will listen */

/* Great! Now, let's create the main function */
int main(int argc, char const *argv[])
{
    /* First, let's check if the user has provided necessary arguments */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);  // Oops, looks like the user missed something!
    }

    /* Let's retrieve the server details from command line arguments */
    char *server_name = (char *) argv[1];
    int server_port = atoi(argv[2]);

    /* Now, let's create a socket for the proxy server */
    int proxy_server_fd = socket(AF_INET, SOCK_STREAM, 0);

    /* Oops, there was an error while creating the socket */
    if (proxy_server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);  // Time to say goodbye!
    }

    /* Let's bind the socket to a particular port */
    struct sockaddr_in proxy_server_address;
    memset(&proxy_server_address, 0, sizeof(proxy_server_address));
    proxy_server_address.sin_family = AF_INET;  // IPv4 
    proxy_server_address.sin_addr.s_addr = htonl(INADDR_ANY);  // Any available address
    proxy_server_address.sin_port = htons(SERVER_PORT);  // The port on which the server will listen

    /* Ouch, there was an error while binding the socket */
    if (bind(proxy_server_fd, (struct sockaddr *) &proxy_server_address, sizeof(proxy_server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);  // Time to say goodbye!
    }

    /* Oh, let's start listening for incoming requests */
    if (listen(proxy_server_fd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);  // Time to say goodbye!
    }

    /* Now, let's wait for incoming requests */
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_fd = accept(proxy_server_fd, (struct sockaddr *) &client_address, &client_address_length);

    /* Oops, there was an error while accepting the connection */
    if (client_fd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);  // Time to say goodbye!
    }

    /* Let's create another socket for connecting to the server */
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    /* Oops, there was an error while creating the socket */
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);  // Time to say goodbye!
    }

    /* Let's retrieve the server details from DNS */
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;  // IPv4
    hints.ai_socktype = SOCK_STREAM;  // TCP stream sockets

    struct addrinfo *result;
    int error = getaddrinfo(server_name, NULL, &hints, &result);

    /* Oops, there was an error while getting server address */
    if (error != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
        exit(EXIT_FAILURE);  // Time to say goodbye!
    }

    /* Great, we have received the server address! Let's connect to it */
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);

    /* Let's try to connect to the server */
    if (connect(server_fd, (struct sockaddr *) result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);  // Time to say goodbye!
    }

    /* Oh, now comes the fun part! Let's relay the messages between client and server */
    fd_set descriptor_set;
    int max_fd = client_fd > server_fd ? client_fd : server_fd;  // Fetch the max(fd) value
    char client_buffer[MAX_BUFFER_SIZE];
    char server_buffer[MAX_BUFFER_SIZE];

    while (1) {
        FD_ZERO(&descriptor_set);
        FD_SET(client_fd, &descriptor_set);
        FD_SET(server_fd, &descriptor_set);   

        /* Let's wait for either of the sockets to become active */
        int activity = select(max_fd + 1, &descriptor_set, NULL, NULL, NULL);

        /* Oops, there was an error while waiting for activity in the sockets */
        if (activity == -1) {
            perror("select");
            exit(EXIT_FAILURE);  // Time to say goodbye!
        }

        /* Great, there was an activity in one of the sockets */
        if (FD_ISSET(client_fd, &descriptor_set)) {
            memset(client_buffer, 0, MAX_BUFFER_SIZE);

            /* Let's receive the message from client */
            int num_bytes = recv(client_fd, client_buffer, MAX_BUFFER_SIZE, 0);

            /* Oops, there was an error while receiving the message */
            if (num_bytes == -1) {
                perror("recv");
                exit(EXIT_FAILURE);  // Time to say goodbye!
            }

            /* Great, we have received the message! Let's relay it to the server */
            if (num_bytes > 0) {
                send(server_fd, client_buffer, num_bytes, 0);
            }

            /* Oops, client has disconnected, let's say goodbye */
            else {
                break;
            }
        }

        /* Oh, there was activity in the server socket */
        if (FD_ISSET(server_fd, &descriptor_set)) {
            memset(server_buffer, 0, MAX_BUFFER_SIZE);

            /* Let's receive the message from server */
            int num_bytes = recv(server_fd, server_buffer, MAX_BUFFER_SIZE, 0);

            /* Oops, there was an error while receiving the message */
            if (num_bytes == -1) {
                perror("recv");
                exit(EXIT_FAILURE);  // Time to say goodbye!
            }

            /* Great, we have received the message! Let's relay it to the client */
            if (num_bytes > 0) {
                send(client_fd, server_buffer, num_bytes, 0);
            }

            /* Oops, server has disconnected, let's say goodbye */
            else {
                break;
            }
        }
    }

    /* Alright, I am done! I hope you had fun watching me ;) */
    close(client_fd);
    close(server_fd);
    close(proxy_server_fd);
    return 0;
}