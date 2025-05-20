//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define MAX_BUF_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage : ./pop3_client [server_address]\n");
        exit(0);
    }
    char *server_address = argv[1];

    int sock_fd;
    struct sockaddr_in server;
    char buf[MAX_BUF_SIZE];

    // Open a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1){
        printf("[Error] Socket creation failed...\n");
        exit(0);
    }
    printf("Socket created successfully...\n");

    // Set server details
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    server.sin_addr.s_addr = inet_addr(server_address);

    // Connect to the server
    if(connect(sock_fd, (struct sockaddr*)&server, sizeof(server))!=0){
        printf("[Error] Connection failed...\n");
        close(sock_fd);
        exit(0);
    }
    printf("Connected to the server...\n");

    // Read the welcome message from the server
    memset(buf, 0, MAX_BUF_SIZE*sizeof(char));
    if(recv(sock_fd, buf, MAX_BUF_SIZE, 0) == -1){
        printf("[Error] Read error...\n");
        close(sock_fd);
        exit(0);
    }
    printf("%s\n", buf);

    // Login to the server
    char username[50], password[50];
    printf("Enter username : ");
    scanf("%s", username);
    printf("Enter password : ");
    scanf("%s", password);

    // Send the USER command to the server
    memset(buf, 0, MAX_BUF_SIZE*sizeof(char));
    snprintf(buf, MAX_BUF_SIZE, "USER %s\r\n", username);
    if(send(sock_fd, buf, strlen(buf), 0) == -1){
        printf("[Error] Write error...\n");
        close(sock_fd);
        exit(0);
    }

    // Read the response from the server
    memset(buf, 0, MAX_BUF_SIZE*sizeof(char));
    if(recv(sock_fd, buf, MAX_BUF_SIZE, 0) == -1){
        printf("[Error] Read error...\n");
        close(sock_fd);
        exit(0);
    }
    printf("%s\n", buf);

    // Send the PASS command to the server
    memset(buf, 0, MAX_BUF_SIZE*sizeof(char));
    snprintf(buf, MAX_BUF_SIZE, "PASS %s\r\n", password);
    if(send(sock_fd, buf, strlen(buf), 0) == -1){
        printf("[Error] Write error...\n");
        close(sock_fd);
        exit(0);
    }

    // Read the response from the server
    memset(buf, 0, MAX_BUF_SIZE*sizeof(char));
    if(recv(sock_fd, buf, MAX_BUF_SIZE, 0) == -1){
        printf("[Error] Read error...\n");
        close(sock_fd);
        exit(0);
    }
    printf("%s\n", buf);

    // Send the LIST command to the server
    memset(buf, 0, MAX_BUF_SIZE*sizeof(char));
    snprintf(buf, MAX_BUF_SIZE, "LIST\r\n");
    if(send(sock_fd, buf, strlen(buf), 0) == -1){
        printf("[Error] Write error...\n");
        close(sock_fd);
        exit(0);
    }

    // Read the response from the server
    memset(buf, 0, MAX_BUF_SIZE*sizeof(char));
    if(recv(sock_fd, buf, MAX_BUF_SIZE, 0) == -1){
        printf("[Error] Read error...\n");
        close(sock_fd);
        exit(0);
    }
    printf("%s\n", buf);

    // Send the QUIT command to the server
    memset(buf, 0, MAX_BUF_SIZE*sizeof(char));
    snprintf(buf, MAX_BUF_SIZE, "QUIT\r\n");
    if(send(sock_fd, buf, strlen(buf), 0) == -1){
        printf("[Error] Write error...\n");
        close(sock_fd);
        exit(0);
    }

    // Read the response from the server
    memset(buf, 0, MAX_BUF_SIZE*sizeof(char));
    if(recv(sock_fd, buf, MAX_BUF_SIZE, 0) == -1){
        printf("[Error] Read error...\n");
        close(sock_fd);
        exit(0);
    }
    printf("%s\n", buf);

    // Close the socket
    close(sock_fd);
    printf("Disconnected from the server...\n");
    return 0;
}