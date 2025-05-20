//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// define constant values
#define MAX_STOCKS 100
#define MAX_NAME_LEN 50

// define struct for holding stock information
typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    float change;
} Stock;

// function for adding new stock to the tracker
void add_stock(Stock *stocks, int *num_stocks) {
    char name[MAX_NAME_LEN];
    float price, change;
    // prompt user to input information for new stock
    printf("Enter name of stock: ");
    fgets(name, MAX_NAME_LEN, stdin);
    printf("Enter price of stock: ");
    scanf("%f", &price);
    printf("Enter change of stock: ");
    scanf("%f", &change);
    // create new stock object and add to stocks array
    Stock new_stock = { .price = price, .change = change };
    strcpy(new_stock.name, name);
    stocks[*num_stocks] = new_stock;
    (*num_stocks)++;
    // output success message
    printf("Successfully added new stock: %s", name);
    printf("Current number of stocks: %d\n", *num_stocks);
}

// function for removing stock from tracker by name
void remove_stock(Stock *stocks, int *num_stocks) {
    char name[MAX_NAME_LEN];
    // prompt user to input name of stock to remove
    printf("Enter name of stock to remove: ");
    fgets(name, MAX_NAME_LEN, stdin);
    // iterate through stocks to find matching name and remove stock
    for (int i = 0; i < *num_stocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            // shift remaining stocks over and decrement num_stocks
            for (int j = i; j < *num_stocks - 1; j++) {
                stocks[j] = stocks[j+1];
            }
            (*num_stocks)--;
            // output success message
            printf("Successfully removed stock: %s", name);
            printf("Current number of stocks: %d\n", *num_stocks);
            return;
        }
    }
    // output error message if no matching stock found
    printf("Error: could not find stock named %s", name);
}

// function to print out current stock information
void print_stocks(Stock *stocks, int num_stocks) {
    // iterate through stocks and output information for each one
    for (int i = 0; i < num_stocks; i++) {
        printf("Stock %d\n", i+1);
        printf("Name: %s", stocks[i].name);
        printf("Price: %.2f\n", stocks[i].price);
        printf("Change: %.2f\n", stocks[i].change);
    }
}

// function to calculate and output the average stock price
void print_average_price(Stock *stocks, int num_stocks) {
    float total_price = 0.0;
    // iterate through stocks and add up all the prices
    for (int i = 0; i < num_stocks; i++) {
        total_price += stocks[i].price;
    }
    // calculate and output the average price
    float average_price = total_price / num_stocks;
    printf("Average stock price: %.2f\n", average_price);
}

// function to calculate and output the total change percentage of all stocks
void print_total_change(Stock *stocks, int num_stocks) {
    float total_change = 0.0;
    // iterate through stocks and add up all the percentage changes
    for (int i = 0; i < num_stocks; i++) {
        total_change += stocks[i].change;
    }
    // output the total change percentage
    printf("Total change percentage: %.2f%%\n", total_change);
}

// main program
int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input;
    // loop through program menu until user quits program
    do {
        // display program menu
        printf("\nProgram Menu:\n");
        printf("1. Add new stock to tracker\n");
        printf("2. Remove stock from tracker\n");
        printf("3. Print current stocks and information\n");
        printf("4. Calculate and print average stock price\n");
        printf("5. Calculate and print total change percentage\n");
        printf("6. Quit program\n");
        printf("Enter menu option: ");
        scanf(" %c", &input);
        // handle menu option chosen by user
        switch (input) {
            case '1':
                add_stock(stocks, &num_stocks);
                break;
            case '2':
                remove_stock(stocks, &num_stocks);
                break;
            case '3':
                print_stocks(stocks, num_stocks);
                break;
            case '4':
                print_average_price(stocks, num_stocks);
                break;
            case '5':
                print_total_change(stocks, num_stocks);
                break;
            case '6':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid menu option, please try again\n");
                break;
        }
    } while (input != '6');
    return 0;
}