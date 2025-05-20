//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 9000
#define BUFFER_SIZE 2048
#define MAX_USERS 100

typedef struct {
    char username[50];
    char ip[INET_ADDRSTRLEN];
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user(const char* username, const char* ip) {
    if (user_count < MAX_USERS) {
        strcpy(users[user_count].username, username);
        strcpy(users[user_count].ip, ip);
        user_count++;
    } else {
        printf("No more space for new users in this desolate world.\n");
    }
}

void list_users() {
    printf("Survivor User List:\n");
    for (int i = 0; i < user_count; i++) {
        printf("%d: %s (%s)\n", i + 1, users[i].username, users[i].ip);
    }
}

void send_message(const char* recipient, const char* message, struct sockaddr_in servaddr) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, recipient) == 0) {
            sendto(sock, message, strlen(message), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
            printf("Message sent to %s: %s\n", recipient, message);
            close(sock);
            return;
        }
    }

    printf("No user with username: %s\n", recipient);
    close(sock);
}

void receive_messages(int sock) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in from_addr;
    socklen_t addr_len = sizeof(from_addr);

    while (1) {
        int n = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &from_addr, &addr_len);
        buffer[n] = '\0';
        
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &from_addr.sin_addr, ip, sizeof(ip));
        
        printf("Message received from %s: %s\n", ip, buffer);
    }
}

int main() {
    printf("Welcome to the Post-Apocalyptic Email Client.\n");
    printf("In these times of darkness, find solace in sending messages.\n");

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (bind(sock, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    char command[50];
    while (1) {
        printf("\nEnter a command (add | list | send | quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char username[50];
            char ip[INET_ADDRSTRLEN];
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter IP address: ");
            scanf("%s", ip);
            add_user(username, ip);
        } else if (strcmp(command, "list") == 0) {
            list_users();
        } else if (strcmp(command, "send") == 0) {
            char recipient[50], message[BUFFER_SIZE];
            printf("Enter recipient username: ");
            scanf("%s", recipient);
            printf("Enter your message: ");
            getchar(); // to consume newline character
            fgets(message, BUFFER_SIZE, stdin);
            message[strcspn(message, "\n")] = 0; // remove newline
            send_message(recipient, message, servaddr);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }
        
        receive_messages(sock);
    }

    close(sock);
    printf("Faced with this desolate world, we bid you farewell in despair.\n");
    return 0;
}