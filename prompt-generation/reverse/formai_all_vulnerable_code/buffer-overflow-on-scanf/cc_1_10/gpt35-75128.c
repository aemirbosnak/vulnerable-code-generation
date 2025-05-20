//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    FILE *fp;

    if(argc != 3){
        printf("Usage: %s <server> <filename>\n", argv[0]);
        exit(1);
    }

    // Step 1: Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) error("ERROR opening socket");

    // Step 2: Set the address information
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0){
        fprintf(stderr, "ERROR invalid address\n");
        exit(1);
    }

    // Step 3: Connect to the server
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR connecting");
    }

    // Step 4: Send the user and password to the server
    char user[256], password[256];
    printf("Username: ");
    scanf("%s", user);
    sprintf(buffer, "USER %s\r\n", user);
    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0) error("ERROR writing to socket");

    printf("Password: ");
    scanf("%s", password);
    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0) error("ERROR writing to socket");

    // Step 5: Enter passive mode
    sprintf(buffer, "PASV\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0) error("ERROR writing to socket");

    // Get the port number and address
    char *p1, *p2, *p3, *p4;
    int port1, port2;
    char address[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if(n < 0) error("ERROR reading from socket");

    // Parse the response to get the address and port number
    p1 = strrchr(buffer, ',');
    p2 = strrchr(p1-1, ',');
    p3 = strrchr(p2-1, ',');
    p4 = strrchr(p3-1, ',');
    port1 = atoi(p2+1);
    port2 = atoi(p1+1);
    snprintf(address, BUFFER_SIZE, "%s.%s.%s.%s", p4+1, p3+1, p2+1, p1+1);

    // Calculate the final port number
    int port = port1 * 256 + port2;

    // Step 6: Open the data connection
    int data_sock;
    struct sockaddr_in data_addr;
    data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(data_sock < 0) error("ERROR opening data socket");

    bzero(&data_addr, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, address, &data_addr.sin_addr) <= 0){
        fprintf(stderr, "ERROR invalid address\n");
        exit(1);
    }

    if(connect(data_sock, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0){
        error("ERROR connecting to data socket");
    }

    // Step 7: Send the retrieve command
    sprintf(buffer, "RETR %s\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0) error("ERROR writing to socket");

    // Step 8: Receive the file
    bzero(buffer, BUFFER_SIZE);
    fp = fopen(argv[2], "wb");
    if(fp == NULL) error("ERROR opening file");

    while((n = read(data_sock, buffer, BUFFER_SIZE)) > 0){
        if(fwrite(buffer, sizeof(char), n, fp) != n) error("ERROR writing to file");
        bzero(buffer, BUFFER_SIZE);
    }

    if(n < 0){
        error("ERROR reading from data socket");
    }

    fclose(fp);
    close(data_sock);
    close(sockfd);
    printf("File transfer complete\n");

    return 0;
}