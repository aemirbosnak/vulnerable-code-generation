//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 100

typedef struct Item
{
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEM_NUM];

void displayItems()
{
    printf("Items:\n");
    for (int i = 0; i < MAX_ITEM_NUM; i++)
    {
        if (items[i].quantity > 0)
        {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void addItem()
{
    Item newItem;
    printf("Enter item name:");
    scanf("%s", newItem.name);
    printf("Enter item quantity:");
    scanf("%d", &newItem.quantity);
    printf("Enter item price:");
    scanf("%f", &newItem.price);

    for (int i = 0; i < MAX_ITEM_NUM; i++)
    {
        if (items[i].quantity == 0)
        {
            items[i] = newItem;
            return;
        }
    }

    printf("Error: Item limit reached.\n");
}

void updateItemQuantity()
{
    char itemName[50];
    int newQuantity;

    printf("Enter item name:");
    scanf("%s", itemName);
    printf("Enter new quantity:");
    scanf("%d", &newQuantity);

    for (int i = 0; i < MAX_ITEM_NUM; i++)
    {
        if (strcmp(items[i].name, itemName) == 0)
        {
            items[i].quantity = newQuantity;
            return;
        }
    }

    printf("Error: Item not found.\n");
}

int main()
{
    int choice;

    printf("Welcome to the Medical Store Management System!\n");
    printf("Please select an option:\n");
    printf("1. Display items\n");
    printf("2. Add item\n");
    printf("3. Update item quantity\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            displayItems();
            break;
        case 2:
            addItem();
            break;
        case 3:
            updateItemQuantity();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}