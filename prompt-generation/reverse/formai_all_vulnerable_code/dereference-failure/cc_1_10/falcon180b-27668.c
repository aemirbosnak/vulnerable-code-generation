//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void error(const char *message) {
    perror(message);
    exit(1);
}

int connect_to_server(const char *server, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error("socket failed");
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, server, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

char *receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    char *response = NULL;
    int bytes_received = 0;

    while (bytes_received < BUFFER_SIZE - 1) {
        int result = recv(sockfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);

        if (result <= 0) {
            error("recv failed");
        }

        bytes_received += result;
    }

    buffer[bytes_received] = '\0';
    response = strdup(buffer);

    return response;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <server> <port> <command>\n", argv[0]);
        return 1;
    }

    const char *server = argv[1];
    int port = atoi(argv[2]);
    const char *command = argv[3];

    // Connect to server
    int sockfd = connect_to_server(server, port);

    // Send command and receive response
    send_command(sockfd, command);
    char *response = receive_response(sockfd);

    // Print response
    printf("FTP response:\n%s\n", response);

    // Close socket
    close(sockfd);

    return 0;
}