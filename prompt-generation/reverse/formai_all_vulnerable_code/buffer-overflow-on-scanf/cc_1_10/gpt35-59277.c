//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, quantity;
    float total = 0;

    printf("=== Cafe Billing System ===\n\n");

    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $1.50\n");
    printf("3. Sandwich - $3.50\n");
    printf("4. Cake - $2.00\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += 2.50 * quantity;
                printf("Added %d coffee(s) to the billing amount.\n\n", quantity);
                break;
            case 2:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += 1.50 * quantity;
                printf("Added %d tea(s) to the billing amount.\n\n", quantity);
                break;
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += 3.50 * quantity;
                printf("Added %d sandwich(es) to the billing amount.\n\n", quantity);
                break;
            case 4:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += 2.00 * quantity;
                printf("Added %d cake(s) to the billing amount.\n\n", quantity);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n\n");
        }

    } while (choice != 5);

    printf("Total amount to be paid: $%.2f\n", total);

    return 0;
}