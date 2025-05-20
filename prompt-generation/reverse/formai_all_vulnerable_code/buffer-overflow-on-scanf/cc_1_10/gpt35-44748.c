//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100

struct item
{
    char name[50];
    int code;
    int qty;
    float price;
};

typedef struct item Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item();
void view_items();
void update_item();
void delete_item();
void search_items();

int main()
{
    int choice;

    do
    {
        printf("\n====== Product Inventory System ======\n");
        printf("1. Add an item\n");
        printf("2. View items\n");
        printf("3. Update item\n");
        printf("4. Delete item\n");
        printf("5. Search items\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_item();
            break;

        case 2:
            view_items();
            break;

        case 3:
            update_item();
            break;

        case 4:
            delete_item();
            break;

        case 5:
            search_items();
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("Invalid choice. Try again.");
        }
    } while (choice != 6);

    return 0;
}

void add_item()
{
    Item new_item;

    printf("\nEnter item name: ");
    scanf("%s", new_item.name);

    printf("Enter item code: ");
    scanf("%d", &new_item.code);

    printf("Enter item quantity: ");
    scanf("%d", &new_item.qty);

    printf("Enter item price: ");
    scanf("%f", &new_item.price);

    inventory[num_items] = new_item;
    num_items++;

    printf("Item added successfully.\n");
}

void view_items()
{
    if (num_items == 0)
    {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nItem Name\tItem Code\tItem Qty\tItem Price\n");

    for (int i = 0; i < num_items; i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].code, inventory[i].qty, inventory[i].price);
    }
}

void update_item()
{
    int code, choice;

    if (num_items == 0)
    {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nEnter item code to update: ");
    scanf("%d", &code);

    for (int i = 0; i < num_items; i++)
    {
        if (inventory[i].code == code)
        {
            printf("\nItem found.");
            printf("\n1. Update item name");
            printf("\n2. Update item quantity");
            printf("\n3. Update item price");
            printf("\nEnter your choice (1-3): ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("\nEnter new item name: ");
                scanf("%s", inventory[i].name);
                printf("Item name updated successfully.\n");
                break;

            case 2:
                printf("\nEnter new item quantity: ");
                scanf("%d", &inventory[i].qty);
                printf("Item quantity updated successfully.\n");
                break;

            case 3:
                printf("\nEnter new item price: ");
                scanf("%f", &inventory[i].price);
                printf("Item price updated successfully.\n");
                break;

            default:
                printf("Invalid choice. Try again.");
            }

            return;
        }
    }

    printf("Item not found.\n");
}

void delete_item()
{
    int code;

    if (num_items == 0)
    {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nEnter item code to delete: ");
    scanf("%d", &code);

    for (int i = 0; i < num_items; i++)
    {
        if (inventory[i].code == code)
        {
            for (int j = i; j < num_items - 1; j++)
            {
                inventory[j] = inventory[j + 1];
            }

            num_items--;

            printf("Item deleted successfully.\n");

            return;
        }
    }

    printf("Item not found.\n");
}

void search_items()
{
    char name[50];

    if (num_items == 0)
    {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nEnter item name to search: ");
    scanf("%s", name);

    printf("\nItem Name\tItem Code\tItem Qty\tItem Price\n");

    for (int i = 0; i < num_items; i++)
    {
        if (strcmp(inventory[i].name, name) == 0)
        {
            printf("%s\t\t%d\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].code, inventory[i].qty, inventory[i].price);
        }
    }
}