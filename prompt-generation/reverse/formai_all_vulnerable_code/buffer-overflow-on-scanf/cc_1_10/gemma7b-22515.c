//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    int quantity;
    double price;
    struct Item* next;
};

struct Item* insertItem(struct Item* head) {
    struct Item* newNode = (struct Item*)malloc(sizeof(struct Item));

    printf("Enter item name: ");
    scanf("%s", newNode->name);

    printf("Enter item quantity: ");
    scanf("%d", &newNode->quantity);

    printf("Enter item price: ");
    scanf("%lf", &newNode->price);

    newNode->next = head;
    head = newNode;

    return head;
}

void printInventory(struct Item* head) {
    struct Item* currentItem = head;

    printf("Inventory:\n");
    while (currentItem) {
        printf("%s - %d - %.2lf\n", currentItem->name, currentItem->quantity, currentItem->price);
        currentItem = currentItem->next;
    }
}

int main() {
    struct Item* head = NULL;

    head = insertItem(head);
    insertItem(head);
    insertItem(head);

    printInventory(head);

    return 0;
}