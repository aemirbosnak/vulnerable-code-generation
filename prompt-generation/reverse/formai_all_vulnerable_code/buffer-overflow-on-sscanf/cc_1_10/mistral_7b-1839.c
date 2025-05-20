//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[5];
    float price;
} Stock;

#define MAX_STOCKS 100

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(const char *symbol, float price) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Cannot add more than %d stocks.\n", MAX_STOCKS);
        return;
    }
    strcpy(stocks[num_stocks].symbol, symbol);
    stocks[num_stocks].price = price;
    num_stocks++;
}

void remove_stock(const char *symbol) {
    int i;
    for (i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            memmove(&stocks[i], &stocks[i + 1], sizeof(Stock) * (num_stocks - i - 1));
            num_stocks--;
            return;
        }
    }
    printf("Error: Stock %s not found.\n", symbol);
}

void print_stocks() {
    int i;
    for (i = 0; i < num_stocks; i++) {
        printf("%s: %.2f\n", stocks[i].symbol, stocks[i].price);
    }
}

int main() {
    char command[20];
    char symbol[5];
    float price;

    while (1) {
        printf("Enter command (add <symbol> <price> | remove <symbol> | print | quit): ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';
        sscanf(command, "add %s %f", symbol, &price);
        if (strcmp(command, "add") == 0) {
            add_stock(symbol, price);
        } else if (strcmp(command, "remove") == 0) {
            sscanf(command + strlen("remove ") + 1, "%s", symbol);
            remove_stock(symbol);
        } else if (strcmp(command, "print") == 0) {
            print_stocks();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}