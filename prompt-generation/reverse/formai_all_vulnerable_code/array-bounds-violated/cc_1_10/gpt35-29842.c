//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25 // SMTP server port
#define MAXSIZE 1024 // maximum buffer size

int main()
{
    char sender[MAXSIZE], recipient[MAXSIZE], subject[MAXSIZE], message[MAXSIZE];
    char buffer[MAXSIZE], response[MAXSIZE];
    int sock = 0;
    struct sockaddr_in server;
    struct hostent *host;
    int bytesSent = 0, bytesReceived = 0;

    // get recipient email address
    printf("Enter recipient email address: ");
    fgets(recipient, MAXSIZE, stdin);
    recipient[strlen(recipient)-1] = '\0'; // remove newline character

    // get sender email address
    printf("Enter your email address: ");
    fgets(sender, MAXSIZE, stdin);
    sender[strlen(sender)-1] = '\0'; // remove newline character

    // get email subject
    printf("Enter email subject: ");
    fgets(subject, MAXSIZE, stdin);
    subject[strlen(subject)-1] = '\0'; // remove newline character

    // get email message
    printf("Enter email message: ");
    fgets(message, MAXSIZE, stdin);
    message[strlen(message)-1] = '\0'; // remove newline character

    // connect to the SMTP server
    host = gethostbyname("mail.example.com");
    if (host == NULL) {
        printf("Error: could not resolve hostname.\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr *)host->h_addr_list[0])));
    server.sin_port = htons(PORT);

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        printf("Error creating socket.\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to server.\n");
        return 1;
    }
    printf("Connected to SMTP server.\n");

    // receive greeting message from SMTP server
    bytesReceived = recv(sock, response, MAXSIZE, 0);
    printf("%.*s", bytesReceived, response);

    // send HELO command to SMTP server
    sprintf(buffer, "HELO mail.example.com\r\n");
    bytesSent = send(sock, buffer, strlen(buffer), 0);
    printf("%s", buffer);

    // receive response from SMTP server
    bytesReceived = recv(sock, response, MAXSIZE, 0);
    printf("%.*s", bytesReceived, response);

    // send MAIL FROM command to SMTP server
    sprintf(buffer, "MAIL FROM:<%s>\r\n", sender);
    bytesSent = send(sock, buffer, strlen(buffer), 0);
    printf("%s", buffer);

    // receive response from SMTP server
    bytesReceived = recv(sock, response, MAXSIZE, 0);
    printf("%.*s", bytesReceived, response);

    // send RCPT TO command to SMTP server
    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    bytesSent = send(sock, buffer, strlen(buffer), 0);
    printf("%s", buffer);

    // receive response from SMTP server
    bytesReceived = recv(sock, response, MAXSIZE, 0);
    printf("%.*s", bytesReceived, response);

    // send DATA command to SMTP server
    sprintf(buffer, "DATA\r\n");
    bytesSent = send(sock, buffer, strlen(buffer), 0);
    printf("%s", buffer);

    // receive response from SMTP server
    bytesReceived = recv(sock, response, MAXSIZE, 0);
    printf("%.*s", bytesReceived, response);

    // send email headers to SMTP server
    sprintf(buffer, "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n", subject, sender, recipient);
    bytesSent = send(sock, buffer, strlen(buffer), 0);
    printf("%s", buffer);

    // send email message to SMTP server
    sprintf(buffer, "%s\r\n.\r\n", message);
    bytesSent = send(sock, buffer, strlen(buffer), 0);
    printf("%s", buffer);

    // receive response from SMTP server
    bytesReceived = recv(sock, response, MAXSIZE, 0);
    printf("%.*s", bytesReceived, response);

    // send QUIT command to SMTP server
    sprintf(buffer, "QUIT\r\n");
    bytesSent = send(sock, buffer, strlen(buffer), 0);
    printf("%s", buffer);

    // receive response from SMTP server
    bytesReceived = recv(sock, response, MAXSIZE, 0);
    printf("%.*s", bytesReceived, response);

    close(sock);
    return 0;
}