//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>

#define MAX_STOCKS 10
#define MAX_PRICES 100

typedef struct {
    char name[20];
    double prices[MAX_PRICES];
    int index;
} Stock;

void initStock(Stock *s) {
    strcpy(s->name, "Unknown");
    s->index = 0;
    for (int i = 0; i < MAX_PRICES; i++) {
        s->prices[i] = 0.0;
    }
}

void updateStock(Stock *s, double price) {
    s->prices[s->index] = price;
    s->index = (s->index + 1) % MAX_PRICES;
}

void printStock(Stock *s) {
    printf("Name: %s\n", s->name);
    printf("Prices:\n");
    for (int i = 0; i < MAX_PRICES; i++) {
        printf("%lf\n", s->prices[i]);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    while (numStocks < MAX_STOCKS) {
        printf("Enter stock name (or 'done' to finish): ");
        scanf("%s", stocks[numStocks].name);

        if (strcmp(stocks[numStocks].name, "done") == 0) {
            break;
        }

        numStocks++;
    }

    while (1) {
        printf("Enter stock index to update (0-%d): ", numStocks - 1);
        int index;
        scanf("%d", &index);

        if (index >= 0 && index < numStocks) {
            printf("Enter new price: ");
            double price;
            scanf("%lf", &price);

            updateStock(&stocks[index], price);
            printStock(&stocks[index]);
        } else {
            printf("Invalid stock index.\n");
        }
    }

    return 0;
}