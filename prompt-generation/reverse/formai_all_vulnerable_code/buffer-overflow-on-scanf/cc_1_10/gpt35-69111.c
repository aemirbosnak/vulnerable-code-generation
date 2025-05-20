//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>

// Function to calculate bill to be paid based on items ordered
float calculateBill(int quantity, float price) {
    return quantity * price;
}

int main() {
    int choice, quantity;
    float price, bill;

    // Display menu to the user
    printf("\nWelcome to Cafe X Billing System!");
    printf("\n1. Coffee (Rs.5 per cup)");
    printf("\n2. Tea (Rs.3 per cup)");
    printf("\n3. Sandwich (Rs.40 per serving)");
    printf("\n4. Cake (Rs.50 per slice)");
    printf("\n5. Exit");

    // Ask user to enter their choice
    printf("\n\nEnter your menu choice (1-5): ");
    scanf("%d", &choice);

    while (choice != 5) {
        switch (choice) {
            case 1:
                // Coffee ordered: ask for quantity
                printf("\nEnter quantity of coffee cups: ");
                scanf("%d", &quantity);

                // Calculate bill to be paid
                price = 5.0;
                bill = calculateBill(quantity, price);
                printf("\nYour bill is Rs.%.2f\n", bill);
                break;
            
            case 2:
                // Tea ordered: ask for quantity
                printf("\nEnter quantity of tea cups: ");
                scanf("%d", &quantity);

                // Calculate bill to be paid
                price = 3.0;
                bill = calculateBill(quantity, price);
                printf("\nYour bill is Rs.%.2f\n", bill);
                break;

            case 3:
                // Sandwich ordered: ask for quantity
                printf("\nEnter quantity of sandwich servings: ");
                scanf("%d", &quantity);

                // Calculate bill to be paid
                price = 40.0;
                bill = calculateBill(quantity, price);
                printf("\nYour bill is Rs.%.2f\n", bill);
                break;

            case 4:
                // Cake ordered: ask for quantity
                printf("\nEnter quantity of cake slices: ");
                scanf("%d", &quantity);

                // Calculate bill to be paid
                price = 50.0;
                bill = calculateBill(quantity, price);
                printf("\nYour bill is Rs.%.2f\n", bill);
                break;

            default:
                printf("\nInvalid choice! Please choose again.\n");
        }

        // Display menu again and ask user to enter a new choice
        printf("\n1. Coffee (Rs.5 per cup)");
        printf("\n2. Tea (Rs.3 per cup)");
        printf("\n3. Sandwich (Rs.40 per serving)");
        printf("\n4. Cake (Rs.50 per slice)");
        printf("\n5. Exit");
        printf("\n\nEnter your menu choice (1-5): ");
        scanf("%d", &choice);
    }

    printf("\nThank you for using Cafe X Billing System!");
    return 0;
}