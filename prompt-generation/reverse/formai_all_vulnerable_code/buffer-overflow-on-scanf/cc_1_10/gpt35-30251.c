//FormAI DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define SERVER "mail.example.com" //replace with your email server
#define PORT 25 //SMTP port

int main(){

    char *email, *rcpt, *user, *pass;
    printf("Enter your email address: ");
    scanf("%s", email);
    printf("Enter recipient's email address: ");
    scanf("%s", rcpt);
    printf("Enter your username: ");
    scanf("%s", user);
    printf("Enter your password: ");
    scanf("%s", pass);
    printf("---------------------------\n");

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(SERVER);
    if (server == NULL){
        perror("ERROR, no such host");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
        perror("ERROR connecting");
        exit(1);
    }

    char buffer[1024];
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // sending HELO to server
    char helo[100] = "HELO ";
    strcat(helo, SERVER);
    strcat(helo, "\r\n");
    send(sockfd, helo, strlen(helo), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // sending AUTH LOGIN to server
    char auth[100] = "AUTH LOGIN\r\n";
    send(sockfd, auth, strlen(auth), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // sending username to server
    char username[100];
    int username_len = b64_encode(user, strlen(user), username);
    strcat(username, "\r\n");
    send(sockfd, username, strlen(username), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // sending password to server
    char password[100];
    int password_len = b64_encode(pass, strlen(pass), password);
    strcat(password, "\r\n");
    send(sockfd, password, strlen(password), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // sending MAIL FROM to server
    char from[100] = "MAIL FROM: <";
    strcat(from, email);
    strcat(from, ">\r\n");
    send(sockfd, from, strlen(from), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // sending RCPT TO to server
    char to[100] = "RCPT TO: <";
    strcat(to, rcpt);
    strcat(to, ">\r\n");
    send(sockfd, to, strlen(to), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // sending DATA to server
    char data[100] = "DATA\r\n";
    send(sockfd, data, strlen(data), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // sending message to server
    char subject[100], message[1000];
    printf("Enter message subject: ");
    scanf("%s", subject);
    printf("Enter message body: ");
    scanf("%s", message);
    char msg[1100];
    char endmsg[6] = "\r\n.\r\n";
    sprintf(msg, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", email, rcpt, subject, message);
    send(sockfd, msg, strlen(msg), 0);
    send(sockfd, endmsg, strlen(endmsg), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // sending QUIT to server
    char quit[100] = "QUIT\r\n";
    send(sockfd, quit, strlen(quit), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    close(sockfd);
    return 0;
}

// function to encode data in base 64
int b64_encode(char *input, int input_len, char *output){
    int i, j;
    char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    char *p;

    for (i = 0, j = 0; i < input_len; i += 3, j += 4){
        p = &output[j];
        *p = base64_table[(input[i] >> 2) & 0x3F];
        p = &output[j+1];
        *p = base64_table[((input[i] & 0x3) << 4) | ((i+1 < input_len) ? ((input[i+1] & 0xF0) >> 4) : 0)];
        p = &output[j+2];
        *p = (i+1 < input_len) ? base64_table[((input[i+1] & 0xF) << 2) | ((i+2 < input_len) ? ((input[i+2] & 0xC0) >> 6) : 0)] : '=';
        p = &output[j+3];
        *p = (i+2 < input_len) ? base64_table[input[i+2] & 0x3F] : '=';
    }
    output[j] = '\0';

    return j;
}