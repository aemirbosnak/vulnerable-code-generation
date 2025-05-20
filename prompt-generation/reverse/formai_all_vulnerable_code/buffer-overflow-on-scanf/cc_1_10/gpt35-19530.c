//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    float subtotal = 0.0, vat = 0.0, grandtotal = 0.0;
    int choice, quantity;
    
    printf("Welcome to C Cafe!\n");
    printf("---------------------\n\n");
    
    do {
        printf("Menu:\n");
        printf("1. Coffee\t\tRM4.50\n");
        printf("2. Tea\t\t\tRM3.00\n");
        printf("3. Sandwich\t\tRM6.50\n");
        printf("4. Cake\t\t\tRM5.00\n");
        printf("5. Exit\n\n");
        printf("What would you like to order? (Enter 1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("How many cups of coffee would you like?: ");
                scanf("%d", &quantity);
                subtotal += quantity * 4.5;
                printf("%d cups of coffee added to the order.\n\n", quantity);
                break;
            case 2:
                printf("How many cups of tea would you like?: ");
                scanf("%d", &quantity);
                subtotal += quantity * 3.0;
                printf("%d cups of tea added to the order.\n\n", quantity);
                break;
            case 3:
                printf("How many sandwiches would you like?: ");
                scanf("%d", &quantity);
                subtotal += quantity * 6.5;
                printf("%d sandwiches added to the order.\n\n", quantity);
                break;
            case 4:
                printf("How many slices of cake would you like?: ");
                scanf("%d", &quantity);
                subtotal += quantity * 5.0;
                printf("%d slices of cake added to the order.\n\n", quantity);
                break;
            case 5:
                printf("Thank you for your order!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while(choice != 5);
    
    vat = subtotal * 0.1; // 10% VAT
    grandtotal = subtotal + vat;
    
    // print receipt
    system("clear"); // clear screen for cleaner output
    printf("C Cafe Receipt\n");
    printf("--------------------\n");
    printf("Subtotal\t\tRM%.2f\n", subtotal);
    printf("VAT (10%%)\t\tRM%.2f\n", vat);
    printf("Grand total\t\tRM%.2f\n", grandtotal);
    printf("--------------------\n");
    printf("Thank you for dining at C Cafe. Have a nice day!\n");
    
    return 0;
}