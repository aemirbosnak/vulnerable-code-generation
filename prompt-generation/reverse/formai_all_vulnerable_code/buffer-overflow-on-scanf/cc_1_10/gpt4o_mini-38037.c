//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(const char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->data, data, sizeof(newNode->data));
    newNode->data[sizeof(newNode->data) - 1] = '\0'; // Ensure null-termination
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(Node **head, const char *data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the list
void displayList(Node *head) {
    Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node from the list
void deleteNode(Node **head, const char *data) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete node.\n");
        return;
    }
    Node *temp = *head, *prev = NULL;

    while (temp != NULL && strcmp(temp->data, data) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data \"%s\" not found.\n", data);
        return;
    }
    if (prev == NULL) {
        *head = temp->next; // Node to delete is the head
    } else {
        prev->next = temp->next; // Bypass the node to delete
    }
    free(temp);
    printf("Node with data \"%s\" deleted successfully.\n", data);
}

// Function to find a node in the list
Node* findNode(Node *head, const char *data) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to free the entire list
void freeList(Node **head) {
    Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Main function
int main() {
    Node *head = NULL;
    int choice;
    char data[100];

    while (1) {
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Delete Node\n");
        printf("4. Find Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the leftover newline character

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = '\0'; // Remove trailing newline
            insertEnd(&head, data);
            break;
        case 2:
            displayList(head);
            break;
        case 3:
            printf("Enter data to delete: ");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = '\0'; // Remove trailing newline
            deleteNode(&head, data);
            break;
        case 4:
            printf("Enter data to find: ");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = '\0'; // Remove trailing newline
            Node *foundNode = findNode(head, data);
            if (foundNode) {
                printf("Node with data \"%s\" found.\n", foundNode->data);
            } else {
                printf("Node with data \"%s\" not found.\n", data);
            }
            break;
        case 5:
            freeList(&head);
            printf("Exiting...\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}