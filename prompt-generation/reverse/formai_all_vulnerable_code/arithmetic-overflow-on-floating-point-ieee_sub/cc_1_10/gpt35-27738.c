//FormAI DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 5    // Maximum number of stocks that can be tracked

// Define each stock with a struct
typedef struct Stock {
    char symbol[5];
    float current_price;
    float open_price;
    float high;
    float low;
} Stock;

// Define the portfolio with an array of Stock structs
typedef struct Portfolio {
    Stock stocks[MAX_STOCKS];
    int num_stocks;
    float portfolio_value;
} Portfolio;

// Function declarations
void print_menu();
void add_stock(Portfolio *p);
void remove_stock(Portfolio *p);
void display_portfolio(Portfolio *p);
void update_prices(Portfolio *p);
void generate_prices(Stock *s);
int get_input();
void clear_buffer();

int main() {
    srand(time(NULL));     // Seed random number generator
    Portfolio p = {0};      // Initialize portfolio with 0 stocks and value
    int choice;

    do {
        print_menu();
        choice = get_input();

        switch (choice) {
            case 1:
                add_stock(&p);
                break;
            case 2:
                remove_stock(&p);
                break;
            case 3:
                display_portfolio(&p);
                break;
            case 4:
                update_prices(&p);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Print the menu options
void print_menu() {
    printf("\n ==== C STOCK MARKET TRACKER ====\n");
    printf("1. Add Stock\n");
    printf("2. Remove Stock\n");
    printf("3. Display Portfolio\n");
    printf("4. Update Prices\n");
    printf("5. Exit\n");
    printf("Please enter a choice: ");
}

// Add a new stock to the portfolio
void add_stock(Portfolio *p) {
    if (p->num_stocks < MAX_STOCKS) {
        printf("Enter stock symbol: ");
        scanf("%s", p->stocks[p->num_stocks].symbol);
        generate_prices(&p->stocks[p->num_stocks]);
        p->num_stocks++;
        printf("Stock added to portfolio.\n");
    } else {
        printf("Portfolio is full. Cannot add more stocks.\n");
    }
}

// Remove a stock from the portfolio
void remove_stock(Portfolio *p) {
    if (p->num_stocks > 0) {
        char symbol[5];
        printf("Enter stock symbol: ");
        scanf("%s", symbol);

        int index = -1;
        for (int i = 0; i < p->num_stocks; i++) {
            if (strcmp(p->stocks[i].symbol, symbol) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("Stock not found in portfolio.\n");
        } else {
            // Remove the stock from the portfolio by shifting all subsequent
            // stocks to the left by one index
            for (int i = index; i < p->num_stocks-1; i++) {
                p->stocks[i] = p->stocks[i+1];
            }
            p->num_stocks--;
            printf("Stock removed from portfolio.\n");
        }
    } else {
        printf("Portfolio is empty. Cannot remove stocks.\n");
    }
}

// Display the current portfolio
void display_portfolio(Portfolio *p) {
    printf("\n");
    printf("== CURRENT PORTFOLIO ==\n");
    float total_value = 0;
    for (int i = 0; i < p->num_stocks; i++) {
        printf("%s - Current price: %.2f, Open price: %.2f, High: %.2f, Low: %.2f\n",
                p->stocks[i].symbol, p->stocks[i].current_price, p->stocks[i].open_price,
                p->stocks[i].high, p->stocks[i].low);
        total_value += p->stocks[i].current_price;
    }
    p->portfolio_value = total_value;
    printf("Total portfolio value: %.2f\n", p->portfolio_value);
}

// Update the prices of all stocks in the portfolio
void update_prices(Portfolio *p) {
    for (int i = 0; i < p->num_stocks; i++) {
        float old_price = p->stocks[i].current_price;
        generate_prices(&p->stocks[i]);
        printf("%s - Old price: %.2f, New price: %.2f\n",
                p->stocks[i].symbol, old_price, p->stocks[i].current_price);
    }
}

// Generate random prices for a stock
void generate_prices(Stock *s) {
    s->open_price = 100 + (float)rand()/(float)(RAND_MAX/50);    // Generate between 100 - 150
    s->current_price = s->open_price + (float)rand()/(float)(RAND_MAX/10) - 5;   // Vary between -5 and 5
    s->high = s->current_price + (float)rand()/(float)(RAND_MAX/10);    // Vary between 0 - 10
    s->low = s->current_price - (float)rand()/(float)(RAND_MAX/10);     // Vary between 0 - 10
}

// Get user input and validate
int get_input() {
    int choice;
    scanf("%d", &choice);
    clear_buffer();     // Clear any extra characters in the input buffer

    return choice;
}

// Clear any extra characters in the input buffer
void clear_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}