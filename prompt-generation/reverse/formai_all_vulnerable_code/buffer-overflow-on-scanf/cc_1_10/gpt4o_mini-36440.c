//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    char data[100];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        strcpy(newNode->data, data);
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a new node at the end
void insertNode(struct Node** head, char* data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** head, char* key) {
    struct Node* temp = *head, *prev = NULL;

    while (temp != NULL && strcmp(temp->data, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Key not found

    if (prev == NULL) {
        *head = temp->next; // Deleting the head
    } else {
        prev->next = temp->next; // Bypass the node
    }
    free(temp);
}

// Function to display the linked list
void displayList(struct Node* node) {
    printf("Current List: ");
    while (node != NULL) {
        printf("'%s' ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to free the entire list
void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

// Function to shape-shift the list based on user input
void shapeShiftList(struct Node** head, char* action, char* data) {
    if (strcmp(action, "add") == 0) {
        insertNode(head, data);
    } else if (strcmp(action, "remove") == 0) {
        deleteNode(head, data);
    } else {
        printf("Unknown action!\n");
    }
}

int main() {
    struct Node* head = NULL;
    char action[10], data[100];
    
    while (1) {
        printf("Enter action (add/remove/show/exit): ");
        scanf("%s", action);
        if (strcmp(action, "exit") == 0) {
            break;
        } else if (strcmp(action, "show") == 0) {
            displayList(head);
        } else {
            printf("Enter data: ");
            scanf(" %[^\n]", data); // Read string with spaces
            shapeShiftList(&head, action, data);
        }
    }
    
    freeList(head);
    return 0;
}