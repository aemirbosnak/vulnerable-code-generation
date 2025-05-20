//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <ctype.h>
#include <time.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

// Function to send data to the server
void send_data(int sock, char *data) {
    write(sock, data, strlen(data));
}

// Function to receive data from the server
char* receive_data(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    read(sock, buffer, BUFFER_SIZE);
    return buffer;
}

// Function to login to the server
void login(int sock) {
    char username[50];
    char password[50];
    char login_response[BUFFER_SIZE];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    sprintf(login_response, "HELO localhost\r\n");
    send_data(sock, login_response);

    sprintf(login_response, "AUTH LOGIN\r\n");
    send_data(sock, login_response);

    sprintf(login_response, "%s\r\n", username);
    send_data(sock, login_response);

    sprintf(login_response, "%s\r\n", password);
    send_data(sock, login_response);

    char* response = receive_data(sock);
    printf("Server response: %s", response);
}

// Function to send email
void send_email(int sock) {
    char from[50];
    char to[50];
    char subject[100];
    char body[1000];

    printf("Enter your email address: ");
    scanf("%s", from);

    printf("Enter recipient's email address: ");
    scanf("%s", to);

    printf("Enter email subject: ");
    scanf("%s", subject);

    printf("Enter email body: ");
    scanf("%[^\n]", body);

    sprintf(body, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", from, to, subject, body);

    sprintf(body, "MAIL FROM:<%s>\r\n", from);
    send_data(sock, body);

    sprintf(body, "RCPT TO:<%s>\r\n", to);
    send_data(sock, body);

    sprintf(body, "DATA\r\n");
    send_data(sock, body);

    send_data(sock, body);

    sprintf(body, ".\r\n");
    send_data(sock, body);

    char* response = receive_data(sock);
    printf("Server response: %s", response);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    login(sock);

    send_email(sock);

    close(sock);

    return 0;
}