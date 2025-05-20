//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct item {
    char name[100];
    int quantity;
    double price;
};

int main() {
    struct item items[100];
    int num_items = 0;
    int choice;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", items[num_items].name);
                printf("Enter item quantity: ");
                scanf("%d", &items[num_items].quantity);
                printf("Enter item price: ");
                scanf("%lf", &items[num_items].price);
                num_items++;
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", items[choice].name);
                printf("Enter item quantity: ");
                scanf("%d", &items[choice].quantity);
                printf("Enter item price: ");
                scanf("%lf", &items[choice].price);
                break;
            case 3:
                printf("Inventory:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%s - %d - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}