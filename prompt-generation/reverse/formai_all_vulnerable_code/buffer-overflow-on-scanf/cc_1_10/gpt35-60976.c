//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
/*
* Romeo and Juliet Stock Market Tracker
*
* Written by: [Your Name]
*/

#include <stdio.h>

int main(){
    // Declare variables
    int stock_price;
    int previous_price;
    int difference;
    char stock_name[20];
  
    // Greet the user
    printf("Welcome to the Romeo and Juliet Stock Market Tracker!\n");
  
    // Ask for stock name and price
    printf("What is the name of the stock you want to track?\n");
    scanf("%s", stock_name);
    printf("What is the current price of %s?\n", stock_name);
    scanf("%d", &stock_price);
  
    // Display initial information
    printf("\n%s is currently priced at $%d per share.\n", stock_name, stock_price);

    // Prompt user to update stock price
    while(1){
        printf("\nWould you like to update the price of %s? (Y/N)\n", stock_name);
        char input;
        scanf(" %c", &input);

        if (input == 'Y' || input == 'y'){
            printf("\nWhat is the new price of %s?\n", stock_name);
            scanf("%d", &previous_price);
            difference = stock_price - previous_price;

            if (difference > 0){
                printf("\nAlas! Poor %s. Their stock has declined by %d dollars, and now stands at %d dollars.\n", stock_name, difference, previous_price);
            }
            else if (difference < 0){
                printf("\nJoy! %s's stock price has risen by %d dollars, and now stands at %d dollars. Will our star-crossed lovers find success?\n", stock_name, abs(difference), previous_price);
            }
            else{
                printf("\n%s's stock price has remained the same at %d dollars. Will fortune smile on their love?\n", stock_name, stock_price);
            }
            stock_price = previous_price;
        } 
        else if (input == 'N' || input == 'n'){
            printf("\nFarewell, and may fortune smile upon %s.\n", stock_name);
            break;
        } 
        else{
            printf("\nI am but a simple program, I cannot understand your input. Please try again.\n");
        }
    }
  
    return 0;
}