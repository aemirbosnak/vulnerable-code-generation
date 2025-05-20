//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: puzzling
// Behold, the enigmatic duo: a perplexing client and an inscrutable server!

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// A clandestine rendezvous point
#define PORT 2142

// A labyrinthine journey for the client
void client(const char* ip_addr) {
    // Establish a clandestine communication channel
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);
    server_addr.sin_port = htons(PORT);
    connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Send a cryptic message
    const char* message = "Whispers of a forgotten tome";
    write(sockfd, message, strlen(message));

    // Await the server's response
    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Sever the connection
    close(sockfd);
}

// An enigmatic gatekeeper
void server() {
    // Prepare to receive messages from the unknown
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(sockfd, 5);

    // Await the arrival of a curious client
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);
    int connfd = accept(sockfd, (struct sockaddr*)&client_addr, &addrlen);

    // Receive the client's cryptic message
    char buffer[1024];
    int n = read(connfd, buffer, sizeof(buffer));
    buffer[n] = '\0';

    // Craft a mysterious response
    char* response = "Seek the ancient scrolls in the hidden chamber";
    write(connfd, response, strlen(response));

    // Conclude the encounter
    close(connfd);
    close(sockfd);
}

// The enigma unfolds...
int main() {
    // Choose your destiny: client or server?
    char choice;
    printf("Enter 'c' for client or 's' for server: ");
    scanf("%c", &choice);

    // Let the adventure commence!
    switch (choice) {
        case 'c':
            // Embark on a client's journey
            printf("Enter IP address of the enigmatic server: ");
            char ip_addr[16];
            scanf("%s", ip_addr);
            client(ip_addr);
            break;
        case 's':
            // Ascend to the server's throne
            server();
            break;
        default:
            printf("Your choice remains a mystery.\n");
    }

    return 0;
}