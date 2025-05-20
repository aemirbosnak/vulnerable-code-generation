//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>   

#define BUFSIZE 1024

int main(int argc , char *argv[]) {

    int sock;
    struct sockaddr_in server;
    char message[BUFSIZE], server_reply[BUFSIZE];
     
    // Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 110 );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
     
    // Receive greeting message from the server
    memset(server_reply, 0, BUFSIZE);
    if (recv(sock, server_reply, BUFSIZE, 0) < 0) {
        perror("recv failed");
        return 1;
    }
    printf("Server message: %s\n", server_reply);
     
    // Send username
    sprintf(message, "USER %s\r\n", argv[1]);
    if( send(sock, message, strlen(message), 0) < 0) {
        puts("send failed");
        return 1;
    }
    printf("Sent message: %s", message);
     
    // Receive username response
    memset(server_reply, 0, BUFSIZE);
    if (recv(sock, server_reply, BUFSIZE, 0) < 0) {
        perror("recv failed");
        return 1;
    }
    printf("Server message: %s\n", server_reply);
     
    // Send password
    sprintf(message, "PASS %s\r\n", argv[2]);
    if( send(sock, message, strlen(message), 0) < 0) {
        puts("send failed");
        return 1;
    }
    printf("Sent message: %s", message);
     
    // Receive password response
    memset(server_reply, 0, BUFSIZE);
    if (recv(sock, server_reply, BUFSIZE, 0) < 0) {
        perror("recv failed");
        return 1;
    }
    printf("Server message: %s\n\n", server_reply);
     
    // Send list command
    sprintf(message, "LIST\r\n");
    if( send(sock, message, strlen(message), 0) < 0) {
        puts("send failed");
        return 1;
    }
    printf("Sent message: %s", message);
     
    // Receive list response
    memset(server_reply, 0, BUFSIZE);
    if (recv(sock, server_reply, BUFSIZE, 0) < 0) {
        perror("recv failed");
        return 1;
    }
    printf("Server message: %s\n", server_reply);
     
    // Send quit command
    sprintf(message, "QUIT\r\n");
    if( send(sock, message, strlen(message), 0) < 0) {
        puts("send failed");
        return 1;
    }
    printf("Sent message: %s", message);
     
    // Receive quit response
    memset(server_reply, 0, BUFSIZE);
    if (recv(sock, server_reply, BUFSIZE, 0) < 0) {
        perror("recv failed");
        return 1;
    }
    printf("Server message: %s\n", server_reply);
     
    close(sock);

    return 0;
}