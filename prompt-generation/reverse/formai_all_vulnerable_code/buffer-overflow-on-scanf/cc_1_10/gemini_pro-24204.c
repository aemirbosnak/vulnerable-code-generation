//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

// Initialize socket communication
int init_socket() {
    int sockfd;
    struct sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }
    return sockfd;
}

// Send email using SMTP protocol
int send_email(int sockfd, char *from, char *to, char *subject, char *body) {
    char buffer[256];
    sprintf(buffer, "HELO my_email_client\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("HELO command failed");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "MAIL FROM: <%s>\r\n", from);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("MAIL FROM command failed");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("RCPT TO command failed");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("DATA command failed");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "From: <%s>\r\n", from);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("From field failed");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "To: <%s>\r\n", to);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("To field failed");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "Subject: %s\r\n", subject);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Subject field failed");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "\r\n%s\r\n", body);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Message body failed");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, ".\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("End of message failed");
        return -1;
    }
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("QUIT command failed");
        return -1;
    }
    return 0;
}

// Main function to handle user input and send email
int main() {
    char from[50], to[50], subject[50], body[256];
    int sockfd;
    printf("Enter sender's email address: ");
    scanf("%s", from);
    printf("Enter recipient's email address: ");
    scanf("%s", to);
    printf("Enter email subject: ");
    scanf("%s", subject);
    printf("Enter email body: ");
    scanf(" %[^\n]%*c", body);
    sockfd = init_socket();
    if (sockfd < 0) {
        return 1;
    }
    if (send_email(sockfd, from, to, subject, body) < 0) {
        return 1;
    }
    printf("Email sent successfully!\n");
    return 0;
}