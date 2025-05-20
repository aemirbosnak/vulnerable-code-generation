//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[5];
    float price;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    char choice;
    
    do {
        printf("Welcome to the Verona Stock Exchange!\n");
        printf("Please choose an option:\n");
        printf("A - Add a stock\n");
        printf("R - Remove a stock\n");
        printf("U - Update a stock's price\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);
        
        switch(choice) {
            case 'A':
                if(numStocks >= MAX_STOCKS) {
                    printf("Error: Maximum number of stocks reached.\n");
                } else {
                    printf("Enter the name of the stock: ");
                    scanf("%s", stocks[numStocks].name);
                    printf("Enter the symbol of the stock (up to 4 characters): ");
                    scanf("%s", stocks[numStocks].symbol);
                    stocks[numStocks].price = 0;
                    numStocks++;
                    printf("Stock added successfully.\n");
                }
                break;
                
            case 'R':
                if(numStocks == 0) {
                    printf("Error: No stocks to remove.\n");
                } else {
                    printf("Enter the symbol of the stock to remove: ");
                    scanf("%s", stocks[numStocks - 1].symbol);
                    numStocks--;
                    printf("Stock removed successfully.\n");
                }
                break;
                
            case 'U':
                if(numStocks == 0) {
                    printf("Error: No stocks to update.\n");
                } else {
                    printf("Enter the symbol of the stock to update: ");
                    scanf("%s", stocks[numStocks - 1].symbol);
                    printf("Enter the new price: ");
                    scanf("%f", &stocks[numStocks - 1].price);
                    printf("Stock updated successfully.\n");
                }
                break;
                
            case 'Q':
                printf("Thank you for using the Verona Stock Exchange. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 'Q');
    
    return 0;
}