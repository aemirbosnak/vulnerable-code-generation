//FormAI DATASET v1.0 Category: Stock market tracker ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STOCKS 100
#define MAX_STOCK_NAME_LEN 20

typedef struct{
    char name[MAX_STOCK_NAME_LEN];
    float price;
} Stock;

int numStocks = 0;
Stock stocks[MAX_STOCKS];
float totalValue = 0;

void addStock(char name[MAX_STOCK_NAME_LEN], float price){
    if(numStocks >= MAX_STOCKS){
        printf("Maximum number of stocks reached!\n");
        return;
    }
    strcpy(stocks[numStocks].name, name);
    stocks[numStocks].price = price;
    numStocks++;
}

void removeStock(char name[MAX_STOCK_NAME_LEN]){
    for(int i=0; i<numStocks; i++){
        if(strcmp(stocks[i].name, name) == 0){
            for(int j=i; j<numStocks-1; j++){
                strcpy(stocks[j].name, stocks[j+1].name);
                stocks[j].price = stocks[j+1].price;
            }
            numStocks--;
            printf("Successfully removed stock %s\n", name);
            return;
        }
    }
    printf("Unable to find stock %s\n", name);
}

void printStocks(){
    printf("Stock Portfolio:\n");
    for(int i=0; i<numStocks; i++){
        printf("%s - $%.2f\n", stocks[i].name, stocks[i].price);
        totalValue += stocks[i].price;
    }
    printf("Total Portfolio Value: $%.2f\n", totalValue);
}

int main(){
    printf("Welcome to the Stock Market Tracker!\n\n");
    printf("Enter 'A' to add a stock\n");
    printf("Enter 'R' to remove a stock\n");
    printf("Enter 'P' to print your stock portfolio\n");
    printf("Enter 'Q' to quit the program\n\n");

    char choice;
    char name[MAX_STOCK_NAME_LEN];
    float price;
    while(1){
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        if(choice == 'A' || choice == 'a'){
            printf("Enter the stock name: ");
            scanf("%s", name);
            printf("Enter the stock price: ");
            scanf("%f", &price);
            addStock(name, price);
        }
        else if(choice == 'R' || choice == 'r'){
            printf("Enter the stock name: ");
            scanf("%s", name);
            removeStock(name);
        }
        else if(choice == 'P' || choice == 'p'){
            printStocks();
            totalValue = 0;
        }
        else if(choice == 'Q' || choice == 'q'){
            printf("Goodbye!\n");
            break;
        }
        else{
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}