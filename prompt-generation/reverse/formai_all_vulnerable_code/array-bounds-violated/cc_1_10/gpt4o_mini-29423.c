//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFFER_SIZE 1024

// Noble Steed to bear our message
typedef struct {
    char *hostname;
    char *path;
} Quest;

void perform_quest(Quest *quest) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    
    // Fortifying the socket for our quest
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Our steed has stumbled!");
        exit(EXIT_FAILURE);
    }
    
    // Preparing the battleground for the greeting with the server's domain
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(quest->hostname);
    
    // Adventuring forth to connect
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Our connection has been thwarted!");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    // Crafting the request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", quest->path, quest->hostname);
    
    // Sending the valiant message
    send(sockfd, request, strlen(request), 0);
    
    // Preparing to receive the response
    printf("Awaiting response from the realm...\n");
    while (1) {
        int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
        if (bytes_received <= 0) {
            break; // The end of the tale
        }
        response[bytes_received] = '\0'; // Terminating the string
        printf("%s", response); // Revealing the words of the server
    }
    
    // Closing the gates post-quest
    close(sockfd);
}

int main(int argc, char *argv[]) {
    Quest quest;
    
    // Verifying the royal decree
    if (argc != 3) {
        printf("Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE; 
    }
    
    // Bestowing values upon our quest
    quest.hostname = argv[1];
    quest.path = argv[2];
    
    // Embarking on our quest
    perform_quest(&quest);
    
    // The conclusion of our tale
    return EXIT_SUCCESS;
}