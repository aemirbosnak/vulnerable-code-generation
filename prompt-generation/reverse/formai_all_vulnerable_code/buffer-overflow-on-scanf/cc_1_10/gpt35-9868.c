//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 50
#define MAX_BIN_LENGTH 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    int bin_number;
} item;

void print_menu();
void add_item(item inventory[], int *num_items);
void remove_item(item inventory[], int *num_items);
void update_item(item inventory[], int num_items);
void print_inventory(item inventory[], int num_items);

int main() {
    item inventory[MAX_ITEMS];
    int num_items = 0;
    int choice;

    srand(time(0));

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(inventory, &num_items);
                break;
            case 2:
                remove_item(inventory, &num_items);
                break;
            case 3:
                update_item(inventory, num_items);
                break;
            case 4:
                print_inventory(inventory, num_items);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}

void print_menu() {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~ WELCOME TO WAREHOUSE 420 ~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("1. Add item to inventory\n");
    printf("2. Remove item from inventory\n");
    printf("3. Update item quantity or bin number\n");
    printf("4. Print inventory\n");
    printf("5. Exit\n");
}

void add_item(item inventory[], int *num_items) {
    if (*num_items == MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }

    item new_item;

    printf("Enter item name: ");
    scanf("%s", new_item.name);

    printf("Enter item description: ");
    scanf("%s", new_item.description);

    new_item.quantity = rand() % 100;
    
    char bin[MAX_BIN_LENGTH];
    sprintf(bin, "%d", rand() % 10);

    if (strlen(bin) == 1) {
        new_item.bin_number = atoi(strcat("0", bin));
    } else {
        new_item.bin_number = atoi(bin);
    }

    inventory[*num_items] = new_item;
    (*num_items)++;
}

void remove_item(item inventory[], int *num_items) {
    if (*num_items == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];

    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < *num_items; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            inventory[i] = inventory[*num_items - 1];
            (*num_items)--;
            printf("%s removed from inventory.\n", name);
            return;
        }
    }

    printf("%s not found in inventory.\n", name);
}

void update_item(item inventory[], int num_items) {
    if (num_items == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];

    printf("Enter item name to update: ");
    scanf("%s", name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter new bin number: ");
            scanf("%d", &inventory[i].bin_number);

            printf("%s updated.\n", name);
            return;
        }
    }

    printf("%s not found in inventory.\n", name);
}

void print_inventory(item inventory[], int num_items) {
    if (num_items == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~           INVENTORY           ~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Name\t\tDescription\tQuantity\tBin\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%s\t\t%d\t\t%d\n", inventory[i].name, inventory[i].description, inventory[i].quantity, inventory[i].bin_number);
    }

    printf("\n");
}