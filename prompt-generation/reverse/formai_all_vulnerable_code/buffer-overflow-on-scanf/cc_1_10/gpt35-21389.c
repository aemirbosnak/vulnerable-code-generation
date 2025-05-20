//FormAI DATASET v1.0 Category: Networking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockID, valRead;
    struct sockaddr_in serverAddr;
    char buffer[1024] = {0};
    
    // Creating socket
    if ((sockID = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error \n");
        return -1;
    }
    printf("Energetic Network Program!\n");

    memset(&serverAddr, '0', sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported \n");
        return -1;
    }

    // Connecting to server
    if (connect(sockID, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Connection failed \n");
        return -1;
    }

    while (1) {
        printf("Enter your message: ");
        scanf("%s", buffer);
        // Sending message to server
        send(sockID , buffer , strlen(buffer) , 0 );
        printf("Message sent to server \n");
        // Receiving message from server
        valRead = read( sockID , buffer, 1024);
        printf("%s\n",buffer );
    }
    return 0;
}