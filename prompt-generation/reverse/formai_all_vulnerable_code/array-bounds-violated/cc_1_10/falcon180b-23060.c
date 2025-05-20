//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char sendline[BUF_SIZE];
    char recvline[BUF_SIZE];
    FILE *fp;
    int n;

    // Check command line arguments
    if (argc!= 4) {
        printf("Usage:./ftpclient <hostname> <port> <filename>\n");
        exit(1);
    }

    // Convert hostname and port to integers
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    // Connect to server
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    // Send commands to server
    sprintf(sendline, "USER anonymous\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, BUF_SIZE, 0);
    recvline[n] = '\0';
    printf("Server response: %s", recvline);

    sprintf(sendline, "PASS %s\r\n", argv[3]);
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, BUF_SIZE, 0);
    recvline[n] = '\0';
    printf("Server response: %s", recvline);

    sprintf(sendline, "RETR %s\r\n", argv[3]);
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, BUF_SIZE, 0);
    recvline[n] = '\0';
    printf("Server response: %s", recvline);

    // Receive file from server
    fp = fopen(argv[3], "wb");
    while ((n = recv(sockfd, recvline, BUF_SIZE, 0)) > 0) {
        fwrite(recvline, 1, n, fp);
    }
    fclose(fp);

    // Close socket
    close(sockfd);

    return 0;
}