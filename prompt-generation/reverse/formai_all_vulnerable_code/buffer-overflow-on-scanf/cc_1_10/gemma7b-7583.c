//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

int main() {
    int i, j, item_no = 0;
    char command;

    // Initialize items
    for (i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].quantity = 0;
        items[i].price = 0.0;
    }

    // Main loop
    while (1) {
        printf("Enter command (add/list/exit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                // Add item
                item_no++;
                printf("Enter item name: ");
                scanf(" %s", items[item_no].name);
                printf("Enter item quantity: ");
                scanf(" %d", &items[item_no].quantity);
                printf("Enter item price: ");
                scanf(" %f", &items[item_no].price);
                break;

            case 'l':
                // List items
                for (j = 0; j < item_no; j++) {
                    printf("%s - %d - %.2f\n", items[j].name, items[j].quantity, items[j].price);
                }
                break;

            case 'e':
                // Exit
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}