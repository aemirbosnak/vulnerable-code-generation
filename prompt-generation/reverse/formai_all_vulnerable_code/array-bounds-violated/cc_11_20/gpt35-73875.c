//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

// POP3 server details
#define POP3_SERVER "mail.example.com"
#define POP3_USER "username@example.com"
#define POP3_PASSWORD "password123"

// POP3 commands
#define POP3_USER_CMD "USER %s\r\n"
#define POP3_PASS_CMD "PASS %s\r\n"
#define POP3_LIST_CMD "LIST\r\n"
#define POP3_RETR_CMD "RETR %d\r\n"
#define POP3_QUIT_CMD "QUIT\r\n"

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server;
    char user_cmd[256];
    char pass_cmd[256];
    char list_cmd[] = "LIST\r\n";
    char retr_cmd[256];
    char quit_cmd[] = "QUIT\r\n";
    char buffer[1024];
    char *msgPtr;
    int msgLen;
    int msgTotalLen;
    int msgCount;
    int i;

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Could not create socket");
        return 1;
    }

    // set POP3 server details
    server.sin_addr.s_addr = inet_addr(POP3_SERVER);
    server.sin_family = AF_INET;
    server.sin_port = htons(110);

    // connect to server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Could not connect to server");
        return 1;
    }

    // receive server greeting
    if ((msgLen = recv(sock, buffer, 1024, 0)) < 0) {
        perror("Could not receive server greeting");
        return 1;
    }
    buffer[msgLen] = '\0';
    printf("%s", buffer);

    // send USER command to server
    sprintf(user_cmd, POP3_USER_CMD, POP3_USER);
    send(sock, user_cmd, strlen(user_cmd), 0);

    // receive response to USER command
    if ((msgLen = recv(sock, buffer, 1024, 0)) < 0) {
        perror("Could not receive USER command response");
        return 1;
    }
    buffer[msgLen] = '\0';
    printf("%s", buffer);

    // send PASS command to server
    sprintf(pass_cmd, POP3_PASS_CMD, POP3_PASSWORD);
    send(sock, pass_cmd, strlen(pass_cmd), 0);

    // receive response to PASS command
    if ((msgLen = recv(sock, buffer, 1024, 0)) < 0) {
        perror("Could not receive PASS command response");
        return 1;
    }
    buffer[msgLen] = '\0';
    printf("%s", buffer);

    // send LIST command to server
    send(sock, list_cmd, strlen(list_cmd), 0);

    // receive response to LIST command
    msgTotalLen = 0;
    msgPtr = buffer;
    while ((msgLen = recv(sock, msgPtr, 1024, 0)) > 0) {
        msgTotalLen += msgLen;
        msgPtr += msgLen;
    }
    buffer[msgTotalLen] = '\0';
    printf("%s", buffer);

    // count number of messages in mailbox
    msgCount = 0;
    for (i = 0; i < msgTotalLen; i++) {
        if (buffer[i] == '\n') {
            msgCount++;
        }
    }
    printf("Number of messages in mailbox: %d\n", msgCount);

    // retrieve messages from mailbox
    for (i = 1; i <= msgCount; i++) {
        // send RETR command to server
        sprintf(retr_cmd, POP3_RETR_CMD, i);
        send(sock, retr_cmd, strlen(retr_cmd), 0);

        // receive response to RETR command
        msgTotalLen = 0;
        msgPtr = buffer;
        while ((msgLen = recv(sock, msgPtr, 1024, 0)) > 0) {
            msgTotalLen += msgLen;
            msgPtr += msgLen;
        }
        buffer[msgTotalLen] = '\0';
        printf("--- Message %d ---\n%s", i, buffer);
    }

    // send QUIT command to server
    send(sock, quit_cmd, strlen(quit_cmd), 0);

    // receive response to QUIT command
    if ((msgLen = recv(sock, buffer, 1024, 0)) < 0) {
        perror("Could not receive QUIT command response");
        return 1;
    }
    buffer[msgLen] = '\0';
    printf("%s", buffer);

    // close socket
    close(sock);

    return 0;
}