//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define remoteIP "127.0.0.1"
#define port_no 21

int main() {
    int sockfd; 
    char buffer[1024] = {0};
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("\nError: Could not create socket\n");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_no);

    if(inet_pton(AF_INET, remoteIP, &serv_addr.sin_addr)<=0) {
        printf("\nError: Invalid address/ Address not supported\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nError: Connection Failed\n");
        return 1;
    }

    printf("Connected to FTP Server <%s:%d>\n", remoteIP, port_no);
    printf("Enter username: ");
    fgets(buffer, 1024, stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    printf("Enter password: ");
    fgets(buffer, 1024, stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    printf("Enter file to download: ");
    fgets(buffer, 1024, stdin);

    if (buffer[strlen(buffer)-1] == '\n')
        buffer[strlen(buffer)-1] = '\0';

    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, 1024);
    recv(sockfd, buffer, 1024, 0);

    if (strcmp(buffer, "404") == 0) {
        printf("Error: File not found on server\n");
        return 1;
    }

    FILE *fp;
    fp = fopen(buffer, "w");

    while (1) {
        memset(buffer, 0, 1024);
        int bytes_read = recv(sockfd, buffer, 1024, 0);

        if (bytes_read == 0)
            break;

        fwrite(buffer, sizeof(char), bytes_read, fp);
    }

    printf("Download successful!\n");
    return 0;
}