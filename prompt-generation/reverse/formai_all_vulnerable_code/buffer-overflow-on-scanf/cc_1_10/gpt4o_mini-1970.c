//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30
#define PRICE_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    float price;
} Stock;

Stock stocks[MAX_STOCKS];
int stock_count = 0;

// Function declarations
void loadStocks();
void saveStocks();
void addStock(const char *name, float price);
void updateStock(const char *name, float new_price);
void viewStocks();
void clearBuffer();

int main() {
    int choice;
    char name[NAME_LENGTH];
    float price;

    loadStocks();

    do {
        printf("\nStock Market Tracker Menu\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. View Stocks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter stock price: ");
                scanf("%f", &price);
                addStock(name, price);
                break;
            case 2:
                printf("Enter stock name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter new stock price: ");
                scanf("%f", &price);
                updateStock(name, price);
                break;
            case 3:
                viewStocks();
                break;
            case 4:
                saveStocks();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void loadStocks() {
    FILE *file = fopen("stocks.txt", "r");
    if (!file) {
        return; // File doesn't exist, no stocks to load
    }
    while (fscanf(file, "%s %f", stocks[stock_count].name, &stocks[stock_count].price) != EOF) {
        stock_count++;
    }
    fclose(file);
}

void saveStocks() {
    FILE *file = fopen("stocks.txt", "w");
    if (!file) {
        printf("Error saving stocks to file.\n");
        return;
    }
    for (int i = 0; i < stock_count; i++) {
        fprintf(file, "%s %.2f\n", stocks[i].name, stocks[i].price);
    }
    fclose(file);
}

void addStock(const char *name, float price) {
    if (stock_count >= MAX_STOCKS) {
        printf("Stock list is full. Cannot add more stocks.\n");
        return;
    }
    strcpy(stocks[stock_count].name, name);
    stocks[stock_count].price = price;
    stock_count++;
    printf("Stock added successfully.\n");
}

void updateStock(const char *name, float new_price) {
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price = new_price;
            printf("Stock price updated successfully.\n");
            return;
        }
    }
    printf("Stock not found.\n");
}

void viewStocks() {
    if (stock_count == 0) {
        printf("No stocks available.\n");
        return;
    }
    printf("\nAvailable Stocks:\n");
    for (int i = 0; i < stock_count; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}