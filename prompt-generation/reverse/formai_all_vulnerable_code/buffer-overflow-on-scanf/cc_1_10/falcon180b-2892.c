//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int quantity;
    float price;
} Item;

void addItem(Item items[], int size, char name[], int quantity, float price) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity += quantity;
            return;
        }
    }
    strcpy(items[size].name, name);
    items[size].quantity = quantity;
    items[size].price = price;
    size++;
}

void removeItem(Item items[], int size, char name[]) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity = 0;
            return;
        }
    }
}

void updateItem(Item items[], int size, char name[], int quantity, float price) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }
}

void displayItems(Item items[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%-20s %d $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    Item items[MAX_SIZE];
    int size = 0;
    char choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Update item\n");
        printf("4. Display items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter item name: ");
                scanf("%s", items[size].name);
                printf("Enter item quantity: ");
                scanf("%d", &items[size].quantity);
                printf("Enter item price: ");
                scanf("%f", &items[size].price);
                size++;
                break;
            case '2':
                printf("Enter item name: ");
                scanf("%s", items[size-1].name);
                removeItem(items, size, items[size-1].name);
                size--;
                break;
            case '3':
                printf("Enter item name: ");
                scanf("%s", items[size-1].name);
                printf("Enter new item quantity: ");
                scanf("%d", &items[size-1].quantity);
                printf("Enter new item price: ");
                scanf("%f", &items[size-1].price);
                updateItem(items, size, items[size-1].name, items[size-1].quantity, items[size-1].price);
                break;
            case '4':
                displayItems(items, size);
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '5');
    return 0;
}