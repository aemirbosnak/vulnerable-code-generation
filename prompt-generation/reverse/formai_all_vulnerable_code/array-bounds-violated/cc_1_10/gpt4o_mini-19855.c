//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void romeo(int sockfd) {
    char message[BUFFER_SIZE];
    while (1) {
        printf("Romeo: Enter your message to Juliet (type 'exit' to leave): ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0;  // Remove the newline character

        send(sockfd, message, strlen(message), 0);
        if (strcmp(message, "exit") == 0) {
            break; // exit the loop if 'exit' is entered
        }
    }
}

void juliet(int sockfd) {
    char buffer[BUFFER_SIZE];
    while (1) {
        int len = recv(sockfd, buffer, sizeof(buffer)-1, 0);
        if (len <= 0) {
            break; // Break if the connection is lost
        }
        buffer[len] = 0; // Null-terminate the received message
        printf("Juliet received: %s\n", buffer);
        if (strcmp(buffer, "exit") == 0) {
            break; // exit the loop if 'exit' is received
        }
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char *role;

    printf("Choose your role (Romeo/Juliet): ");
    char choice[10];
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0;  // Remove newline

    if (strcmp(choice, "Romeo") == 0) {
        role = "Romeo";
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(PORT);
        
        if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("Bind failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        if (listen(sockfd, 1) < 0) {
            perror("Listen failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        socklen_t addr_len = sizeof(client_addr);
        int new_sock = accept(sockfd, (struct sockaddr*)&client_addr, &addr_len);
        if (new_sock < 0) {
            perror("Accept failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        printf("Romeo has met Juliet!\n");
        romeo(new_sock);
        close(new_sock);
        close(sockfd);
        printf("Romeo's heart has departed.\n");

    } else if (strcmp(choice, "Juliet") == 0) {
        role = "Juliet";
        sleep(1); // Ensure Romeo starts first
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(PORT);

        if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("Connection failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        printf("Juliet awaits Romeo...\n");
        juliet(sockfd);
        close(sockfd);
        printf("Juliet's heart has ceased to beat.\n");

    } else {
        printf("Invalid role selection. Choose 'Romeo' or 'Juliet'.\n");
        return 1;
    }

    return 0;
}