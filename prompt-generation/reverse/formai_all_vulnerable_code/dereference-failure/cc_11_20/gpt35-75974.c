//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Alas! Failed to create socket to send my love :(\n");
        return 1;
    }
    printf("Hark! I have created a socket to send my love to thee <3\n");

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    //Connect to the server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        printf("Oh! mine heart aches! Failed to connect to thy server :(\n");
        return 1;
    }
    printf("Huzzah! I have connected to thy server and begone to your port 25!\n");

    char message[1000];

    //Receive a message from the server
    if(recv(sock, message, 1000, 0) < 0) {
        printf("How now! Failed to receive message from thee :(\n");
        return 1;
    }
    printf("Received: %s\n", message);

    //Send the EHLO command to the server
    char ehlo[100] = "EHLO ";
    strcat(ehlo, argv[1]);
    strcat(ehlo, "\r\n");
    if(send(sock, ehlo, strlen(ehlo), 0) < 0) {
        printf("Alas! Failed to send EHLO command to thee server :(\n");
        return 1;
    }
    printf("Sent: %s", ehlo);

    //Receive a message from the server
    if(recv(sock, message, 1000, 0) < 0) {
        printf("How now! Failed to receive message from thee :(\n");
        return 1;
    }
    printf("Received: %s\n", message);

    //Send the MAIL FROM command to the server
    char mail_from[100] = "MAIL FROM:<";
    strcat(mail_from, argv[2]);
    strcat(mail_from, ">\r\n");
    if(send(sock, mail_from, strlen(mail_from), 0) < 0) {
        printf("Alas! Failed to send MAIL FROM command to thee server :(\n");
        return 1;
    }
    printf("Sent: %s", mail_from);

    //Receive a message from the server
    if(recv(sock, message, 1000, 0) < 0) {
        printf("How now! Failed to receive message from thee :(\n");
        return 1;
    }
    printf("Received: %s\n", message);

    //Send the RCPT TO command to the server
    char rcpt_to[100] = "RCPT TO:<";
    strcat(rcpt_to, argv[3]);
    strcat(rcpt_to, ">\r\n");
    if(send(sock, rcpt_to, strlen(rcpt_to), 0) < 0) {
        printf("Alas! Failed to send RCPT TO command to thee server :(\n");
        return 1;
    }
    printf("Sent: %s", rcpt_to);

    //Receive a message from the server
    if(recv(sock, message, 1000, 0) < 0) {
        printf("How now! Failed to receive message from thee :(\n");
        return 1;
    }
    printf("Received: %s\n", message);

    //Send the DATA command to the server
    if(send(sock, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
        printf("Alas! Failed to send DATA command to thee server :(\n");
        return 1;
    }
    printf("Sent: DATA\r\n");

    //Receive a message from the server
    if(recv(sock, message, 1000, 0) < 0) {
        printf("How now! Failed to receive message from thee :(\n");
        return 1;
    }
    printf("Received: %s\n", message);

    //Send the message to the server
    char data[1000];
    printf("My dearest, please share thy message of love (must end with a period on a new line):\n");
    fgets(data, 1000, stdin);
    if(send(sock, data, strlen(data), 0) < 0) {
        printf("Alas! Failed to send thy message to thee server :(\n");
        return 1;
    }

    //Receive a message from the server
    if(recv(sock, message, 1000, 0) < 0) {
        printf("How now! Failed to receive message from thee :(\n");
        return 1;
    }
    printf("Received: %s\n", message);

    //Send the QUIT command to the server
    if(send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        printf("Alas! Failed to send QUIT command to thee server :(\n");
        return 1;
    }
    printf("Sent: QUIT\r\n");

    //Receive a message from the server
    if(recv(sock, message, 1000, 0) < 0) {
        printf("How now! Failed to receive message from thee :(\n");
        return 1;
    }
    printf("Received: %s\n", message);

    //Close the socket
    close(sock);
    printf("Farewell my dearest! I have successfully sent my love to thee!\n");
    return 0;
}