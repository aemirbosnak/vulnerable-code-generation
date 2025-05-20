//FormAI DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stock {
    char symbol[10];
    char name[50];
    float price;
};

void displayMenu();
void displayStock(struct stock s);
void displayAllStocks(struct stock s[], int count);
int searchStock(struct stock s[], int count, char curSymbol[]);
void addStock(struct stock s[], int *count);
void deleteStock(struct stock s[], int *count);
void updatePrice(struct stock s[], int count);

int main() {
    struct stock stocks[100];
    int count = 0;
    int selection;
    
    do {
        displayMenu();
        scanf("%d", &selection);
        switch(selection) {
            case 1: //Add stock
                addStock(stocks, &count);
                break;
            case 2: //Delete stock
                deleteStock(stocks, &count);
                break;
            case 3: //Update stock price
                updatePrice(stocks, count);
                break;
            case 4: //Display stock
                printf("Enter stock symbol: ");
                char curSymbol[10];
                scanf("%s", curSymbol);
                int index = searchStock(stocks, count, curSymbol);
                if(index == -1) {
                    printf("\nStock not found! \n");
                } else {
                    displayStock(stocks[index]);
                }
                break;
            case 5: //Display all stocks
                displayAllStocks(stocks, count);
                break;
            case 6: //Exit
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid Input! Please try again.\n");
        }
    } while(selection != 6);
    
    return 0;
}

void displayMenu() {
    printf("\nWelcome to the Stock Market Tracker!\n");
    printf("Please select from the following options:\n");
    printf("1. Add Stock\n");
    printf("2. Delete Stock\n");
    printf("3. Update Stock Price\n");
    printf("4. Display Stock\n");
    printf("5. Display All Stocks\n");
    printf("6. Exit\n");
    printf("Selection: ");
}

void displayStock(struct stock s) {
    printf("\nSymbol: %s\n", s.symbol);
    printf("Name: %s\n", s.name);
    printf("Price: $%.2f\n", s.price);
}

void displayAllStocks(struct stock s[], int count) {
    if(count == 0) {
        printf("\nNo stocks added yet!\n");
    } else {
        printf("\nAll Stocks: \n");
        for(int i=0; i<count; i++) {
            displayStock(s[i]);
        }
    }
}

int searchStock(struct stock s[], int count, char curSymbol[]) {
    int index = -1;
    for(int i=0; i<count; i++) {
        if(strcmp(s[i].symbol, curSymbol) == 0) {
            index = i;
            break;
        }
    }
    return index;
}

void addStock(struct stock s[], int *count) {
    printf("\nEnter stock symbol: ");
    scanf("%s", s[*count].symbol);
    printf("Enter stock name: ");
    scanf("%s", s[*count].name);
    printf("Enter stock price: $");
    scanf("%f", &s[*count].price);
    (*count)++;
    printf("\nStock added successfully!\n");
}

void deleteStock(struct stock s[], int *count) {
    printf("\nEnter stock symbol: ");
    char curSymbol[10];
    scanf("%s", curSymbol);
    int index = searchStock(s, *count, curSymbol);
    if(index == -1) {
        printf("\nStock not found! \n");
    } else {
        for(int i=index; i<*count-1; i++) {
            s[i] = s[i+1];
        }
        (*count)--;
        printf("\nStock deleted successfully!\n");
    }
}

void updatePrice(struct stock s[], int count) {
    printf("\nEnter stock symbol: ");
    char curSymbol[10];
    scanf("%s", curSymbol);
    int index = searchStock(s, count, curSymbol);
    if(index == -1) {
        printf("\nStock not found! \n");
    } else {
        printf("Enter new stock price: $");
        scanf("%f", &s[index].price);
        printf("\nPrice updated successfully!\n");
    }
}