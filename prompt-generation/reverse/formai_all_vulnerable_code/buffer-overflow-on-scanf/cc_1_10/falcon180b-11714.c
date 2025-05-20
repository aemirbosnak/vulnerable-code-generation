//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE 1000

typedef struct{
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
}Stock;

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(){
    if(num_stocks == MAX_STOCKS){
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[num_stocks].name);
    printf("Enter stock symbol: ");
    scanf("%s", stocks[num_stocks].symbol);
    printf("Enter stock price: ");
    scanf("%lf", &stocks[num_stocks].price);
    printf("Enter stock quantity: ");
    scanf("%d", &stocks[num_stocks].quantity);
    num_stocks++;
    printf("Stock added successfully.\n");
}

void remove_stock(){
    if(num_stocks == 0){
        printf("Error: No stocks available.\n");
        return;
    }
    int choice;
    printf("Enter stock to remove: ");
    for(int i=0; i<num_stocks; i++){
        printf("%d. %s (%s)\n", i+1, stocks[i].name, stocks[i].symbol);
    }
    scanf("%d", &choice);
    printf("Removing stock %s...\n", stocks[choice-1].name);
    num_stocks--;
}

void update_stock(){
    if(num_stocks == 0){
        printf("Error: No stocks available.\n");
        return;
    }
    int choice;
    printf("Enter stock to update: ");
    for(int i=0; i<num_stocks; i++){
        printf("%d. %s (%s)\n", i+1, stocks[i].name, stocks[i].symbol);
    }
    scanf("%d", &choice);
    printf("Updating stock %s...\n", stocks[choice-1].name);
    printf("Enter new stock price: ");
    scanf("%lf", &stocks[choice-1].price);
    printf("Stock updated successfully.\n");
}

void view_stocks(){
    if(num_stocks == 0){
        printf("No stocks available.\n");
        return;
    }
    printf("ID\tName\tSymbol\tPrice\tQuantity\n");
    for(int i=0; i<num_stocks; i++){
        printf("%d\t%s\t%s\t%.2f\t%d\n", i+1, stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

int main(){
    int choice;
    while(true){
        printf("1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. Update stock\n");
        printf("4. View stocks\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_stock();
                break;
            case 2:
                remove_stock();
                break;
            case 3:
                update_stock();
                break;
            case 4:
                view_stocks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}