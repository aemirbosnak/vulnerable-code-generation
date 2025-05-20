//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock {
    char symbol[5];
    float price;
    struct Stock *next;
} Stock;

void get_latest_price(Stock **head, char symbol[5]);
void print_stock_list(Stock *head);

void get_latest_price(Stock **head, char symbol[5]) {
    Stock *current = *head;

    if (*head == NULL) {
        printf("No stocks found.\n");
        return;
    }

    while (current != NULL) {
        if (strcmp(current->symbol, symbol) == 0) {
            printf("The latest price for %s is %.2f\n", symbol, current->price);
            return;
        }
        current = current->next;
    }

    printf("Stock %s not found in the list.\n", symbol);

    Stock *new_stock = (Stock *)malloc(sizeof(Stock));
    strcpy(new_stock->symbol, symbol);

    printf("Enter the latest price for %s: ", symbol);
    scanf("%f", &new_stock->price);

    new_stock->next = *head;
    *head = new_stock;

    get_latest_price(head, symbol);
}

void print_stock_list(Stock *head) {
    Stock *current = head;

    if (head == NULL) {
        printf("No stocks found.\n");
        return;
    }

    printf("\nCurrent Stock Prices:\n");

    while (current != NULL) {
        printf("%s\t%.2f\n", current->symbol, current->price);
        current = current->next;
    }
}

int main() {
    Stock *head = NULL;

    while (1) {
        char symbol[5];
        printf("\nEnter the symbol of the stock or type 'quit' to exit: ");
        scanf("%s", symbol);

        if (strcmp(symbol, "quit") == 0) {
            break;
        }

        get_latest_price(&head, symbol);
    }

    print_stock_list(head);

    Stock *current = head;
    while (current != NULL) {
        Stock *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}