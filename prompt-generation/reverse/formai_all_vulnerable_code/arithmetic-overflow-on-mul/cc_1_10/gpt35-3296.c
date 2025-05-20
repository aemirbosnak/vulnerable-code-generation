//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// define constants for the prices of each item
#define COFFEE_PRICE 80
#define TEA_PRICE 65
#define BAGEL_PRICE 120
#define SANDWICH_PRICE 180

// function to calculate sub-total
int calculateSubTotal(int[]);

// function to calculate total bill
int calculateTotalBill(int[]);

// function to print receipt
void printReceipt(int[], int, int);

int main() {
    int coffeeCount = 0, teaCount = 0, bagelCount = 0, sandwichCount = 0;
    int quantities[4] = { 0 };
    char choice;
    do {
        printf("Welcome to the Cafe Billing System\n");
        printf("What do you want to order?\n");
        printf("1. Coffee - $80\n");
        printf("2. Tea - $65\n");
        printf("3. Bagel - $120\n");
        printf("4. Sandwich - $180\n");
        printf("Enter your choice (1-4): ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("How many cups of coffee do you want to order? ");
                scanf("%d", &coffeeCount);
                quantities[0] = coffeeCount;
                break;
            case '2':
                printf("How many cups of tea do you want to order? ");
                scanf("%d", &teaCount);
                quantities[1] = teaCount;
                break;
            case '3':
                printf("How many bagels do you want to order? ");
                scanf("%d", &bagelCount);
                quantities[2] = bagelCount;
                break;
            case '4':
                printf("How many sandwiches do you want to order? ");
                scanf("%d", &sandwichCount);
                quantities[3] = sandwichCount;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice < '1' || choice > '4');

    int subTotal = calculateSubTotal(quantities);
    int totalBill = calculateTotalBill(quantities);
    printReceipt(quantities, subTotal, totalBill);

    printf("Thank you for using the Cafe Billing System!\n");
    return 0;
}

// function to calculate sub-total
int calculateSubTotal(int quantities[]) {
    int subTotal = 0;

    subTotal += quantities[0] * COFFEE_PRICE;
    subTotal += quantities[1] * TEA_PRICE;
    subTotal += quantities[2] * BAGEL_PRICE;
    subTotal += quantities[3] * SANDWICH_PRICE;

    return subTotal;
}

// function to calculate total bill
int calculateTotalBill(int quantities[]) {
    int subTotal = calculateSubTotal(quantities);
    int totalBill = subTotal;
    if (subTotal >= 500) {
        totalBill -= 50;
    }
    return totalBill;
}

// function to print receipt
void printReceipt(int quantities[], int subTotal, int totalBill) {
    printf("\n************ Cafe Billing Receipt ************\n");
    printf("%-10s%-10s%-10s\n", "ITEM", "QUANTITY", "PRICE");
    if (quantities[0] > 0) {
        printf("%-10s%-10d%-10d\n", "Coffee", quantities[0], quantities[0] * COFFEE_PRICE);
    }
    if (quantities[1] > 0) {
        printf("%-10s%-10d%-10d\n", "Tea", quantities[1], quantities[1] * TEA_PRICE);
    }
    if (quantities[2] > 0) {
        printf("%-10s%-10d%-10d\n", "Bagel", quantities[2], quantities[2] * BAGEL_PRICE);
    }
    if (quantities[3] > 0) {
        printf("%-10s%-10d%-10d\n", "Sandwich", quantities[3], quantities[3] * SANDWICH_PRICE);
    }
    printf("\n%-10s%-10d\n", "Sub-Total", subTotal);
    if (subTotal >= 500) {
        printf("%-10s%-10d\n", "Discount", 50);
    }
    printf("%-10s%-10d\n", "Total Bill", totalBill);
    printf("\n**********************************************\n");
}