//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024
#define PORT 25

int main()
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *he;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get the server information
    he = gethostbyname("mail.server.com");
    if (he == NULL)
    {
        perror("ERROR getting host by name");
        exit(1);
    }

    // Create the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr, he->h_addr_list[0], he->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting to server");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Send the HELO command
    sprintf(buffer, "HELO myclient.com\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM:<sender@example.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO:<receiver@example.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Send the message content
    sprintf(buffer, "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}