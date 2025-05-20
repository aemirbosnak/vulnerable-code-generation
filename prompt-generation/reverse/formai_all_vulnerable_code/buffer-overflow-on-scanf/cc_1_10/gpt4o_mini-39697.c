//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating a structure for a node in the linked list
struct Node {
    char name[50];
    int age;
    float salary;
    struct Node* next; // Pointer to the next node
};

// Function prototypes
struct Node* createNode(char* name, int age, float salary);
void insertAtEnd(struct Node** head, char* name, int age, float salary);
void displayList(struct Node* head);
void freeList(struct Node* head);

// Main function
int main() {
    struct Node* head = NULL; // Initialize the head of the linked list
    char name[50];
    int age;
    float salary;
    int option;

    // Menu for user interaction
    do {
        printf("\n---- Linked List Operations ----\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Salary: ");
                scanf("%f", &salary);
                insertAtEnd(&head, name, age, salary);
                printf("Node inserted successfully!\n");
                break;
            case 2:
                printf("Displaying List:\n");
                displayList(head);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (option != 3);

    // Free allocated memory
    freeList(head);
    return 0;
}

// Function to create and initialize a new node
struct Node* createNode(char* name, int age, float salary) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->salary = salary;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, char* name, int age, float salary) {
    struct Node* newNode = createNode(name, age, salary);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, set new node as head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Link the new node
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", temp->name, temp->age, temp->salary);
        temp = temp->next; // Move to the next node
    }
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head; // Store the current node
        head = head->next; // Move to the next node
        free(temp); // Free the current node
    }
}