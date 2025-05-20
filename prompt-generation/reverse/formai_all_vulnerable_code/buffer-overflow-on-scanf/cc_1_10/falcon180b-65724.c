//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char symbol[10];
    double price;
    int quantity;
} stock;

int main() {
    int choice = 0;
    char symbol[10];
    stock *s = NULL;
    int n = 0;
    double total_price = 0;
    double avg_price;

    do {
        printf("\n\n\t\t\tSTOCK MARKET TRACKER\n\n");
        printf("1. Buy Stock\n2. Sell Stock\n3. View Portfolio\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the stock symbol: ");
                scanf("%s", symbol);
                s = (stock*)malloc(sizeof(stock));
                strcpy(s->symbol, symbol);
                printf("Enter the quantity: ");
                scanf("%d", &s->quantity);
                printf("Enter the price per share: ");
                scanf("%lf", &s->price);
                total_price += s->price * s->quantity;
                n++;
                break;
            case 2:
                printf("\nEnter the stock symbol: ");
                scanf("%s", symbol);
                for(int i=0; i<n; i++) {
                    if(strcmp(s[i].symbol, symbol) == 0) {
                        printf("\nEnter the quantity to sell: ");
                        scanf("%d", &s[i].quantity);
                        total_price -= s[i].price * s[i].quantity;
                        s[i].quantity = 0;
                        break;
                    }
                }
                break;
            case 3:
                printf("\nYour portfolio:\n");
                for(int i=0; i<n; i++) {
                    printf("\nSymbol: %s\nQuantity: %d\nPrice: $%.2lf\nTotal Price: $%.2lf\n", s[i].symbol, s[i].quantity, s[i].price, s[i].price * s[i].quantity);
                }
                avg_price = total_price / n;
                printf("\nAverage price per share: $%.2lf\n", avg_price);
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice!= 4);

    return 0;
}