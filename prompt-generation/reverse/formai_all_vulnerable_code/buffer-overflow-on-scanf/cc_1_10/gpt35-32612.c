//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define constants for the coffee prices
#define AMERICANO_PRICE 3.5
#define LATTE_PRICE 4
#define MOCHA_PRICE 4.5
#define CAPPUCCINO_PRICE 4

// Define a function to display the menu options and return the selected option
int displayMenu() {
    int option;
        
    printf("Welcome to Café de Coding!\n");
    printf("1. Americano - $%.2lf\n", AMERICANO_PRICE);
    printf("2. Latte - $%.2lf\n", LATTE_PRICE);
    printf("3. Mocha - $%.2lf\n", MOCHA_PRICE);
    printf("4. Cappuccino - $%.2lf\n", CAPPUCCINO_PRICE);
    printf("5. Exit\n");
    printf("Please select an option: ");
    scanf("%d", &option);

    return option;
}

// Define a function to calculate the total and print the bill
void printBill(int americanoQty, int latteQty, int mochaQty, int cappuccinoQty) {
    double total = (americanoQty * AMERICANO_PRICE) 
                 + (latteQty * LATTE_PRICE) 
                 + (mochaQty * MOCHA_PRICE) 
                 + (cappuccinoQty * CAPPUCCINO_PRICE);

    printf("\nCafé de Coding Bill\n");
    printf("====================\n");
    printf("Americano x %d - $%.2lf\n", americanoQty, americanoQty * AMERICANO_PRICE);
    printf("Latte x %d - $%.2lf\n", latteQty, latteQty * LATTE_PRICE);
    printf("Mocha x %d - $%.2lf\n", mochaQty, mochaQty * MOCHA_PRICE);
    printf("Cappuccino x %d - $%.2lf\n", cappuccinoQty, cappuccinoQty * CAPPUCCINO_PRICE);
    printf("--------------------\n");
    printf("Total - $%.2lf\n", total);
}

int main() {
    int americanoQty = 0;
    int latteQty = 0;
    int mochaQty = 0;
    int cappuccinoQty = 0;
    int option;
        
    do {
        option = displayMenu();
        
        switch(option) {
            case 1:
                americanoQty++;
                break;
            case 2:
                latteQty++;
                break;
            case 3:
                mochaQty++;
                break;
            case 4:
                cappuccinoQty++;
                break;
            case 5:
                printf("\nExiting Café de Coding...\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while(option != 5);

    if(americanoQty > 0 || latteQty > 0 || mochaQty > 0 || cappuccinoQty > 0) {
        printBill(americanoQty, latteQty, mochaQty, cappuccinoQty);
    }
        
    return 0;
}