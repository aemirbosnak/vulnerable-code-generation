//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the C Cafe!\n\n");
    printf("Menu:\n");
    printf("1. Coffee\n");
    printf("2. Latte\n");
    printf("3. Cappuccino\n");
    printf("4. Tea\n");
    printf("5. Sandwich\n");
    printf("6. Croissant\n");
    
    int choice = 0;
    int quantity = 0;
    double subtotal = 0.0;
    double tax = 0.0;
    double total = 0.0;
    
    while (choice != 7) {
        printf("\nWhat would you like to order? (Enter 7 to exit)\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("How many cups of coffee would you like?\n");
                scanf("%d", &quantity);
                subtotal += quantity * 2.50;
                break;
            case 2:
                printf("How many cups of latte would you like?\n");
                scanf("%d", &quantity);
                subtotal += quantity * 3.50;
                break;
            case 3:
                printf("How many cups of cappuccino would you like?\n");
                scanf("%d", &quantity);
                subtotal += quantity * 4.00;
                break;
            case 4:
                printf("How many cups of tea would you like?\n");
                scanf("%d", &quantity);
                subtotal += quantity * 2.00;
                break;
            case 5:
                printf("How many sandwiches would you like?\n");
                scanf("%d", &quantity);
                subtotal += quantity * 5.00;
                break;
            case 6:
                printf("How many croissants would you like?\n");
                scanf("%d", &quantity);
                subtotal += quantity * 2.50;
                break;
            case 7:
                printf("Thank you for visiting the C Cafe! Come back soon!...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    tax = subtotal * 0.13;
    total = subtotal + tax;
    
    printf("\nSubtotal: $%.2lf\n", subtotal);
    printf("Tax: $%.2lf\n", tax);
    printf("Total: $%.2lf\n", total);
    
    return 0;
}