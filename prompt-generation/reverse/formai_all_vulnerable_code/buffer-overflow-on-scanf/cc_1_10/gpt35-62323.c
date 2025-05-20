//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void displayMenu();
void calculateTotal(int quantity, float price, float* total);

int main(){

    int choice, quantity;
    float price, total = 0;

    while(1){

        displayMenu();
        scanf("%d", &choice);

        switch(choice){

            case 1:
                price = 2.50;
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                calculateTotal(quantity, price, &total);
                break;

            case 2:
                price = 1.75;
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                calculateTotal(quantity, price, &total);
                break;

            case 3:
                price = 3.00;
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                calculateTotal(quantity, price, &total);
                break;

            case 4:
                price = 4.50;
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                calculateTotal(quantity, price, &total);
                break;

            case 5:
                printf("\nThank you for using Cafe Calculator. Your total is $%.2f\n", total);
                exit(0);

            default:
                printf("\nPlease select a valid option.\n");
                break;
        }
    }

    return 0;
}

void displayMenu(){

    printf("\n== Cafe Calculator ==\n");
    printf("1. Coffee ($2.50)\n");
    printf("2. Tea ($1.75)\n");
    printf("3. Sandwich ($3.00)\n");
    printf("4. Cake ($4.50)\n");
    printf("5. Exit\n");
    printf(">> ");
}

void calculateTotal(int quantity, float price, float* total){

    float subtotal = quantity * price;
    *total += subtotal;
    printf("\nSubtotal: $%.2f\n", subtotal);
}