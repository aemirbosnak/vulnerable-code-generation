//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>

// Declare all the functions
void printMenu();
int calculateBill(int choice, int quantity);
float applyDiscount(int totalBill);

int main()
{
    // Declare variables to store menu choice and quantity
    int choice, quantity;

    // Call the function to print menu
    printMenu();

    // Read the menu choice from user
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Read the quantity from user
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Calculate the bill amount
    int totalBill = calculateBill(choice, quantity);

    // Apply the discount
    float finalBill = applyDiscount(totalBill);

    // Print the final bill amount
    printf("\nTotal bill amount: %d\n", totalBill);
    printf("Discounted amount: %.2f\n", finalBill);

    return 0;
}

void printMenu()
{
    printf("Welcome to C Cafe!\n");
    printf("1. Coffee - $5\n");
    printf("2. Tea - $3\n");
    printf("3. Sandwich - $7\n");
    printf("4. Pastry - $2\n");
}

int calculateBill(int choice, int quantity)
{
    int rate;

    switch(choice)
    {
        case 1:
            rate = 5;
            break;
        case 2:
            rate = 3;
            break;
        case 3:
            rate = 7;
            break;
        case 4:
            rate = 2;
            break;
        default:
            printf("Invalid choice!");
            return 0;
    }

    return rate * quantity;
}

float applyDiscount(int totalBill)
{
    if(totalBill > 50)
    {
        return totalBill * 0.9; // 10% discount
    }
    else
    {
        return totalBill;
    }
}