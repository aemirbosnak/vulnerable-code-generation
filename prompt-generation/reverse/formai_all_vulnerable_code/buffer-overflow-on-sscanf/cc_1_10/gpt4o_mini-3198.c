//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 110  // Standard port for POP3
#define MAX_BUFFER 1024
#define MAX_EMAILS 100

typedef struct {
    char sender[100];
    char subject[100];
    char body[500];
} Email;

void printEmail(Email em) {
    printf("\nFrom: %s\nSubject: %s\nBody:\n%s\n\n", em.sender, em.subject, em.body);
}

void receiveEmails(int socketFD) {
    char buffer[MAX_BUFFER];
    int numEmails = 0;
    Email emails[MAX_EMAILS];

    // Send USER command
    send(socketFD, "USER username\r\n", 16, 0);  
    recv(socketFD, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send PASS command
    send(socketFD, "PASS password\r\n", 16, 0);
    recv(socketFD, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send LIST command
    send(socketFD, "LIST\r\n", 7, 0);
    recv(socketFD, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    while (strstr(buffer, "OK") == NULL && numEmails < MAX_EMAILS) {
        sprintf(buffer, "RETR %d\r\n", numEmails + 1);
        send(socketFD, buffer, strlen(buffer), 0);
        recv(socketFD, buffer, MAX_BUFFER, 0);
        sscanf(buffer, "From: %s\nSubject: %s\n\n%s\n", emails[numEmails].sender, emails[numEmails].subject, emails[numEmails].body);
        numEmails++;
    }

    for (int i = 0; i < numEmails; i++) {
        printEmail(emails[i]);
    }

    // Send QUIT command
    send(socketFD, "QUIT\r\n", 7, 0);
    recv(socketFD, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int socketFD;
    struct sockaddr_in serverAddr;
    
    // Setup socket
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Setup server address struct
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(socketFD, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        close(socketFD);
        return EXIT_FAILURE;
    }

    printf("Connected to email server.\n");

    // Receive emails
    receiveEmails(socketFD);

    close(socketFD);
    return EXIT_SUCCESS;
}