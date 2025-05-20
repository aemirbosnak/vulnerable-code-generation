//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char menu[] = "Enter 1 for Add Item, 2 for Search Item, 3 for Remove Item, 4 for View Inventory";
    char choice;
    int item_id;
    char item_name[20];
    int item_quantity;
    float item_price;
    struct item {
        int id;
        char name[20];
        int quantity;
        float price;
    } items[100];
    int items_count = 0;

    printf("%s\n", menu);
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            printf("Enter item name: ");
            scanf(" %s", item_name);
            printf("Enter item quantity: ");
            scanf(" %d", &item_quantity);
            printf("Enter item price: ");
            scanf(" %f", &item_price);

            items[items_count].id = items_count;
            strcpy(items[items_count].name, item_name);
            items[items_count].quantity = item_quantity;
            items[items_count].price = item_price;

            items_count++;
            break;

        case '2':
            printf("Enter item name: ");
            scanf(" %s", item_name);

            for (int i = 0; i < items_count; i++) {
                if (strcmp(items[i].name, item_name) == 0) {
                    printf("Item ID: %d\n", items[i].id);
                    printf("Item Quantity: %d\n", items[i].quantity);
                    printf("Item Price: %.2f\n", items[i].price);
                }
            }
            break;

        case '3':
            printf("Enter item ID: ");
            scanf(" %d", &item_id);

            for (int i = 0; i < items_count; i++) {
                if (items[i].id == item_id) {
                    items[i].quantity--;
                    printf("Item Quantity: %d\n", items[i].quantity);
                }
            }
            break;

        case '4':
            printf("Inventory:\n");
            for (int i = 0; i < items_count; i++) {
                printf("%s (Q: %d, P: %.2f)\n", items[i].name, items[i].quantity, items[i].price);
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}