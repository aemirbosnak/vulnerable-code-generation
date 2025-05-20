//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items == MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf(" %[^\n]", items[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);

    num_items++;
}

void remove_item() {
    char name[50];

    printf("Enter item name to remove: ");
    scanf(" %[^\n]", name);

    int found = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            found = 1;

            for (int j = i; j < num_items - 1; j++) {
                items[j] = items[j + 1];
            }

            num_items--;
            break;
        }
    }

    if (!found) {
        printf("Error: Item not found.\n");
    }
}

void update_item() {
    char name[50];

    printf("Enter item name to update: ");
    scanf(" %[^\n]", name);

    int found = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            found = 1;

            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter new item price: ");
            scanf("%f", &items[i].price);

            break;
        }
    }

    if (!found) {
        printf("Error: Item not found.\n");
    }
}

void print_items() {
    printf("Name\tQuantity\tPrice\n");
    printf("-----------------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("Medical Store Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Update item\n");
        printf("4. Print items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
            case 5:
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}