//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int portNumber = 110; // Default port number for POP3 protocol
    char *serverAddress = NULL; // POP3 server address to connect
    char *username = NULL; // POP3 username
    char *password = NULL; // POP3 password

    // Check if correct number of command line arguments are passed
    if(argc == 4) {
        serverAddress = argv[1];
        username = argv[2];
        password = argv[3];
    }
    else {
        printf("Please enter correct command line arguments: <POP3 server address> <username> <password>\n");
        return 1;
    }

    // Create a TCP socket to connect to POP3 server
    int socketFileDescriptor;
    if((socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error in creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Set POP3 server address and port
    struct sockaddr_in serverAddressInfo;
    memset(&serverAddressInfo, 0, sizeof(serverAddressInfo));
    serverAddressInfo.sin_family = AF_INET;
    serverAddressInfo.sin_port = htons(portNumber);
    if(inet_pton(AF_INET, serverAddress, &serverAddressInfo.sin_addr) <= 0) {
        printf("Error in converting server address: %s\n", strerror(errno));
        return 1;
    }

    // Connect to POP3 server
    if(connect(socketFileDescriptor, (struct sockaddr *)&serverAddressInfo, sizeof(serverAddressInfo)) < 0) {
        printf("Error in connecting to server: %s\n", strerror(errno));
        close(socketFileDescriptor);
        return 1;
    }

    // Receive server greeting
    char buffer[BUFFER_SIZE];
    memset(&buffer, 0, BUFFER_SIZE);
    if(recv(socketFileDescriptor, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error in receiving server greeting: %s\n", strerror(errno));
        close(socketFileDescriptor);
        return 1;
    }

    // Print server greeting
    printf("%s", buffer);

    // Send POP3 authentication commands
    char *tempBuffer;
    int tempBufferSize;

    // User command
    tempBufferSize = asprintf(&tempBuffer, "USER %s\r\n", username);
    if(send(socketFileDescriptor, tempBuffer, tempBufferSize, 0) != tempBufferSize) {
        printf("Error in sending USER command: %s\n", strerror(errno));
        free(tempBuffer);
        close(socketFileDescriptor);
        return 1;
    }
    printf("Sent USER command: %s", tempBuffer);
    free(tempBuffer);

    // Receive response to USER command
    memset(&buffer, 0, BUFFER_SIZE);
    if(recv(socketFileDescriptor, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error in receiving response to USER command: %s\n", strerror(errno));
        close(socketFileDescriptor);
        return 1;
    }
    printf("%s", buffer);

    // Pass command
    tempBufferSize = asprintf(&tempBuffer, "PASS %s\r\n", password);
    if(send(socketFileDescriptor, tempBuffer, tempBufferSize, 0) != tempBufferSize) {
        printf("Error in sending PASS command: %s\n", strerror(errno));
        free(tempBuffer);
        close(socketFileDescriptor);
        return 1;
    }
    printf("Sent PASS command: %s", tempBuffer);
    free(tempBuffer);

    // Receive response to PASS command
    memset(&buffer, 0, BUFFER_SIZE);
    if(recv(socketFileDescriptor, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error in receiving response to PASS command: %s\n", strerror(errno));
        close(socketFileDescriptor);
        return 1;
    }
    printf("%s", buffer);

    // List command to list all messages available
    tempBufferSize = asprintf(&tempBuffer, "LIST\r\n");
    if(send(socketFileDescriptor, tempBuffer, tempBufferSize, 0) != tempBufferSize) {
        printf("Error in sending LIST command: %s\n", strerror(errno));
        free(tempBuffer);
        close(socketFileDescriptor);
        return 1;
    }
    printf("Sent LIST command: %s", tempBuffer);
    free(tempBuffer);

    // Receive response to LIST command and print individual message headers
    memset(&buffer, 0, BUFFER_SIZE);
    if(recv(socketFileDescriptor, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error in receiving response to LIST command: %s\n", strerror(errno));
        close(socketFileDescriptor);
        return 1;
    }
    printf("%s", buffer);
    if(strncmp(buffer, "+OK", 3) == 0) {
        char *messageToken = strtok(buffer, "\r\n");
        messageToken = strtok(NULL, "\r\n"); // Skip +OK message
        while(messageToken != NULL) {
            printf("%s\n", messageToken);
            messageToken = strtok(NULL, "\r\n");
        }
    }

    // Quit command to end POP3 session
    tempBufferSize = asprintf(&tempBuffer, "QUIT\r\n");
    if(send(socketFileDescriptor, tempBuffer, tempBufferSize, 0) != tempBufferSize) {
        printf("Error in sending QUIT command: %s\n", strerror(errno));
        free(tempBuffer);
        close(socketFileDescriptor);
        return 1;
    }
    printf("Sent QUIT command: %s", tempBuffer);
    free(tempBuffer);

    // Receive response to QUIT command
    memset(&buffer, 0, BUFFER_SIZE);
    if(recv(socketFileDescriptor, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error in receiving response to QUIT command: %s\n", strerror(errno));
        close(socketFileDescriptor);
        return 1;
    }
    printf("%s", buffer);

    // Close socket file descriptor
    close(socketFileDescriptor);

    return 0;
}