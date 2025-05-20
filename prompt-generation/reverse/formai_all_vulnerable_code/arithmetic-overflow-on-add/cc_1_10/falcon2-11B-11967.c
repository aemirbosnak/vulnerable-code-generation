//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_QUANTITY 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    int id;
    Item items[MAX_ITEMS];
    int num_items;
} Store;

void print_items(Store* store) {
    int i;
    for (i = 0; i < store->num_items; i++) {
        printf("%s: %d\n", store->items[i].name, store->items[i].quantity);
    }
}

int main() {
    Store store;
    int choice;

    printf("Welcome to the Medical Store Management System!\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Update quantity\n");
    printf("4. Print items\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice!= 5) {
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", store.items[store.num_items].name);
                store.num_items++;
                printf("Item added successfully!\n");
                break;
            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", store.items[store.num_items].name);
                for (int i = 0; i < store.num_items; i++) {
                    if (strcmp(store.items[i].name, store.items[store.num_items].name) == 0) {
                        for (int j = i; j < store.num_items - 1; j++) {
                            store.items[j] = store.items[j + 1];
                        }
                        store.num_items--;
                        break;
                    }
                }
                printf("Item removed successfully!\n");
                break;
            case 3:
                printf("Enter item name to update quantity: ");
                scanf("%s", store.items[store.num_items].name);
                printf("Enter new quantity: ");
                scanf("%d", &store.items[store.num_items].quantity);
                printf("Quantity updated successfully!\n");
                break;
            case 4:
                print_items(&store);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}