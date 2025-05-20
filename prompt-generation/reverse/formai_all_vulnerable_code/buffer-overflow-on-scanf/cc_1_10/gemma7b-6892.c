//Gemma-7B DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

#define SERVER_PORT 25
#define SERVER_NAME "localhost"

int main()
{
    int sockfd, port, n, i, server_fd;
    char buffer[1024], filename[256], mail_from[256], mail_to[256], subject[256], message[1024];
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_NAME);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send mail from
    printf("Enter your email address: ");
    scanf("%s", mail_from);

    // Send mail to
    printf("Enter the recipient's email address: ");
    scanf("%s", mail_to);

    // Subject
    printf("Enter the subject: ");
    scanf("%s", subject);

    // Message
    printf("Enter your message: ");
    scanf("%s", message);

    // Send the email
    sprintf(buffer, "FROM: %s\r\nTO: %s\r\nSubject: %s\r\n\r\n%s", mail_from, mail_to, subject, message);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("Error sending email");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    // Success
    printf("Email sent successfully!\n");

    return 0;
}