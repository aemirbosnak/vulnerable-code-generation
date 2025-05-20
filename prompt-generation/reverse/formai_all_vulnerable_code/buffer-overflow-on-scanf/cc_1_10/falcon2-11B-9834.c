//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct item {
    char name[50];
    int quantity;
    float price;
};

void menu() {
    printf("1. Add item\n2. Remove item\n3. View inventory\n4. View sales\n5. Quit\n");
}

int main() {
    int choice;
    struct item items[100]; // Maximum 100 items allowed
    int num_items = 0;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add item
                printf("Enter item name: ");
                scanf("%s", items[num_items].name);
                printf("Enter quantity: ");
                scanf("%d", &items[num_items].quantity);
                printf("Enter price: ");
                scanf("%f", &items[num_items].price);
                num_items++;
                break;
            case 2: // Remove item
                printf("Enter item name to remove: ");
                scanf("%s", items[num_items].name);
                for (int i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, items[num_items].name) == 0) {
                        for (int j = i; j < num_items - 1; j++) {
                            items[j] = items[j + 1];
                        }
                        num_items--;
                        break;
                    }
                }
                break;
            case 3: // View inventory
                for (int i = 0; i < num_items; i++) {
                    printf("Item: %s, Quantity: %d, Price: $%.2f\n", items[i].name, items[i].quantity, items[i].price);
                }
                break;
            case 4: // View sales
                printf("Sales:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("Item: %s, Quantity Sold: %d\n", items[i].name, items[i].quantity - items[i].quantity);
                }
                break;
            case 5: // Quit
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}