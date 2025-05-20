//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
// This C program simulates a billing system for a cafe
// Designed by Claude Shannon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to store item details
struct item {
    char name[50];
    float price;
};

int main()
{
    // initialize menu items
    struct item menu[10];
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 1.50;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 1.25;
    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 3.50;
    strcpy(menu[3].name, "Salad");
    menu[3].price = 4.25;
    strcpy(menu[4].name, "Burger");
    menu[4].price = 5.00;
    strcpy(menu[5].name, "Fries");
    menu[5].price = 2.50;
    
    // initialize variables
    int choice, quantity;
    float total = 0.0;
    
    // display menu to user
    printf("Welcome to Claude's Cafe!\n");
    printf("Here is our menu:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    
    // loop until user quits
    while (1) {
        printf("Enter menu choice (0 to quit): ");
        scanf("%d", &choice);
        
        if (choice == 0)
            break;
        
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        // add item total to running total
        total += menu[choice-1].price * quantity;
    }
    
    // print total to user
    printf("Your total is $%.2f. Thank you for dining with us!\n", total);
    
    return 0;
}