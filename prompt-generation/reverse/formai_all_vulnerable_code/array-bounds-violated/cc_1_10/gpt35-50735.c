//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
// C program for a basic FTP Client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd = 0, port = 21, nrecv = 0, nsent = 0;
    char buffer[BUFFER_SIZE] = {0};
    char username[BUFFER_SIZE], password[BUFFER_SIZE], filename[BUFFER_SIZE], command[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    
    // Check if enough arguments are provided
    if(argc < 2) {
        printf("Usage: %s server_ip_address [port_number]\n", argv[0]);
        return -1;
    }
    
    // Convert the arguments and initialize serv_addr
    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("Invalid server address\n");
        return -1;
    }
    if(argc == 3) {
        port = atoi(argv[2]);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    
    // Create socket and connect to server
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        return -1;
    }
    
    // Receive welcome message from server
    nrecv = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[nrecv] = '\0';
    printf("%s", buffer);
    
    // Authenticate with server
    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    username[strlen(username)-1] = '\0';
    sprintf(command, "USER %s\r\n", username);
    nsent = send(sockfd, command, strlen(command), 0);
    nrecv = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[nrecv] = '\0';
    printf("%s", buffer);
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);
    password[strlen(password)-1] = '\0';
    sprintf(command, "PASS %s\r\n", password);
    nsent = send(sockfd, command, strlen(command), 0);
    nrecv = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[nrecv] = '\0';
    printf("%s", buffer);
    
    // Request file from server
    printf("File name: ");
    fgets(filename, BUFFER_SIZE, stdin);
    filename[strlen(filename)-1] = '\0';
    sprintf(command, "RETR %s\r\n", filename);
    nsent = send(sockfd, command, strlen(command), 0);
    nrecv = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[nrecv] = '\0';
    printf("%s", buffer);
    if(strncmp(buffer, "550", 3) == 0) {
        printf("File not found\n");
        close(sockfd);
        return -1;
    }
    
    // Receive file from server
    FILE *fp = fopen(filename, "w");
    while((nrecv = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), nrecv, fp);
        memset(buffer, 0, BUFFER_SIZE);
    }
    
    // Close connection and file
    fclose(fp);
    printf("File download complete\n");
    close(sockfd);
    return 0;
}