//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, quantity;
    float price, total = 0;

    while(1) {
        printf("\n\nWelcome to C Cafe\n");
        printf("1. Americano - $2.50\n");
        printf("2. Cappuccino - $3.00\n");
        printf("3. Latte - $3.50\n");
        printf("4. Espresso - $2.00\n");
        printf("5. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);
        
        if(choice == 5){
            printf("\nYour total bill is $%.2f. Thank you for choosing C Cafe.\n", total);
            break;
        }
        
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        
        switch(choice) {
            case 1:
                price = 2.50;
                break;
            case 2:
                price = 3.00;
                break;
            case 3:
                price = 3.50;
                break;
            case 4:
                price = 2.00;
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }
        
        total += price * quantity;
        printf("Your total is $%.2f\n", total);
    }
    
    return 0;
}