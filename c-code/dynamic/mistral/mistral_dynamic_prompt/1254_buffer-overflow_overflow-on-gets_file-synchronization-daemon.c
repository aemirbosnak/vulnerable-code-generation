#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define PORT 12345

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, clilen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    printf("Listening on port %d...\n", PORT);

    clilen = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clilen);

    if (new_sockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while (1) {
        gets(buffer);
        write(new_sockfd, buffer, strlen(buffer));
    }

    close(new_sockfd);
    close(sockfd);

    return 0;
}
