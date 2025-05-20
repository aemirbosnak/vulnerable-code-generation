//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>

// Initializing the prices of items
float coffee = 2.50;
float tea = 1.50;
float pastry = 3.00;

int main() {
    int choice, quantity;
    float total_price = 0.0;
    
    // Greeting message for the customer
    printf("Welcome to the Happy Cafe Billing System!\n");
    printf("What would you like to order?\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $1.50\n");
    printf("3. Pastry - $3.00\n");
    
    // Loop for taking customer's order
    do {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        if (choice == 1 || choice == 2 || choice == 3) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            
            switch(choice) {
                case 1:
                    total_price += quantity * coffee;
                    break;
                case 2:
                    total_price += quantity * tea;
                    break;
                case 3:
                    total_price += quantity * pastry;
                    break;
            }
        } else {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
        }
        
        // Asking customer if they want to order more
        printf("Would you like to order more? (1 for yes, 0 for no) ");
        scanf("%d", &choice);
    } while (choice == 1);
    
    // Printing the bill
    printf("\n");
    printf("**********************************\n");
    printf("          HAPPY CAFE BILL         \n");
    printf("**********************************\n");
    printf("Item            Quantity   Price  \n");
    printf("----------------------------------\n");
    if (total_price > 0) {
        printf("Coffee          %3d       $%.2f\n", quantity, coffee);
        printf("Tea             %3d       $%.2f\n", quantity, tea);
        printf("Pastry          %3d       $%.2f\n", quantity, pastry);
        printf("----------------------------------\n");
    }
    printf("Total amount:           $%.2f\n", total_price);
    printf("**********************************\n");

    return 0;
}