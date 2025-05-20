//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 30
#define MAX_HISTORY_LENGTH 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price_history[MAX_HISTORY_LENGTH];
    int history_count;
} Stock;

void add_stock(Stock stocks[], int *stock_count);
void update_stock(Stock stocks[], int stock_count);
void view_stocks(const Stock stocks[], int stock_count);
void save_to_file(const Stock stocks[], int stock_count);
void load_from_file(Stock stocks[], int *stock_count);
void print_menu();

int main() {
    Stock stocks[MAX_STOCKS];
    int stock_count = 0;
    load_from_file(stocks, &stock_count);
    
    while (1) {
        int choice;
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_stock(stocks, &stock_count);
                break;
            case 2:
                update_stock(stocks, stock_count);
                break;
            case 3:
                view_stocks(stocks, stock_count);
                break;
            case 4:
                save_to_file(stocks, stock_count);
                break;
            case 5:
                exit(0);
            default:
                printf("Unknown option!\n");
        }
    }
    return 0;
}

void print_menu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Stocks\n");
    printf("4. Save to File\n");
    printf("5. Exit\n");
}

void add_stock(Stock stocks[], int *stock_count) {
    if (*stock_count < MAX_STOCKS) {
        printf("Enter stock name: ");
        scanf("%s", stocks[*stock_count].name);
        stocks[*stock_count].price_history[0] = 0.0; // Initialize first price
        stocks[*stock_count].history_count = 0;
        (*stock_count)++;
        printf("Stock added successfully!\n");
    } else {
        printf("Cannot add more stocks!\n");
    }
}

void update_stock(Stock stocks[], int stock_count) {
    char stock_name[MAX_NAME_LENGTH];
    double new_price;
    
    printf("Enter stock name to update: ");
    scanf("%s", stock_name);
    
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, stock_name) == 0) {
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%lf", &new_price);
            if (stocks[i].history_count < MAX_HISTORY_LENGTH) {
                stocks[i].price_history[stocks[i].history_count++] = new_price;
            }
            printf("Price updated for %s!\n", stocks[i].name);
            return;
        }
    }
    printf("Stock not found!\n");
}

void view_stocks(const Stock stocks[], int stock_count) {
    printf("\n--- Current Stocks ---\n");
    for (int i = 0; i < stock_count; i++) {
        printf("%s: ", stocks[i].name);
        for (int j = 0; j < stocks[i].history_count; j++) {
            printf("%.2f ", stocks[i].price_history[j]);
        }
        printf("\n");
    }
}

void save_to_file(const Stock stocks[], int stock_count) {
    FILE *file = fopen("stocks.txt", "w");
    if (!file) {
        printf("Error saving to file!\n");
        return;
    }
    
    for (int i = 0; i < stock_count; i++) {
        fprintf(file, "%s ", stocks[i].name);
        for (int j = 0; j < stocks[i].history_count; j++) {
            fprintf(file, "%.2f ", stocks[i].price_history[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Stocks saved to stock.txt!\n");
}

void load_from_file(Stock stocks[], int *stock_count) {
    FILE *file = fopen("stocks.txt", "r");
    if (!file) {
        return; // No stocks to load initially
    }
    
    while (fscanf(file, "%s", stocks[*stock_count].name) != EOF) {
        double price;
        stocks[*stock_count].history_count = 0;
        while (fscanf(file, "%lf", &price) != EOF) {
            if (stocks[*stock_count].history_count < MAX_HISTORY_LENGTH) {
                stocks[*stock_count].price_history[stocks[*stock_count].history_count++] = price;
            } else {
                break;
            }
        }
        (*stock_count)++;
    }
    fclose(file);
    printf("Stocks loaded from file!\n");
}