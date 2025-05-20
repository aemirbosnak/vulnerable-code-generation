//FormAI DATASET v1.0 Category: Product Inventory System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

struct Item {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
};

struct Item items[MAX_ITEMS];

int num_items = 0;
int next_id = 1;

int main(int argc, char* argv[]) {

    // Create socket
    int port = 8080;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    int bind_result = bind(sock, (struct sockaddr*)&server_address, sizeof(server_address));
    if (bind_result < 0) {
        perror("Failed to bind socket to port");
        exit(EXIT_FAILURE);
    }

    printf("Product Inventory System running on port %d\n", port);

    while (1) {

        // Receive request from client
        struct sockaddr_in client_address;
        socklen_t addr_len = sizeof(client_address);
        char buffer[100];
        memset(buffer, 0, sizeof(buffer));
        ssize_t num_bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_address, &addr_len);
        if (num_bytes < 0) {
            perror("Failed to receive data");
            exit(EXIT_FAILURE);
        }

        // Parse command
        char cmd[10];
        int param1 = 0;
        char param2[MAX_NAME_LENGTH];
        sscanf(buffer, "%s %d %s", cmd, &param1, param2);

        if (strcmp(cmd, "add") == 0) {
            // Add new item
            struct Item item = {next_id++, param2, param1};
            items[num_items++] = item;
            printf("Added item with id %d: %s (%d)\n", item.id, item.name, item.quantity);

        } else if (strcmp(cmd, "remove") == 0) {
            // Remove item by id
            int found = 0;
            for (int i = 0; i < num_items; i++) {
                if (items[i].id == param1) {
                    found = 1;
                    printf("Removed item with id %d: %s (%d)\n", items[i].id, items[i].name, items[i].quantity);
                    for (int j = i; j < num_items - 1; j++) {
                        items[j] = items[j+1];
                    }
                    num_items--;
                    break;
                }
            }
            if (!found) {
                printf("Item with id %d not found\n", param1);
            }

        } else if (strcmp(cmd, "search") == 0) {
            // Search for item by name
            int found = 0;
            for (int i = 0; i < num_items; i++) {
                if (strcmp(items[i].name, param2) == 0) {
                    found = 1;
                    printf("Found item with id %d: %s (%d)\n", items[i].id, items[i].name, items[i].quantity);
                    break;
                }
            }
            if (!found) {
                printf("Item with name %s not found\n", param2);
            }

        } else if (strcmp(cmd, "list") == 0) {
            // List all items
            printf("Inventory:\n");
            for (int i = 0; i < num_items; i++) {
                printf("%d. %s (%d)\n", items[i].id, items[i].name, items[i].quantity);
            }
        }

        // Send response to client
        char response[100];
        memset(response, 0, sizeof(response));
        snprintf(response, sizeof(response), "OK %d", num_items);
        sendto(sock, response, strlen(response), 0, (struct sockaddr*)&client_address, sizeof(client_address));
    }

    // Close socket
    close(sock);
    return 0;
}