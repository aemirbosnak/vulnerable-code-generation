//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>

int main() {
    int order, quantity;
    float price, total = 0;
    char ans;

    printf("Welcome to the C Cafe!\n");

    do {
        printf("\nMenu:\n\n");
        printf("1. Espresso - $1.50\n");
        printf("2. Cappuccino - $2.00\n");
        printf("3. Latte - $2.50\n");
        printf("4. Mocha - $3.00\n");
        printf("\nEnter your order (1-4): ");
        scanf("%d", &order);

        switch (order) {
            case 1:
                price = 1.50;
                printf("Espresso selected!\n");
                break;
            case 2:
                price = 2.00;
                printf("Cappuccino selected!\n");
                break;
            case 3:
                price = 2.50;
                printf("Latte selected!\n");
                break;
            case 4:
                price = 3.00;
                printf("Mocha selected!\n");
                break;
            default:
                printf("Invalid order. Please try again.\n");
                continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        total += price * quantity;

        printf("\nDo you want to order anything else? (y/n): ");
        scanf(" %c", &ans);

    } while (ans == 'y' || ans == 'Y');

    printf("\nYour total bill is: $%.2f\n", total);
    printf("Thank you for visiting the C Cafe!");

    return 0;
}