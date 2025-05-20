//FormAI DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STOCKS 50 // maximum stocks to track

struct stock {
    char name[20];
    float price;
    float change;
    float perc_change;
};

struct stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock() {
    if (num_stocks == MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[num_stocks].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[num_stocks].price);
    printf("Enter stock change: ");
    scanf("%f", &stocks[num_stocks].change);
    stocks[num_stocks].perc_change = (stocks[num_stocks].change / stocks[num_stocks].price) * 100;
    num_stocks++;
}

void remove_stock() {
    char name[20];
    printf("Enter stock name to remove: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            int j;
            for (j = i; j < num_stocks - 1; j++) {
                strcpy(stocks[j].name, stocks[j+1].name);
                stocks[j].price = stocks[j+1].price;
                stocks[j].change = stocks[j+1].change;
                stocks[j].perc_change = stocks[j+1].perc_change;
            }
            num_stocks--;
            break;
        }
    }
    if (i == num_stocks) {
        printf("Stock not found.\n");
    }
}

void update_stock() {
    char name[20];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    int found = 0;
    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Enter new stock price: ");
            scanf("%f", &stocks[i].price);
            printf("Enter new stock change: ");
            scanf("%f", &stocks[i].change);
            stocks[i].perc_change = (stocks[i].change / stocks[i].price) * 100;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Stock not found.\n");
    }
}

void print_stock(struct stock s) {
    printf("%-20s $%-10.2f $%-10.2f (%.2f%%)\n", s.name, s.price, s.change, s.perc_change);
}

void print_stocks() {
    int i;
    for (i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }
}

void menu() {
    printf("Stock Market Tracker\n");
    printf("1. Add stock\n");
    printf("2. Remove stock\n");
    printf("3. Update stock\n");
    printf("4. Print stocks\n");
    printf("5. Exit\n");
}

int main() {
    int option;
    do {
        menu();
        printf("Enter an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_stock();
                break;
            case 2:
                remove_stock();
                break;
            case 3:
                update_stock();
                break;
            case 4:
                print_stocks();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 5);
    return 0;
}