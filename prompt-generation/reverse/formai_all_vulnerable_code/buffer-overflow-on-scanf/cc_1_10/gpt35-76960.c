//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

typedef struct {
    char name[30];
    double price;
    double change;
} Stock;

void addStock(Stock stocks[], int* numStocks)
{
    if(*numStocks >= MAX_STOCKS){
        printf("Maximum number of stocks reached!\n");
        return;
    }
    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%lf", &newStock.price);
    printf("Enter stock change: ");
    scanf("%lf", &newStock.change);
    stocks[*numStocks] = newStock;
    *numStocks = *numStocks + 1;
    printf("Stock added successfully!\n");
}

void printStocks(Stock stocks[], int numStocks)
{
    printf("%-30s %-15s %-15s\n", "Stock Name", "Price", "Change");
    printf("------------------------------------------------\n");
    for(int i=0;i<numStocks;i++){
        printf("%-30s $%-15.2lf %-+15.2lf%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void updateStock(Stock stocks[], int numStocks)
{
    char stockName[30];
    int found = 0;
    printf("Enter stock name to update: ");
    scanf("%s", stockName);
    for(int i=0;i<numStocks;i++){
        if(strcmp(stocks[i].name, stockName) == 0){
            printf("Enter new price: ");
            scanf("%lf", &stocks[i].price);
            printf("Enter new change: ");
            scanf("%lf", &stocks[i].change);
            printf("Stock updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Stock not found!\n");
    }
}

void searchStock(Stock stocks[], int numStocks)
{
    char stockName[30];
    int found = 0;
    printf("Enter stock name to search: ");
    scanf("%s", stockName);
    for(int i=0;i<numStocks;i++){
        if(strcmp(stocks[i].name, stockName) == 0){
            printf("%-30s $%-15.2lf %-+15.2lf%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Stock not found!\n");
    }
}

int main(void)
{
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    int choice = 0;
    while(choice != 5){
        printf("1. Add Stock\n");
        printf("2. Print All Stocks\n");
        printf("3. Update Stock\n");
        printf("4. Search Stock\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addStock(stocks, &numStocks);
            break;
        case 2:
            printStocks(stocks, numStocks);
            break;
        case 3:
            updateStock(stocks, numStocks);
            break;
        case 4:
            searchStock(stocks, numStocks);
            break;
        case 5:
            printf("Exiting Program.\n");
            break;
        default:
            printf("Invalid Choice!\n");
            break;
        }
    }

    return 0;
}