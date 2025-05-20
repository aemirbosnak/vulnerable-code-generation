//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to The Coding Cafe!\n");
    printf("Our menu:\n");
    
    printf("\t1. Espresso - Rs. 80\n");
    printf("\t2. Cappuccino - Rs. 90\n");
    printf("\t3. Latte - Rs. 100\n");
    printf("\t4. Mocha - Rs. 110\n");
    printf("\t5. Hot Chocolate - Rs. 120\n");

    int choice, quantity;
    float amount = 0;
    
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    switch(choice) {
        case 1:
            amount += 80 * quantity;
            printf("\nYou have ordered %d Espresso(s).\n", quantity);
            break;
        case 2:
            amount += 90 * quantity;
            printf("\nYou have ordered %d Cappuccino(s).\n", quantity);
            break;
        case 3:
            amount += 100 * quantity;
            printf("\nYou have ordered %d Latte(s).\n", quantity);
            break;
        case 4:
            amount += 110 * quantity;
            printf("\nYou have ordered %d Mocha(s).\n", quantity);
            break;
        case 5:
            amount += 120 * quantity;
            printf("\nYou have ordered %d Hot Chocolate(s).\n", quantity);
            break;
        default:
            printf("\nInvalid choice! Please choose between 1-5.\n");
            exit(0);
    }
    
    printf("\nYour total bill is: Rs.%.2f/-\n", amount);
    
    printf("\nThank you for choosing The Coding Cafe!\n");
    
    return 0;
}