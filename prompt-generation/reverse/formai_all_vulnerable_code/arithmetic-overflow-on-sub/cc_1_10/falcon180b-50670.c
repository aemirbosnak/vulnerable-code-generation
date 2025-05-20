//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;
    int total_sent = 0;
    int send_count = 0;
    int bytes_sent;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        addrlen = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        send_count = 0;
        total_sent = 0;
        start_time = time(NULL);

        while (total_sent < 1024) {
            bytes_sent = send(client_socket, "Hello World!", strlen("Hello World!"), 0);
            if (bytes_sent == -1) {
                printf("Error sending data\n");
                exit(1);
            }
            total_sent += bytes_sent;
            send_count++;

            if (send_count % 10 == 0) {
                end_time = time(NULL);
                printf("Sent %d bytes in %d seconds\n", total_sent, end_time - start_time);
            }
        }

        close(client_socket);
    }

    return 0;
}