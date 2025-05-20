//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100
#define ITEM_NAME_LEN 50

int itemCount = 0;

struct Item{
    char name[ITEM_NAME_LEN];
    int quantity;
    float price;
}itemList[MAX_ITEMS];

void addItem(){
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full!!\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", itemList[itemCount].name);
    printf("Enter quantity: ");
    scanf("%d", &itemList[itemCount].quantity);
    printf("Enter price: ");
    scanf("%f", &itemList[itemCount].price);
    printf("Item added successfully!\n");
    itemCount++;
}

void displayItems(){
    if (itemCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("Inventory items:\n");
    printf("Item No.      Item Name           Quantity          Price\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-14d%-20s%-18d$%.2f\n", i + 1, itemList[i].name, itemList[i].quantity, itemList[i].price);
    }
}

int searchItem(char searchName[ITEM_NAME_LEN]){
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(itemList[i].name, searchName) == 0) {
            return i;
        }
    }
    return -1;
}

void updateItem(){
    char searchName[ITEM_NAME_LEN];
    int index;

    if (itemCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Enter item name to update: ");
    scanf("%s", searchName);
    index = searchItem(searchName);
    if (index == -1) {
        printf("Item not found!\n");
        return;
    }
    printf("Enter new quantity: ");
    scanf("%d", &itemList[index].quantity);
    printf("Enter new price: ");
    scanf("%f", &itemList[index].price);
    printf("Item updated successfully!\n");
}

void deleteItem(){
    char searchName[ITEM_NAME_LEN];
    int index;

    if (itemCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Enter item name to delete: ");
    scanf("%s", searchName);
    index = searchItem(searchName);
    if (index == -1) {
        printf("Item not found!\n");
        return;
    }
    for (int i = index; i < itemCount - 1; i++) {
        strcpy(itemList[i].name, itemList[i + 1].name);
        itemList[i].quantity = itemList[i + 1].quantity;
        itemList[i].price = itemList[i + 1].price;
    }
    itemCount--;
    printf("Item deleted successfully!\n");
}

int main(){
    int choice;
    do {
        printf("Enter 1 to add item\n");
        printf("Enter 2 to display items\n");
        printf("Enter 3 to update item\n");
        printf("Enter 4 to delete item\n");
        printf("Enter 0 to exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 0:
                printf("Goodbye! Inventory system shut down...\n");
                break;
            default:
                printf("Invalid choice!! Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}