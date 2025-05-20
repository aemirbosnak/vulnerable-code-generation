//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    //initialize variables
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAXSIZE] = {0};
    char filename[MAXSIZE];

    //check if enough arguments are passed
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error("ERROR: Cannot create socket");
    }

    //set server address to connect to
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0){
        error("ERROR: Invalid address/ Address not supported");
    }

    //connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR: Connection failed");
    }
    printf("Connected to server on port %d\n", portno);

    //prompt for filename and send to server
    printf("Enter filename: ");
    scanf("%s", filename);
    send(sockfd, filename, strlen(filename), 0);

    //receive file from server
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL){
        error("ERROR: File cannot be created");
    }

    while((n = recv(sockfd, buffer, MAXSIZE, 0)) > 0){
        fwrite(buffer, sizeof(char), n, fp);
        memset(buffer, 0, MAXSIZE);
    }

    printf("File transferred successfully.\n");

    //close socket and file
    close(sockfd);
    fclose(fp);

    return 0;
}