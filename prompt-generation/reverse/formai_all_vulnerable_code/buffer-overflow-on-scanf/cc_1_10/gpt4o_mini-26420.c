//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for our linked list
struct Node {
    char name[50];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the end of the linked list
void addNode(struct Node** head, char* name) {
    struct Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Yay! Added '%s' to the list!\n", name);
}

// Function to display the names in the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty! Let's add some names!\n");
        return;
    }
    printf("Here are the wonderful names in the list:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("- %s\n", temp->name);
        temp = temp->next;
    }
}

// Function to remove a node from the linked list
void removeNode(struct Node** head, char* name) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Check if the head node is the node to remove
    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        printf("Oh no! '%s' has been removed from the list. Bye-bye!\n", name);
        return;
    }

    // Search for the node to remove
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        printf("Oops! '%s' is not in the list!\n", name);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Yay! '%s' has been successfully removed. See you later!\n", name);
}

// Function to free the entire linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All names have been freed. Let's start fresh!\n");
}

// Main function to interact with the user
int main() {
    struct Node* head = NULL;
    char command[50];
    char name[50];

    printf("Welcome to the Happy Names List!\n");
    printf("You can add, remove, or display names. Type 'exit' to quit.\n");

    while (1) {
        printf("\nEnter a command (add, remove, display, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter a name to add: ");
            scanf("%s", name);
            addNode(&head, name);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter a name to remove: ");
            scanf("%s", name);
            removeNode(&head, name);
        } else if (strcmp(command, "display") == 0) {
            displayList(head);
        } else if (strcmp(command, "exit") == 0) {
            freeList(head);
            printf("Thanks for using Happy Names List! Have a great day!\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }
    return 0;
}