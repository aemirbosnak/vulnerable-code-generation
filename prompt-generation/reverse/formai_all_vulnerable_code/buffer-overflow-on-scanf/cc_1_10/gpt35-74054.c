//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
#include <stdio.h>

// Function to calculate total bill including taxes
float calculateTotalBill(float subTotal){
    float tax = subTotal * 0.05;
    float totalBill = subTotal + tax;
    return totalBill;
}

int main(){
    int choice, quantity;
    float subTotal = 0;

    printf("Welcome to C Cafe!\n");

    do {
        printf("\nMenu: \n");
        printf("\n1. Coffee - $2.50");
        printf("\n2. Tea - $2.00");
        printf("\n3. Sandwich - $3.50");
        printf("\n4. Quit ordering");

        printf("\n\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        // Condition to exit ordering
        if(choice == 4){
            break;
        }

        printf("\nEnter quantity: ");
        scanf("%d", &quantity);

        // Switch case to calculate subtotal for each item
        switch (choice) {
            case 1:
                subTotal += quantity * 2.50;
                break;
            case 2:
                subTotal += quantity * 2.00;
                break;
            case 3:
                subTotal += quantity * 3.50;
                break;
            default:
                printf("\nInvalid Choice!");
                break;
        }

    } while (choice != 4);

    // Printing the Subtotal and Total Bill
    printf("\nSubtotal: $%.2f", subTotal);
    printf("\nTotal Bill (including taxes): $%.2f", calculateTotalBill(subTotal));

    return 0;
}