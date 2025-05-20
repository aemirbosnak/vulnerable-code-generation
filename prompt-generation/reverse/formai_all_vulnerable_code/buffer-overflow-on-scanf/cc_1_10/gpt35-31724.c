//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>
#include <string.h>

float calculate_bill(int quantity, float price){
    return quantity * price;
}

int main(){
    int option, quantity;
    float price, total_amount=0;
    char choice;

    do{
        printf("Welcome to Visionary Cafe!\n");
        printf("1. Coffee -> $3.00\n");
        printf("2. Tea -> $2.50\n");
        printf("3. Sandwich -> $5.00\n");

        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                price = 3.00;
                total_amount += calculate_bill(quantity, price);
                break;

            case 2:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                price = 2.50;
                total_amount += calculate_bill(quantity, price);
                break;

            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                price = 5.00;
                total_amount += calculate_bill(quantity, price);
                break;

            default:
                printf("Invalid option!\n");
        }

        printf("Do you want to order anything else? (Y/N)\n");
        scanf(" %c", &choice);

    }while(choice == 'Y' || choice == 'y');

    printf("Total amount to be paid is: $%.2f\n", total_amount);

    return 0;
}