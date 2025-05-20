//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc , char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    int code;

    // create socket
    if((sock = socket(AF_INET , SOCK_STREAM , 0)) == -1) {
        error("Failed to create socket");
    }

    // set up server address
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);

    // connect to server
    if(connect(sock , (struct sockaddr *)&server_addr , sizeof(server_addr)) == -1) {
        error("Failed to connect to server");
    }

    // receive welcome message
    if(recv(sock , response , BUFFER_SIZE , 0) == -1) {
        error("Failed to receive welcome message");
    }
    printf("%s", response);

    // get username
    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\n")] = 0;

    // send username
    sprintf(buffer, "USER %s\r\n", username);
    send(sock , buffer , strlen(buffer) , 0);

    // receive username response
    if(recv(sock , response , BUFFER_SIZE , 0) == -1) {
        error("Failed to receive username response");
    }
    printf("%s", response);
    sscanf(response, "%d", &code);

    // get password
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = 0;

    // send password
    sprintf(buffer, "PASS %s\r\n", password);
    send(sock , buffer , strlen(buffer) , 0);

    // receive password response
    if(recv(sock , response , BUFFER_SIZE , 0) == -1) {
        error("Failed to receive password response");
    }
    printf("%s", response);
    sscanf(response, "%d", &code);

    // send command to change to binary mode
    strcpy(buffer, "TYPE I\r\n");
    send(sock , buffer , strlen(buffer) , 0);

    // receive binary mode response
    if(recv(sock , response , BUFFER_SIZE , 0) == -1) {
        error("Failed to receive binary mode response");
    }
    printf("%s", response);
    sscanf(response, "%d", &code);

    // send command to list directory
    strcpy(buffer, "LIST\r\n");
    send(sock , buffer , strlen(buffer) , 0);

    // receive directory list
    if(recv(sock , response , BUFFER_SIZE , 0) == -1) {
        error("Failed to receive directory list");
    }
    printf("%s", response);

    close(sock);

    return 0;
}