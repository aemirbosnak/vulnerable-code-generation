//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int sock, port;
    char *server_ip, server_reply[2000], message[1000];

    printf("\n\n**********************************\n");
    printf("*** SMTP Client in Sherlock Holmes style ***\n");
    printf("**********************************\n");

    // Get the server IP and port number from user
    printf("\nEnter the server IP address: ");
    scanf("%s", server_ip);
    printf("Enter the port number:");
    scanf("%d", &port);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("\nCould not create socket");
        return 1;
    }

    // Set up server information
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("\nConnection error, please ensure server is running and try again!");
        return 1;
    }

    // Get welcome message from the server
    if (recv(sock, server_reply, strlen(server_reply), 0) < 0) {
        printf("\nReceive failed");
        return 1;
    }

    printf("\n\nServer: %s", server_reply);

    printf("\n\nWatson: Hello, I am sending an email now, Sherlock!");

    // Send EHLO command to server
    strcpy(message, "EHLO localhost\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("\nSend failed");
        return 1;
    }

    // Get response from server
    if (recv(sock, server_reply, strlen(server_reply), 0) < 0) {
        printf("\nReceive failed");
        return 1;
    }

    printf("\n\nServer: %s", server_reply);

    // Send MAIL FROM command to server
    strcpy(message, "MAIL FROM: <watson@bakerstreet.com>\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("\nSend failed");
        return 1;
    }

    // Get response from server
    if (recv(sock, server_reply, strlen(server_reply), 0) < 0) {
        printf("\nReceive failed");
        return 1;
    }

    printf("\n\nServer: %s", server_reply);

    // Send RCPT TO command to server
    strcpy(message, "RCPT TO: <sherlock@bakerstreet.com>\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("\nSend failed");
        return 1;
    }

    // Get response from server
    if (recv(sock, server_reply, strlen(server_reply), 0) < 0) {
        printf("\nReceive failed");
        return 1;
    }

    printf("\n\nServer: %s", server_reply);

    // Send DATA command to server
    strcpy(message, "DATA\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("\nSend failed");
        return 1;
    }

    // Get response from server
    if (recv(sock, server_reply, strlen(server_reply), 0) < 0) {
        printf("\nReceive failed");
        return 1;
    }

    printf("\n\nServer: %s", server_reply);

    // Send email message to server
    strcpy(message, "From: Watson <watson@bakerstreet.com>\r\nTo: Sherlock <sherlock@bakerstreet.com>\r\nSubject: A message from Watson\r\n\r\nDear Sherlock, \r\n\r\nI hope you're well. Just wanted to say that the case we worked on last week has been solved! Found the murderer, thanks to your expert deduction skills. Keep up the good work! \r\n\r\nSincerely, \r\nWatson.");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("\nSend failed");
        return 1;
    }

    // Send QUIT command to server
    strcpy(message, "QUIT\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("\nSend failed");
        return 1;
    }

    // Get response from server
    if (recv(sock, server_reply, strlen(server_reply), 0) < 0) {
        printf("\nReceive failed");
        return 1;
    }

    printf("\n\nServer: %s", server_reply);

    close(sock);

    return 0;
}