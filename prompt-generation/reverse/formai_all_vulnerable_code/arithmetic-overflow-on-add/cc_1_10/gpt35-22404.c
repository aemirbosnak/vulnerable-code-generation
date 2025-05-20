//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20

// Structures
typedef struct Item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct Inventory {
    Item items[MAX_ITEMS];
    int num_items;
} Inventory;

// Function Prototypes
void print_menu();
void add_item(Inventory *inv);
void remove_item(Inventory *inv);
void restock_item(Inventory *inv);
void view_inventory(Inventory inv);
void save_inventory(Inventory inv);
Inventory load_inventory();

// Main Function
int main() {
    Inventory inv = load_inventory();
    bool exit_program = false;
    int choice = 0;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(&inv);
                break;
            case 2:
                remove_item(&inv);
                break;
            case 3:
                restock_item(&inv);
                break;
            case 4:
                view_inventory(inv);
                break;
            case 5:
                save_inventory(inv);
                exit_program = true;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (!exit_program);
    return 0;
}

// Function Definitions
void print_menu() {
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Restock Item\n");
    printf("4. View Inventory\n");
    printf("5. Exit Program\n");
}

void add_item(Inventory *inv) {
    printf("Enter name of item: ");
    scanf("%s", inv->items[inv->num_items].name);
    printf("Enter quantity: ");
    scanf("%d", &inv->items[inv->num_items].quantity);
    printf("Enter price: ");
    scanf("%f", &inv->items[inv->num_items].price);
    inv->num_items++;
}

void remove_item(Inventory *inv) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of item to remove: ");
    scanf("%s", name);
    int index = -1;
    for (int i = 0; i < inv->num_items; i++) {
        if (strcmp(name, inv->items[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Item not found.\n");
    } else {
        for (int i = index; i < inv->num_items - 1; i++) {
            inv->items[i] = inv->items[i+1];
        }
        inv->num_items--;
        printf("Item removed.\n");
    }
}

void restock_item(Inventory *inv) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of item to restock: ");
    scanf("%s", name);
    int index = -1;
    for (int i = 0; i < inv->num_items; i++) {
        if (strcmp(name, inv->items[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Item not found.\n");
    } else {
        printf("Enter quantity to add: ");
        int quantity = 0;
        scanf("%d", &quantity);
        inv->items[index].quantity += quantity;
        printf("Item restocked.\n");
    }
}

void view_inventory(Inventory inv) {
    printf("Here is the current inventory: \n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < inv.num_items; i++) {
        printf("%-20s %-10d %-10.2f\n", inv.items[i].name, inv.items[i].quantity, inv.items[i].price);
    }
}

void save_inventory(Inventory inv) {
    FILE *fp = fopen("inventory.dat", "wb");
    fwrite(&inv, sizeof(inv), 1, fp);
    fclose(fp);
    printf("Inventory saved.\n");
}

Inventory load_inventory() {
    Inventory inv = {0};
    FILE *fp = fopen("inventory.dat", "rb");
    if (fp) {
        fread(&inv, sizeof(inv), 1, fp);
        fclose(fp);
        printf("Inventory loaded.\n");
    } else {
        printf("No inventory file found. New inventory created.\n");
    }
    return inv;
}