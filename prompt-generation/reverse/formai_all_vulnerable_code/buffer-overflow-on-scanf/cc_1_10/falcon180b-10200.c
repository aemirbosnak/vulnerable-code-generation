//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SYMBOLS 100
#define MAX_HISTORY 1000

typedef struct {
    char symbol[10];
    double price;
    time_t timestamp;
} History;

void add_history(History *history, int *size, char *symbol, double price) {
    if (*size >= MAX_HISTORY) {
        printf("Error: History is full\n");
        return;
    }
    strcpy(history[*size].symbol, symbol);
    history[*size].price = price;
    history[*size].timestamp = time(NULL);
    (*size)++;
}

void print_history(History *history, int size) {
    printf("History for %s:\n", history[0].symbol);
    for (int i = 0; i < size; i++) {
        printf("%s %.2f %s\n", ctime(&history[i].timestamp), history[i].price, history[i].symbol);
    }
}

int main() {
    char symbol[10];
    double price;
    int size = 0;
    History history[MAX_HISTORY];

    printf("Welcome to the Stock Market Tracker!\n");
    while (1) {
        printf("Enter a stock symbol (or type 'history' to view history): ");
        scanf("%s", symbol);

        if (strcmp(symbol, "history") == 0) {
            print_history(history, size);
        } else {
            if (size >= MAX_HISTORY) {
                printf("Error: History is full\n");
            } else {
                add_history(history, &size, symbol, 0.0);
            }
        }
    }

    return 0;
}