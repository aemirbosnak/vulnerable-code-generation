//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct Node {
    char name[50];
    struct Node* next;
};

// Function declarations
struct Node* createNode(char* name);
void insertNode(struct Node** head, char* name);
void deleteNode(struct Node** head, char* name);
struct Node* searchNode(struct Node* head, char* name);
void displayList(struct Node* head);
void freeList(struct Node** head);

int main() {
    struct Node* head = NULL;
    int choice;
    char name[50];

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter name to insert: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character
                insertNode(&head, name);
                break;
            case 2:
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character
                deleteNode(&head, name);
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character
                struct Node* found = searchNode(head, name);
                if (found) {
                    printf("Node found: %s\n", found->name);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                freeList(&head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new Node
struct Node* createNode(char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->next = NULL;
    return newNode;
}

// Function to insert a Node at the end of the list
void insertNode(struct Node** head, char* name) {
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
    printf("Inserted: %s\n", name);
}

// Function to delete a Node from the list
void deleteNode(struct Node** head, char* name) {
    struct Node* temp = *head, *prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;  // Changed head
        free(temp);
        printf("Deleted: %s\n", name);
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found: %s\n", name);
        return;
    }

    prev->next = temp->next;  // Unlink the node
    free(temp);
    printf("Deleted: %s\n", name);
}

// Function to search for a Node
struct Node* searchNode(struct Node* head, char* name) {
    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to display all Nodes in the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List of Names:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the entire list
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}