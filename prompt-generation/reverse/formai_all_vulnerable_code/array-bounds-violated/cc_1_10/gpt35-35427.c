//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock, port, nBytes, totalBytes = 0;
    char recvBuf[BUFSIZE], sendBuf[BUFSIZE], *serverAddr, *username, *password;
    struct sockaddr_in server;
    socklen_t rcvAddrLen = sizeof(server);

    // Check for correct argument count
    if (argc != 4) {
        printf("Usage: %s <server IP> <server port> <username>\n", argv[0]);
        exit(1);
    }

    // Get arguments
    serverAddr = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    printf("Enter password:\n");
    fgets(sendBuf, BUFSIZE, stdin);
    strtok(sendBuf, "\n");  // remove newline character from password
    password = sendBuf;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create socket.\n");
        exit(1);
    }

    // Set server address and port
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_aton(serverAddr, &server.sin_addr) == 0) {
        printf("Invalid server IP address.\n");
        exit(1);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server, rcvAddrLen) < 0) {
        printf("Failed to connect to server.\n");
        exit(1);
    }

    // Receive server greeting
    memset(recvBuf, '\0', BUFSIZE);
    nBytes = recv(sock, recvBuf, BUFSIZE - 1, 0);
    recvBuf[nBytes] = '\0';
    printf("%s", recvBuf);  // print server greeting

    // Send username
    sprintf(sendBuf, "USER %s\r\n", username);
    send(sock, sendBuf, strlen(sendBuf), 0);

    // Receive response to username
    memset(recvBuf, '\0', BUFSIZE);
    nBytes = recv(sock, recvBuf, BUFSIZE - 1, 0);
    recvBuf[nBytes] = '\0';
    printf("%s", recvBuf);  // print response to username

    // Send password
    sprintf(sendBuf, "PASS %s\r\n", password);
    send(sock, sendBuf, strlen(sendBuf), 0);

    // Receive response to password
    memset(recvBuf, '\0', BUFSIZE);
    nBytes = recv(sock, recvBuf, BUFSIZE - 1, 0);
    recvBuf[nBytes] = '\0';
    printf("%s", recvBuf);  // print response to password

    // Check if login was successful
    if (strstr(recvBuf, "OK") == NULL) {
        printf("Failed to login. Quitting...\n");
        exit(1);
    }

    // Send command to list messages
    sprintf(sendBuf, "LIST\r\n");
    send(sock, sendBuf, strlen(sendBuf), 0);

    // Receive response to list command
    memset(recvBuf, '\0', BUFSIZE);
    nBytes = recv(sock, recvBuf, BUFSIZE - 1, 0);
    recvBuf[nBytes] = '\0';
    printf("%s", recvBuf);  // print response to list command

    // Parse message IDs from response to list command
    int numMessages = 0;
    char *msgIDs[BUFSIZE], *token;
    memset(msgIDs, 0, BUFSIZE);
    token = strtok(recvBuf, "\r\n");
    while(token != NULL) {
        if (isdigit(token[0])) {
            msgIDs[numMessages] = token;
            totalBytes += atoi(strtok(token, " "));
            numMessages++;
        }
        token = strtok(NULL, "\r\n");
    }

    // Print number of messages and total size
    printf("Number of messages: %d\n", numMessages);
    printf("Total size: %d bytes\n", totalBytes);

    // Print header for each message
    for (int i = 0; i < numMessages; i++) {
        printf("Message %d:\n", atoi(strtok(msgIDs[i], " ")));
        sprintf(sendBuf, "TOP %s 0\r\n", msgIDs[i]);
        send(sock, sendBuf, strlen(sendBuf), 0);
        memset(recvBuf, '\0', BUFSIZE);
        nBytes = recv(sock, recvBuf, BUFSIZE - 1, 0);
        recvBuf[nBytes] = '\0';
        printf("%s", recvBuf);
    }

    // Close socket
    close(sock);

    return 0;
}