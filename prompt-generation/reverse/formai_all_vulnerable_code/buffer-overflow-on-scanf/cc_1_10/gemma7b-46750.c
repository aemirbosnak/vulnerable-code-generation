//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item
{
    char name[50];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS];

int item_index = 0;

void add_item()
{
    items[item_index].name[0] = '\0';
    printf("Enter item name: ");
    scanf("%s", items[item_index].name);

    items[item_index].quantity = 0;
    printf("Enter item quantity: ");
    scanf("%d", &items[item_index].quantity);

    items[item_index].price = 0.0;
    printf("Enter item price: ");
    scanf("%lf", &items[item_index].price);

    item_index++;
}

void list_items()
{
    for (int i = 0; i < item_index; i++)
    {
        printf("%s - %d - %.2lf\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void search_items()
{
    char search_name[50];
    printf("Enter item name: ");
    scanf("%s", search_name);

    for (int i = 0; i < item_index; i++)
    {
        if (strcmp(items[i].name, search_name) == 0)
        {
            printf("%s - %d - %.2lf\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void update_item()
{
    char update_name[50];
    printf("Enter item name: ");
    scanf("%s", update_name);

    for (int i = 0; i < item_index; i++)
    {
        if (strcmp(items[i].name, update_name) == 0)
        {
            printf("Enter new item name: ");
            scanf("%s", items[i].name);

            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter new item price: ");
            scanf("%lf", &items[i].price);
        }
    }
}

int main()
{
    int choice;

    printf("Welcome to the Mind-Bending Medical Store Management System!\n");

    while (1)
    {
        printf("Please select an option:\n");
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Search Items\n");
        printf("4. Update Item\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_item();
                break;
            case 2:
                list_items();
                break;
            case 3:
                search_items();
                break;
            case 4:
                update_item();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}