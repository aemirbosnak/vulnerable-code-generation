//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 10000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

int main() {
    int num_items = 0;
    Item items[MAX_ITEMS];

    while (1) {
        printf("Enter option:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Update item quantity\n");
        printf("4. Display items\n");
        printf("5. Exit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (num_items >= MAX_ITEMS) {
                    printf("Error: Maximum number of items reached.\n");
                } else {
                    printf("Enter item name (up to %d characters): ", MAX_NAME_LEN - 1);
                    scanf("%s", items[num_items].name);
                    printf("Enter item quantity: ");
                    scanf("%d", &items[num_items].quantity);
                    num_items++;
                }
                break;
            case 2:
                if (num_items == 0) {
                    printf("Error: No items in warehouse.\n");
                } else {
                    printf("Enter item name to remove: ");
                    scanf("%s", items[num_items - 1].name);
                    num_items--;
                }
                break;
            case 3:
                if (num_items == 0) {
                    printf("Error: No items in warehouse.\n");
                } else {
                    printf("Enter item name to update quantity: ");
                    scanf("%s", items[num_items - 1].name);
                    printf("Enter new item quantity: ");
                    scanf("%d", &items[num_items - 1].quantity);
                }
                break;
            case 4:
                if (num_items == 0) {
                    printf("Error: No items in warehouse.\n");
                } else {
                    printf("Item name\tQuantity\n");
                    for (int i = 0; i < num_items; i++) {
                        printf("%s\t%d\n", items[i].name, items[i].quantity);
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Error: Invalid option.\n");
        }
    }

    return 0;
}