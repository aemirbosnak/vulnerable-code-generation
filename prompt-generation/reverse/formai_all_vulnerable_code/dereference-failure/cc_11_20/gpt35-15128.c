//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_DATA_SIZE] = { 0 };
    int opt = 1;
    int addrlen = sizeof(server_addr);

    // create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // bind socket to address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // receive data from client
        int bytes_received = recv(client_fd, buffer, MAX_DATA_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        // determine quality of service based on amount of data received
        if (bytes_received <= 10) {
            printf("POOR QOS\n");
        } else if (bytes_received > 10 && bytes_received <= 100) {
            printf("AVERAGE QOS\n");
        } else if (bytes_received > 100) {
            printf("EXCELLENT QOS\n");
        }

        // send response to client
        char response[] = "Connection received.";
        if (send(client_fd, response, strlen(response), 0) == -1) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        close(client_fd);
    }

    return 0;
}