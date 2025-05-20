//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} Stock;

int main() {
    int numStocks;
    scanf("%d", &numStocks);

    Stock stocks[MAX_STOCKS];
    int i = 0;

    for (i = 0; i < numStocks; i++) {
        scanf("%s %lf", stocks[i].name, &stocks[i].price);
        stocks[i].name[strcspn(stocks[i].name, "\n")] = '\0'; // Remove newline character from name
    }

    char searchName[MAX_NAME_LENGTH];
    double searchPrice;

    while (1) {
        printf("Enter a stock name to search for or type 'exit' to quit: ");
        scanf("%s", searchName);

        if (strcmp(searchName, "exit") == 0) {
            break;
        }

        int found = 0;
        for (i = 0; i < numStocks; i++) {
            if (strcmp(stocks[i].name, searchName) == 0) {
                printf("Stock found:\n");
                printf("Name: %s\n", stocks[i].name);
                printf("Price: $%.2f\n", stocks[i].price);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Stock not found.\n");
        }
    }

    return 0;
}