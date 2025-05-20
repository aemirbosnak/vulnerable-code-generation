//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LEN 50

// Cyberpunk structure for a Node in the linked list
typedef struct Node {
    char name[MAX_NAME_LEN];
    int powerLevel;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(char* name, int powerLevel);
void insertAtHead(Node** headRef, char* name, int powerLevel);
void displayList(Node* head);
void deleteNode(Node** headRef, char* name);
void freeList(Node* head);

int main() {
    Node* head = NULL;
    char command[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    int powerLevel;

    printf("=== Cybernetic Node Operative ===\n");
    printf("Manage your squad of Cyber Ninjas at the Neon Night Market.\n");
    printf("Available commands:\n");
    printf("1. Add a ninja (add <name> <powerLevel>)\n");
    printf("2. Remove a ninja (remove <name>)\n");
    printf("3. Show squad (show)\n");
    printf("4. Quit (quit)\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strncmp(command, "add", 3) == 0) {
            // Parse name and power level from command
            sscanf(command + 4, "%s %d", name, &powerLevel);
            insertAtHead(&head, name, powerLevel);
            printf("Ninja %s added with power level %d.\n", name, powerLevel);
        } else if (strncmp(command, "remove", 6) == 0) {
            sscanf(command + 7, "%s", name);
            deleteNode(&head, name);
        } else if (strcmp(command, "show") == 0) {
            displayList(head);
        } else if (strcmp(command, "quit") == 0) {
            printf("Dismissing Cyber Ninja Operative...\n");
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }
    }

    freeList(head);
    return 0;
}

// Function to create a new node
Node* createNode(char* name, int powerLevel) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LEN);
    newNode->powerLevel = powerLevel;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtHead(Node** headRef, char* name, int powerLevel) {
    Node* newNode = createNode(name, powerLevel);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("No ninjas in the squad. Empty as a black void.\n");
        return;
    }
    printf("===== Current Squad =====\n");
    while (head != NULL) {
        printf("Ninja: %s | Power Level: %d\n", head->name, head->powerLevel);
        head = head->next;
    }
    printf("=========================\n");
}

// Function to delete a node
void deleteNode(Node** headRef, char* name) {
    Node* current = *headRef;
    Node* previous = NULL;

    while (current != NULL && strncmp(current->name, name, MAX_NAME_LEN) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Ninja %s not found in the squad.\n", name);
        return;
    }

    if (previous == NULL) {
        // Node to delete is the head
        *headRef = current->next;
    } else {
        previous->next = current->next;
    }
    
    printf("Ninja %s has been eliminated.\n", current->name);
    free(current);
}

// Function to free the linked list
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}