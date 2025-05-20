//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100

typedef struct item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int quantity, float price) {
    if (num_items == MAX_ITEMS) {
        printf("Error: Item list is full.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].quantity = quantity;
    items[num_items].price = price;
    num_items++;
}

void remove_item(char *name) {
    int i;

    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                items[j] = items[j + 1];
            }
            num_items--;
            return;
        }
    }

    printf("Error: Item not found.\n");
}

void update_item(char *name, int quantity, float price) {
    int i;

    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }

    printf("Error: Item not found.\n");
}

void print_items() {
    int i;

    printf("Items in stock:\n");
    for (i = 0; i < num_items; i++) {
        printf("%s: %d units, $%.2f each\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    char command;
    char name[50];
    int quantity;
    float price;

    while (1) {
        printf("Enter a command (a/r/u/p/q): ");
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                printf("Enter item name: ");
                scanf(" %s", name);
                printf("Enter quantity: ");
                scanf(" %d", &quantity);
                printf("Enter price: ");
                scanf(" %f", &price);
                add_item(name, quantity, price);
                break;
            case 'r':
                printf("Enter item name: ");
                scanf(" %s", name);
                remove_item(name);
                break;
            case 'u':
                printf("Enter item name: ");
                scanf(" %s", name);
                printf("Enter new quantity: ");
                scanf(" %d", &quantity);
                printf("Enter new price: ");
                scanf(" %f", &price);
                update_item(name, quantity, price);
                break;
            case 'p':
                print_items();
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}