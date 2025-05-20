//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE_LEN], recvline[MAX_LINE_LEN];
    int n;
    FILE *fp;
    char username[50], password[50];
    char hostname[50];
    int user_socket;
    int bytes_read;

    printf("Enter the POP3 server hostname: ");
    scanf("%s", hostname);

    printf("Enter the POP3 server port number: ");
    scanf("%d", &portno);

    printf("Enter the POP3 username: ");
    scanf("%s", username);

    printf("Enter the POP3 password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        return 1;
    }

    printf("Connected to POP3 server\n");

    fp = fdopen(sockfd, "r+");
    if (fp == NULL) {
        printf("Error: Failed to open file pointer\n");
        return 1;
    }

    printf("Enter the POP3 command: ");
    fgets(sendline, MAX_LINE_LEN, stdin);
    send(sockfd, sendline, strlen(sendline), 0);

    while ((n = fread(recvline, 1, MAX_LINE_LEN, fp)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}