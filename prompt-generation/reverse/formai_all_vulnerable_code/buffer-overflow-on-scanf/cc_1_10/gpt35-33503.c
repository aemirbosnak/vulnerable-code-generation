//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float calculateTax(float);
void printReceipt(int, float);

// Main function
int main(){
    int menuSelection, quantity;
    float itemPrice, tax, subtotal = 0, total = 0;

    printf("***C Cafe Billing System***\n");

    // Loop for taking menu inputs from user
    do{
        printf("\nEnter item number (1-5) or 0 to exit: ");
        scanf("%d", &menuSelection);

        switch(menuSelection){
            case 0:
                printf("\nExiting Billing System.\n");
                break;
            
            case 1:
                itemPrice = 5.00; // Set price
                printf("\nEnter quantity: ");
                scanf("%d", &quantity);
                subtotal += (itemPrice * quantity); // Calculate subtotal
                break;
            
            case 2:
                itemPrice = 2.50; // Set price
                printf("\nEnter quantity: ");
                scanf("%d", &quantity);
                subtotal += (itemPrice * quantity); // Calculate subtotal
                break;
            
            case 3:
                itemPrice = 3.00; // Set price
                printf("\nEnter quantity: ");
                scanf("%d", &quantity);
                subtotal += (itemPrice * quantity); // Calculate subtotal
                break;

            case 4:
                itemPrice = 4.50; // Set price
                printf("\nEnter quantity: ");
                scanf("%d", &quantity);
                subtotal += (itemPrice * quantity); // Calculate subtotal
                break;

            case 5:
                itemPrice = 3.50; // Set price
                printf("\nEnter quantity: ");
                scanf("%d", &quantity);
                subtotal += (itemPrice * quantity); // Calculate subtotal
                break;

            default:
                printf("\nInvalid item number, please try again.\n");
                break;
        }
    }while(menuSelection != 0);

    // Calculate tax and total
    tax = calculateTax(subtotal);
    total = subtotal + tax;

    // Print receipt
    printReceipt(menuSelection, total);

    return 0;
}

// Function to calculate tax
float calculateTax(float amount){
    float taxRate = 0.05; // Set tax rate
    float tax = amount * taxRate; // Calculate tax
    return tax;
}

// Function to print receipt
void printReceipt(int item, float total){
    printf("\n\n");
    printf("----------------------------\n");
    printf("      C Cafe Receipt        \n");
    printf("----------------------------\n");
    printf("Item purchased:  %d          \n", item);
    printf("Subtotal:      $%.2f        \n", total);
    printf("Tax:           $%.2f        \n", calculateTax(total));
    printf("----------------------------\n");
    printf("Total:         $%.2f        \n", total+calculateTax(total));
    printf("----------------------------\n");
    printf("Thank you for your purchase!\n");
    printf("----------------------------\n");
}