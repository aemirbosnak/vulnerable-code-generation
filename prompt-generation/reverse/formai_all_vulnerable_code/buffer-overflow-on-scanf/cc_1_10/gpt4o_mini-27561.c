//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTIONS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    float current_price;
    int total_shares;
} Stock;

typedef struct {
    char stock_name[MAX_NAME_LENGTH];
    int shares;
    float price_per_share;
} Transaction;

Stock stocks[MAX_STOCKS];
Transaction transactions[MAX_TRANSACTIONS];
int stock_count = 0;
int transaction_count = 0;

void add_stock(char *name, float price) {
    strcpy(stocks[stock_count].name, name);
    stocks[stock_count].current_price = price;
    stocks[stock_count].total_shares = 0;
    stock_count++;
}

void update_stock_price(char *name, float new_price) {
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].current_price = new_price;
            printf("Updated price of %s to %.2f\n", name, new_price);
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void record_transaction(char *name, int shares, float price_per_share) {
    strcpy(transactions[transaction_count].stock_name, name);
    transactions[transaction_count].shares = shares;
    transactions[transaction_count].price_per_share = price_per_share;
    transaction_count++;

    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].total_shares += shares;
            printf("Recorded transaction: %d shares of %s at %.2f each\n", shares, name, price_per_share);
            return;
        }
    }
    printf("Stock %s not found to record transaction.\n", name);
}

void print_stock_info() {
    printf("\nStock Information:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < stock_count; i++) {
        printf("Name: %s, Current Price: %.2f, Total Shares Owned: %d\n",
               stocks[i].name, stocks[i].current_price, stocks[i].total_shares);
    }
    printf("--------------------------------------------------\n");
}

void print_transaction_history() {
    printf("\nTransaction History:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < transaction_count; i++) {
        printf("Stock: %s, Shares: %d, Price per Share: %.2f\n",
               transactions[i].stock_name, transactions[i].shares, transactions[i].price_per_share);
    }
    printf("--------------------------------------------------\n");
}

int main() {
    add_stock("Apple", 150.00);
    add_stock("Google", 2800.00);
    add_stock("Amazon", 3300.00);
    
    update_stock_price("Apple", 155.50);
    record_transaction("Apple", 10, 155.50);
    record_transaction("Google", 5, 2800.00);
    
    print_stock_info();
    print_transaction_history();

    float price;
    char stock_name[MAX_NAME_LENGTH];
    
    while (1) {
        printf("Enter stock name to update price (or 'exit' to quit): ");
        scanf("%s", stock_name);
        if (strcmp(stock_name, "exit") == 0) break;
        printf("Enter new price for %s: ", stock_name);
        scanf("%f", &price);
        update_stock_price(stock_name, price);
    }

    return 0;
}