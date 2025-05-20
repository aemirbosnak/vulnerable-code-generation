//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define the maximum number of stocks */
#define MAX_STOCKS 100

/* Define the structure of a stock */
typedef struct {
    char name[50];
    float price;
    int volume;
} Stock;

/* Define an array to store stocks data */
Stock stocks[MAX_STOCKS];

/* Define a function to initialize stocks data */
void initStocks() {
    strcpy(stocks[0].name, "AAPL");
    stocks[0].price = 150.25;
    stocks[0].volume = 100000;

    strcpy(stocks[1].name, "GOOG");
    stocks[1].price = 2700.00;
    stocks[1].volume = 50000;

    strcpy(stocks[2].name, "MSFT");
    stocks[2].price = 300.50;
    stocks[2].volume = 75000;
}

/* Define a function to display the stock data */
void displayStocks() {
    int i;
    printf("Name\tPrice\tVolume\n");
    for (i = 0; i < MAX_STOCKS; i++) {
        if (strlen(stocks[i].name) > 0) {
            printf("%s\t%.2f\t%d\n",
                    stocks[i].name,
                    stocks[i].price,
                    stocks[i].volume);
        }
    }
}

/* Define a function to update the stock data */
void updateStocks() {
    int i, index;
    char name[50];
    float price;
    int volume;

    /* Get the stock details from the user */
    printf("Enter stock name: ");
    scanf("%s", name);
    printf("Enter stock price: ");
    scanf("%f", &price);
    printf("Enter stock volume: ");
    scanf("%d", &volume);

    /* Search for the stock */
    index = -1;
    for (i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(name, stocks[i].name) == 0) {
            index = i;
            break;
        }
    }

    /* Update the stock if found */
    if (index != -1) {
        stocks[index].price = price;
        stocks[index].volume = volume;
        printf("Stock data updated successfully.\n");
    } else {
        printf("Stock not found.\n");
    }
}

/* Define the main function */
int main() {
    int option;
    srand(time(NULL)); /* Initialize the random number generator */

    /* Initialize the stocks data */
    initStocks();

    /* Display the menu */
    while (1) {
        printf("\n\nStock Market Tracker\n");
        printf("====================\n");
        printf("1. Display stocks\n");
        printf("2. Update stock\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        /* Handle the menu options */
        switch (option) {
            case 1:
                displayStocks();
                break;
            case 2:
                updateStocks();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}