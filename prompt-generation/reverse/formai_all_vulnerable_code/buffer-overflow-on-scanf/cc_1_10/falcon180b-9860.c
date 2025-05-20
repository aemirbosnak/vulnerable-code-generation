//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

void add_item(struct item *items, int num_items, char *name, int quantity, float price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }
    strcpy(items[num_items].name, name);
    items[num_items].quantity = quantity;
    items[num_items].price = price;
    num_items++;
}

void remove_item(struct item *items, int num_items, char *name) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            num_items--;
            break;
        }
    }
}

void display_items(struct item *items, int num_items) {
    int i;
    printf("Name\tQuantity\tPrice\n");
    for (i = 0; i < num_items; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;
    char choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add item\n2. Remove item\n3. Display items\n4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter item name: ");
                scanf("%s", items[num_items].name);
                printf("Enter item quantity: ");
                scanf("%d", &items[num_items].quantity);
                printf("Enter item price: ");
                scanf("%f", &items[num_items].price);
                num_items++;
                break;
            case '2':
                printf("Enter item name to remove: ");
                scanf("%s", items[num_items-1].name);
                remove_item(items, num_items, items[num_items-1].name);
                break;
            case '3':
                display_items(items, num_items);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');
}