//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
/* A configurable TCP/IP server program that accepts incoming connections and 
returns a custom message to the client. The port number and custom message 
can be configured via command line arguments */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10 // maximum number of clients that can connect
#define BUFF_SIZE 1024 // buffer size for incoming data

int main(int argc, char *argv[]) {
    int port, server_fd, client_fds[MAX_CLIENTS], max_clients = 0;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFF_SIZE];

    // parse command line arguments for port number and custom message
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <port number> \"<message>\"\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);

    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creation failed");
        exit(1);
    }

    // set server address and bind socket to it
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("listen failed");
        exit(1);
    }

    // set up select() to handle multiple clients
    fd_set read_fds;
    int max_fd;
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        max_fd = server_fd;

        // add connected client sockets to the set if they exist
        for (int i = 0; i < max_clients; i++) {
            if (client_fds[i] > 0) {
                FD_SET(client_fds[i], &read_fds);
                if (client_fds[i] > max_fd)
                    max_fd = client_fds[i];
            }
        }

        // wait for input from any of the sockets
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select error");
            exit(1);
        }

        // check if there is incoming data on the server socket (new connection)
        if (FD_ISSET(server_fd, &read_fds)) {
            // accept new connection
            int new_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
            if (new_fd < 0) {
                perror("accept failed");
                exit(1);
            }

            // add new client socket to array
            if (max_clients < MAX_CLIENTS)
                client_fds[max_clients++] = new_fd;
            else {
                fprintf(stderr, "Max number of clients reached. Connection refused.\n");
                close(new_fd);
            }
        }

        // check if there is incoming data on any of the client sockets
        for (int i = 0; i < max_clients; i++) {
            if (client_fds[i] > 0 && FD_ISSET(client_fds[i], &read_fds)) {
                // read incoming data
                memset(buffer, 0, BUFF_SIZE);
                int bytes_read = read(client_fds[i], buffer, BUFF_SIZE);
                if (bytes_read == 0) {
                    // client closed connection
                    close(client_fds[i]);
                    client_fds[i] = 0;
                } else {
                    // send custom message back to the client
                    char *custom_msg = argv[2];
                    send(client_fds[i], custom_msg, strlen(custom_msg), 0);
                }
            }
        }
    }

    return 0;
}