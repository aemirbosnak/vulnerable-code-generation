#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

void chat(const char* host, int port) {
    char buffer[256];
    char* server_response;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    while (1) {
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(sockfd, buffer, strlen(buffer) + 1);

        server_response = malloc(4096);
        read(sockfd, server_response, 4096);
        printf("Server response: %s\n", server_response);
        free(server_response);
    }

    close(sockfd);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    chat(argv[1], atoi(argv[2]));

    return 0;
}
