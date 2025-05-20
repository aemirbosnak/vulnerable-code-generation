//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} Stock;

Stock portfolio[MAX_STOCKS];
int stock_count = 0;

void load_stocks() {
    FILE *file = fopen("stocks.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %f %d", portfolio[stock_count].name, &portfolio[stock_count].price, &portfolio[stock_count].quantity) == 3) {
            stock_count++;
        }
        fclose(file);
    }
}

void save_stocks() {
    FILE *file = fopen("stocks.txt", "w");
    for (int i = 0; i < stock_count; i++) {
        fprintf(file, "%s %.2f %d\n", portfolio[i].name, portfolio[i].price, portfolio[i].quantity);
    }
    fclose(file);
}

void add_stock() {
    if (stock_count >= MAX_STOCKS) {
        printf("Stock limit reached!\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", portfolio[stock_count].name);
    printf("Enter stock price: ");
    scanf("%f", &portfolio[stock_count].price);
    printf("Enter stock quantity: ");
    scanf("%d", &portfolio[stock_count].quantity);
    stock_count++;
    save_stocks();
}

void update_stock_price() {
    char name[MAX_NAME_LEN];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(portfolio[i].name, name) == 0) {
            printf("Enter new price for %s: ", portfolio[i].name);
            scanf("%f", &portfolio[i].price);
            save_stocks();
            printf("Updated %s to new price: %.2f\n", portfolio[i].name, portfolio[i].price);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void view_portfolio() {
    printf("Your Stock Portfolio:\n");
    printf("---------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Stock Name", "Price", "Quantity");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < stock_count; i++) {
        printf("%-20s %-10.2f %-10d\n", portfolio[i].name, portfolio[i].price, portfolio[i].quantity);
    }
}

void display_menu() {
    printf("\nStock Market Tracker Menu:\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Portfolio\n");
    printf("4. Exit\n");
}

int main() {
    load_stocks();
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                update_stock_price();
                break;
            case 3:
                view_portfolio();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}