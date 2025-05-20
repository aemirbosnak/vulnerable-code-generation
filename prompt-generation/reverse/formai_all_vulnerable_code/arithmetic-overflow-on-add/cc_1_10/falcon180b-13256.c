//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Inventory;

int main() {
    Inventory store = {0};

    while (1) {
        printf("1. Add item\n2. Display inventory\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item name: ");
            scanf("%s", store.items[store.num_items].name);
            printf("Enter item description: ");
            scanf("%s", store.items[store.num_items].description);
            printf("Enter item quantity: ");
            scanf("%d", &store.items[store.num_items].quantity);
            printf("Enter item price: ");
            scanf("%f", &store.items[store.num_items].price);
            store.num_items++;
            break;
        case 2:
            printf("Item\tDescription\tQuantity\tPrice\n");
            for (int i = 0; i < store.num_items; i++) {
                printf("%s\t%s\t%d\t%.2f\n", store.items[i].name, store.items[i].description, store.items[i].quantity, store.items[i].price);
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}