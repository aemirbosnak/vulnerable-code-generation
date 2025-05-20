//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>

// Function to calculate total bill amount
float calculate_bill(int qty, float rate) {
    return qty * rate;
}

int main() {
    char input;
    int quantity, total_quantity = 0;
    float rate, total_amount = 0;

    // Print menu
    printf("------------------\n");
    printf("     C Cafe\n");
    printf("------------------\n");
    printf("Item\t\tRate\n");
    printf("1. Coffee\tRs. 20\n");
    printf("2. Tea\t\tRs. 15\n");
    printf("3. Sandwich\tRs. 30\n");
    printf("4. Pizza\tRs. 50\n");
    printf("------------------\n");

    // Take orders until user enters 'n'
    do {
        // Take input
        printf("Enter item number: ");
        scanf(" %c", &input);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate and add to total amount
        switch(input) {
            case '1':
                rate = 20.0;
                total_quantity += quantity;
                total_amount += calculate_bill(quantity, rate);
                break;
            case '2':
                rate = 15.0;
                total_quantity += quantity;
                total_amount += calculate_bill(quantity, rate);
                break;
            case '3':
                rate = 30.0;
                total_quantity += quantity;
                total_amount += calculate_bill(quantity, rate);
                break;
            case '4':
                rate = 50.0;
                total_quantity += quantity;
                total_amount += calculate_bill(quantity, rate);
                break;
            default:
                printf("Invalid item number.\n");
        }

        // Ask for another order
        printf("Do you want to order another item? (y/n): ");
        scanf(" %c", &input);
    } while(input == 'y' || input == 'Y');

    // Print bill
    printf("------------------\n");
    printf("     Bill\n");
    printf("------------------\n");
    printf("Item\t\tQuantity\tRate\t\tAmount\n");
    printf("Coffee\t\t%d\t\tRs. 20\t\tRs. %.2f\n", total_quantity, calculate_bill(total_quantity, 20.0));
    printf("Tea\t\t%d\t\tRs. 15\t\tRs. %.2f\n", total_quantity, calculate_bill(total_quantity, 15.0));
    printf("Sandwich\t%d\t\tRs. 30\t\tRs. %.2f\n", total_quantity, calculate_bill(total_quantity, 30.0));
    printf("Pizza\t\t%d\t\tRs. 50\t\tRs. %.2f\n", total_quantity, calculate_bill(total_quantity, 50.0));
    printf("------------------\n");
    printf("Total Amount:\t\t\t\t\tRs. %.2f\n", total_amount);

    return 0;
}