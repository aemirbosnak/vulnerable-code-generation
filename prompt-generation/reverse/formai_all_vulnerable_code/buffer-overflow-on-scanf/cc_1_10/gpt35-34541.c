//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    //Welcome message
    printf("Welcome to the Cafe Billing System!\n\n");
    
    //Initializing variables
    int itemCounter = 0;
    float totalCost = 0;
    char menuOption;
    
    //Menu loop
    do {
        //Displaying menu options
        printf("Please choose an item from the menu below:\n");
        printf("a. Coffee - $2.50\n");
        printf("b. Croissant - $1.75\n");
        printf("c. Sandwich - $4.25\n");
        printf("d. Exit\n");
        
        //Getting user input
        printf("Enter your choice: ");
        scanf(" %c", &menuOption);
        
        //Processing user input
        switch(menuOption) {
            case 'a':
                itemCounter++;
                totalCost += 2.5;
                printf("\nYou have selected Coffee. Total cost: $%.2f\n\n", totalCost);
                break;
                
            case 'b':
                itemCounter++;
                totalCost += 1.75;
                printf("\nYou have selected Croissant. Total cost: $%.2f\n\n", totalCost);
                break;
                
            case 'c':
                itemCounter++;
                totalCost += 4.25;
                printf("\nYou have selected Sandwich. Total cost: $%.2f\n\n", totalCost);
                break;
            
            case 'd':
                printf("\nThank you for using the Cafe Billing System.\n");
                break;
                
            default:
                printf("\nInvalid menu option selected. Please try again.\n\n");
        }
    } while(menuOption != 'd');
    
    //Displaying bill
    printf("Total number of items ordered: %d\n", itemCounter);
    printf("Total cost of items ordered: $%.2f\n", totalCost);
    
    return 0;
}