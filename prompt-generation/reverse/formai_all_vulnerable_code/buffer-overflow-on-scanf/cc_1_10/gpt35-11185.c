//FormAI DATASET v1.0 Category: Client Server Application ; Style: peaceful
/* A peaceful C Client-Server Application for Sending and Receiving Messages */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char message[1024] = {0}, buffer[1024] = {0};

    // Creating a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error.\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converting IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("Invalid address/ Address not supported.\n");
        return -1;
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection Failed.\n");
        return -1;
    }

    // Sending message to the server
    printf("Enter your message: ");
    scanf("%s", message);

    if( send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed.\n");
        return -1;
    }
    printf("Message sent successfully.\n");

    // Receiving message from the server
    valread = read(sock, buffer, 1024);
    printf("Server Message: %s\n", buffer);

    return 0;
}