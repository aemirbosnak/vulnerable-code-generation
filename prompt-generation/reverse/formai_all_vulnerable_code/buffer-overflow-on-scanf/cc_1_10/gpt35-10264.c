//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXSIZE 1024

int sock_descriptor;  // Global variable

int connectToServer(char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    sock_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if(sock_descriptor < 0) {
        perror("Error : Cannot create socket.");
        return -1;
    }

    server = gethostbyname(hostname);

    if(server == NULL) {
        fprintf(stderr, "Error : Host not found.");
        return -1;
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if(connect(sock_descriptor, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error : Could not connect.");
        return -1;
    }

    return 0;
}

void sendCommand(char *cmd) {
    char buffer[MAXSIZE];
    recv(sock_descriptor, buffer, MAXSIZE, 0);
    memset(buffer, 0, MAXSIZE);
    sprintf(buffer, "%s\r\n", cmd);
    send(sock_descriptor, buffer, strlen(buffer), 0);
}

void receiveData() {
    char buffer[MAXSIZE];
    memset(buffer, 0, MAXSIZE);
    recv(sock_descriptor, buffer, MAXSIZE, 0);
    printf("%s", buffer);
}

int main() {
    char username[50];
    char password[50];
    char servername[50];

    printf("Enter server name : ");
    scanf("%s", servername);
    printf("Enter username : ");
    scanf("%s", username);
    printf("Enter password : ");
    scanf("%s", password);

    if(connectToServer(servername, 143) < 0) {
        return -1;
    }

    receiveData();
    sendCommand("A01 LOGIN ");
    sendCommand(username);
    sendCommand(" ");
    sendCommand(password);

    receiveData();
    sendCommand("A02 SELECT INBOX");
    receiveData();

    return 0;
}