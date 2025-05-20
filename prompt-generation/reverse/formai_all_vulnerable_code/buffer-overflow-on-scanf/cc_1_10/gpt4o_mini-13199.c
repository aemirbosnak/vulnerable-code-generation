//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a single linked list node
struct Node {
    char data[100];   // String data can be stored
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strncpy(newNode->data, data, 100);
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(struct Node** head, const char* data) {
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

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List Contents:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node with a specific value from the linked list
void deleteNode(struct Node** head, const char* data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head node itself holds the value to be deleted
    if (temp != NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && strcmp(temp->data, data) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the linked list
    if (temp == NULL) {
        printf("Value %s not found in the list.\n", data);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to clear the entire list and free memory
void clearList(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;
    
    char input[100];

    // Interactive menu for user to manipulate the linked list
    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Append Node\n");
        printf("2. Display List\n");
        printf("3. Delete Node\n");
        printf("4. Count Nodes\n");
        printf("5. Clear List\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        int choice;
        scanf("%d", &choice);
        getchar();  // consume leftover newline

        switch (choice) {
            case 1:
                printf("Enter value to append: ");
                fgets(input, sizeof(input), stdin);
                strtok(input, "\n"); // Remove trailing newline
                appendNode(&head, input);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter value to delete: ");
                fgets(input, sizeof(input), stdin);
                strtok(input, "\n"); // Remove trailing newline
                deleteNode(&head, input);
                break;
            case 4:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 5:
                clearList(&head);
                printf("List cleared.\n");
                break;
            case 6:
                clearList(&head);
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}