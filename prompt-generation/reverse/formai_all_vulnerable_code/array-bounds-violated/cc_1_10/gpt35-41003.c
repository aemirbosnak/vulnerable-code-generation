//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

/* Function to connect to IMAP server using TCP/IP */
int connectToServer(char *hostname, int port)
{
    int sock;
    struct sockaddr_in server;

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // set up server address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Error getting host");
        exit(1);
    }
    bzero((char *)&server, sizeof(server));
    server.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server.sin_addr.s_addr, host->h_length);
    server.sin_port = htons(port);

    // connect to server
    if (connect(sock,(struct sockaddr *)&server,sizeof(server)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    return sock;
}

/* Function to send a message to the server */
void sendMessage(int sock, char *msg)
{
    if (send(sock, msg, strlen(msg), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }
}

/* Function to receive a message from the server */
char* receiveMessage(int sock)
{
    char buffer[BUFFER_SIZE];
    int n = recv(sock, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) {
        perror("Error receiving message");
        exit(1);
    }
    buffer[n] = '\0';
    return strdup(buffer);
}

/* Main function */
int main(int argc, char **argv)
{
    if (argc != 4) {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    // connect to server
    int sock = connectToServer(server, port);

    // receive banner message
    char *response = receiveMessage(sock);
    printf("%s\n", response);
    free(response);

    // send login message
    char loginMsg[BUFFER_SIZE];
    sprintf(loginMsg, "a001 LOGIN %s\r\n", username);
    sendMessage(sock, loginMsg);

    // receive login response
    response = receiveMessage(sock);
    printf("%s\n", response);
    free(response);

    // send select INBOX message
    sendMessage(sock, "a002 SELECT INBOX\r\n");

    // receive select INBOX response
    response = receiveMessage(sock);
    printf("%s\n", response);
    free(response);

    // send fetch messages message
    sendMessage(sock, "a003 FETCH 1:* (FLAGS BODY[HEADER.FIELDS (FROM SUBJECT DATE)])\r\n");

    // receive fetch messages response
    response = receiveMessage(sock);
    printf("%s\n", response);
    free(response);

    // send logout message
    sendMessage(sock, "a004 LOGOUT\r\n");

    // receive logout response
    response = receiveMessage(sock);
    printf("%s\n", response);
    free(response);

    // close socket
    close(sock);

    return 0;
}