#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 110
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char user[256], pass[256];

    if (argc != 3) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    write(sockfd, "USER ", 5);
    n = read(sockfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "+OK %s\n", user);

    write(sockfd, "PASS ", 5);
    n = read(sockfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%*s %n", pass);

    write(sockfd, "LIST\r\n", 6);
    n = read(sockfd, buffer, BUFFER_SIZE);

    // Buffer overflow vulnerability here
    strcpy(buffer + n, argv[2]);

    write(sockfd, buffer, strlen(buffer));

    close(sockfd);
    return 0;
}
