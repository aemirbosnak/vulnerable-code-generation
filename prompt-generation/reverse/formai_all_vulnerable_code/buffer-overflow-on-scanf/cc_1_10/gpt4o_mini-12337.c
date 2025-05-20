//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 30
#define MAX_HISTORY_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float current_price;
    float history[MAX_HISTORY_LENGTH];
    int history_size;
} Stock;

Stock stocks[MAX_STOCKS];
int stock_count = 0;

void add_stock() {
    if (stock_count >= MAX_STOCKS) {
        printf("Maximum stock limit reached. Cannot add more stocks.\n");
        return;
    }
    Stock new_stock;
    printf("Enter stock name: ");
    scanf("%s", new_stock.name);
    printf("Enter current price: ");
    scanf("%f", &new_stock.current_price);
    new_stock.history_size = 0;
    stocks[stock_count] = new_stock;
    stock_count++;
    printf("Stock added successfully!\n");
}

void update_stock_price() {
    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            float new_price;
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%f", &new_price);
            stocks[i].history[stocks[i].history_size] = stocks[i].current_price;
            stocks[i].history_size++;
            stocks[i].current_price = new_price;
            printf("Price updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void view_stock() {
    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to view: ");
    scanf("%s", name);
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Stock: %s\n", stocks[i].name);
            printf("Current Price: %.2f\n", stocks[i].current_price);
            printf("Price History: ");
            for (int j = 0; j < stocks[i].history_size; j++) {
                printf("%.2f ", stocks[i].history[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void display_stocks() {
    printf("Available Stocks:\n");
    for (int i = 0; i < stock_count; i++) {
        printf("%s - Current Price: %.2f\n", stocks[i].name, stocks[i].current_price);
    }
}

void save_to_file() {
    FILE *file = fopen("stocks.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < stock_count; i++) {
        fprintf(file, "%s %.2f %d ", stocks[i].name, stocks[i].current_price, stocks[i].history_size);
        for (int j = 0; j < stocks[i].history_size; j++) {
            fprintf(file, "%.2f ", stocks[i].history[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Stocks saved to file successfully.\n");
}

void load_from_file() {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(file, "%s %f %d", stocks[stock_count].name, &stocks[stock_count].current_price, &stocks[stock_count].history_size) != EOF) {
        for (int j = 0; j < stocks[stock_count].history_size; j++) {
            fscanf(file, "%f", &stocks[stock_count].history[j]);
        }
        stock_count++;
        if (stock_count >= MAX_STOCKS) break;  // Prevent exceeding MAX_STOCKS
    }

    fclose(file);
    printf("Stocks loaded from file successfully.\n");
}

int main() {
    int choice;
    do {
        printf("\nStock Market Tracker Menu:\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. View Stock Details\n");
        printf("4. Display All Stocks\n");
        printf("5. Save Stocks to File\n");
        printf("6. Load Stocks from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                update_stock_price();
                break;
            case 3:
                view_stock();
                break;
            case 4:
                display_stocks();
                break;
            case 5:
                save_to_file();
                break;
            case 6:
                load_from_file();
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}