//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 21 // FTP port
#define MAXLINE 1024 // Maximum size of a command
#define IPADDR "127.0.0.1" // Use localhost for testing purposes

int main() {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, IPADDR, &servaddr.sin_addr) < 0) {
        perror("Error converting IP address");
        exit(1);
    }

    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = '\0';
    printf("%s\n", recvline);

    char user[MAXLINE], pass[MAXLINE], cmd[MAXLINE];
    printf("Username: ");
    scanf("%s", user);
    sprintf(cmd, "USER %s\r\n", user);
    send(sockfd, cmd, strlen(cmd), 0);

    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = '\0';
    printf("%s\n", recvline);
    if(strncmp(recvline, "331", 3) != 0) {
        perror("Error entering username");
        exit(1);
    }

    printf("Password: ");
    scanf("%s", pass);
    sprintf(cmd, "PASS %s\r\n", pass);
    send(sockfd, cmd, strlen(cmd), 0);

    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = '\0';
    printf("%s\n", recvline);
    if(strncmp(recvline, "230", 3) != 0) {
        perror("Error entering password");
        exit(1);
    }

    char filename[MAXLINE], buf[MAXLINE];
    FILE *fp;

    printf("Enter filename to upload: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if(fp == NULL) {
        perror("Error opening file for reading");
        exit(1);
    }

    sprintf(cmd, "TYPE I\r\n");
    send(sockfd, cmd, strlen(cmd), 0);
    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = '\0';
    printf("%s\n", recvline);

    sprintf(cmd, "PASV\r\n");
    send(sockfd, cmd, strlen(cmd), 0);
    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = '\0';
    printf("%s\n", recvline);
    if(strncmp(recvline, "227", 3) != 0) {
        perror("Error entering passive mode");
        exit(1);
    }

    char *ip, *p1, *p2;
    p1 = strchr(recvline, '(') + 1;
    p2 = strchr(recvline, ')');
    *p2 = '\0';
    ip = strtok(p1, ",");
    for(int i=0; i<3; i++) {
        strcat(ip, ".");
        ip = strtok(NULL, ",");
    }

    int port1, port2;
    port1 = atoi(strtok(NULL, ","));
    port2 = atoi(strtok(NULL, ","));
    int port = port1 * 256 + port2;

    struct sockaddr_in servaddr_data;
    int sockfd_data = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr_data, 0, sizeof(servaddr_data));
    servaddr_data.sin_family = AF_INET;
    servaddr_data.sin_port = htons(port);
    inet_pton(AF_INET, ip, &servaddr_data.sin_addr);

    if(connect(sockfd_data, (struct sockaddr *) &servaddr_data, sizeof(servaddr_data)) < 0) {
        perror("Error connecting to data channel");
        exit(1);
    }

    sprintf(cmd, "STOR %s\r\n", filename);
    send(sockfd, cmd, strlen(cmd), 0);
    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = '\0';
    printf("%s\n", recvline);

    while(fgets(buf, MAXLINE, fp) != NULL) {
        send(sockfd_data, buf, strlen(buf), 0);
    }

    close(sockfd_data);
    fclose(fp);
    close(sockfd);

    return 0;
}