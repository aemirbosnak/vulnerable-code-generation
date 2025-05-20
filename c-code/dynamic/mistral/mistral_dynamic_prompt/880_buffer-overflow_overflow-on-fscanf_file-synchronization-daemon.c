#include <stdint.h>
#include <stddef.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main() {
    int sockfd, connfd;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);

    while (true) {
        connfd = accept(sockfd, (struct sockaddr *)&cli_addr, NULL);
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, stdin);
        scanf("%s", buffer + BUFFER_SIZE - 1); // intentionally overflowing the buffer

        send(connfd, buffer, strlen(buffer), 0);
        close(connfd);
    }

    close(sockfd);
    return 0;
}
