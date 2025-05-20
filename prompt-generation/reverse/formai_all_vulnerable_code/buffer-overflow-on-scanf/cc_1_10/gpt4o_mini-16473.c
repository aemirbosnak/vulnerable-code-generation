//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int shares;
} Stock;

void add_stock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Maximum stock limit reached.\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    printf("Enter number of shares: ");
    scanf("%d", &stocks[*count].shares);
    (*count)++;
    printf("Stock added successfully!\n");
}

void update_stock(Stock stocks[], int count) {
    char stock_name[NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", stock_name);
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, stock_name) == 0) {
            printf("Enter new stock price: ");
            scanf("%f", &stocks[i].price);
            printf("Enter new number of shares: ");
            scanf("%d", &stocks[i].shares);
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Stock not found.\n");
}

void list_stocks(Stock stocks[], int count) {
    printf("\nCurrent Stocks:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Price: %.2f | Shares: %d\n", stocks[i].name, stocks[i].price, stocks[i].shares);
    }
}

void delete_stock(Stock stocks[], int *count) {
    char stock_name[NAME_LENGTH];
    printf("Enter stock name to delete: ");
    scanf("%s", stock_name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, stock_name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*count)--;
            printf("Stock deleted successfully!\n");
            return;
        }
    }
    printf("Stock not found.\n");
}

void calculate_total_value(Stock stocks[], int count) {
    float total_value = 0.0;
    for (int i = 0; i < count; i++) {
        total_value += stocks[i].price * stocks[i].shares;
    }
    printf("Total portfolio value: %.2f\n", total_value);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock\n");
        printf("3. List Stocks\n");
        printf("4. Delete Stock\n");
        printf("5. Calculate Total Portfolio Value\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock(stocks, &count);
                break;
            case 2:
                update_stock(stocks, count);
                break;
            case 3:
                list_stocks(stocks, count);
                break;
            case 4:
                delete_stock(stocks, &count);
                break;
            case 5:
                calculate_total_value(stocks, count);
                break;
            case 6:
                printf("Exiting the program. Farewell!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}