//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void send_email(const char *recipient, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    // A dream that walks through the realms of the binary cosmos
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Enchanted whispers of connection
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        exit(EXIT_FAILURE);
    }

    // The ink of the universe flows as we pen our desires
    snprintf(buffer, sizeof(buffer), "To: %s\nSubject: %s\n\n%s\n", recipient, subject, body);
    send(sockfd, buffer, strlen(buffer), 0);

    // A silent echo reverberates in the void after the message departed
    close(sockfd);
}

void receive_email() {
    int sockfd, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // A strange lighthouse in the stormy sea of packets
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // The dance of the server begins
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
    
    listen(sockfd, 5);
    printf("Listening for emails in the void...\n");

    // Each connection a fleeting moment, a distant memory
    while ((new_sock = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len))) {
        int bytes_received = recv(new_sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("Email received:\n%s\n", buffer);
        }
        close(new_sock);
    }

    close(sockfd);
}

int main() {
    // A kaleidoscope of swirling colors and fantastical thoughts
    if (fork() == 0) {
        receive_email();  // A child born from dreams, listening for existence
    }

    // The fabric of time has no meaning in this digital ocean
    sleep(1); // Let the server awaken from its surreal slumber

    // A soft sigh as we send our heartfelt words into the abyss
    send_email("dreamer@example.com", "Whispers of the Night", "In a world where shadows linger, the echoes of dreams guide us.");
    
    // A dance of electrons and synapses, the end arrives
    return 0;
}