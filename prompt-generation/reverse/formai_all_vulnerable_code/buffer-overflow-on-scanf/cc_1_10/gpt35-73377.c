//FormAI DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    //Welcome message
    printf("Welcome to the Kingdom's Digital Auction System!\n");
    printf("In this system, you will be able to bid on various medieval treasures.\n");
    
    //Creating an array to store the items and their initial prices
    char items[5][20] = {"Chalice", "Sword", "Crown", "Armor", "Ring"};
    int prices[5] = {100, 250, 500, 750, 1000};
    
    //Asking the user for their name
    char name[20];
    printf("What is your name, noble bidder? ");
    scanf("%s", name);
    printf("Welcome, %s!\n", name);
    
    //Displaying the items and their prices
    printf("Here are the items available in today's auction:\n");
    for(int i=0; i<5; i++) {
        printf("%d. %s - Starting price: %d gold coins\n", i+1, items[i], prices[i]);
    }
    
    //Asking the user to select an item to bid on
    int choice;
    printf("Please select an item to bid on (1-5): ");
    scanf("%d", &choice);
    
    //Validating the user's choice
    while(choice<1 || choice>5) {
        printf("Invalid choice. Please select again (1-5): ");
        scanf("%d", &choice);
    }
    printf("You have selected the %s.\n", items[choice-1]);
    
    //Asking the user to enter their bid
    int bid;
    printf("What is your bid, %s? ", name);
    scanf("%d", &bid);
    
    //Validating the user's bid
    while(bid<prices[choice-1]) {
        printf("Your bid is too low. The starting price for this item is %d gold coins.\n", prices[choice-1]);
        printf("Please enter a higher bid: ");
        scanf("%d", &bid);
    }
    
    //Displaying the final bid amount and thanking the user
    printf("Congratulations, %s! You have won the %s for %d gold coins.\n", name, items[choice-1], bid);
    printf("Thank you for using the Kingdom's Digital Auction System.\n");
    
    return 0;
}