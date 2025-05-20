//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int quantity;
    float price;
} item_t;

int main() {
    int choice;
    int i, j;
    int found;
    item_t items[100];
    int num_items = 0;

    do {
        printf("Medical Store Management System\n");
        printf("1. Add item\n");
        printf("2. Delete item\n");
        printf("3. Update item\n");
        printf("4. Search item\n");
        printf("5. List all items\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", items[num_items].name);
                printf("Enter item quantity: ");
                scanf("%d", &items[num_items].quantity);
                printf("Enter item price: ");
                scanf("%f", &items[num_items].price);
                num_items++;
                break;
            case 2:
                printf("Enter item name to delete: ");
                scanf("%s", items[num_items].name);
                found = 0;
                for (i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, items[num_items].name) == 0) {
                        found = 1;
                        for (j = i; j < num_items - 1; j++) {
                            items[j] = items[j + 1];
                        }
                        num_items--;
                        break;
                    }
                }
                if (!found) {
                    printf("Item not found\n");
                }
                break;
            case 3:
                printf("Enter item name to update: ");
                scanf("%s", items[num_items].name);
                found = 0;
                for (i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, items[num_items].name) == 0) {
                        found = 1;
                        printf("Enter new item quantity: ");
                        scanf("%d", &items[i].quantity);
                        printf("Enter new item price: ");
                        scanf("%f", &items[i].price);
                        break;
                    }
                }
                if (!found) {
                    printf("Item not found\n");
                }
                break;
            case 4:
                printf("Enter item name to search: ");
                scanf("%s", items[num_items].name);
                found = 0;
                for (i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, items[num_items].name) == 0) {
                        found = 1;
                        printf("Item found:\n");
                        printf("Name: %s\n", items[i].name);
                        printf("Quantity: %d\n", items[i].quantity);
                        printf("Price: %f\n", items[i].price);
                        break;
                    }
                }
                if (!found) {
                    printf("Item not found\n");
                }
                break;
            case 5:
                printf("List of all items:\n");
                for (i = 0; i < num_items; i++) {
                    printf("Name: %s\n", items[i].name);
                    printf("Quantity: %d\n", items[i].quantity);
                    printf("Price: %f\n", items[i].price);
                    printf("\n");
                }
                break;
            case 6:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}