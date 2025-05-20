//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for item in warehouse
struct Item {
    char name[50];
    int quantity;
    float price;
};

// Define struct for node in linked list
struct Node {
    struct Item data;
    struct Node *next;
};

// Declare global variable for head of linked list
struct Node *head = NULL;

// Function to add item to warehouse
void addItem(char name[], int quantity, float price) {
    struct Item newItem;
    strcpy(newItem.name, name);
    newItem.quantity = quantity;
    newItem.price = price;

    // Create new node for item and add to linked list
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newItem;
    newNode->next = head;
    head = newNode;

    printf("\nItem added successfully!");
}

// Function to remove item from warehouse
void removeItem(char name[]) {
    struct Node *prevNode = NULL;
    struct Node *currNode = head;

    // Traverse linked list to find node with item name
    while (currNode != NULL && strcmp(currNode->data.name, name) != 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // If item not found
    if (currNode == NULL) {
        printf("\nItem not found in warehouse!");
        return;
    }

    // If item found, delete node from linked list
    if (prevNode == NULL) {
        head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }
    free(currNode);

    printf("\nItem removed successfully!");
}

// Function to display all items in warehouse
void displayItems() {
    printf("\n%-25s %-12s %-8s", "Name", "Quantity", "Price");
    printf("\n------------------------- ------------ --------");
    struct Node *currNode = head;

    while (currNode != NULL) {
        printf("\n%-25s %-12d $%-8.2f", currNode->data.name, currNode->data.quantity, currNode->data.price);
        currNode = currNode->next;
    }
}

// Main function for warehouse management system
int main() {
    while (1) {
        printf("\n\nWarehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter item name: ");
            char name[50];
            scanf("%s", name);
            printf("Enter quantity: ");
            int quantity;
            scanf("%d", &quantity);
            printf("Enter price: ");
            float price;
            scanf("%f", &price);
            addItem(name, quantity, price);
        } else if (choice == 2) {
            printf("\nEnter item name: ");
            char name[50];
            scanf("%s", name);
            removeItem(name);
        } else if (choice == 3) {
            displayItems();
        } else if (choice == 4) {
            printf("\nGoodbye!");
            exit(0);
        } else {
            printf("\nInvalid choice. Please try again!");
        }
    }
    return 0;
}