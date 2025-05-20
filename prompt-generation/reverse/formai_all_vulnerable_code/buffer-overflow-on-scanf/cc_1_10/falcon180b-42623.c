//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Item;

void add_item(Item* items, int num_items) {
    printf("Enter item ID: ");
    scanf("%d", &items[num_items].id);

    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item description: ");
    scanf("%s", items[num_items].description);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    printf("Enter item price: ");
    scanf("%lf", &items[num_items].price);

    num_items++;
}

void display_items(Item* items, int num_items) {
    printf("\nItem ID\tItem Name\tItem Description\tItem Quantity\tItem Price\n");

    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%s\t%d\t%.2lf\n", items[i].id, items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

void search_item(Item* items, int num_items) {
    char search_name[MAX_NAME_LENGTH];

    printf("\nEnter item name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, search_name) == 0) {
            printf("\nItem found:\n");
            printf("Item ID: %d\n", items[i].id);
            printf("Item Name: %s\n", items[i].name);
            printf("Item Description: %s\n", items[i].description);
            printf("Item Quantity: %d\n", items[i].quantity);
            printf("Item Price: %.2lf\n", items[i].price);
        }
    }
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("\nChoose an option:\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Search item\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_items >= MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                } else {
                    add_item(items, num_items);
                    num_items++;
                }
                break;

            case 2:
                display_items(items, num_items);
                break;

            case 3:
                search_item(items, num_items);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}