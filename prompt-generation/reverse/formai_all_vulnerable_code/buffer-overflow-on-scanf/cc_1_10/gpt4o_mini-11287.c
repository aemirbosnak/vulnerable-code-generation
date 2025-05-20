//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CLIENTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float balance;
} Client;

void printClientInfo(Client* client) {
    if(client != NULL) {
        printf("Client Name: %s\n", client->name);
        printf("Age: %d\n", client->age);
        printf("Balance: %.2f\n", client->balance);
        printf("---------------------------\n");
    } else {
        printf("Client not found.\n");
    }
}

void allocateClients(Client** clients, int num) {
    *clients = (Client*)malloc(num * sizeof(Client));
    if (*clients == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
}

void deallocateClients(Client* clients) {
    free(clients);
}

void enterClientData(Client* client) {
    printf("Enter client name: ");
    fgets(client->name, MAX_NAME_LENGTH, stdin);
    client->name[strcspn(client->name, "\n")] = 0; // Remove newline

    printf("Enter age: ");
    scanf("%d", &client->age);
    
    printf("Enter balance: ");
    scanf("%f", &client->balance);
    getchar();  // Clear buffer after scanf
}

void simulateClientAccountActions(Client* client) {
    int choice;
    do {
        printf("Client %s - Choose an action:\n", client->name);
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Display Balance\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline left by scanf

        switch (choice) {
            case 1:
                {
                    float deposit;
                    printf("Enter amount to deposit: ");
                    scanf("%f", &deposit);
                    client->balance += deposit;
                    printf("Deposited: %.2f\n", deposit);
                    break;
                }
            case 2:
                {
                    float withdraw;
                    printf("Enter amount to withdraw: ");
                    scanf("%f", &withdraw);
                    if (withdraw > client->balance) {
                        printf("Insufficient funds!\n");
                    } else {
                        client->balance -= withdraw;
                        printf("Withdrew: %.2f\n", withdraw);
                    }
                    break;
                }
            case 3:
                printf("Current balance: %.2f\n", client->balance);
                break;
            case 4:
                printf("Exiting actions for client %s.\n", client->name);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
        printf("---------------------------\n");
    } while (choice != 4);
}

int main() {
    Client* clients = NULL;
    int numClients;

    printf("Hello, how many clients do you want to manage? (Max %d): ", MAX_CLIENTS);
    scanf("%d", &numClients);
    getchar();  // Clear buffer after scanf
    
    if (numClients > MAX_CLIENTS || numClients <= 0) {
        fprintf(stderr, "Invalid number of clients!\n");
        return 1;
    }

    allocateClients(&clients, numClients);

    for (int i = 0; i < numClients; i++) {
        printf("\nEntering data for client %d:\n", i + 1);
        enterClientData(&clients[i]);
    }

    printf("\nClient Info:\n");
    for (int i = 0; i < numClients; i++) {
        printClientInfo(&clients[i]);
        simulateClientAccountActions(&clients[i]);
    }

    deallocateClients(clients);
    printf("Memory freed. Thank you for using the client management system!\n");

    return 0;
}