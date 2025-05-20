//FormAI DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
    char *name;
    float price;
    float variance;
};

typedef struct Stock Stock;

int main() {
    int stockCount = 0; //Number of stocks to be tracked
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &stockCount);

    Stock stocks[stockCount];

    for (int i = 0; i < stockCount; i++) {
        stocks[i].name = (char *) malloc(sizeof(char)*50); //Allocating memory for 50 characters
        printf("Enter the name of Stock %d: ", (i+1));
        scanf("%s", stocks[i].name);
        printf("Enter the price of Stock %d: ", (i+1));
        scanf("%f", &stocks[i].price);
        printf("Enter the variance of Stock %d: ", (i+1));
        scanf("%f", &stocks[i].variance);
    }

    while(1) { //Continuous loop till the user exits
        printf("\n===============================\n");
        printf("Stock Market Tracker\n");
        printf("===============================\n");

        for (int i = 0; i < stockCount; i++) {
            float randNum = ((float)rand()/(float)(RAND_MAX)) * stocks[i].variance; //Generating random number

            if (randNum > stocks[i].variance/2.0) {
                stocks[i].price += randNum; //Incrementing price if random number is greater than half of variance
            } else {
                stocks[i].price -= randNum; //Decrementing price if random number is lesser than or equal to half of variance
            }

            printf("\n%s: $%.2f\n", stocks[i].name, stocks[i].price);
        }

        printf("\nPress any key to continue or 'q' to quit: ");
        char ch = getchar();

        if (ch == 'q') {
            printf("\nExiting Stock Market Tracker...\n");
            break;
        }
    }

    return 0;
}