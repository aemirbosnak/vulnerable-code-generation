//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50

struct WarehouseItem
{
    char name[MAX_NAME_LENGTH];
    int quantity;
};

struct Warehouse
{
    int num_items;
    struct WarehouseItem items[MAX_ITEMS];
};

void add_item(struct Warehouse *warehouse, char *name, int quantity)
{
    if (warehouse->num_items >= MAX_ITEMS)
    {
        printf("Error: warehouse is at max capacity.\n");
        return;
    }

    for (int i = 0; i < warehouse->num_items; i++)
    {
        if (strcmp(warehouse->items[i].name, name) == 0)
        {
            warehouse->items[i].quantity += quantity;
            printf("Added %d %s.\n", quantity, name);
            return;
        }
    }

    struct WarehouseItem item = {0};
    strcpy(item.name, name);
    item.quantity = quantity;
    warehouse->items[warehouse->num_items++] = item;

    printf("Added %d %s.\n", quantity, name);
}

void remove_item(struct Warehouse *warehouse, char *name, int quantity)
{
    for (int i = 0; i < warehouse->num_items; i++)
    {
        if (strcmp(warehouse->items[i].name, name) == 0)
        {
            if (warehouse->items[i].quantity >= quantity)
            {
                warehouse->items[i].quantity -= quantity;
                printf("Removed %d %s.\n", quantity, name);
            }
            else
            {
                printf("Error: not enough %s in warehouse.\n", name);
            }
            return;
        }
    }

    printf("Error: %s not found in warehouse.\n", name);
}

void print_items(struct Warehouse *warehouse)
{
    printf("Items in warehouse:\n");
    for (int i = 0; i < warehouse->num_items; i++)
    {
        printf("- %d %s\n", warehouse->items[i].quantity, warehouse->items[i].name);
    }
}

int main()
{
    struct Warehouse warehouse = {0};

    while (1)
    {
        printf("Enter command (add, remove, print, exit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0)
        {
            char name[MAX_NAME_LENGTH];
            int quantity;
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            add_item(&warehouse, name, quantity);
        }
        else if (strcmp(command, "remove") == 0)
        {
            char name[MAX_NAME_LENGTH];
            int quantity;
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            remove_item(&warehouse, name, quantity);
        }
        else if (strcmp(command, "print") == 0)
        {
            print_items(&warehouse);
        }
        else if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}