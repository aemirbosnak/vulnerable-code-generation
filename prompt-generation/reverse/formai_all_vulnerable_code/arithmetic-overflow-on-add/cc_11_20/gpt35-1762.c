//FormAI DATASET v1.0 Category: Stock market tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int stock_prices[5] = {50, 75, 30, 120, 85}; // starting stock prices
    int day = 1; // starting day

    printf("Welcome to the post-apocalyptic stock market tracker!\n");

    printf("Today is day %d.\n", day);
    printf("The starting prices for the day are:\n");

    for (int i = 0; i < 5; i++) {
        printf("Stock %d: $%d\n", i+1, stock_prices[i]);
    }

    while (1) { // loop until the user decides to exit

        printf("\nWhat would you like to do?\n");
        printf("1. View prices for today\n");
        printf("2. View prices for a specific day\n");
        printf("3. Generate random event\n");
        printf("4. Exit\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            printf("Today's prices are:\n");

            for (int i = 0; i < 5; i++) {
                printf("Stock %d: $%d\n", i+1, stock_prices[i]);
            }
        } else if (option == 2) {
            printf("Enter the day you would like to view (1-%d): ", day);
            int requested_day;
            scanf("%d", &requested_day);

            if (requested_day > day) {
                printf("You can't view prices for a future day!\n");
            } else {
                printf("Prices for day %d are:\n", requested_day);

                for (int i = 0; i < 5; i++) {
                    int price = stock_prices[i] + (requested_day - day);
                    printf("Stock %d: $%d\n", i+1, price);
                }
            }
        } else if (option == 3) {
            printf("Generating random event...\n");

            srand(time(NULL)); // seed random number generator with current time
            int event = rand() % 5; // generate random event type

            if (event == 0) {
                printf("A new technology is discovered, causing Stock 2 to double in price!\n");
                stock_prices[1] *= 2;
            } else if (event == 1) {
                printf("A natural disaster strikes, causing Stock 3 to lose 75%% of its value.\n");
                stock_prices[2] /= 4;
            } else if (event == 2) {
                printf("The government announces new regulations, causing Stock 4 to lose 50%% of its value.\n");
                stock_prices[3] /= 2;
            } else if (event == 3) {
                printf("A major corporation goes bankrupt, causing Stock 5 to lose 90%% of its value.\n");
                stock_prices[4] /= 10;
            } else if (event == 4) {
                printf("The economy improves, causing all stocks to increase in value by 10%%.\n");

                for (int i = 0; i < 5; i++) {
                    stock_prices[i] *= 1.1;
                }
            }
        } else if (option == 4) {
            printf("Thanks for using the post-apocalyptic stock market tracker!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }

        day++; // increase day counter by 1 after each action
    }

    return 0;
}