//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    struct Node *next;
} Node;

Node* createNode(char *name) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, char *name) {
    Node *newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("A shapeshifter named '%s' has joined the realm!\n", name);
}

void deleteNode(Node **head, char *name) {
    Node *temp = *head, *prev = NULL;
    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next; 
        free(temp); 
        printf("The shapeshifter named '%s' has departed!\n", name);
        return;
    }
    
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("The shapeshifter named '%s' was not found!\n", name);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("The shapeshifter named '%s' has departed!\n", name);
}

void display(Node *node) {
    if (!node) {
        printf("No shapeshifters in the realm.\n");
        return;
    }
    printf("The shapeshifters currently in the realm:\n");
    while (node != NULL) {
        printf("- %s\n", node->name);
        node = node->next;
    }
}

void shapeShift(Node *node, char *name, char *newName) {
    while (node != NULL) {
        if (strcmp(node->name, name) == 0) {
            strncpy(node->name, newName, sizeof(node->name) - 1);
            printf("The shapeshifter '%s' has transformed into '%s'!\n", name, newName);
            return;
        }
        node = node->next;
    }
    printf("The shapeshifter '%s' was not found to transform!\n", name);
}

int main() {
    Node *head = NULL;
    int choice;
    char name[20], newName[20];

    do {
        printf("\nShape Shifter Linked List Operations\n");
        printf("1. Insert Shapeshifter\n");
        printf("2. Delete Shapeshifter\n");
        printf("3. Display Shapeshifters\n");
        printf("4. Transform Shapeshifter\n");
        printf("5. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the shapeshifter: ");
                scanf("%s", name);
                insert(&head, name);
                break;
            case 2:
                printf("Enter the name of the shapeshifter to delete: ");
                scanf("%s", name);
                deleteNode(&head, name);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Enter the name of the shapeshifter to transform: ");
                scanf("%s", name);
                printf("Enter the new name of the shapeshifter: ");
                scanf("%s", newName);
                shapeShift(head, name, newName);
                break;
            case 5:
                printf("Exiting the realm of shapeshifters...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    // Free memory
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}