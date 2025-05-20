//FormAI DATASET v1.0 Category: Stock market tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 5

typedef struct {
    char name[20];
    float price;
    float percent_change;
} Stock;

void initialize_stocks(Stock *stocks, int size);
void update_stock_prices(Stock *stocks, int size);
void print_stock_info(const Stock *stock);
void print_stock_list(const Stock *stocks, int size);

int main(void) {
    srand(time(NULL));
    Stock stocks[MAX_STOCKS];
    int i, choice;

    initialize_stocks(stocks, MAX_STOCKS);

    do {
        printf("What would you like to do?\n");
        printf("1. Update stock prices\n");
        printf("2. View stock info\n");
        printf("3. View stock list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                update_stock_prices(stocks, MAX_STOCKS);
                break;
            case 2:
                printf("Enter stock index: ");
                scanf("%d", &i);
                if (i >= 0 && i < MAX_STOCKS) {
                    print_stock_info(&stocks[i]);
                } else {
                    printf("Invalid stock index\n");
                }
                break;
            case 3:
                print_stock_list(stocks, MAX_STOCKS);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    printf("Exiting program\n");

    return 0;
}

void initialize_stocks(Stock *stocks, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Enter name of stock %d: ", i + 1);
        scanf("%s", stocks[i].name);
        stocks[i].price = (float) (rand() % 1000) / 10.0f;
        stocks[i].percent_change = 0.0f;
    }
}

void update_stock_prices(Stock *stocks, int size) {
    int i;
    float random_change;
    for (i = 0; i < size; i++) {
        random_change = (float) (rand() % 201 - 100) / 1000.0f;
        stocks[i].percent_change = random_change;
        printf("Updating stock %d: %s\n", i + 1, stocks[i].name);
        printf("Old price: %.2f\n", stocks[i].price);
        stocks[i].price += stocks[i].price * random_change;
        printf("New price: %.2f\n", stocks[i].price);
    }
}

void print_stock_info(const Stock *stock) {
    printf("Stock name: %s\n", stock->name);
    printf("Current price: %.2f\n", stock->price);
    printf("Percentage change: %.2f%%\n", stock->percent_change * 100.0f);
}

void print_stock_list(const Stock *stocks, int size) {
    int i;
    printf("Stock list:\n");
    for (i = 0; i < size; i++) {
        printf("%d. %s - %.2f (%+.2f%%)\n", i + 1, stocks[i].name, stocks[i].price, stocks[i].percent_change * 100.0f);
    }
}