//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_SIZE 1024

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("usage: ./smtpclient <server_name> <port_number> <email_subject>\n");
        return EXIT_FAILURE;
    }

    char* server_name = argv[1];
    int port_number = atoi(argv[2]);
    char* email_subject = argv[3];

    struct hostent* server = gethostbyname(server_name);
    if (server == NULL) {
        printf("Error: Could not resolve server name.\n");
        return EXIT_FAILURE;
    }

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: Could not create socket.\n");
        return EXIT_FAILURE;    
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*(server->h_addr_list)));
    server_address.sin_port = htons(port_number);

    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        printf("Error: Could not connect to server.\n");
        return EXIT_FAILURE;
    }

    char buffer[MAX_SIZE];

    // SMTP communication sequence begin
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    snprintf(buffer, MAX_SIZE, "EHLO %s\r\n", server_name);
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    // Your code to send the email content can be added here.
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    snprintf(buffer, MAX_SIZE, "MAIL FROM: <youremail@example.com>\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    snprintf(buffer, MAX_SIZE, "RCPT TO: <recipient@example.com>\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    snprintf(buffer, MAX_SIZE, "DATA\r\n");  
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    // Sending the email content in the correct format for SMTP
    snprintf(buffer, MAX_SIZE, 
        "From: <youremail@example.com>\r\n"
        "To: <recipient@example.com>\r\n"
        "Subject: %s\r\n"
        "Date: %d/%d/%d %d:%d:%d\r\n"
        "\r\n"
        "Hello,\r\n"
        "This is an email sent from a SMTP client program written in C.\r\n"
        "\r\n"
        "Best regards,\r\n"
        "Your Name\r\n"
        ".\r\n", 
        email_subject, tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    snprintf(buffer, MAX_SIZE, "QUIT\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, MAX_SIZE, 0);
    printf("%s", buffer);

    close(client_socket);
    return EXIT_SUCCESS;
}