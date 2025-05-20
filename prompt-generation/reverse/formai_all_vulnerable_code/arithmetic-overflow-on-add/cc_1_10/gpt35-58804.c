//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Warehouse {
    char name[50];
    struct Item items[MAX_ITEMS];
    int num_items;
};

struct Warehouse warehouse;

void print_menu();
void add_item();
void remove_item();
void edit_item();
void print_inventory();
void save_inventory();

int main()
{
    printf("Welcome to the Warehouse Management System!\n");

    printf("Please enter the name of the warehouse: ");
    fgets(warehouse.name, 50, stdin);
    warehouse.name[strcspn(warehouse.name, "\n")] = '\0';

    warehouse.num_items = 0;

    int choice = 0;

    while (choice != 5) {
        print_menu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                edit_item();
                break;
            case 4:
                print_inventory();
                break;
            case 5:
                save_inventory();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void print_menu()
{
    printf("\nPlease choose an option:\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Edit item\n");
    printf("4. Print inventory\n");
    printf("5. Save and exit\n");
}

void add_item()
{
    if (warehouse.num_items >= MAX_ITEMS) {
        printf("Sorry, the warehouse is full.\n");
        return;
    }

    printf("\nPlease enter the name of the item: ");
    fgets(warehouse.items[warehouse.num_items].name, 50, stdin);
    warehouse.items[warehouse.num_items].name[strcspn(warehouse.items[warehouse.num_items].name, "\n")] = '\0';

    printf("Please enter the quantity of the item: ");
    scanf("%d", &warehouse.items[warehouse.num_items].quantity);
    getchar();

    printf("Please enter the price of the item: ");
    scanf("%f", &warehouse.items[warehouse.num_items].price);
    getchar();

    warehouse.num_items++;

    printf("Item added successfully.\n");
}

void remove_item()
{
    if (warehouse.num_items == 0) {
        printf("Sorry, the warehouse is empty.\n");
        return;
    }

    printf("\nPlease enter the name of the item to remove: ");
    char name[50];
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    int i;
    for (i = 0; i < warehouse.num_items; i++) {
        if (strcmp(name, warehouse.items[i].name) == 0) {
            int j;
            for (j = i; j < warehouse.num_items - 1; j++) {
                warehouse.items[j] = warehouse.items[j + 1];
            }
            warehouse.num_items--;
            printf("Item removed successfully.\n");
            return;
        }
    }

    printf("Sorry, item not found.\n");
}

void edit_item()
{
    if (warehouse.num_items == 0) {
        printf("Sorry, the warehouse is empty.\n");
        return;
    }

    printf("\nPlease enter the name of the item to edit: ");
    char name[50];
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    int i;
    for (i = 0; i < warehouse.num_items; i++) {
        if (strcmp(name, warehouse.items[i].name) == 0) {
            printf("Please enter the new quantity of the item: ");
            scanf("%d", &warehouse.items[i].quantity);
            getchar();

            printf("Please enter the new price of the item: ");
            scanf("%f", &warehouse.items[i].price);
            getchar();

            printf("Item edited successfully.\n");
            return;
        }
    }

    printf("Sorry, item not found.\n");
}

void print_inventory()
{
    if (warehouse.num_items == 0) {
        printf("\nThe warehouse is empty.\n");
        return;
    }

    printf("\nInventory for %s:\n", warehouse.name);
    printf("%-20s%-10s%-10s\n", "Name", "Quantity", "Price");

    int i;
    for (i = 0; i < warehouse.num_items; i++) {
        printf("%-20s%-10d%-10.2f\n", warehouse.items[i].name, warehouse.items[i].quantity, warehouse.items[i].price);
    }
}

void save_inventory()
{
    if (warehouse.num_items == 0) {
        printf("Exiting without saving.\n");
        return;
    }

    char filename[100];
    snprintf(filename, sizeof(filename), "%s.txt", warehouse.name);

    FILE *f = fopen(filename, "w");

    fprintf(f, "%-20s%-10s%-10s\n", "Name", "Quantity", "Price");

    int i;
    for (i = 0; i < warehouse.num_items; i++) {
        fprintf(f, "%-20s%-10d%-10.2f\n", warehouse.items[i].name, warehouse.items[i].quantity, warehouse.items[i].price);
    }

    fclose(f);

    printf("Inventory saved to %s.\n", filename);
}