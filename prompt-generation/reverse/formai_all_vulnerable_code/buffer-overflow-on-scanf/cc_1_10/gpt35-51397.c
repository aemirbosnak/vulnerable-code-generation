//FormAI DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

typedef struct {
    char name[20];
    float price;
} Stock;

Stock stocks[MAX_STOCKS];
int count = 0;

void addStock() {
    char name[20];
    float price;
    
    printf("Enter stock name: ");
    scanf("%s", name);
    
    printf("Enter stock price: ");
    scanf("%f", &price);
    
    strcpy(stocks[count].name, name);
    stocks[count].price = price;
    
    count++;
}

void printStocks() {
    printf("\nSTOCKS\n");
    printf("------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    int choice;
    
    printf("STOCK MARKET TRACKER\n");
    printf("--------------------\n");
    
    do {
        printf("\n1. Add stock\n");
        printf("2. Print stocks\n");
        printf("3. Exit\n");
        
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStock();
                break;
            
            case 2:
                printStocks();
                break;
            
            case 3:
                printf("\nExiting program...\n");
                break;
            
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}