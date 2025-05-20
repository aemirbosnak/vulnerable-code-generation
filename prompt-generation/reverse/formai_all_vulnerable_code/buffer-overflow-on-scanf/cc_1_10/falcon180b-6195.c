//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME 50
#define MAX_PRICE 20

typedef struct {
    char name[MAX_NAME];
    float price;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks;

void add_stock(char* name, float price) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }
    strcpy(stocks[num_stocks].name, name);
    stocks[num_stocks].price = price;
    num_stocks++;
}

void remove_stock(int index) {
    if (index < 0 || index >= num_stocks) {
        printf("Error: Invalid stock index.\n");
        return;
    }
    num_stocks--;
    for (int i = index; i < num_stocks; i++) {
        strcpy(stocks[i].name, stocks[i+1].name);
        stocks[i].price = stocks[i+1].price;
    }
}

void display_stocks() {
    printf("Name\tPrice\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t%.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    num_stocks = 0;
    char input[100];
    while (1) {
        printf("Enter command (add/remove/display/exit): ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            char name[MAX_NAME];
            float price;
            printf("Enter stock name: ");
            scanf("%s", name);
            printf("Enter stock price: ");
            scanf("%f", &price);
            add_stock(name, price);
        } else if (strcmp(input, "remove") == 0) {
            int index;
            printf("Enter stock index to remove: ");
            scanf("%d", &index);
            remove_stock(index);
        } else if (strcmp(input, "display") == 0) {
            display_stocks();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}