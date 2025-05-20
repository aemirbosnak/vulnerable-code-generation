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

#define BUF_SIZE 1024
#define PORT 8080

int main() {
    int sockfd, new_sockfd, numbytes;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);
    printf("Listening on port %d\n", PORT);

    while (1) {
        new_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)NULL);
        char buffer[BUF_SIZE];
        numbytes = recv(new_sockfd, buffer, BUF_SIZE - 1, 0);
        if (numbytes < 0) {
            perror("ERROR reading from socket");
            return 1;
        }
        buffer[numbytes] = '\0';
        // Buf overflow vulnerability in scanf below
        scanf(buffer);

        close(new_sockfd);
    }

    close(sockfd);
    return 0;
}
