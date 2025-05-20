//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
// Romeo and Juliet - Stock Market Tracker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    int shares;
    float price;
    float market_value;
} stock;

int main() {
    stock s[5];
    strcpy(s[0].name, "Apple");
    strcpy(s[1].name, "Microsoft");
    strcpy(s[2].name, "Amazon");
    strcpy(s[3].name, "Facebook");
    strcpy(s[4].name, "Tesla");

    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++) {
        s[i].shares = rand() % 100;
        s[i].price = (rand() % 2000) / 100.0;
        s[i].market_value = s[i].shares * s[i].price;
    }

    printf("Welcome to the Stock Market Tracker, dear Romeo and Juliet!\n");
    printf("Here are the stocks and their current values:\n");
    printf("Stock Name\tShares\tPrice\tMarket Value\n");
    for (i = 0; i < 5; i++) {
        printf("%s\t\t%d\t$%.2f\t$%.2f\n", s[i].name, s[i].shares, s[i].price, s[i].market_value);
    }

    printf("\nWould you like to buy any of these stocks, dear Romeo?\n");
    printf("Enter the name of the stock you wish to buy: ");
    char stock_name[20];
    scanf("%s", stock_name);

    for (i = 0; i < 5; i++) {
        if (strcmp(s[i].name, stock_name) == 0) {
            printf("How many shares would you like to buy, dear Romeo?\n");
            int num_shares;
            scanf("%d", &num_shares);
            if (num_shares > s[i].shares) {
                printf("Sorry, dear Romeo, but there are only %d shares available. Please try again later.\n", s[i].shares);
            } else {
                float transaction_value = num_shares * s[i].price; 
                printf("Thank you for buying %d shares of %s, dear Romeo! The total cost is $%.2f.\n", num_shares, s[i].name, transaction_value);
            }
            break;
        }
    }

    printf("\nDear Juliet, how about you? Would you like to sell any of your stocks?");
    printf("\nEnter the name of the stock you wish to sell: ");
    scanf("%s", stock_name);

    for (i = 0; i < 5; i++) {
        if (strcmp(s[i].name, stock_name) == 0) {
            printf("How many shares would you like to sell, dear Juliet?\n");
            int num_shares;
            scanf("%d", &num_shares);
            if (num_shares > s[i].shares) {
                printf("Sorry, dear Juliet, but you do not have %d shares of %s. Please check your portfolio.\n", num_shares, s[i].name);
            } else {
                float transaction_value = num_shares * s[i].price;
                printf("Thank you for selling %d shares of %s, dear Juliet! The total sale value is $%.2f.\n", num_shares, s[i].name, transaction_value);
            }
            break;
        }
    }

    printf("\nThank you for using the Stock Market Tracker, dear Romeo and Juliet. Have a good day!");

    return 0;
}