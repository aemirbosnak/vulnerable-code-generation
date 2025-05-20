//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_RESPONSE_LENGTH 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char ip_address[20];
    strcpy(ip_address, argv[1]);

    int port = atoi(argv[2]);

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        error("ERROR: failed to create socket");
    }

    struct sockaddr_in server_address;
    memset(&server_address, '\0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &server_address.sin_addr) <= 0) {
        error("ERROR: invalid IP address");
    }

    if (connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("ERROR: failed to connect to server");
    }

    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];

    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strlen(command) - 1] = '\0';

        send(sock_fd, &command, strlen(command), 0);

        memset(&response, '\0', sizeof(response));
        recv(sock_fd, &response, MAX_RESPONSE_LENGTH - 1, 0);

        printf("%s\n", response);
    }

    close(sock_fd);

    return 0;
}