//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void error(char *msg) {
   perror(msg);
   exit(0);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    char host[256];

    printf("Enter the hostname or IP address of the FTP server:\n");
    fgets(host, 255, stdin);

    printf("Enter the port number of the FTP server:\n");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Connected to FTP server\n");

    while (1) {
        printf("Enter FTP command (QUIT to exit):\n");
        memset(buffer, 0, 256);
        fgets(buffer, 255, stdin);

        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            error("ERROR writing to socket");
        }

        if (strcmp(buffer, "QUIT\n") == 0) {
            break;
        }

        memset(buffer, 0, 256);
        n = read(sockfd, buffer, 255);

        if (n < 0) {
            error("ERROR reading from socket");
        }

        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}