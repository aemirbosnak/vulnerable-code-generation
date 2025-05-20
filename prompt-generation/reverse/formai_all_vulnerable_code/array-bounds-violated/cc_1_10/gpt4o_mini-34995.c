//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <ifaddrs.h>

#define MAX_RULES 100
#define BUFFER_SIZE 2048
#define PORT 8888

typedef struct {
    char ip[INET_ADDRSTRLEN];
    char action[10]; // "ALLOW" or "BLOCK"
} FirewallRule;

FirewallRule rules[MAX_RULES];
int rule_count = 0;

void add_rule(const char *ip, const char *action) {
    if (rule_count >= MAX_RULES) {
        fprintf(stderr, "Maximum rule limit reached!\n");
        return;
    }
    strncpy(rules[rule_count].ip, ip, INET_ADDRSTRLEN);
    strncpy(rules[rule_count].action, action, sizeof(rules[rule_count].action) - 1);
    rule_count++;
}

void print_rules() {
    printf("Current Firewall Rules:\n");
    for (int i = 0; i < rule_count; i++) {
        printf("IP: %s | Action: %s\n", rules[i].ip, rules[i].action);
    }
}

int should_block(const char *ip) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && strcmp(rules[i].action, "BLOCK") == 0) {
            return 1;
        }
    }
    return 0; // Allow by default if not matched
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    char client_ip[INET_ADDRSTRLEN];
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Get client address
    getpeername(client_sock, (struct sockaddr *)&client_addr, &addr_len);
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));

    printf("Connection from %s\n", client_ip);

    if (should_block(client_ip)) {
        printf("Blocked incoming connection from %s\n", client_ip);
        close(client_sock);
        return;
    }

    // Echo back client message
    int bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Error reading from socket");
    } else {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Received message: %s\n", buffer);

        // Echo to client
        send(client_sock, buffer, bytes_received, 0);
    }

    close(client_sock);
}

int main() {
    // Basic GUI menu
    printf("----- Simple C Firewall -----\n");
    printf("1. Add Rule\n");
    printf("2. Show Rules\n");
    printf("3. Start Firewall\n");
    printf("4. Exit\n");

    int choice;
    while (1) {
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            char ip[INET_ADDRSTRLEN], action[10];
            printf("Enter IP Address: ");
            scanf("%s", ip);
            printf("Enter Action (ALLOW/BLOCK): ");
            scanf("%s", action);
            add_rule(ip, action);
        }
        else if (choice == 2) {
            print_rules();
        }
        else if (choice == 3) {
            int server_sock, client_sock;
            struct sockaddr_in server_addr;

            // Create socket
            if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("Socket creation failed");
                exit(EXIT_FAILURE);
            }

            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = INADDR_ANY;
            server_addr.sin_port = htons(PORT);

            // Bind the socket
            if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                perror("Bind failed");
                close(server_sock);
                exit(EXIT_FAILURE);
            }

            // Start listening for incoming connections
            if (listen(server_sock, 3) < 0) {
                perror("Listen failed");
                close(server_sock);
                exit(EXIT_FAILURE);
            }
            printf("Firewall is active on port %d\n", PORT);

            while (1) {
                if ((client_sock = accept(server_sock, NULL, NULL)) < 0) {
                    perror("Accept failed");
                    continue; // Ignore this failure and try next
                }
                handle_client(client_sock);
            }

            close(server_sock);
        }
        else if (choice == 4) {
            printf("Exiting Firewall...\n");
            break;
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}