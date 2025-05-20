//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} item_t;

int main() {
    int choice;
    item_t inventory[MAX_ITEMS];
    int num_items = 0;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. View inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_items >= MAX_ITEMS) {
                printf("Inventory is full!\n");
            } else {
                printf("Enter item name: ");
                scanf("%s", inventory[num_items].name);
                printf("Enter quantity: ");
                scanf("%d", &inventory[num_items].quantity);
                printf("Enter price: ");
                scanf("%f", &inventory[num_items].price);
                num_items++;
            }
            break;

        case 2:
            if (num_items == 0) {
                printf("Inventory is empty!\n");
            } else {
                printf("Enter item name to remove: ");
                scanf("%s", inventory[num_items - 1].name);
                num_items--;
            }
            break;

        case 3:
            printf("Inventory:\n");
            for (int i = 0; i < num_items; i++) {
                printf("%s - %d units - $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}