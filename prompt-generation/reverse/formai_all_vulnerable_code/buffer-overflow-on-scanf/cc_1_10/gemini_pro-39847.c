//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: futuristic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stock_node {
    char *symbol;
    double price;
    struct stock_node *next;
} stock_node;

typedef struct stock_list {
    struct stock_node *head;
    struct stock_node *tail;
} stock_list;

void print_stock_list(stock_list *list) {
    stock_node *current = list->head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->symbol, current->price);
        current = current->next;
    }
}

int main() {
    stock_list *list = malloc(sizeof(stock_list));
    list->head = NULL;
    list->tail = NULL;

    int num_stocks;
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        stock_node *new_node = malloc(sizeof(stock_node));
        new_node->next = NULL;

        char *symbol = malloc(20);
        printf("Enter the stock symbol: ");
        scanf("%s", symbol);
        new_node->symbol = symbol;

        double price;
        printf("Enter the current price: ");
        scanf("%lf", &price);
        new_node->price = price;

        if (list->head == NULL) {
            list->head = new_node;
        } else {
            list->tail->next = new_node;
        }

        list->tail = new_node;
    }

    printf("\nCurrent Stock Prices:\n");
    print_stock_list(list);

    return 0;
}