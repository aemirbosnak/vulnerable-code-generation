//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
/* SMTP Client Program */
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

#define MSG_LEN 2000

int main(int argc, char* argv[]) {
    if(argc<4) {
        printf("\nUsage: ./smtpclient <MailServer IP> <MailServer Port> <Sender Email> <Recipient Email>\n");
        exit(1);
    }
    char *mailserver_ip = argv[1];
    int mailserver_port = atoi(argv[2]);
    char *sender = argv[3];
    char *recipient = argv[4];
    char message[MSG_LEN];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock<0) {
        perror("\nError: Could not create socket!\n");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(mailserver_ip);
    server.sin_port = htons(mailserver_port);
    if(connect(sock, (struct sockaddr*)&server, sizeof(server))<0) {
        perror("\nError: Connection failed!\n");
        exit(1);
    }
    if(recv(sock, message, MSG_LEN, 0)<0) {
        perror("\nError: Could not receive data!\n");
        exit(1);
    }
    printf("\nMessage from server: %s\n", message);
    memset(message, 0, MSG_LEN);
    sprintf(message, "HELO %s\r\n", mailserver_ip);
    if(send(sock, message, strlen(message), 0)<0) {
        perror("\nError: Could not send data!\n");
        exit(1);
    }
    memset(message, 0, MSG_LEN);
    if(recv(sock, message, MSG_LEN, 0)<0) {
        perror("\nError: Could not receive data!\n");
        exit(1);
    }
    printf("\nMessage from server: %s\n", message);
    memset(message, 0, MSG_LEN);
    sprintf(message, "MAIL FROM:<%s>\r\n", sender);
    if(send(sock, message, strlen(message), 0)<0) {
        perror("\nError: Could not send data!\n");
        exit(1);
    }
    memset(message, 0, MSG_LEN);
    if(recv(sock, message, MSG_LEN, 0)<0) {
        perror("\nError: Could not receive data!\n");
        exit(1);
    }
    printf("\nMessage from server: %s\n", message);
    memset(message, 0, MSG_LEN);
    sprintf(message, "RCPT TO:<%s>\r\n", recipient);
    if(send(sock, message, strlen(message), 0)<0) {
        perror("\nError: Could not send data!\n");
        exit(1);
    }
    memset(message, 0, MSG_LEN);
    if(recv(sock, message, MSG_LEN, 0)<0) {
        perror("\nError: Could not receive data!\n");
        exit(1);
    }
    printf("\nMessage from server: %s\n", message);
    memset(message, 0, MSG_LEN);
    sprintf(message, "DATA\r\n");
    if(send(sock, message, strlen(message), 0)<0) {
        perror("\nError: Could not send data!\n");
        exit(1);
    }
    memset(message, 0, MSG_LEN);
    if(recv(sock, message, MSG_LEN, 0)<0) {
        perror("\nError: Could not receive data!\n");
        exit(1);
    }
    printf("\nMessage from server: %s\n", message);
    printf("\nEnter Message. Terminate with \\r\\n.:\n");
    char temp;
    int counter = 0;
    while((temp = getchar())!='\n') {
        message[counter++] = temp;
    }
    message[counter] = '\r';
    message[counter+1] = '\n';
    message[counter+2] = '\0';
    if(send(sock, message, strlen(message), 0)<0) {
        perror("\nError: Could not send data!\n");
        exit(1);
    }
    memset(message, 0, MSG_LEN);
    if(recv(sock, message, MSG_LEN, 0)<0) {
        perror("\nError: Could not receive data!\n");
        exit(1);
    }
    printf("\nMessage from server: %s\n", message);
    memset(message, 0, MSG_LEN);
    sprintf(message, "QUIT\r\n");
    if(send(sock, message, strlen(message), 0)<0) {
        perror("\nError: Could not send data!\n");
        exit(1);
    }
    memset(message, 0, MSG_LEN);
    if(recv(sock, message, MSG_LEN, 0)<0) {
        perror("\nError: Could not receive data!\n");
        exit(1);
    }
    printf("\nMessage from server: %s\n", message);
    close(sock);
    return 0;
}