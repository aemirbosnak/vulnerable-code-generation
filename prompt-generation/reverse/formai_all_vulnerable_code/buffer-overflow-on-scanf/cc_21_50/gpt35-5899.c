//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_SERVER "smtp.gmail.com"
#define SMTP_PORT 587

int main()
{
    int sockfd, sent_len;
    struct sockaddr_in serv_addr;
    char username[50], password[50], from[50], to[50], subject[100], data[500], message[500];
    
    // Get user credentials and email details
    printf("Enter your username (email address): ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("From: ");
    scanf("%s", from);
    printf("To: ");
    scanf("%s", to);
    printf("Subject: ");
    scanf("%s", subject);
    printf("Message: ");
    scanf("%s", message);
    
    // Construct email data
    strcpy(data, "From: ");
    strcat(data, from);
    strcat(data, "\r\nTo: ");
    strcat(data, to);
    strcat(data, "\r\nSubject: ");
    strcat(data, subject);
    strcat(data, "\r\n\r\n");
    strcat(data, message);
    strcat(data, "\r\n.\r\n");
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Cannot create socket");
        return -1;
    }
    
    // Set server address details
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, SMTP_SERVER, &serv_addr.sin_addr);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: Cannot connect to server");
        return -1;
    }
    
    // Read response from server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR: Failed to receive response from server");
        return -1;
    }
    printf("%s\n", buffer);
    
    // Send HELO message to server
    char helo[50];
    sprintf(helo, "HELO %s\r\n", SMTP_SERVER);
    sent_len = send(sockfd, helo, strlen(helo), 0);
    if (sent_len < 0) {
        perror("ERROR: Cannot send HELO message");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR: Failed to receive response from server");
        return -1;
    }
    printf("%s\n", buffer);
    
    // Send STARTTLS message to server
    char starttls[] = "STARTTLS\r\n";
    sent_len = send(sockfd, starttls, strlen(starttls), 0);
    if (sent_len < 0) {
        perror("ERROR: Cannot send STARTTLS message");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR: Failed to receive response from server");
        return -1;
    }
    printf("%s\n", buffer);
    
    // Start TLS encryption
    if (system("openssl s_client -starttls smtp -crlf -connect smtp.gmail.com:587 > /dev/null 2>&1") != 0) {
         perror("ERROR: Failed to start TLS encryption");
         return -1;
    }
    
    // Send authentication details to server
    char auth[100];
    sprintf(auth, "AUTH LOGIN\r\n%s\r\n%s\r\n", username, password);
    sent_len = send(sockfd, auth, strlen(auth), 0);
    if (sent_len < 0) {
        perror("ERROR: Cannot send authentication details");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR: Failed to receive response from server");
        return -1;
    }
    printf("%s\n", buffer);
    
    // Send MAIL FROM message to server
    char mail_from[100];
    sprintf(mail_from, "MAIL FROM: <%s>\r\n", from);
    sent_len = send(sockfd, mail_from, strlen(mail_from), 0);
    if (sent_len < 0) {
        perror("ERROR: Cannot send MAIL FROM message");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR: Failed to receive response from server");
        return -1;
    }
    printf("%s\n", buffer);
    
    // Send RCPT TO message to server
    char rcpt_to[100];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", to);
    sent_len = send(sockfd, rcpt_to, strlen(rcpt_to), 0);
    if (sent_len < 0) {
        perror("ERROR: Cannot send RCPT TO message");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR: Failed to receive response from server");
        return -1;
    }
    printf("%s\n", buffer);
    
    // Send DATA message to server
    char data_msg[] = "DATA\r\n";
    sent_len = send(sockfd, data_msg, strlen(data_msg), 0);
    if (sent_len < 0) {
        perror("ERROR: Cannot send DATA message");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR: Failed to receive response from server");
        return -1;
    }
    printf("%s\n", buffer);
    
    // Send email data to server
    sent_len = send(sockfd, data, strlen(data), 0);
    if (sent_len < 0) {
        perror("ERROR: Cannot send email data");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR: Failed to receive response from server");
        return -1;
    }
    printf("%s\n", buffer);
    
    // Send QUIT message to server
    char quit[] = "QUIT\r\n";
    sent_len = send(sockfd, quit, strlen(quit), 0);
    if (sent_len < 0) {
        perror("ERROR: Cannot send QUIT message");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR: Failed to receive response from server");
        return -1;
    }
    printf("%s\n", buffer);
    
    // Close socket
    close(sockfd);
    
    return 0;
}