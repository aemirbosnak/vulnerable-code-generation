//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[1024], server_reply[4000], username[100], password[100];
    char *hostname = "pop.gmail.com";
    int port = 995;
    
    printf("Enter your email address: ");
    scanf("%s", username);
    printf("Enter your email password: ");
    scanf("%s", password);
    
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
    
    server.sin_addr.s_addr = inet_addr(hostname);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
 
    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }
    
    puts("Connected\n");
 
    //Login using username and password
    sprintf(message, "USER %s\r\n", username);
    if(send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    if(recv(sock, server_reply, 4000, 0) < 0) {
        puts("recv failed");
        return 1;
    }
    
    sprintf(message, "PASS %s\r\n", password);
    if(send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    if(recv(sock, server_reply, 4000, 0) < 0) {
        puts("recv failed");
        return 1;
    }
    
    //List email
    sprintf(message, "LIST\r\n");
    if(send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    if(recv(sock, server_reply, 4000, 0) < 0) {
        puts("recv failed");
        return 1;
    }
    printf("Email List:\n%s", server_reply);
    
    //Retrieve email
    int email_number;
    printf("\nEnter the email number you want to retrieve: ");
    scanf("%d", &email_number);
    
    sprintf(message, "RETR %d\r\n", email_number);
    if(send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    if(recv(sock, server_reply, 4000, 0) < 0) {
        puts("recv failed");
        return 1;
    }
    printf("\nEmail Contents:\n%s", server_reply);
    
    close(sock);
    return 0;
}