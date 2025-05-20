//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    //initial set up
    int choice = 0;
    float total = 0.00;

    //menu options
    printf("------------------------\n");
    printf("Welcome to C Cafe\n");
    printf("------------------------\n");
    printf("1. Espresso - $2.50\n");
    printf("2. Latte - $3.50\n");
    printf("3. Cappuccino - $4.00\n");
    printf("4. Americano - $2.75\n");
    printf("5. Exit\n");

    while (choice != 5) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                total += 2.50;
                printf("Espresso added to cart.\n");
                break;
            case 2:
                total += 3.50;
                printf("Latte added to cart.\n");
                break;
            case 3:
                total += 4.00;
                printf("Cappuccino added to cart.\n");
                break;
            case 4:
                total += 2.75;
                printf("Americano added to cart.\n");
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }

    printf("\nTotal Cost: $%.2f\n", total);

    return 0;
}