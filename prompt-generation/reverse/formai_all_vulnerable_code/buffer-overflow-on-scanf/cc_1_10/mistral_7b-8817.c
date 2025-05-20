//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Stock {
    char symbol[5];
    float price;
    struct Stock *next;
} Stock;

Stock *head = NULL;

void addStock(char *symbol, float price) {
    Stock *newStock = (Stock *)malloc(sizeof(Stock));
    strcpy(newStock->symbol, symbol);
    newStock->price = price;
    newStock->next = head;
    head = newStock;
}

void removeStock(char *symbol) {
    Stock *current = head;
    Stock *previous = NULL;

    while (current != NULL) {
        if (strcasecmp(current->symbol, symbol) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void displayStocks() {
    Stock *current = head;

    printf("Current Stocks:\n");
    while (current != NULL) {
        printf("%s: %.2f\n", current->symbol, current->price);
        current = current->next;
    }
}

int searchStock(char *symbol) {
    Stock *current = head;

    while (current != NULL) {
        if (strcasecmp(current->symbol, symbol) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    char cmd[20], symbol[5];
    float price;

    while (1) {
        printf("Stock Tracker> ");
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            scanf("%s %f", symbol, &price);
            addStock(symbol, price);
        } else if (strcmp(cmd, "remove") == 0) {
            scanf("%s", symbol);
            removeStock(symbol);
        } else if (strcmp(cmd, "display") == 0) {
            displayStocks();
        } else if (strcmp(cmd, "search") == 0) {
            scanf("%s", symbol);
            if (searchStock(symbol) == 1) {
                printf("Stock found!\n");
            } else {
                printf("Stock not found.\n");
            }
        } else if (strcmp(cmd, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}