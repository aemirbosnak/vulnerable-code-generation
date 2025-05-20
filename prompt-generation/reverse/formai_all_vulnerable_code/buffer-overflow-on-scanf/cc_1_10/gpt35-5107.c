//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "pop.myemail.com" // Your POP Server address goes here
#define PORT 110 // POP3 port

void receiveMessage(int sd, char* message) {
    memset(message, 0, strlen(message)); // Clear the message buffer
    recv(sd, message, 2048, 0); // Receive the message
    printf("%s", message); // Display the message on the console
}

int main() { 
    int sd; // Socket descriptor for connecting to POP server
    struct sockaddr_in server; // Data structure to hold server address
    char message[2048]; // Buffer to hold server messages
    char user[50], pass[50]; // Credentials for POP3 account
 
    // Create server socket
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        printf("Error creating socket");
        return 1;
    }
 
    // Set server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(SERVER); 
    server.sin_port = htons(PORT);
 
    // Connect to server
    if (connect(sd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Error connecting to server");
        return 1;
    }
 
    // Receive greeting message from server
    receiveMessage(sd, message);

    // Send credentials to server 
    printf("Enter your POP3 Username: ");
    scanf("%s", user);
    sprintf(message, "USER %s\r\n", user);
    send(sd, message, strlen(message), 0);
    receiveMessage(sd, message);

    printf("Enter your POP3 Password: ");
    scanf("%s", pass);
    sprintf(message, "PASS %s\r\n", pass);
    send(sd, message, strlen(message), 0);
    receiveMessage(sd, message);

    // Check for successful authentication
    if (strstr(message, "+OK logged in") == NULL) {
        printf("Invalid Credentials!");
        close(sd);
        return 1;
    }

    // List messages in Inbox
    sprintf(message, "LIST\r\n");
    send(sd, message, strlen(message), 0);
    receiveMessage(sd, message);

    // Quit session
    sprintf(message, "QUIT\r\n");
    send(sd, message, strlen(message), 0);
    receiveMessage(sd, message);

    close(sd); // Close the socket

    return 0;
}