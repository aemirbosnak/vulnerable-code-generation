//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<fcntl.h>

int main(int argc, char* argv[]) {

    int sockfd, nread, nwrite, nport;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[257];

    // Some Initializations
    bzero((char *)&serv_addr, sizeof(serv_addr));
    nport = 21;

    // Check if hostname and port provided, if yes then use them instead of the default ones
    if(argc == 2) {
        server = gethostbyname(argv[1]);
    } else if(argc == 3) {
        server = gethostbyname(argv[1]);
        nport = atoi(argv[2]);
    } else {
        printf("Please provide hostname and port of server\n");
        exit(0);
    }

    // Check if server exists
    if(server == NULL) {
        printf("No such server exits\n");
        exit(0);
    }

    // Creating Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1) {
        printf("Socket Creation Failed\n");
        exit(0);
    } else {
        printf("Socket Created Successfully\n");
    }

    // Filling server details
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr*)server->h_addr);
    serv_addr.sin_port = htons(nport);

    // Connecting to Server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Connection Failed\n");
        exit(0);
    } else {
        printf("Connected to Server Successfully\n");
    }

    // Login
    nread = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[nread] = '\0';
    printf("%s", buffer);

    printf("Username: ");
    bzero(buffer, sizeof(buffer));
    fgets(buffer, sizeof(buffer), stdin);

    nwrite = send(sockfd, buffer, strlen(buffer), 0);
    if(nwrite == -1) {
        printf("Error sending Username\n");
        exit(0);
    }

    nread = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[nread] = '\0';
    printf("%s", buffer);

    printf("Password: ");
    bzero(buffer, sizeof(buffer));
    fgets(buffer, sizeof(buffer), stdin);

    nwrite = send(sockfd, buffer, strlen(buffer), 0);
    if(nwrite == -1) {
        printf("Error sending Password\n");
        exit(0);
    }

    nread = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[nread] = '\0';
    printf("%s", buffer);

    // Passive Mode
    nwrite = send(sockfd, "PASV\r\n", strlen("PASV\r\n"), 0);
    if(nwrite == -1) {
        printf("Error sending PASV Command\n");
        exit(0);
    }

    nread = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[nread] = '\0';
    printf("%s", buffer);

    // Enter the Passive Mode
    int a,b,c,d,port;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &a, &b, &c, &d, &port, &port);

    // Creating new Socket for Data Transfer
    int datasockfd, n;
    struct sockaddr_in data_serv_addr;
    if((datasockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket for data transfer\n");
        exit(0);
    }

    data_serv_addr.sin_family = AF_INET;
    data_serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &data_serv_addr.sin_addr);

    if(connect(datasockfd, (struct sockaddr*)&data_serv_addr, sizeof(data_serv_addr)) == -1) {
        printf("Error in connecting socket for data transfer\n");
        exit(0);
    }

    printf("Enter File Name: ");
    bzero(buffer, sizeof(buffer));
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer)-1] = '\0';

    char m[100] = "RETR ";
    strcat(m, buffer);
    strcat(m, "\r\n");

    nwrite = send(sockfd, m, strlen(m), 0);
    if(nwrite == -1) {
        printf("Error sending RETR Command\n");
        exit(0);
    }

    nread = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[nread] = '\0';
    printf("%s", buffer);

    int fd;
    if((fd = open(buffer, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        printf("Error Creating file in client side\n");
        exit(0);
    }

    while((n = recv(datasockfd, buffer, sizeof(buffer), 0)) > 0) {
        write(fd, buffer, n);
    }

    // Closing Connections
    close(fd);
    close(datasockfd);
    close(sockfd);

    return 0;
}