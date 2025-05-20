//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_id = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return 1;
    }

    if (connect(sock_id, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Could not connect");
        return 1;
    }

    char buff[BUFF_SIZE];

    recv(sock_id, buff, sizeof(buff), 0);

    printf("Connected to FTP server %s", buff);

    memset(buff, 0, sizeof buff);

    printf("Enter username: ");
    scanf("%s", buff);
    send(sock_id, buff, strlen(buff), 0);
     
    memset(buff, 0, sizeof buff);

    recv(sock_id, buff, sizeof(buff), 0);
    printf("Received: %s", buff);

    memset(buff, 0, sizeof buff);

    printf("Enter password: ");
    scanf("%s", buff);
    send(sock_id, buff, strlen(buff), 0);

    memset(buff, 0, sizeof buff);

    recv(sock_id, buff, sizeof(buff), 0);
    printf("Received: %s", buff);

    printf("Logged in successfully");

    while (1) {
        printf("Enter command: ");
        scanf("%s", buff);
        send(sock_id, buff, strlen(buff), 0);

        memset(buff, 0, sizeof buff);

        recv(sock_id, buff, sizeof(buff), 0);
        printf("%s", buff);

        if (strcmp(buff, "QUIT\n") == 0) {
            break;
        }
    }

    close(sock_id);

    return 0;
}