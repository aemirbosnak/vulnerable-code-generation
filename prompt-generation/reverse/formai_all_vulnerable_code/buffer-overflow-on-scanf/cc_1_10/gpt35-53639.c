//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#define VAT_PERCENTAGE 0.12

int main() {
    // Welcome message
    printf("Welcome to Cafe Billing System!\n\n");

    // Variable declaration
    int choice, quantity;
    float price, vat, total = 0;

    // Menu
    printf("------------------------------\n");
    printf("ITEMS\t\t\tPRICE\n");
    printf("------------------------------\n");
    printf("1. Coffee\t\t50\n");
    printf("2. Tea\t\t\t30\n");
    printf("3. Sandwich\t\t100\n");
    printf("4. Burger\t\t120\n");
    printf("------------------------------\n");

    // While loop for ordering
    while (1) {
        // User input
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        // Exit condition
        if (choice == 0) {
            break;
        }

        // Quantity input
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculation
        switch (choice) {
        case 1:
            price = 50;
            break;
        case 2:
            price = 30;
            break;
        case 3:
            price = 100;
            break;
        case 4:
            price = 120;
            break;
        default:
            printf("Invalid choice!\n");
            continue;
        }

        total += price * quantity;
        printf("Added %d x %s to the bill!\n", quantity, choice == 1 ? "Coffee" : choice == 2 ? "Tea" : choice == 3 ? "Sandwich" : "Burger");
    }

    // VAT calculation
    vat = total * VAT_PERCENTAGE;

    // Bill
    printf("\n------------------------------\n");
    printf("            BILL\n");
    printf("------------------------------\n");
    printf("TOTAL\t\t\t%.2f\n", total);
    printf("VAT (%.0f%%)\t\t%.2f\n", VAT_PERCENTAGE * 100, vat);
    printf("GRAND TOTAL\t\t%.2f\n", total + vat);
    printf("------------------------------\n");

    return 0;
}