//FormAI DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 20
#define MAX_NAME_LEN 20

struct Stock {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
};

int main() {
    struct Stock stocks[MAX_STOCKS];
    int numStocks = 0, choice, i;
    
    do {
        printf("Welcome to the Stock Market Tracker!\n");
        printf("1. Add Stock\n");
        printf("2. View Stocks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(numStocks == MAX_STOCKS) {
                    printf("Maximum number of stocks reached!\n");
                    break;
                }
                printf("Enter Stock name: ");
                scanf("%s", stocks[numStocks].name);
                printf("Enter Stock price: ");
                scanf("%f", &stocks[numStocks].price);
                printf("Enter Stock quantity: ");
                scanf("%d", &stocks[numStocks].quantity);
                numStocks++;
                break;
                
            case 2:
                printf("Stocks in your portfolio:\n");
                printf("-----------------------\n");
                for(i = 0; i < numStocks; i++) {
                    printf("%s - $%.2f - %d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
                }
                break;
                
            case 3:
                printf("Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice!\n");
        }
    } while(1);
    
    return 0;
}