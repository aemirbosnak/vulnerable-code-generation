//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_LEN 1024
#define PORT 8080

void cryptic_message(const char *message, char *buffer) {
    while (*message) {
        // Simple character shift for the message
        *buffer++ = *message++ + 3; // Shift characters
    }
    *buffer = '\0';
}

void decipher_message(const char *message, char *buffer) {
    while (*message) {
        // Reverse character shift
        *buffer++ = *message++ - 3; // Shift characters back
    }
    *buffer = '\0';
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_LEN], crypt_buffer[BUFFER_LEN];
    socklen_t addr_len = sizeof(client_addr);
    
    // Socket creation
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    
    // Server information
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // All available interfaces
    server_addr.sin_port = htons(PORT); // Port number

    // Binding the socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind Failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server is up and running on port %d...\n", PORT);
    
    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_LEN, MSG_WAITALL, 
                         (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0';

        printf("Received: %s\n", buffer);

        // Encrypt the message
        cryptic_message(buffer, crypt_buffer);
        printf("Encrypted message: %s\n", crypt_buffer);

        // Send the encrypted message back
        sendto(sockfd, crypt_buffer, strlen(crypt_buffer), MSG_CONFIRM, 
               (const struct sockaddr *)&client_addr, addr_len);
        
        // Let's add a deciphering part too
        decipher_message(crypt_buffer, buffer);
        printf("Deciphered message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}