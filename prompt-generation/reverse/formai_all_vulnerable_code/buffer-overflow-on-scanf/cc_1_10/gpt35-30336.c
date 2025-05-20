//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* C Stock Market Tracker Example Program */

#define MAX_STOCKS 10 /* Maximum number of stocks that can be tracked */
#define SYMBOL_SIZE 6 /* Maximum size of stock symbol */

typedef struct {
    char symbol[SYMBOL_SIZE]; /* Stock symbol */
    float price; /* Current stock price */
} stock_t;

int read_symbol(char symbol[]); /* Function to read a stock symbol from user */
int track_stock(FILE *fp, stock_t stocks[], int *num_stocks); /* Function to track a stock */
void print_stocks(stock_t stocks[], int num_stocks); /* Function to display all tracked stocks */
void prompt(); /* Function to display the prompt message */

int main(void) {
    FILE *fp;
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0, choice;

    /* Open the file */
    fp = fopen("stocks.txt", "a+");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    /* Read stocks from file */
    rewind(fp);
    while (fread(&stocks[num_stocks], sizeof(stock_t), 1, fp) == 1) {
        num_stocks++;
    }
    fclose(fp);

    /* Loop until user exits */
    do {
        prompt();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (track_stock(fp, stocks, &num_stocks)) {
                    printf("Stock added to tracker.\n");
                } else {
                    printf("Failed to add stock.\n");
                }
                break;
            case 2:
                print_stocks(stocks, num_stocks);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    /* Save stocks to file */
    fp = fopen("stocks.txt", "w");
    if (fp == NULL) {
        printf("Error saving file.\n");
        return 1;
    }

    for (int i = 0; i < num_stocks; i++) {
        fwrite(&stocks[i], sizeof(stock_t), 1, fp);
    }
    fclose(fp);

    return 0;
}

/* Function to read a stock symbol from user */
int read_symbol(char symbol[]) {
    /* Clear input buffer */
    fflush(stdin);

    printf("Enter stock symbol: ");
    fgets(symbol, SYMBOL_SIZE, stdin);
    symbol[strcspn(symbol, "\n")] = '\0';

    /* Convert symbol to uppercase */
    for (int i = 0; i < strlen(symbol); i++) {
        symbol[i] = toupper(symbol[i]);
    }

    /* Check for invalid symbol */
    if (strlen(symbol) != 5) {
        return 0;
    }
    for (int i = 0; i < strlen(symbol); i++) {
        if (!isalpha(symbol[i])) {
            return 0;
        }
    }
    return 1;
}

/* Function to track a stock */
int track_stock(FILE *fp, stock_t stocks[], int *num_stocks) {
    char symbol[SYMBOL_SIZE];
    float price;

    /* Read symbol from user */
    if (!read_symbol(symbol)) {
        printf("Invalid stock symbol.\n");
        return 0;
    }

    /* Check if symbol is already tracked */
    for (int i = 0; i < *num_stocks; i++) {
        if (strcmp(symbol, stocks[i].symbol) == 0) {
            printf("Stock already tracked.\n");
            return 0;
        }
    }

    /* Read price from user */
    printf("Enter current price: ");
    scanf("%f", &price);

    /* Add stock to tracker */
    if (*num_stocks < MAX_STOCKS) {
        strncpy(stocks[*num_stocks].symbol, symbol, SYMBOL_SIZE);
        stocks[*num_stocks].price = price;
        (*num_stocks)++;
        fwrite(&stocks[(*num_stocks)-1], sizeof(stock_t), 1, fp);
        return 1;
    } else {
        printf("Tracker is full. Please remove a stock before adding a new one.\n");
        return 0;
    }
}

/* Function to display all tracked stocks */
void print_stocks(stock_t stocks[], int num_stocks) {
    if (num_stocks == 0) {
        printf("No stocks are currently tracked.\n");
        return;
    }

    printf("%-10s%-10s\n", "Symbol", "Price");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-10s%-10.2f\n", stocks[i].symbol, stocks[i].price);
    }
}

/* Function to display the prompt message */
void prompt() {
    printf("\nStock Tracker\n");
    printf("==============\n");
    printf("1 - Add stock\n");
    printf("2 - Show all stocks\n");
    printf("3 - Exit\n");
    printf("Enter choice: ");
}