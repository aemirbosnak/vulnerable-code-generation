//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, j, choice, quantity, price, totalprice = 0, pos = 0;
    char order[100][100], option[10];

    // Display the menu options
    printf("Welcome to the Cafe Billing System!\n");
    printf("==============================\n");
    printf("MENU\n");
    printf("==============================\n");
    printf("1. Coffee   - $3\n");
    printf("2. Tea      - $2\n");
    printf("3. Burger   - $5\n");
    printf("4. Hot Dog  - $4\n");
    printf("5. Fries    - $2\n");
    printf("==============================\n");

    // Start taking orders
    while (1) {
        printf("\nEnter your order (Enter '0' to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            // Exit the loop if user enters 0
            break;
        }

        switch (choice) {
            case 1:
                strcpy(order[pos], "Coffee");
                price = 3;
                break;
            case 2:
                strcpy(order[pos], "Tea");
                price = 2;
                break;
            case 3:
                strcpy(order[pos], "Burger");
                price = 5;
                break;
            case 4:
                strcpy(order[pos], "Hot Dog");
                price = 4;
                break;
            case 5:
                strcpy(order[pos], "Fries");
                price = 2;
                break;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }

        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        // Calculate the total price and add it to the running total
        totalprice += quantity * price;
        pos++;
    }

    // Print the bill
    printf("==============================\n");
    printf("Your ORDER\n");
    printf("==============================\n");

    for (i = 0; i < pos; i++) {
        printf("%s\t\t$%d\n", order[i], price);
    }

    printf("\nTotal\t\t$%d\n", totalprice);
    printf("==============================\n");

    // Ask for payment
    printf("\nWould you like to pay now? (y/n): ");
    fflush(stdin);
    scanf("%s", option);

    if (strcmp(option, "y") == 0 || strcmp(option, "Y") == 0) {
        printf("Payment received. Thank you for dining with us!\n");
    } else {
        printf("Payment not received. Please pay at the counter.\n");
    }

    return 0;
}