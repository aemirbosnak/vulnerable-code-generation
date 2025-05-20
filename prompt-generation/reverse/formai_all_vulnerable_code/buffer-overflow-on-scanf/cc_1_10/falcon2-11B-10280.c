//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_MESSAGE_LENGTH 1024

// Function to send an email using SMTP protocol
int sendEmail(char* hostname, char* username, char* password, char* to, char* message) {
    int sockfd, port;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char send_email[MAX_MESSAGE_LENGTH];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    port = htons(25);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        perror("ERROR converting host name to address");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return -1;
    }

    bzero(send_email, MAX_MESSAGE_LENGTH);
    sprintf(send_email, "EHLO localhost\r\n");
    if (send(sockfd, send_email, strlen(send_email), 0) < 0) {
        perror("ERROR sending EHLO");
        return -1;
    }

    sprintf(send_email, "MAIL FROM:<%s>\r\n", username);
    if (send(sockfd, send_email, strlen(send_email), 0) < 0) {
        perror("ERROR sending MAIL FROM");
        return -1;
    }

    sprintf(send_email, "RCPT TO:<%s>\r\n", to);
    if (send(sockfd, send_email, strlen(send_email), 0) < 0) {
        perror("ERROR sending RCPT TO");
        return -1;
    }

    sprintf(send_email, "DATA\r\n");
    if (send(sockfd, send_email, strlen(send_email), 0) < 0) {
        perror("ERROR sending DATA");
        return -1;
    }

    sprintf(send_email, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", username, to, "Test Subject", message);
    if (send(sockfd, send_email, strlen(send_email), 0) < 0) {
        perror("ERROR sending email message");
        return -1;
    }

    sprintf(send_email, "QUIT\r\n");
    if (send(sockfd, send_email, strlen(send_email), 0) < 0) {
        perror("ERROR sending QUIT");
        return -1;
    }

    close(sockfd);

    return 0;
}

// Function to retrieve email messages using POP3 protocol
int retrieveEmail(char* hostname, char* username, char* password, int numMessages) {
    int sockfd, port;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char receive_email[MAX_MESSAGE_LENGTH];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    port = htons(110);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        perror("ERROR converting host name to address");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return -1;
    }

    bzero(receive_email, MAX_MESSAGE_LENGTH);
    sprintf(receive_email, "USER %s\r\n", username);
    if (send(sockfd, receive_email, strlen(receive_email), 0) < 0) {
        perror("ERROR sending USER command");
        return -1;
    }

    sprintf(receive_email, "PASS %s\r\n", password);
    if (send(sockfd, receive_email, strlen(receive_email), 0) < 0) {
        perror("ERROR sending PASS command");
        return -1;
    }

    sprintf(receive_email, "STAT\r\n");
    if (send(sockfd, receive_email, strlen(receive_email), 0) < 0) {
        perror("ERROR sending STAT command");
        return -1;
    }

    int num_lines = 0;
    while (num_lines < numMessages) {
        char line[MAX_EMAIL_LENGTH];
        int len = recv(sockfd, line, MAX_EMAIL_LENGTH, 0);
        if (len < 0) {
            perror("ERROR receiving email message");
            return -1;
        }

        if (line[0] == '+') {
            num_lines++;
        } else if (line[0] == '-') {
            num_lines--;
        } else {
            break;
        }
    }

    close(sockfd);

    return num_lines;
}

int main(int argc, char *argv[]) {
    char hostname[MAX_EMAIL_LENGTH];
    char username[MAX_EMAIL_LENGTH];
    char password[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter email hostname: ");
    scanf("%s", hostname);

    printf("Enter email username: ");
    scanf("%s", username);

    printf("Enter email password: ");
    scanf("%s", password);

    printf("Enter email recipient: ");
    scanf("%s", to);

    printf("Enter email message: ");
    scanf("%s", message);

    sendEmail(hostname, username, password, to, message);

    int numMessages = retrieveEmail(hostname, username, password, 2);

    printf("Number of email messages retrieved: %d\n", numMessages);

    return 0;
}