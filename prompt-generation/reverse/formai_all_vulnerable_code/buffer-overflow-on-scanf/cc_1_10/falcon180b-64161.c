//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int quantity;
    double price;
} item_t;

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    while (1) {
        printf("1. Add item\n2. View items\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_items >= MAX_ITEMS) {
                printf("Max items reached!\n");
                break;
            }

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
            break;

        case 2:
            printf("Item ID\tName\tDescription\tQuantity\tPrice\n");
            for (int i = 0; i < num_items; i++) {
                printf("%d\t%s\t%s\t%d\t%.2lf\n", items[i].id, items[i].name, items[i].description, items[i].quantity, items[i].price);
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}