//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items == MAX_ITEMS) {
        printf("Error: The maximum number of items has been reached.\n");
        return;
    }

    printf("Enter the name of the item: ");
    scanf(" %[^\n]%*c", items[num_items].name);

    printf("Enter the quantity of the item: ");
    scanf(" %d", &items[num_items].quantity);

    printf("Enter the price of the item: ");
    scanf(" %f", &items[num_items].price);

    num_items++;
}

void remove_item() {
    char name[MAX_NAME_LENGTH];

    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]%*c", name);

    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Item not found.\n");
        return;
    }

    for (int i = index; i < num_items - 1; i++) {
        items[i] = items[i + 1];
    }

    num_items--;
}

void update_item() {
    char name[MAX_NAME_LENGTH];

    printf("Enter the name of the item to update: ");
    scanf(" %[^\n]%*c", name);

    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Item not found.\n");
        return;
    }

    printf("Enter the new quantity of the item: ");
    scanf(" %d", &items[index].quantity);

    printf("Enter the new price of the item: ");
    scanf(" %f", &items[index].price);
}

void print_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("  %s: %d, %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;

    do {
        printf("Medical Store Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item\n");
        printf("4. Print Items\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                update_item();
                break;
            case 4:
                print_items();
                break;
        }
    } while (choice != 5);

    return 0;
}