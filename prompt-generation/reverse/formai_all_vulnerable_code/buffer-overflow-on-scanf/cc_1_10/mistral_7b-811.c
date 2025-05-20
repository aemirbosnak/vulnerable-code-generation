//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 50
#define TICKER_LEN 10

typedef struct Stock {
    char ticker[TICKER_LEN + 1];
    float price;
    int qty;
} Stock;

typedef struct Node {
    Stock stock;
    struct Node *next;
} Node;

Node *head = NULL;
int numStocks = 0;

void addStock(char *ticker, float price, int qty) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error! Max stocks reached.\n");
        return;
    }

    strcpy(newNode->stock.ticker, ticker);
    newNode->stock.price = price;
    newNode->stock.qty = qty;
    newNode->next = head;
    head = newNode;
    numStocks++;
}

void removeStock(char *ticker) {
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->stock.ticker, ticker) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            numStocks--;
            break;
        }
        previous = current;
        current = current->next;
    }
}

void viewPortfolio() {
    Node *current = head;
    int total = 0;

    printf("\nPORTFOLIO:\n");
    printf("%-10s %-10s %-10s\n", "Ticker", "Price", "Quantity");

    while (current != NULL) {
        printf("%-10s %-10.2f %-10d\n", current->stock.ticker, current->stock.price, current->stock.qty);
        total += current->stock.price * current->stock.qty;
        current = current->next;
    }

    printf("\nTotal: $%.2f\n", total);
}

int main() {
    char command[20];
    char ticker[TICKER_LEN];
    float price;
    int qty, choice;

    while (1) {
        printf("\nStock Market Tracker\n");
        printf("1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. View portfolio\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ticker: ");
                scanf("%s", ticker);
                ticker[0] = toupper(ticker[0]); // Make first letter capital
                scanf("%f", &price);
                scanf("%d", &qty);
                addStock(ticker, price, qty);
                break;
            case 2:
                printf("Enter ticker: ");
                scanf("%s", ticker);
                removeStock(ticker);
                break;
            case 3:
                viewPortfolio();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}