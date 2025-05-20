//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CLIENTS 100

typedef struct {
    char name[50];
    int id;
    double score;
} Client;

void printClients(Client clients[], int n) {
    printf("\nList of Clients:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n", clients[i].id, clients[i].name, clients[i].score);
    }
}

int compareByName(const void *a, const void *b) {
    Client *clientA = (Client *)a;
    Client *clientB = (Client *)b;
    return strcmp(clientA->name, clientB->name);
}

int compareByScore(const void *a, const void *b) {
    Client *clientA = (Client *)a;
    Client *clientB = (Client *)b;
    if (clientA->score < clientB->score) return -1;
    if (clientA->score > clientB->score) return 1;
    return 0;
}

void sortClients(Client clients[], int n, int sortBy) {
    if (sortBy == 1) {
        qsort(clients, n, sizeof(Client), compareByName);
        printf("Clients sorted by Name:\n");
    } else if (sortBy == 2) {
        qsort(clients, n, sizeof(Client), compareByScore);
        printf("Clients sorted by Score:\n");
    } else {
        printf("Invalid sorting option.\n");
    }
}

void displayMenu() {
    printf("\nWelcome to Baker Street Client Sorting System\n");
    printf("1. Sort by Client Name\n");
    printf("2. Sort by Client Score\n");
    printf("3. Exit\n");
}

void populateClients(Client clients[], int *n) {
    printf("Enter the number of clients (up to %d): ", MAX_CLIENTS);
    scanf("%d", n);
    
    if (*n > MAX_CLIENTS || *n < 1) {
        printf("Invalid number of clients. Setting to maximum (%d).\n", MAX_CLIENTS);
        *n = MAX_CLIENTS;
    }
    
    for (int i = 0; i < *n; i++) {
        printf("\nEnter details for Client %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &clients[i].id);
        printf("Name: ");
        scanf("%s", clients[i].name);
        printf("Score: ");
        scanf("%lf", &clients[i].score);
    }
}

int main() {
    Client clients[MAX_CLIENTS];
    int n, choice;

    populateClients(clients, &n);
    printClients(clients, n);

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program. Good day, sir!\n");
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        sortClients(clients, n, choice);
        printClients(clients, n);
    }

    return 0;
}