//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 25

int main() {
    // Get the hostname and IP address of the SMTP server
    char hostname[256];
    struct hostent *host;
    printf("Enter the hostname of the SMTP server: ");
    scanf("%s", hostname);
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Invalid hostname!\n");
        return 1;
    }
    char *ip_address = inet_ntoa(*((struct in_addr *)host->h_addr_list[0]));

    // Create a socket and connect to the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Could not create socket!\n");
        return 1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Could not connect to SMTP server!\n");
        return 1;
    }

    // Send the HELO command
    char buffer[256];
    sprintf(buffer, "HELO %s\r\n", hostname);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Could not send HELO command!\n");
        return 1;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        printf("Could not receive response to HELO command!\n");
        return 1;
    }
    printf("%s", buffer);

    // Send the MAIL FROM command
    printf("Enter the sender's email address: ");
    char sender_email[256];
    scanf("%s", sender_email);
    sprintf(buffer, "MAIL FROM: <%s>\r\n", sender_email);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Could not send MAIL FROM command!\n");
        return 1;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        printf("Could not receive response to MAIL FROM command!\n");
        return 1;
    }
    printf("%s", buffer);

    // Send the RCPT TO command
    printf("Enter the recipient's email address: ");
    char recipient_email[256];
    scanf("%s", recipient_email);
    sprintf(buffer, "RCPT TO: <%s>\r\n", recipient_email);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Could not send RCPT TO command!\n");
        return 1;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        printf("Could not receive response to RCPT TO command!\n");
        return 1;
    }
    printf("%s", buffer);

    // Send the DATA command
    if (send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0) == -1) {
        printf("Could not send DATA command!\n");
        return 1;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        printf("Could not receive response to DATA command!\n");
        return 1;
    }
    printf("%s", buffer);

    // Send the email message
    printf("Enter the email message (end with a single period on a line by itself):\n");
    char message[1024];
    int message_length = 0;
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, ".\n") == 0) {
            break;
        }
        memcpy(message + message_length, buffer, strlen(buffer));
        message_length += strlen(buffer);
    }
    if (send(sockfd, message, message_length, 0) == -1) {
        printf("Could not send email message!\n");
        return 1;
    }

    // Send the QUIT command
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        printf("Could not send QUIT command!\n");
        return 1;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        printf("Could not receive response to QUIT command!\n");
        return 1;
    }
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}