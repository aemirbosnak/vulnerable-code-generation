//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure with whimsical design
typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(const char* name);
void appendNode(Node** head, const char* name);
void displayList(Node* head);
void removeNode(Node** head, const char* name);
void freeList(Node** head);
void interactiveMenu();

// Create a new node with dynamic memory
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        strncpy(newNode->name, name, sizeof(newNode->name) - 1);
        newNode->name[sizeof(newNode->name) - 1] = '\0'; // Ensuring null-termination
        newNode->next = NULL;
    } else {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return newNode;
}

// Append a new node to the end of the list
void appendNode(Node** head, const char* name) {
    Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode; // Start of the list
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next; // Traverse to the end
    }
    current->next = newNode; // Attach new node
}

// Display all nodes in the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty...\n");
        return;
    }
    printf("Current list of enchanting names:\n");
    while (head != NULL) {
        printf(" -> %s\n", head->name);
        head = head->next;
    }
}

// Remove a node by name from the list
void removeNode(Node** head, const char* name) {
    Node* current = *head;
    Node* previous = NULL;
    
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("No such node named '%s' found.\n", name);
        return; // Node not found
    }
    
    if (previous == NULL) {
        *head = current->next; // Node to remove is the first node
    } else {
        previous->next = current->next; // Bypass the node
    }
    free(current); // Free the memory
    printf("Fantastically removed '%s' from the list.\n", name);
}

// Free all nodes in the list
void freeList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next; // Store next node
        free(current); // Free current node
        current = nextNode; // Move to the next
    }
    *head = NULL; // Reset head to NULL
    printf("All nodes have been bid farewell!\n");
}

// Interactive menu for user to manipulate the list
void interactiveMenu() {
    Node* head = NULL;
    char name[50];
    int choice;
    
    while (1) {
        printf("\nEnchanted Linked List Menu:\n");
        printf("1. Add name to the list\n");
        printf("2. Remove name from the list\n");
        printf("3. Display the list\n");
        printf("4. Exit enchanted land\n");
        printf("Choose your potion (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter a name to befriend: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                appendNode(&head, name);
                break;
            case 2:
                printf("Enter a name to cast away: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                removeNode(&head, name);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                freeList(&head);
                printf("Thank you for visiting the enchanted land!\n");
                exit(0);
            default:
                printf("Invalid choice, please enter a number between 1 and 4.\n");
        }
    }
}

// Main function to begin the adventure
int main() {
    interactiveMenu();
    return 0;
}