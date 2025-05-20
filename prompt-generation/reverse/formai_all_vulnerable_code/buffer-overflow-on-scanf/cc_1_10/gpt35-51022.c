//FormAI DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_HISTORY 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price_history[MAX_PRICE_HISTORY];
    int price_history_count;
    double latest_price;
} Stock;

void add_stock(Stock *stocks, int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Maximum number of stocks reached!\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the stock: ");
    scanf("%s", name);

    double latest_price;
    printf("Enter the latest price of the stock: ");
    scanf("%lf", &latest_price);

    Stock new_stock;
    strcpy(new_stock.name, name);
    new_stock.price_history[0] = latest_price;
    new_stock.price_history_count = 1;
    new_stock.latest_price = latest_price;

    stocks[*count] = new_stock;
    (*count)++;

    printf("Stock added successfully!\n");
}

void print_stock(Stock stock) {
    printf("%s: [Latest price: %.2lf, Price history: {", stock.name, stock.latest_price);

    for (int i = 0; i < stock.price_history_count; i++) {
        printf("%.2lf", stock.price_history[i]);

        if (i != stock.price_history_count - 1) {
            printf(", ");
        }
    }

    printf("}]\n");
}

void show_stocks(Stock *stocks, int count) {
    if (count == 0) {
        printf("No stocks added yet!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        print_stock(stocks[i]);
    }
}

void update_price(Stock *stock) {
    double new_price;
    printf("Enter the new price of the stock: ");
    scanf("%lf", &new_price);

    stock->latest_price = new_price;

    if (stock->price_history_count == MAX_PRICE_HISTORY) {
        for (int i = 0; i < MAX_PRICE_HISTORY - 1; i++) {
            stock->price_history[i] = stock->price_history[i + 1];
        }

        stock->price_history[MAX_PRICE_HISTORY - 1] = new_price;
    } else {
        stock->price_history[stock->price_history_count] = new_price;
        (stock->price_history_count)++;
    }

    printf("Price updated successfully!\n");
}

void perform_action(char action, Stock *stocks, int *count) {
    switch (toupper(action)) {
        case 'A':
            add_stock(stocks, count);
            break;
        case 'S':
            show_stocks(stocks, *count);
            break;
        case 'U':
            printf("Enter the name of the stock to update price: ");
            char stock_name[MAX_NAME_LENGTH];
            scanf("%s", stock_name);

            Stock *stock_to_update = NULL;
            for (int i = 0; i < *count; i++) {
                if (strcmp(stocks[i].name, stock_name) == 0) {
                    stock_to_update = &stocks[i];
                    break;
                }
            }

            if (stock_to_update == NULL) {
                printf("Stock not found!\n");
            } else {
                update_price(stock_to_update);
            }

            break;
        case 'Q':
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid action!\n");
            break;
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;

    printf("*** STOCK MARKET TRACKER ***\n");

    while (1) {
        printf("\nAvailable actions:\n");
        printf("A -> Add a stock\n");
        printf("S -> Show all stocks\n");
        printf("U -> Update the price of a stock\n");
        printf("Q -> Quit\n");

        printf("Enter your choice: ");
        char choice;
        scanf(" %c", &choice);

        perform_action(choice, stocks, &count);
    }

    return 0;
}