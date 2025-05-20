//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Configure the email server
    const char* smtp_server = "smtp.example.com";
    int smtp_port = 587;

    // Socket creation
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the socket address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(smtp_port);
    struct hostent* host = gethostbyname(smtp_server);
    if (host == NULL) {
        perror("Invalid server name");
        exit(EXIT_FAILURE);
    }
    servaddr.sin_addr = *(struct in_addr*)host->h_addr_list[0];

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // SMTP handshake
    printf("HELO %s\r\n", smtp_server);
    int bytesRead;
    char buffer[1024];
    bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    // Sender's email address
    printf("MAIL FROM: <sender@example.com>\r\n");
    bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    // Recipient's email address
    printf("RCPT TO: <recipient@example.com>\r\n");
    bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    // DATA command to start email body
    printf("DATA\r\n");
    bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    // Compose and send the email body
    const char* subject = "Greetings from C Email Client!";
    const char* message = "Hello! This is our enthusiasm-fueled C Email Client in action!";
    printf("Subject: %s\r\n", subject);
    printf("\r\n");
    printf("%s\r\n", message);

    // Indicate message completion
    printf(".\r\n");
    bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    // QUIT command to close the connection
    printf("QUIT\r\n");
    bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    close(sockfd);

    printf("Your email has been sent! Yahoo! Feel the enthusiasm!\n");
    return 0;
}