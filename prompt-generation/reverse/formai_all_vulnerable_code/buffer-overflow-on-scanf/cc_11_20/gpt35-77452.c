//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define PORT 110 //Port number of POP3 server
#define MAX_SIZE 1024 //Maximum size of buffer

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[MAX_SIZE], server_reply[MAX_SIZE];
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Error creating socket!");
    }
    puts("Socket created successfully!");
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        return 1;
    }
    puts("Connected to server successfully!");

    //Receive connection greeting
    if(recv(sock, server_reply, MAX_SIZE, 0) == -1) {
        printf("Error receiving from server!");
    }
    printf("%s\n", server_reply);

    //Send user name to server
    printf("Enter User Name: ");
    scanf("%[^\n]",message);
    getchar();
    strcat(message,"\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending username!");
        return 1;
    }

    //Receive response to username
    if(recv(sock, server_reply, MAX_SIZE, 0) == -1) {
        printf("Error receiving from server!");
    }
    printf("%s\n", server_reply);

    //Send password to server
    printf("Enter Password: ");
    scanf("%[^\n]",message);
    getchar();
    strcat(message,"\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending password!");
        return 1;
    }

    //Receive response to password
    if(recv(sock, server_reply, MAX_SIZE, 0) == -1) {
        printf("Error receiving from server!");
    }
    printf("%s\n", server_reply);

    //Send LIST command to server
    strcpy(message,"LIST\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending LIST command!");
        return 1;
    }

    //Receive list of emails from server
    if(recv(sock, server_reply, MAX_SIZE, 0) == -1) {
        printf("Error receiving from server!");
    }
    printf("%s\n", server_reply);

    //Send RETR command to server
    printf("Enter email number to retrieve: ");
    scanf("%[^\n]",message);
    getchar();
    strcat(message,"\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending RETR command!");
        return 1;
    }

    //Receive email from server
    if(recv(sock, server_reply, MAX_SIZE, 0) == -1) {
        printf("Error receiving from server!");
    }
    printf("%s\n", server_reply);

    //Disconnect from server
    strcpy(message,"QUIT\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending QUIT command!");
        return 1;
    }
    close(sock);
    return 0;
}