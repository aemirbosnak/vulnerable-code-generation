//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <recipient email address>\n", argv[0]);
        exit(1);
    }

    // Define Cyberpunk SMTP server address
    char *cyberpunk_smtp_server_address = "smtp.cyberpunk.net";

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Resolve server address
    struct hostent *server_info = gethostbyname(cyberpunk_smtp_server_address);
    if (server_info == NULL) {
        fprintf(stderr, "Failed to resolve server address: %s\n", cyberpunk_smtp_server_address);
        exit(1);
    }

    // Build server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *((struct in_addr *) server_info->h_addr_list[0]);
    server_address.sin_port = htons(587); // Cyberpunk SMTP server runs on port 587

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Read greeting message from server
    char buffer[1024];
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to read greeting message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send EHLO command to server
    char ehlo_command[100];
    sprintf(ehlo_command, "EHLO %s\r\n", cyberpunk_smtp_server_address);
    if (send(sock, ehlo_command, strlen(ehlo_command), 0) < 0) {
        perror("Failed to send EHLO command to server");
        exit(1);
    }

    // Read response from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to read response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send MAIL FROM command
    char mail_from[100];
    sprintf(mail_from, "MAIL FROM: <%s>\r\n", "cyberpunk@cyberpunk.net");
    if (send(sock, mail_from, strlen(mail_from), 0) < 0) {
        perror("Failed to send MAIL FROM command");
        exit(1);
    }

    // Read response from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to read response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send RCPT TO command
    char rcpt_to[100];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", argv[1]);
    if (send(sock, rcpt_to, strlen(rcpt_to), 0) < 0) {
        perror("Failed to send RCPT TO command");
        exit(1);
    }

    // Read response from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to read response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send DATA command
    char data_command[10];
    strcpy(data_command, "DATA\r\n");
    if (send(sock, data_command, strlen(data_command), 0) < 0) {
        perror("Failed to send DATA command");
        exit(1);
    }

    // Read response from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to read response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send email content
    char email_content[500];
    sprintf(email_content, "From: Cyberpunk <cyberpunk@cyberpunk.net>\r\nTo: <%s>\r\nSubject: Welcome to Cyberpunk\r\n\r\nDear user,\r\n\r\nWelcome to the world of Cyberpunk. We are excited to have you join us!\r\n\r\n-The Cyberpunk Team\r\n.\r\n", argv[1]);
    if (send(sock, email_content, strlen(email_content), 0) < 0) {
        perror("Failed to send email content");
        exit(1);
    }

    // Read response from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to read response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send QUIT command
    char quit_command[10];
    strcpy(quit_command, "QUIT\r\n");
    if (send(sock, quit_command, strlen(quit_command), 0) < 0) {
        perror("Failed to send QUIT command");
        exit(1);
    }

    // Read response from server
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to read response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    if (close(sock) < 0) {
        perror("Failed to close socket");
        exit(1);
    }

    return 0;
}