//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    int quantity;
} Stock;

void print_stock(Stock *stock) {
    printf("Stock Name: %s\n", stock->name);
    printf("Current Price: $%.2f\n", stock->price);
    printf("Quantity Available: %d\n", stock->quantity);
}

void update_stock_price(Stock *stock) {
    double change = ((rand() % 41) - 20) / 100.0; // Random change between -0.20 to +0.20
    stock->price += stock->price * change;
}

void display_stocks(Stock *stocks, int count) {
    for (int i = 0; i < count; i++) {
        print_stock(&stocks[i]);
        printf("\n");
    }
}

void add_stock(Stock *stocks, int *count, const char *name, double price, int quantity) {
    if (*count >= MAX_STOCKS) {
        printf("Cannot add more stocks. Max limit reached.\n");
        return;
    }
    strncpy(stocks[*count].name, name, MAX_NAME_LENGTH - 1);
    stocks[*count].price = price;
    stocks[*count].quantity = quantity;
    (*count)++;
}

void simulate_market(Stock *stocks, int count) {
    for (int i = 0; i < count; i++) {
        update_stock_price(&stocks[i]);
    }
}

void save_to_file(Stock *stocks, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%.2f,%d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
    fclose(file);
    printf("Stocks saved to %s\n", filename);
}

void load_from_file(Stock *stocks, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file for reading.\n");
        return;
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) && (*count < MAX_STOCKS)) {
        char name[MAX_NAME_LENGTH];
        double price;
        int quantity;
        sscanf(buffer, "%[^,],%lf,%d", name, &price, &quantity);
        add_stock(stocks, count, name, price, quantity);
    }
    fclose(file);
    printf("Stocks loaded from %s\n", filename);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stock_count = 0;
    int choice;
    char filename[100];

    srand(time(NULL));

    do {
        printf("\nStock Market Tracker Menu:\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Simulate Market\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                double price;
                int quantity;
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%lf", &price);
                printf("Enter stock quantity: ");
                scanf("%d", &quantity);
                add_stock(stocks, &stock_count, name, price, quantity);
                break;
            }
            case 2:
                display_stocks(stocks, stock_count);
                break;
            case 3:
                simulate_market(stocks, stock_count);
                printf("Market simulation complete.\n");
                break;
            case 4:
                printf("Enter filename to save stock data: ");
                scanf("%s", filename);
                save_to_file(stocks, stock_count, filename);
                break;
            case 5:
                printf("Enter filename to load stock data: ");
                scanf("%s", filename);
                load_from_file(stocks, &stock_count, filename);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}