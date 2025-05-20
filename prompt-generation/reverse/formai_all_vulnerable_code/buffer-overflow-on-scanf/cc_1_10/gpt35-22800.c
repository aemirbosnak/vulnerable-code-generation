//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "smtp.gmail.com"  // SMTP Server Address
#define PORT 587                  // SMTP Server Port

int main(int argc, char *argv[]) {
    int socket_fd;
    struct sockaddr_in server_address;
    char message[1024], server_reply[2000], username[100], password[100];

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        printf("Oops! Socket creation failed.\n");
    }

    printf("\nSMTP Client Initialized!\n");

    // SMTP Server Address
    server_address.sin_addr.s_addr = inet_addr(SERVER);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Establish Connection to SMTP Server
    int connection_status = connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));

    if (connection_status == -1) {
        printf("Oops! Connection Error!.\n");
        return -1;
    }

    printf("\nConnection Established Successfully!.\n");

    // Receive greeting message from SMTP server
    if(recv(socket_fd, server_reply, sizeof(server_reply), 0) < 0) {
        printf("Oops! Failed to receive greeting message.\n");
        return -1;
    }

    printf("\nGREETING MESSAGE: %s\n", server_reply);

    // Authenticate user
    printf("Enter your email address: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Send login credentials to SMTP server
    sprintf(message, "AUTH LOGIN\r\n");
    send(socket_fd, message, strlen(message), 0);
    recv(socket_fd, server_reply, sizeof(server_reply), 0);

    // Send username to SMTP server
    sprintf(message, "%s\r\n", username);
    send(socket_fd, message, strlen(message), 0);
    recv(socket_fd, server_reply, sizeof(server_reply), 0);

    // Send password to SMTP server
    sprintf(message, "%s\r\n", password);
    send(socket_fd, message, strlen(message), 0);
    recv(socket_fd, server_reply, sizeof(server_reply), 0);

    printf("\nAuthentication Successful!.\n");

    // Send email content to SMTP server
    printf("\nEnter the recipient's email address: ");
    scanf("%s", message);
    sprintf(message, "RCPT TO: %s\r\n", message);
    send(socket_fd, message, strlen(message), 0);
    recv(socket_fd, server_reply, sizeof(server_reply), 0);

    printf("\nEnter your email subject: ");
    scanf("%s", message);
    sprintf(message, "Subject: %s\r\n", message);
    send(socket_fd, message, strlen(message), 0);

    printf("\nEnter your email content: ");
    scanf("%s", message);
    sprintf(message, "%s\r\n.\r\n", message);
    send(socket_fd, message, strlen(message), 0);

    printf("\nEmail sent successfully!.\n");

    // Terminate Connection to SMTP Server
    sprintf(message, "QUIT\r\n");
    send(socket_fd, message, strlen(message), 0);
    recv(socket_fd, server_reply, sizeof(server_reply), 0);

    printf("\nConnection terminated successfully!.\n");

    // Close socket connection
    close(socket_fd);

    return 0;
}