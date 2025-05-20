//FormAI DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_STOCKS 10
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
    float price;
    float change;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks = 0;

void addStock() {
    if(numStocks == MAX_STOCKS) {
        printf("Maximum limit reached!");
        return;
    }

    Stock newStock;

    printf("Enter stock name: ");
    scanf("%s", newStock.name);

    printf("Enter opening price: ");
    scanf("%f", &newStock.price);

    printf("Enter change percentage: ");
    scanf("%f", &newStock.change);

    stocks[numStocks] = newStock;
    numStocks++;

    printf("Stock added successfully!");
}

void removeStock() {
    char name[MAX_NAME];
    printf("Enter stock name to remove: ");
    scanf("%s", name);

    int i, found = 0;
    for(i = 0; i < numStocks; i++) {
        if(strcmp(stocks[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Stock not found!");
        return;
    }

    int j;
    for(j = i; j < numStocks - 1; j++) {
        stocks[j] = stocks[j+1];
    }
    numStocks--;

    printf("Stock removed successfully!");
}

void showStocks() {
    if(numStocks == 0) {
        printf("No stocks to show!");
        return;
    }

    printf("Name\tPrice\tChange\n");
    int i;
    for(i = 0; i < numStocks; i++) {
        printf("%s\t%.2f\t%.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void updateStocks() {
    srand(time(NULL));

    int i;
    for(i = 0; i < numStocks; i++) {
        // randomly change price by +/- 5%
        float change = (float)rand() / (float)(RAND_MAX/10.0f) - 5.0f;
        stocks[i].price += (stocks[i].price * change / 100.0f);

        // update change percentage
        stocks[i].change = ((stocks[i].price - stocks[i].change) / stocks[i].price) * 100.0f;
    }

    printf("Stocks updated successfully!");
}

int main() {
    int choice;

    do {
        printf("\n\n");
        printf("1. Add a stock\n");
        printf("2. Remove a stock\n");
        printf("3. Show all stocks\n");
        printf("4. Update stocks\n");
        printf("5. Exit\n");
        printf("\nEnter choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStock();
                break;
            case 2:
                removeStock();
                break;
            case 3:
                showStocks();
                break;
            case 4:
                updateStocks();
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Invalid choice!");
                break;
        }
    } while(1);

    return 0;
}