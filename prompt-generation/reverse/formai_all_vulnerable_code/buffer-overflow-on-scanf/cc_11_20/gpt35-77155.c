//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>

#define MAXSIZE 1024
#define PORT 21

int main(int argc, char const *argv[]) {

    //creating socket and error handling
    int sockfd, connfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }

    //initailizing socket address and port
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    //connecting with server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection with the server failed...\n");
        exit(0);
    } else {
        printf("Connected to the server...\n");
    }

    char buffer[MAXSIZE];
    memset(buffer, 0, MAXSIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    //entering credentials to login
    char user[MAXSIZE], pass[MAXSIZE];
    printf("Enter username: ");
    scanf("%s", user);
    send(sockfd, user, strlen(user), 0);

    memset(buffer, 0, MAXSIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    printf("Enter password: ");
    scanf("%s", pass);
    send(sockfd, pass, strlen(pass), 0);

    memset(buffer, 0, MAXSIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);

    printf("%s", buffer);

    printf("Sending Commands to server...\n");
    char* command1 = "CWD /home/user/Documents\n";
    char* command2 = "PASV\n";
    char* command3 = "LIST\n";
    char* command4 = "QUIT\n";

    send(sockfd, command1, strlen(command1), 0);

    memset(buffer, 0, MAXSIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    send(sockfd, command2, strlen(command2), 0);

    memset(buffer, 0, MAXSIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Data Port: %s", buffer);

    // extracting dat port number to use to create another socket
    int start = 0, hex = 0;
    for (int i=0; i<strlen(buffer); i++) {
        if (buffer[i] == '(') {
            start = i+1;
        }
        if (buffer[i] == ')') {
            char* sub = (char*) calloc(i-start+1, sizeof(char));
            memcpy(sub, buffer+start, i-start);
            hex = (int) strtol(sub, NULL, 16);
            free(sub);
        }
    }

    // creating new socket and connecting to extracted port number
    struct sockaddr_in data_addr;
    bzero(&data_addr, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    data_addr.sin_port = htons(hex);

    int datafd;
    datafd = socket(AF_INET, SOCK_STREAM, 0);
    if (datafd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }

    if (connect(datafd, (struct sockaddr*)&data_addr, sizeof(data_addr)) != 0) {
        printf("Connection with the server failed...\n");
        exit(0);
    } else {
        printf("Connected to the server...\n");
    }

    //sending commands
    send(sockfd, command3, strlen(command3), 0);

    // running overall operations in an aynchronous manner.
    while (1) {
        memset(buffer, 0, MAXSIZE);
        int nbytes = read(datafd, buffer, MAXSIZE);

        if (nbytes == -1) {
            printf("Error while receiving file\n");
            exit(EXIT_FAILURE);
        } else if (nbytes == 0) {
            break;
        }

        printf("%s", buffer);
        memset(buffer, 0, MAXSIZE);
    }

    send(sockfd, command4, strlen(command4), 0);

    close(sockfd);
    close(datafd);

    return 0;
}