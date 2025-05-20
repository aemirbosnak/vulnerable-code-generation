//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include<stdio.h>

// Function to calculate the bill amount
float calculate_bill(int quantity, float price_per_unit)
{
    float total_price = quantity * price_per_unit;
    float discount = 0.0;
    
    if(quantity > 10 && quantity <= 20)
    {
        discount = total_price * 0.05;
    }
    else if(quantity > 20)
    {
        discount = total_price * 0.10;
    }
    
    return (total_price - discount);
}

// Main function
int main()
{
    int quantity, option;
    float price_per_unit, total_bill;
    
    printf("Welcome to our Cafe!\n");
    
    printf("Please choose an item from our menu:\n");
    printf("1. Coffee (Rs. 50 per unit)\n");
    printf("2. Tea (Rs. 30 per unit)\n");
    printf("3. Hot Chocolate (Rs. 70 per unit)\n");
    scanf("%d", &option);
    
    switch(option)
    {
        case 1:
            price_per_unit = 50.0;
            break;
        case 2:
            price_per_unit = 30.0;
            break;
        case 3:
            price_per_unit = 70.0;
            break;
        default:
            printf("Invalid option selected! Please try again.\n");
            return 0;
    }
    
    printf("Please enter the quantity: ");
    scanf("%d", &quantity);
    
    total_bill = calculate_bill(quantity, price_per_unit);
    
    printf("Your bill amount is: Rs. %.2f\n", total_bill);
    
    return 0;   
}