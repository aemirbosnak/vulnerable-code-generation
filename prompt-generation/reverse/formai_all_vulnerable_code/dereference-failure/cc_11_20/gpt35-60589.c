//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SMTP_PORT 25

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Please provide the recipient email address as a command line argument\n");
        exit(EXIT_FAILURE);
    }

    char* recipient_email = argv[1];

    // 1. Get MX records for recipient's domain
    struct hostent* host = gethostbyname(strrchr(recipient_email, '@') + 1);
    if (!host) {
        printf("Could not retrieve MX records\n");
        exit(EXIT_FAILURE);
    }

    // 2. Connect to mail server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in mail_server_address;
    mail_server_address.sin_family = AF_INET;
    mail_server_address.sin_port = htons(SMTP_PORT);
    memcpy(&mail_server_address.sin_addr, host->h_addr_list[0], host->h_length);
    if (connect(sockfd, (struct sockaddr*)&mail_server_address, sizeof(mail_server_address)) == -1) {
        printf("Could not connect to mail server\n");
        exit(EXIT_FAILURE);
    }

    // 3. Receive greeting from mail server
    char buffer[BUFFER_SIZE + 1];
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive greeting from mail server\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // 4. Send HELO command
    char* helo_command = "HELO example.com\r\n";
    if (send(sockfd, helo_command, strlen(helo_command), 0) == -1) {
        printf("Could not send HELO command\n");
        exit(EXIT_FAILURE);
    }

    // 5. Receive response to HELO command
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive response to HELO command\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // 6. Send MAIL FROM command
    char* from_address = "example@example.com";
    char mail_from_command[BUFFER_SIZE + 1];
    snprintf(mail_from_command, BUFFER_SIZE, "MAIL FROM: <%s>\r\n", from_address);
    if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) == -1) {
        printf("Could not send MAIL FROM command\n");
        exit(EXIT_FAILURE);
    }

    // 7. Receive response to MAIL FROM command
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive response to MAIL FROM command\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // 8. Send RCPT TO command
    char* to_address = recipient_email;
    char rcpt_to_command[BUFFER_SIZE + 1];
    snprintf(rcpt_to_command, BUFFER_SIZE, "RCPT TO: <%s>\r\n", to_address);
    if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) == -1) {
        printf("Could not send RCPT TO command\n");
        exit(EXIT_FAILURE);
    }

    // 9. Receive response to RCPT TO command
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive response to RCPT TO command\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // 10. Send DATA command
    char* data_command = "DATA\r\n";
    if (send(sockfd, data_command, strlen(data_command), 0) == -1) {
        printf("Could not send DATA command\n");
        exit(EXIT_FAILURE);
    }

    // 11. Receive response to DATA command
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive response to DATA command\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // 12. Send email content
    char email_body[BUFFER_SIZE + 1] = "From: <example@example.com>\r\nTo: <%s>\r\nSubject: Testing SMTP Client\r\n\r\nHello!\r\nThis is a test email from my SMTP client.\r\n";
    char email_content[BUFFER_SIZE + 1];
    snprintf(email_content, BUFFER_SIZE, email_body, recipient_email);
    if (send(sockfd, email_content, strlen(email_content), 0) == -1) {
        printf("Could not send email content\n");
        exit(EXIT_FAILURE);
    }

    // 13. Send end of email data command
    char* end_data_command = "\r\n.\r\n";
    if (send(sockfd, end_data_command, strlen(end_data_command), 0) == -1) {
        printf("Could not send end of email data command\n");
        exit(EXIT_FAILURE);
    }

    // 14. Receive response to end of email data command
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive response to end of email data command\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // 15. Send QUIT command
    char* quit_command = "QUIT\r\n";
    if (send(sockfd, quit_command, strlen(quit_command), 0) == -1) {
        printf("Could not send QUIT command\n");
        exit(EXIT_FAILURE);
    }

    // 16. Receive closing message from mail server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive closing message from mail server\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // 17. Close the connection to the mail server
    close(sockfd);

    printf("Your email has been successfully sent to %s\n", recipient_email);

    return 0;
}