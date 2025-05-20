//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, val;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    printf("FTP Client\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    val = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Connected to server\n");

    while (1) {
        printf("Enter command (e.g. get filename.txt): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        send(sockfd, command, strlen(command), 0);
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}