//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Stock;

void display_menu();
void display_stocks(Stock stocks[], int n);
void update_stocks(Stock stocks[], int n);
void buy_stock(Stock stocks[], int n);
void sell_stock(Stock stocks[], int n);
void exit_program();

int main() {
    Stock stocks[MAX_STOCKS];
    int n = 0;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_stocks(stocks, n);
                break;
            case 2:
                update_stocks(stocks, n);
                break;
            case 3:
                buy_stock(stocks, n);
                break;
            case 4:
                sell_stock(stocks, n);
                break;
            case 5:
                exit_program();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

void display_menu() {
    printf("Welcome to the stock market tracker\n");
    printf("1. Display stocks\n");
    printf("2. Update stocks\n");
    printf("3. Buy stock\n");
    printf("4. Sell stock\n");
    printf("5. Exit program\n");
    printf("Enter your choice: ");
}

void display_stocks(Stock stocks[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

void update_stocks(Stock stocks[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        stocks[i].price += (rand() % 10 - 5) / 100.0;
    }
}

void buy_stock(Stock stocks[], int n) {
    char name[50];
    float price;
    int quantity;
    printf("Enter stock name: ");
    scanf("%s", name);
    printf("Enter stock price: ");
    scanf("%f", &price);
    printf("Enter stock quantity: ");
    scanf("%d", &quantity);
    for (int i = 0; i < n; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price = price;
            stocks[i].quantity += quantity;
            break;
        }
    }
}

void sell_stock(Stock stocks[], int n) {
    char name[50];
    float price;
    int quantity;
    printf("Enter stock name: ");
    scanf("%s", name);
    printf("Enter stock price: ");
    scanf("%f", &price);
    printf("Enter stock quantity: ");
    scanf("%d", &quantity);
    for (int i = 0; i < n; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price = price;
            stocks[i].quantity -= quantity;
            break;
        }
    }
}

void exit_program() {
    printf("Thank you for using the stock market tracker\n");
    exit(0);
}