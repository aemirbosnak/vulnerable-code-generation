//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

int main() {
    float expresso = 2.00, latte = 3.50, cappuccino = 4.00;
    float total = 0.0, tax = 0.0, amount = 0.0;
    int option = 0, quantity = 0;

    printf("Welcome to Cafe Billing System!\n");
    printf("Please select one of the following options:\n\n");
    printf("1- Espresso\t $%.2f\n", expresso);
    printf("2- Latte\t $%.2f\n", latte);
    printf("3- Cappuccino\t $%.2f\n", cappuccino);
    printf("4- Exit\n\n");

    do {
        printf("Enter your selection (1-4): ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += expresso * quantity;
                break;
            case 2:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += latte * quantity;
                break;
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += cappuccino * quantity;
                break;
            case 4:
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }

    } while(option != 4);

    tax = total * 0.05;
    amount = total + tax;

    printf("\n\n\t ==== Cafe Billing System Summary ====\n\n");
    printf("\t Total items purchased: $%.2f\n", total);
    printf("\t Tax (5%%): \t\t$%.2f\n", tax);
    printf("\t Amount payable: \t$%.2f\n", amount);
    printf("\n\nThank you for your purchase!");

    return 0;
}