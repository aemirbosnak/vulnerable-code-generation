//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 80
#define MAX_CATEGORY_LEN 20
#define MAX_QUANTITY 1000
#define MAX_PRICE 9999.99

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    double price;
} item_t;

void print_item(item_t *item) {
    printf("Name: %s\n", item->name);
    printf("Category: %s\n", item->category);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: $%.2f\n", item->price);
}

int main() {
    int choice;
    item_t items[MAX_ITEMS];
    int num_items = 0;

    do {
        printf("Medical Store Management System\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Remove item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_items >= MAX_ITEMS) {
                printf("Maximum number of items reached.\n");
            } else {
                printf("Enter item name: ");
                scanf("%s", items[num_items].name);
                printf("Enter item category: ");
                scanf("%s", items[num_items].category);
                printf("Enter item quantity: ");
                scanf("%d", &items[num_items].quantity);
                printf("Enter item price: ");
                scanf("%lf", &items[num_items].price);
                num_items++;
            }
            break;
        case 2:
            if (num_items == 0) {
                printf("No items found.\n");
            } else {
                printf("List of items:\n");
                for (int i = 0; i < num_items; i++) {
                    print_item(&items[i]);
                }
            }
            break;
        case 3:
            if (num_items == 0) {
                printf("No items found.\n");
            } else {
                printf("Enter item index to remove: ");
                int index;
                scanf("%d", &index);
                if (index >= 0 && index < num_items) {
                    num_items--;
                    for (int i = index; i < num_items; i++) {
                        items[i] = items[i+1];
                    }
                } else {
                    printf("Invalid item index.\n");
                }
            }
            break;
        case 4:
            printf("Exiting...\n");
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}