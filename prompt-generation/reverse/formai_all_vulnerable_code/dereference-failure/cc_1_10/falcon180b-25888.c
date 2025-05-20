//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    char name[20];
    float amount;
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, char* name, float amount);
void deleteNode(Node** head, char* name);
void printList(Node* head);
float getTotalAmount(Node* head);

int main() {
    Node* head = NULL;

    // Add nodes
    addNode(&head, "Salary", 5000.00);
    addNode(&head, "Rent", -1000.00);
    addNode(&head, "Groceries", -200.00);

    // Print list
    printf("List:\n");
    printList(head);
    printf("\n");

    // Get total amount
    float totalAmount = getTotalAmount(head);
    printf("Total Amount: $%.2f\n", totalAmount);

    // Delete node
    deleteNode(&head, "Rent");

    // Print updated list
    printf("\nList after deleting 'Rent':\n");
    printList(head);
    printf("\n");

    // Get updated total amount
    totalAmount = getTotalAmount(head);
    printf("Updated Total Amount: $%.2f\n", totalAmount);

    return 0;
}

void addNode(Node** head, char* name, float amount) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->amount = amount;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(Node** head, char* name) {
    Node* temp = *head;

    if (temp!= NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
    } else {
        Node* current = *head;
        while (current->next!= NULL && strcmp(current->next->name, name)!= 0) {
            current = current->next;
        }

        if (current->next!= NULL) {
            Node* nodeToDelete = current->next;
            current->next = current->next->next;
            free(nodeToDelete);
        }
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%s: $%.2f\n", current->name, current->amount);
        current = current->next;
    }
}

float getTotalAmount(Node* head) {
    float totalAmount = 0.00;
    Node* current = head;
    while (current!= NULL) {
        totalAmount += current->amount;
        current = current->next;
    }
    return totalAmount;
}