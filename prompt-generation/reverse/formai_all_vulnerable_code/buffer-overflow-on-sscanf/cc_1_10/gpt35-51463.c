//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {

    int sock;
    struct hostent *host;
    struct sockaddr_in serverAddress;
    char buffer[BUFFER_SIZE];

    //POP3 server information
    char* POP3ServerName = "pop.gmail.com";
    char* POP3Username = "example@gmail.com";
    char* POP3Password = "password";
    int POP3Port = 995;

    //Connect to the POP3 server
    host = gethostbyname(POP3ServerName);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(POP3Port);
    bcopy((char *)host->h_addr, (char *)&serverAddress.sin_addr.s_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }

    //Receive server banner
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("[%s]\n", buffer);

    //Login to the POP3 server
    char loginMessage[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(loginMessage, "USER %s\r\n", POP3Username);
    send(sock, loginMessage, strlen(loginMessage), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("[%s]\n", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(loginMessage, "PASS %s\r\n", POP3Password);
    send(sock, loginMessage, strlen(loginMessage), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("[%s]\n", buffer);

    //Get number of messages in mailbox
    int numberOfMessages = 0;
    char numMessagesMessage[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(numMessagesMessage, "STAT\r\n");
    send(sock, numMessagesMessage, strlen(numMessagesMessage), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("[%s]\n", buffer);

    sscanf(buffer, "+OK %d", &numberOfMessages);

    //Retrieve all messages
    for (int i = 1; i <= numberOfMessages; i++) {

        char retrieveMessage[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        sprintf(retrieveMessage, "RETR %d\r\n", i);
        send(sock, retrieveMessage, strlen(retrieveMessage), 0);
        recv(sock, buffer, BUFFER_SIZE, 0);
        printf("[%s]\n", buffer);

        //Save message to file
        char filename[20];
        sprintf(filename, "message%d.txt", i);
        FILE *fp = fopen(filename, "w");
        fprintf(fp, "%s", buffer);
        fclose(fp);

    }

    //Logout from the POP3 server and close the connection
    char logoutMessage[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(logoutMessage, "QUIT\r\n");
    send(sock, logoutMessage, strlen(logoutMessage), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("[%s]\n", buffer);

    close(sock);

    return EXIT_SUCCESS;
}