//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char name[20];
    int quantity;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char* name, int quantity) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void traverse(Node* head) {
    while (head) {
        printf("%s - %d\n", head->name, head->quantity);
        head = head->next;
    }
}

int main() {

    Node* head = NULL;

    // Multiplayer Simulation
    char name[20];
    int quantity;

    // Player 1
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);
    insertAtTail(&head, name, quantity);

    // Player 2
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);
    insertAtTail(&head, name, quantity);

    // Print Inventory
    traverse(head);

    return 0;
}