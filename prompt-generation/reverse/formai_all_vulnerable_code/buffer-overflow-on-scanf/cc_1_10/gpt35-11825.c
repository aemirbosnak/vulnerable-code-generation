//FormAI DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    float price;
    float percent_change;
} stock;

stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock() {
    if(num_stocks >= MAX_STOCKS) {
        printf("Maximum number of stocks reached\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[num_stocks].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[num_stocks].price);
    printf("Enter percent change: ");
    scanf("%f", &stocks[num_stocks].percent_change);
    stocks[num_stocks].id = num_stocks + 1;
    num_stocks++;
    printf("Stock added successfully!\n");
}

void print_stock_info(stock s) {
    printf("%d. %s - $%.2f (%.2f%%)\n", s.id, s.name, s.price, s.percent_change);
}

void view_stocks() {
    printf("Stocks:\n");
    for(int i=0; i<num_stocks; i++) {
        print_stock_info(stocks[i]);
    }
}

void update_stock() {
    int id;
    printf("Enter stock ID: ");
    scanf("%d", &id);
    if(id > num_stocks || id <= 0) {
        printf("Invalid stock ID\n");
        return;
    }
    stock *s = &stocks[id-1];
    printf("Updating stock:\n");
    print_stock_info(*s);
    printf("Enter new stock name (press enter to skip): ");
    char name[MAX_NAME_LEN];
    fgets(name, MAX_NAME_LEN, stdin);
    if(strlen(name) > 1) { // not just newline character
        strcpy(s->name, name);
    }
    printf("Enter new stock price (press enter to skip): ");
    char price_str[15];
    fgets(price_str, 15, stdin);
    if(strlen(price_str) > 1) {
        sscanf(price_str, "%f", &s->price);
    }
    printf("Enter new percent change (press enter to skip): ");
    char pc_str[15];
    fgets(pc_str, 15, stdin);
    if(strlen(pc_str) > 1) {
        sscanf(pc_str, "%f", &s->percent_change);
    }
    printf("Stock updated successfully!\n");
}

void delete_stock() {
    int id;
    printf("Enter stock ID: ");
    scanf("%d", &id);
    if(id > num_stocks || id <= 0) {
        printf("Invalid stock ID\n");
        return;
    }
    for(int i=id-1; i<num_stocks-1; i++) {
        stocks[i] = stocks[i+1];
        stocks[i].id = i+1;
    }
    num_stocks--;
    printf("Stock deleted successfully!\n");
}

int main() {
    printf("Welcome to the paranoid stock market tracker\n");
    char choice;
    do {
        printf("Options:\n");
        printf("1. Add stock\n");
        printf("2. View stocks\n");
        printf("3. Update stock\n");
        printf("4. Delete stock\n");
        printf("5. Quit\n");
        printf("Enter choice (1-5): ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1': // Add stock
                add_stock();
                break;
            case '2': // View stocks
                view_stocks();
                break;
            case '3': // Update stock
                update_stock();
                break;
            case '4': // Delete stock
                delete_stock();
                break;
            case '5': // Quit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(choice != '5');

    return 0;
}