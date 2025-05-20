//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure representing each element in the linked list
typedef struct Node {
    char shape[15];
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(const char* shape);
void insertShape(Node** head, const char* shape);
void deleteShape(Node** head, const char* shape);
void displayShapes(Node* head);
void transformShapes(Node** head);
void freeList(Node** head);

int main() {
    Node* head = NULL;  // Start with an empty linked list
    int choice;
    char shape[15];

    printf("Welcome to the Shape-shifting Linked List!\n");

    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert Shape\n");
        printf("2. Delete Shape\n");
        printf("3. Display Shapes\n");
        printf("4. Transform Shapes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter shape to insert: ");
                fgets(shape, sizeof(shape), stdin);
                shape[strcspn(shape, "\n")] = 0; // Remove newline
                insertShape(&head, shape);
                printf("Shape '%s' inserted!\n", shape);
                break;
            case 2:
                printf("Enter shape to delete: ");
                fgets(shape, sizeof(shape), stdin);
                shape[strcspn(shape, "\n")] = 0; // Remove newline
                deleteShape(&head, shape);
                break;
            case 3:
                printf("Current Shapes in the List:\n");
                displayShapes(head);
                break;
            case 4:
                transformShapes(&head);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
    } while (choice != 5);

    freeList(&head);
    printf("Shape-shifting Linked List Exited. Shapes transformed into memories!\n");
    return 0;
}

// Function to create a new node
Node* createNode(const char* shape) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->shape, shape);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new shape at the end of the linked list
void insertShape(Node** head, const char* shape) {
    Node* newNode = createNode(shape);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a specific shape from the linked list
void deleteShape(Node** head, const char* shape) {
    Node *temp = *head, *prev = NULL;
    
    while (temp != NULL && strcmp(temp->shape, shape) != 0) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Shape '%s' not found!\n", shape);
        return;
    }

    if (prev == NULL) { // Node to be deleted is the first node
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Shape '%s' deleted!\n", shape);
}

// Function to display the entire linked list
void displayShapes(Node* head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("- %s\n", temp->shape);
        temp = temp->next;
    }
}

// Function to transform shapes in the linked list
void transformShapes(Node** head) {
    if (*head == NULL) {
        printf("No shapes to transform!\n");
        return;
    }

    Node* temp = *head;
    while (temp != NULL) {
        strcat(temp->shape, "-transformed");
        temp = temp->next;
    }

    printf("All shapes have been transformed into their other forms!\n");
}

// Function to free the linked list
void freeList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    *head = NULL;
}