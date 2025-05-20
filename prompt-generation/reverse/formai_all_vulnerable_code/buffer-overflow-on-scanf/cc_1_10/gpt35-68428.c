//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: surprised
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 1024

int main(){
    printf("Welcome to POP3 Client example program!\n");
    struct sockaddr_in server_address;
    char buffer[MAX_SIZE], uid[MAX_SIZE], password[MAX_SIZE];

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1){
        printf("Failed to create socket!\n");
        exit(0);
    }
    printf("Socket created successfully!\n");

    // Prepare the sockaddr_in structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(110);

    // Connect to remote server
    if (connect(socket_fd , (struct sockaddr *)&server_address , sizeof(server_address)) < 0){
        printf("Failed to connect to server!\n");
        exit(0);
    }
    printf("Connection to server established successfully!\n");

    // Get greeting response from server
    if(recv(socket_fd , buffer , MAX_SIZE , 0) < 0){
        printf("Failed to get response from server!\n");
        exit(0);
    }
    printf("%s", buffer);

    // Get username and password from user
    printf("Please enter your username: ");
    scanf("%s", uid);
    printf("Please enter your password: ");
    scanf("%s", password);

    // Send login credentials to server
    sprintf(buffer, "USER %s\r\n", uid);
    if (send(socket_fd , buffer , strlen(buffer) , 0) < 0){
        printf("Failed to send username to server!\n");
        exit(0);
    }
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(socket_fd , buffer , strlen(buffer) , 0) < 0){
        printf("Failed to send password to server!\n");
        exit(0);
    }
    printf("Login credentials sent successfully!\n");

    // Get response from server after login
    if(recv(socket_fd , buffer , MAX_SIZE , 0) < 0){
        printf("Failed to get response from server after login!\n");
        exit(0);
    }
    printf("%s", buffer);

    // Send command to list all emails
    if (send(socket_fd , "LIST\r\n" , strlen("LIST\r\n") , 0) < 0){
        printf("Failed to send command to server!\n");
        exit(0);
    }
    printf("Command to list all emails sent successfully!\n");

    // Get response from server after list command
    if(recv(socket_fd , buffer , MAX_SIZE , 0) < 0){
        printf("Failed to get response from server after list command!\n");
        exit(0);
    }
    printf("%s", buffer);

    // Close the socket
    close(socket_fd);

    printf("Execution of POP3 Client example program completed successfully!\n");

    return 0;
}