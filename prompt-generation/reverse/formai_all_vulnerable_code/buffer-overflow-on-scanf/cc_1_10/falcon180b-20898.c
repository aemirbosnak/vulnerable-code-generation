//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];
    char send_buffer[BUFSIZE];
    int n, i;

    printf("Enter the port number: ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFSIZE);
        n = read(sockfd, buffer, BUFSIZE);
        if (n < 0) {
            printf("Error reading from socket\n");
            exit(1);
        }
        buffer[n] = '\0';
        printf("%s", buffer);

        if (strncmp(buffer, "+OK", 4) == 0) {
            printf("Enter the command: ");
            fgets(send_buffer, BUFSIZE, stdin);
            send_buffer[strcspn(send_buffer, "\r")] = '\0';
            write(sockfd, send_buffer, strlen(send_buffer));
        }
    }

    close(sockfd);
    return 0;
}