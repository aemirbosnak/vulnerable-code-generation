//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct Item
{
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void display_items()
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (items[i].quantity > 0)
        {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void add_item()
{
    Item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);

    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);

    printf("Enter item price: ");
    scanf("%f", &new_item.price);

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (items[i].quantity == 0)
        {
            items[i] = new_item;
            return;
        }
    }

    printf("Error: Item limit reached.\n");
}

void update_item()
{
    char item_name[20];
    int quantity_change;

    printf("Enter item name: ");
    scanf("%s", item_name);

    printf("Enter quantity change: ");
    scanf("%d", &quantity_change);

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (strcmp(items[i].name, item_name) == 0)
        {
            items[i].quantity += quantity_change;
            return;
        }
    }

    printf("Error: Item not found.\n");
}

void remove_item()
{
    char item_name[20];

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (strcmp(items[i].name, item_name) == 0)
        {
            items[i].quantity = 0;
            return;
        }
    }

    printf("Error: Item not found.\n");
}

int main()
{
    int choice;

    printf("Welcome to the Cyberpunk Medical Store Management System!\n");

    while (1)
    {
        printf("Enter 1 to display items, 2 to add item, 3 to update item, or 4 to remove item: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display_items();
                break;
            case 2:
                add_item();
                break;
            case 3:
                update_item();
                break;
            case 4:
                remove_item();
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}