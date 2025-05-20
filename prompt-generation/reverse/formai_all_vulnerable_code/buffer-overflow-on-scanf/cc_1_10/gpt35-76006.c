//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate GST
float computeGST(float amount, float taxRate) {
    return amount * (taxRate / 100);
}

int main() {
    char itemName[50];
    int quantity;
    float price, subtotal, gstAmount, total, taxRate = 5.0;
    int choice = 0;

    printf("Welcome to the C Cafe Billing System\n");
    printf("===================================\n");

    do {
        printf("Menu:\n");
        printf("1. Add Item\n");
        printf("2. View Bill\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Item Name: ");
                scanf("%s", itemName);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Price: ");
                scanf("%f", &price);
                subtotal = price * quantity;
                gstAmount = computeGST(subtotal, taxRate);
                total = subtotal + gstAmount;
                printf("\nItem Added Successfully!\n\n");
                break;
            case 2:
                printf("\n\n\t\tC Cafe Bill\n");
                printf("\t\t============\n");
                printf("Item Name \t Quantity \t Price \t Subtotal \n");
                printf("------------------------------------------------\n");
                printf("%s \t\t %d \t\t %.2f \t %.2f \n", itemName, quantity, price, subtotal);
                printf("\n");
                printf("GST Amount @%.2f%% : \t\t\t %.2f \n", taxRate, gstAmount);
                printf("Total Amount Payable : \t\t\t %.2f \n", total);
                break;
            case 3:
                printf("\nThank you for using the C Cafe Billing System!\n");
                break;
            default:
                printf("\nInvalid Choice! Please enter a valid choice (1/2/3).\n");
        }
    } while (choice != 3);

    return 0;
}