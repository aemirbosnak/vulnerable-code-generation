//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Define the prices of items
#define COFFEE_PRICE 2.50
#define TEA_PRICE 1.75
#define PASTRY_PRICE 3.00
#define SANDWICH_PRICE 4.50

int main() {
    // Initialize variables
    float total = 0.0;
    int choice;

    // Display menu
    printf("Welcome to the Cafe!\n");
    printf("Please choose an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Pastry\n");
    printf("4. Sandwich\n");
    printf("5. Exit\n");

    // Get customer choice
    scanf("%d", &choice);

    // Process customer choice
    switch(choice) {
        case 1:
            // Customer chose coffee
            printf("You ordered a coffee for $%.2f.\n", COFFEE_PRICE);
            total += COFFEE_PRICE;
            break;
        case 2:
            // Customer chose tea
            printf("You ordered a tea for $%.2f.\n", TEA_PRICE);
            total += TEA_PRICE;
            break;
        case 3:
            // Customer chose pastry
            printf("You ordered a pastry for $%.2f.\n", PASTRY_PRICE);
            total += PASTRY_PRICE;
            break;
        case 4:
            // Customer chose sandwich
            printf("You ordered a sandwich for $%.2f.\n", SANDWICH_PRICE);
            total += SANDWICH_PRICE;
            break;
        case 5:
            // Customer chose to exit
            printf("Thank you for visiting the Cafe!\n");
            break;
        default:
            // Invalid choice
            printf("Invalid choice.\n");
            break;
    }

    // Display total and exit
    printf("Your total is $%.2f.\n", total);
    return 0;
}