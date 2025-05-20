//FormAI DATASET v1.0 Category: Simple Web Server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *hello = "Hello from server";
    char buffer[1024] = {0};

    // Creating a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Hello! Welcome to my mysterious web server. What is your secret word?\n");
    scanf("%s", buffer);
    printf("\nHmm, let me confirm your secret word...\n");

    int length = strlen(buffer);
    int i;
    for (i=0; i<length; i++) {
        buffer[i] += i;
    }

    if (strcmp(buffer, "gcmpzwg") == 0) {
        printf("\nCongratulations! You have successfully unlocked my web server.\n\n");
        send(new_socket, hello, strlen(hello), 0);
    }
    else {
        printf("\nAccess Denied. Your secret word is incorrect.\n\n");
    }

    close(new_socket);
    close(server_fd);

    return 0;
}