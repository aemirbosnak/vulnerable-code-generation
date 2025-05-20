//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main(){
    // Initialize variables
    int option = 0;
    int quantity = 0;
    float price = 0.0;
    float total = 0.0;

    printf("Welcome to C Cafe\n");

    // Loop for taking orders
    while(option != 4){
        printf("\nPlease select an option:\n");
        printf("1. Americano - $2.50\n");
        printf("2. Latte - $3.00\n");
        printf("3. Cappuccino - $3.50\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch(option){
            case 1: // Americano
                printf("You selected Americano\n");
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                price = 2.50;
                total += (price * quantity);
                break;
            case 2: // Latte
                printf("You selected Latte\n");
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                price = 3.00;
                total += (price * quantity);
                break;
            case 3: // Cappuccino
                printf("You selected Cappuccino\n");
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                price = 3.50;
                total += (price * quantity);
                break;
            case 4: // Exit loop
                printf("Thank you for visiting C Cafe!\n");
                break;
            default: // Invalid selection
                printf("Invalid selection. Please try again.\n");
                break;
        }
    }

    // Display total bill
    printf("Your total bill is: $%.2f\n", total);
    printf("Thank you for using C Cafe Billing System");

    return 0;
}