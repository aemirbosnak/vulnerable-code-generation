//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for inventory item
struct Item {
    char itemName[50];
    int itemNum;
    int quantity;
};

// Function to add a new inventory item
void addItem(struct Item itemList[], int *size) {
    printf("Enter item name: ");
    scanf("%s", itemList[*size].itemName);
    printf("Enter item number: ");
    scanf("%d", &itemList[*size].itemNum);
    printf("Enter quantity: ");
    scanf("%d", &itemList[*size].quantity);
    (*size)++;
    printf("\nItem added successfully!\n\n");
}

// Function to remove an inventory item
void removeItem(struct Item itemList[], int *size, int itemNum) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (itemList[i].itemNum == itemNum) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nItem number not found.\n\n");
        return;
    }
    for (int i = index; i < *size-1; i++) {
        itemList[i] = itemList[i+1];
    }
    (*size)--;
    printf("\nItem removed successfully!\n\n");
}

// Function to update the quantity of an inventory item
void updateQuantity(struct Item itemList[], int size, int itemNum) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (itemList[i].itemNum == itemNum) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nItem number not found.\n\n");
        return;
    }
    printf("Enter new quantity: ");
    scanf("%d", &itemList[index].quantity);
    printf("\nQuantity updated successfully!\n\n");
}

// Function to display all inventory items
void displayItems(struct Item itemList[], int size) {
    printf("\n%-30s %-10s %-10s\n", "ITEM NAME", "ITEM NUMBER", "QUANTITY");
    for (int i = 0; i < size; i++) {
        printf("%-30s %-10d %-10d\n", itemList[i].itemName, itemList[i].itemNum, itemList[i].quantity);
    }
    printf("\n");
}

int main() {
    struct Item itemList[100];
    int size = 0;
    char option = ' ';
    int itemNum = 0;

    printf("Welcome to the Warehouse Management System!\n\n");

    while (option != '4') {
        printf("Please select an option:\n");
        printf("1. Add new item\n");
        printf("2. Remove item by item number\n");
        printf("3. Update quantity by item number\n");
        printf("4. Exit program\n\n");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                addItem(itemList, &size);
                break;
            case '2':
                printf("Enter item number to remove: ");
                scanf("%d", &itemNum);
                removeItem(itemList, &size, itemNum);
                break;
            case '3':
                printf("Enter item number to update quantity: ");
                scanf("%d", &itemNum);
                updateQuantity(itemList, size, itemNum);
                break;
            case '4':
                printf("Exiting Warehouse Management System...");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n\n");
        }
        displayItems(itemList, size);
    }

    return 0;
}