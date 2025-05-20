//FormAI DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STOCKS 100 // Maximum number of stocks to track
#define MAX_NAME_LENGTH 20 // Maximum length for ticker names
#define MAX_LINES 500 // Maximum number of lines to read from the input file
#define MAX_CHARS 1000 // Maximum number of characters per line

int check_stock(char stocks[MAX_STOCKS][MAX_NAME_LENGTH], int num_stocks, char ticker[MAX_NAME_LENGTH]);
// Function to check if a stock is being tracked or not
void update_price(float prices[MAX_STOCKS], char stocks[MAX_STOCKS][MAX_NAME_LENGTH], 
char ticker[MAX_NAME_LENGTH], float price);
// Function to update price of a tracked stock
void display_stocks(int num_stocks, char stocks[MAX_STOCKS][MAX_NAME_LENGTH], 
float prices[MAX_STOCKS]);
// Function to display tracked stocks and their prices

int main()
{
    char stocks[MAX_STOCKS][MAX_NAME_LENGTH]; // Array to store the ticker names of tracked stocks
    float prices[MAX_STOCKS]; // Array to store the prices of tracked stocks
    int num_stocks = 0; // Variable to keep track of the number of stocks being tracked
    char input_file[] = "input.txt"; // Input file from which prices will be read
    char line[MAX_CHARS]; // Line buffer to read from input file
    char ticker[MAX_NAME_LENGTH]; // Temporary buffer to store ticker name from line read from input file
    float price; // Temporary buffer to store price from line read from input file

    // Read prices for tracked stocks from input file
    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        printf("Error opening %s\n", input_file);
        exit(1);
    }
    int i = 0;
    while ((i < MAX_LINES) && (fgets(line, sizeof(line), file) != NULL)) {
        if (sscanf(line, "%s %f", ticker, &price) == 2) {
            if (check_stock(stocks, num_stocks, ticker)) {
                update_price(prices, stocks, ticker, price);
            } else if (num_stocks < MAX_STOCKS) {
                // Add new stock to array if maximum number of tracked stocks hasn't been reached yet
                snprintf(stocks[num_stocks], MAX_NAME_LENGTH, "%s", ticker);
                prices[num_stocks] = price;
                num_stocks++;
            }
        }
        i++;
    }
    fclose(file);

    // Display tracked stocks and their prices every 5 seconds
    srand(time(NULL));
    while(1) {
        display_stocks(num_stocks, stocks, prices);
        int sleep_time = (rand() % 11) + 5; // Random number between 5 and 15 seconds
        printf("Sleeping for %d seconds...\n", sleep_time);
        sleep(sleep_time);
    }

    return 0;
}

int check_stock(char stocks[MAX_STOCKS][MAX_NAME_LENGTH], int num_stocks, char ticker[MAX_NAME_LENGTH]) {
    // Check if the stock is already being tracked
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i], ticker) == 0) {
            return 1;
        }
    }
    return 0;
}

void update_price(float prices[MAX_STOCKS], char stocks[MAX_STOCKS][MAX_NAME_LENGTH], 
char ticker[MAX_NAME_LENGTH], float price) {
    // Update price of a tracked stock
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(stocks[i], ticker) == 0) {
            prices[i] = price;
            return;
        }
    }
}

void display_stocks(int num_stocks, char stocks[MAX_STOCKS][MAX_NAME_LENGTH], 
float prices[MAX_STOCKS]) {
    // Display all tracked stocks and their prices
    printf("\nTicker\t\tPrice\n");
    printf("------\t\t-----\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-4s\t\t%.2f\n", stocks[i], prices[i]);
    }
    printf("------------------------\n");
}