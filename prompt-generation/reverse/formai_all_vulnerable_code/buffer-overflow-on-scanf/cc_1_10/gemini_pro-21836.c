//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main() {

    // Initialize variables
    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;

    // Create the socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Set server information
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("192.168.1.1"); // Set the IP address of the server
    server.sin_port = htons(25); // Set the port number

    // Connect to the server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("Connect error");
        return 1;
    }
    puts("Connected\n");

    // Receive a welcome message from the server
    char server_reply[2000];
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        puts("Receive error");
        return 1;
    }
    puts(server_reply);

    // Get the email address of the sender
    char sender_email[100];
    printf("Enter the sender email address: ");
    scanf("%s", sender_email);

    // Get the email address of the recipient
    char recipient_email[100];
    printf("Enter the recipient email address: ");
    scanf("%s", recipient_email);

    // Get the subject of the email
    char subject[100];
    printf("Enter the subject of the email: ");
    scanf(" %[^\n]%*c", subject); // To handle spaces in subject

    // Get the body of the email
    char body[1000];
    printf("Enter the body of the email:\n");
    scanf(" %[^\n]%*c", body);  // To handle newlines in body

    // Construct the email message
    char email_message[2000];
    sprintf(email_message, "From: %s\nTo: %s\nSubject: %s\n\n%s", sender_email, recipient_email, subject, body);

    // Send the email message to the server
    if (send(socket_desc, email_message, strlen(email_message), 0) < 0) {
        puts("Send error");
        return 1;
    }

    // Receive a response from the server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        puts("Receive error");
        return 1;
    }
    puts(server_reply);

    // Close the socket
    close(socket_desc);

    return 0;
}