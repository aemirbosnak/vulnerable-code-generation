//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice, count = 0;
    char search[50];
    struct Medicine inventory[100];

    while (1) {
        // Display menu
        printf("\n========== Medical Store Management System ==========\n");
        printf("1. Add medicine\n");
        printf("2. Search medicine\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add medicine
                printf("\nEnter medicine name: ");
                scanf("%s", inventory[count].name);
                printf("Enter quantity: ");
                scanf("%d", &inventory[count].quantity);
                printf("Enter price: ");
                scanf("%f", &inventory[count].price);
                count++;
                break;
            case 2:
                // Search medicine
                printf("\nEnter medicine name: ");
                scanf("%s", search);
                for (int i = 0; i < count; i++) {
                    if (strcmp(inventory[i].name, search) == 0) {
                        printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                        break;
                    }
                }
                break;
            case 3:
                // Display inventory
                printf("\nInventory\n\nMedicine\tQuantity\tPrice\n");
                for (int i = 0; i < count; i++) {
                    printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                break;
            case 4:
                // Exit
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}