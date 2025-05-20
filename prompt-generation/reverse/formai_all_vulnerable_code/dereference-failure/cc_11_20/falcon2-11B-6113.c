//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, listen_fd, portno;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;

    int addrlen = sizeof(server_addr);

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) == -1) {
        fprintf(stderr, "ERROR setting socket option\n");
        exit(1);
    }

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "ERROR on binding\n");
        exit(1);
    }

    listen(server_fd, 5);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) == -1) {
            fprintf(stderr, "ERROR on accept\n");
            exit(1);
        }

        if (fork() == 0) {
            close(server_fd);

            if ((portno = atoi(getenv("PORT"))) == 0) {
                portno = PORT;
            }

            while (1) {
                char buffer[MAX_BUFFER_SIZE];
                int n;

                n = recv(new_socket, buffer, MAX_BUFFER_SIZE, 0);
                if (n < 0) {
                    fprintf(stderr, "ERROR receiving data\n");
                    exit(1);
                }

                printf("Received: %s\n", buffer);

                n = send(new_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, world!</h1>", strlen("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, world!</h1>") + 1, 0);
                if (n < 0) {
                    fprintf(stderr, "ERROR sending data\n");
                    exit(1);
                }
            }
        }

        close(new_socket);
    }

    close(server_fd);
    exit(0);
}