//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 100
#define MAX_CASES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 256

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_DESCRIPTION_LENGTH];
} Client;

typedef struct {
    int id;
    char title[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int clientId;
    int isSolved;
} Case;

Client clients[MAX_CLIENTS];
Case cases[MAX_CASES];
int clientCount = 0;
int caseCount = 0;

void addClient() {
    if (clientCount >= MAX_CLIENTS) {
        printf("Client limit reached.\n");
        return;
    }
    Client newClient;
    newClient.id = clientCount + 1;
    printf("Enter client name: ");
    scanf(" %[^\n]s", newClient.name);
    printf("Enter client age: ");
    scanf("%d", &newClient.age);
    printf("Enter client address: ");
    scanf(" %[^\n]s", newClient.address);

    clients[clientCount++] = newClient;
    printf("Client %s added successfully!\n", newClient.name);
}

void addCase() {
    if (caseCount >= MAX_CASES) {
        printf("Case limit reached.\n");
        return;
    }
    Case newCase;
    newCase.id = caseCount + 1;
    printf("Enter case title: ");
    scanf(" %[^\n]s", newCase.title);
    printf("Enter case description: ");
    scanf(" %[^\n]s", newCase.description);
    
    printf("Enter client ID for this case: ");
    scanf("%d", &newCase.clientId);
    
    newCase.isSolved = 0; // default to unsolved

    cases[caseCount++] = newCase;
    printf("Case '%s' added successfully!\n", newCase.title);
}

void displayClients() {
    printf("Clients List:\n");
    for (int i = 0; i < clientCount; i++) {
        printf("ID: %d, Name: %s, Age: %d, Address: %s\n",
               clients[i].id, clients[i].name, clients[i].age, clients[i].address);
    }
}

void displayCases() {
    printf("Cases List:\n");
    for (int i = 0; i < caseCount; i++) {
        printf("ID: %d, Title: %s, Description: %s, Client ID: %d, Status: %s\n",
               cases[i].id, cases[i].title, cases[i].description, cases[i].clientId,
               cases[i].isSolved ? "Solved" : "Unsolved");
    }
}

void solveCase() {
    int caseId;
    printf("Enter case ID to mark as solved: ");
    scanf("%d", &caseId);
    for (int i = 0; i < caseCount; i++) {
        if (cases[i].id == caseId) {
            cases[i].isSolved = 1;
            printf("Case '%s' marked as solved!\n", cases[i].title);
            return;
        }
    }
    printf("Case ID not found.\n");
}

void searchClientByCase() {
    int caseId;
    printf("Enter case ID to find client: ");
    scanf("%d", &caseId);
    for (int i = 0; i < caseCount; i++) {
        if (cases[i].id == caseId) {
            for (int j = 0; j < clientCount; j++) {
                if (clients[j].id == cases[i].clientId) {
                    printf("Client for Case '%s': %s, Age: %d, Address: %s\n",
                           cases[i].title, clients[j].name, clients[j].age, clients[j].address);
                    return;
                }
            }
        }
    }
    printf("No client found for the given case ID.\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Sherlock Holmes Database ---\n");
        printf("1. Add Client\n");
        printf("2. Add Case\n");
        printf("3. Display Clients\n");
        printf("4. Display Cases\n");
        printf("5. Solve Case\n");
        printf("6. Search Client by Case\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addClient();
                break;
            case 2:
                addCase();
                break;
            case 3:
                displayClients();
                break;
            case 4:
                displayCases();
                break;
            case 5:
                solveCase();
                break;
            case 6:
                searchClientByCase();
                break;
            case 7:
                printf("Exiting the Sherlock Holmes Database. Farewell!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}