//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float current_price;
    float previous_price;
} Stock;

void display_menu();
void add_stock(Stock stocks[], int *stock_count);
void update_stock(Stock stocks[], int stock_count);
void display_stocks(Stock stocks[], int stock_count);
void save_to_file(Stock stocks[], int stock_count);
void load_from_file(Stock stocks[], int *stock_count);

int main() {
    Stock stocks[MAX_STOCKS];
    int stock_count = 0;
    load_from_file(stocks, &stock_count);

    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_stock(stocks, &stock_count);
                break;
            case 2:
                update_stock(stocks, stock_count);
                break;
            case 3:
                display_stocks(stocks, stock_count);
                break;
            case 4:
                save_to_file(stocks, stock_count);
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n##### Stock Market Tracker #####\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock\n");
    printf("3. Display Stocks\n");
    printf("4. Save Stocks to File\n");
    printf("5. Exit\n");
    printf("###############################\n");
}

void add_stock(Stock stocks[], int *stock_count) {
    if (*stock_count >= MAX_STOCKS) {
        printf("Cannot add more stocks, limit reached.\n");
        return;
    }
    
    printf("Enter stock name: ");
    scanf("%s", stocks[*stock_count].name);
    printf("Enter current price: ");
    scanf("%f", &stocks[*stock_count].current_price);
    stocks[*stock_count].previous_price = stocks[*stock_count].current_price; // Initialize previous price
    (*stock_count)++;
    
    printf("Stock %s added successfully!\n", stocks[*stock_count - 1].name);
}

void update_stock(Stock stocks[], int stock_count) {
    char name[MAX_NAME_LEN];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].previous_price = stocks[i].current_price;
            printf("Enter new current price: ");
            scanf("%f", &stocks[i].current_price);
            printf("Stock %s updated successfully!\n", stocks[i].name);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void display_stocks(Stock stocks[], int stock_count) {
    if (stock_count == 0) {
        printf("No stocks available to display.\n");
        return;
    }

    printf("\n##### Current Stock Prices #####\n");
    printf("%-30s %-15s %-15s\n", "Stock Name", "Current Price", "Previous Price");
    for (int i = 0; i < stock_count; i++) {
        printf("%-30s %-15.2f %-15.2f\n", stocks[i].name, stocks[i].current_price, stocks[i].previous_price);
    }
    printf("################################\n");
}

void save_to_file(Stock stocks[], int stock_count) {
    FILE *file = fopen("stocks.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < stock_count; i++) {
        fprintf(file, "%s %.2f %.2f\n", stocks[i].name, stocks[i].current_price, stocks[i].previous_price);
    }
    fclose(file);
    printf("Stocks saved to stocks.txt successfully!\n");
}

void load_from_file(Stock stocks[], int *stock_count) {
    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("No existing stock data to load.\n");
        return;
    }

    while (fscanf(file, "%s %f %f", stocks[*stock_count].name, &stocks[*stock_count].current_price, 
                  &stocks[*stock_count].previous_price) != EOF) {
        (*stock_count)++;
        if (*stock_count >= MAX_STOCKS) {
            break;
        }
    }

    fclose(file);
    printf("Stocks loaded from stocks.txt successfully!\n");
}