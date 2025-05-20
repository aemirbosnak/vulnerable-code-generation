//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <string.h>

struct item {
    char name[50]; 
    int quantity; 
    float price; 
};

int main()
{
    // Initializing variables
    float total = 0; 
    int choice, quantity;
    char cont = 'y'; 
    struct item menu[5]; 

    // Populating menu items
    strcpy(menu[0].name, "Coffee");
    menu[0].quantity = 10;
    menu[0].price = 1.5;
    strcpy(menu[1].name, "Tea");
    menu[1].quantity = 7;
    menu[1].price = 1.0;
    strcpy(menu[2].name, "Sandwich");
    menu[2].quantity = 5;
    menu[2].price = 3.0;
    strcpy(menu[3].name, "Cake");
    menu[3].quantity = 3;
    menu[3].price = 2.0;
    strcpy(menu[4].name, "Juice");
    menu[4].quantity = 8;
    menu[4].price = 2.5;

    printf("Welcome to C Cafe!\n");

    while(cont == 'y') { // Loop until customer is done ordering

        // Printing menu
        printf("\nMenu:\n");
        printf("Item\t\tPrice\t\tQuantity\n");
        for(int i=0; i<5; i++) {
            printf("%s\t\t%.2f\t\t%d\n", menu[i].name, menu[i].price, menu[i].quantity);
        }

        // Getting customer order
        printf("\nEnter the item number you want to order: ");
        scanf("%d", &choice);

        // Validating choice
        if(choice < 1 || choice > 5) {
            printf("Invalid choice. Please select again.\n");
            continue;
        }

        // Getting quantity
        printf("Enter the quantity you want to order: ");
        scanf("%d", &quantity);

        // Validating quantity
        if(quantity > menu[choice-1].quantity) {
            printf("Sorry, we do not have enough quantity!\n");
            continue;
        }

        // Updating total and item quantity
        total += menu[choice-1].price * quantity;
        menu[choice-1].quantity -= quantity;

        // Asking if customer wants to order more
        printf("Do you want to order more (y/n)? ");
        scanf(" %c", &cont);

    }

    // Displaying total
    printf("\nThank you for ordering. Your total bill is $%.2f\n", total);

    return 0;
}