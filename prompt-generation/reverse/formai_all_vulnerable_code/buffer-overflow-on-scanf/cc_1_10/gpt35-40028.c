//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

struct Product {
    int id;
    char name[20];
    int quantity;
    float price;
};

struct Node {
    struct Product data;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void displayMenu() {
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. Update a product\n");
    printf("4. Display all products\n");
    printf("5. Exit\n");
}

void addProduct() {
    struct Product p;
    printf("Enter product ID: ");
    scanf("%d", &p.id);
    printf("Enter product name: ");
    scanf("%s", &p.name);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = p;
    newNode->next = NULL;
    if(head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void removeProduct() {
    int pid;
    printf("Enter product ID to remove: ");
    scanf("%d", &pid);
    struct Node *currentNode = head;
    struct Node *prevNode = NULL;
    while(currentNode != NULL) {
        if(currentNode->data.id == pid) {
            if(prevNode == NULL) {
                head = currentNode->next;
            } else if(currentNode->next == NULL) {
                prevNode->next = NULL;
                tail = prevNode;
            } else {
                prevNode->next = currentNode->next;
            }
            free(currentNode);
            printf("Product removed successfully.\n");
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    printf("Product not found with ID: %d\n", pid);
}

void updateProduct() {
    int pid;
    printf("Enter product ID to update: ");
    scanf("%d", &pid);
    struct Node *currentNode = head;
    while(currentNode != NULL) {
        if(currentNode->data.id == pid) {
            printf("Enter new product name: ");
            scanf("%s", &currentNode->data.name);
            printf("Enter new product quantity: ");
            scanf("%d", &currentNode->data.quantity);
            printf("Enter new product price: ");
            scanf("%f", &currentNode->data.price);
            printf("Product updated successfully.\n");
            return;
        }
        currentNode = currentNode->next;
    }
    printf("Product not found with ID: %d\n", pid);
}

void displayProducts() {
    struct Node *currentNode = head;
    printf("ID\tName\tQuantity\tPrice\n");
    while(currentNode != NULL) {
        printf("%d\t%s\t%d\t\t%.2f\n", currentNode->data.id, currentNode->data.name, currentNode->data.quantity, currentNode->data.price);
        currentNode = currentNode->next;
    }
}

int main() {
    int choice;
    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}