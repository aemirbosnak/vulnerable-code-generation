//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

#define SERVER "mail.example.com"
#define PORT 110

int main(){
    int sock;
    struct sockaddr_in server;
    char message[2000], server_reply[2000];

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("mail.example.com");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    //Connect to remote server
    if(connect(sock, (struct sockadd *)&server, sizeof(server)) < 0){
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    //Receive welcome message from the server
    if(recv(sock, server_reply, 2000, 0) < 0){
        puts("recv failed");
    }
    puts(server_reply);

    //Send username to the server
    printf("Enter username: ");
    scanf("%s", message);

    if(send(sock, message, strlen(message), 0) < 0){
        puts("Send failed");
        return 1;
    }

    //Receive confirmation from server
    if(recv(sock, server_reply, 2000, 0) < 0){
        puts("recv failed");
    }
    if(server_reply[0] == '+'){
        puts("User found, please enter password.");
    }

    //Send password to the server
    printf("Enter password: ");
    scanf("%s", message);

    if(send(sock, message, strlen(message), 0) < 0){
        puts("Send failed");
        return 1;
    }

    //Receive confirmation from server
    if(recv(sock, server_reply, 2000, 0) < 0){
        puts("recv failed");
    }
    if(server_reply[0] == '+'){
        puts("Logged in successfully");
    }

    //Send command to list the messages
    if(send(sock, "LIST\r\n", strlen("LIST\r\n"), 0) < 0){
        puts("Send failed");
        return 1;
    }

    //Receive list of messages
    if(recv(sock, server_reply, 2000, 0) < 0){
        puts("recv failed");
    }
    puts(server_reply);

    //Close the socket
    close(sock);
    return 0;
}