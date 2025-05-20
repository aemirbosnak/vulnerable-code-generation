//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) 
{
    struct sockaddr_in serv_addr;
    int sockfd, bytes_recv;
    char buffer[BUFSIZE];
    char user[BUFSIZE];
    char password[BUFSIZE];
    char filename[BUFSIZE];
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <Server IP>\n", argv[0]);
        exit(1);
    }

    // Creating a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Clearing and setting server address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connecting to FTP Server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receiving welcome message
    memset(buffer, 0, BUFSIZE);
    bytes_recv = recv(sockfd, buffer, BUFSIZE, 0);
    buffer[bytes_recv] = '\0';
    printf("%s\n", buffer);

    // Sending username
    printf("\nMy name is: ");
    fgets(user, BUFSIZE, stdin);
    user[strlen(user) - 1] = '\0';
    sprintf(buffer, "USER %s\r\n", user);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receiving response
    memset(buffer, 0, BUFSIZE);
    bytes_recv = recv(sockfd, buffer, BUFSIZE, 0);
    buffer[bytes_recv] = '\0';
    printf("%s\n", buffer);

    // Sending password
    printf("\nWhat's your password? ");
    fgets(password, BUFSIZE, stdin);
    password[strlen(password) - 1] = '\0';
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receiving response
    memset(buffer, 0, BUFSIZE);
    bytes_recv = recv(sockfd, buffer, BUFSIZE, 0);
    buffer[bytes_recv] = '\0';
    printf("%s\n", buffer);

    // Sending PASV command to enter passive mode
    sprintf(buffer, "PASV\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receiving response to get IP and Port for passive mode
    memset(buffer, 0, BUFSIZE);
    bytes_recv = recv(sockfd, buffer, BUFSIZE, 0);
    buffer[bytes_recv] = '\0';
    printf("%s\n", buffer);

    // Parsing received IP and Port
    char *ip;
    int port, a, b, c, d, e, f;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &a, &b, &c, &d, &e, &f);
    ip = malloc(strlen(argv[1]));
    strcpy(ip, argv[1]);
    ip = strtok(ip, ".");
    sprintf(buffer, "%d.%d.%d.%d", a, b, c, d);
    while (ip != NULL) {
        ip = strtok(NULL, ".");
        if (ip != NULL) {
            strcat(buffer, ",");
            strcat(buffer, ip);
        }   
    }
    port = (e << 8) | f;

    // Connecting to FTP Server passive mode
    struct sockaddr_in serv_data_addr;
    int sockfd_data;
    
    if ((sockfd_data = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&serv_data_addr, 0, sizeof(serv_data_addr));
    serv_data_addr.sin_family = AF_INET;
    serv_data_addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, buffer, &serv_data_addr.sin_addr) <= 0)    {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd_data, (struct sockaddr *)&serv_data_addr, sizeof(serv_data_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Sending RETR command to download file
    printf("\nWhat is the name of the file, my love? ");
    fgets(filename, BUFSIZE, stdin);
    filename[strlen(filename) - 1] = '\0';
    sprintf(buffer, "RETR %s\r\n", filename);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receiving response to RETR command
    memset(buffer, 0, BUFSIZE);
    bytes_recv = recv(sockfd, buffer, BUFSIZE, 0);
    buffer[bytes_recv] = '\0';
    if (buffer[0] == '5') {
        printf("%s\n Quiting!!", buffer);
        exit(1);
    } else {
        printf("\nDownloading %s...\n", filename);
    }

    // Saving file from data connection to local device
    fp = fopen(filename, "wb");
    while ((bytes_recv = recv(sockfd_data, buffer, BUFSIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_recv, fp);
    }
    fclose(fp);

    // Closing data connection
    close(sockfd_data);

    // Closing control connection
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receiving response to QUIT command
    memset(buffer, 0, BUFSIZE);
    bytes_recv = recv(sockfd, buffer, BUFSIZE, 0);
    buffer[bytes_recv] = '\0';

    // Closing control connection
    close(sockfd);

    return 0;
}