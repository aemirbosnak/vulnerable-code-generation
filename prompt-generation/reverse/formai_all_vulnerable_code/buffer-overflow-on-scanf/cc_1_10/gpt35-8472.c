//FormAI DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

struct stock{
    char symbol[10];
    float price;
};

void display_menu(){
    printf("\n1. Add new stock\n");
    printf("2. Remove a stock\n");
    printf("3. Update stock price\n");
    printf("4. Display all stocks\n");
    printf("5. Display stock details by symbol\n");
    printf("6. Exit\n");
    printf("\nEnter your choice (1-6): ");
}

int find_stock_by_symbol(struct stock s[], char symbol[], int num_of_stocks){
    for(int i=0; i<num_of_stocks; i++){
        if(strcmp(s[i].symbol, symbol) == 0){
            return i;
        }
    }
    return -1;
}

void add_new_stock(struct stock s[], int *num_of_stocks){
    if(*num_of_stocks == MAX_STOCKS){
        printf("\nSorry, maximum number of stocks reached. Cannot add new stocks.\n");
        return;
    }

    char symbol[10];
    float price;

    printf("\nEnter symbol of the stock: ");
    scanf("%s", symbol);

    if(find_stock_by_symbol(s, symbol, *num_of_stocks) != -1){
        printf("\nThis stock already exists.\n");
        return;
    }

    printf("Enter the current price of the stock: ");
    scanf("%f", &price);

    strcpy(s[*num_of_stocks].symbol, symbol);
    s[*num_of_stocks].price = price;

    (*num_of_stocks)++;
    printf("\nNew stock added successfully.\n");
}

void remove_stock(struct stock s[], int *num_of_stocks){
    char symbol[10];

    printf("\nEnter symbol of the stock to be removed: ");
    scanf("%s", symbol);

    int pos = find_stock_by_symbol(s, symbol, *num_of_stocks);
    if(pos == -1){
        printf("\nThis stock does not exist.\n");
        return;
    }

    for(int i=pos; i<(*num_of_stocks)-1; i++){
        strcpy(s[i].symbol, s[i+1].symbol);
        s[i].price = s[i+1].price;
    }
    (*num_of_stocks)--;
    printf("\nStock removed successfully.\n");
}

void update_stock_price(struct stock s[], int num_of_stocks){
    char symbol[10];
    float price;

    printf("\nEnter symbol of the stock to be updated: ");
    scanf("%s", symbol);

    int pos = find_stock_by_symbol(s, symbol, num_of_stocks);
    if(pos == -1){
        printf("\nThis stock does not exist.\n");
        return;
    }

    printf("Enter the new price of the stock: ");
    scanf("%f", &price);

    s[pos].price = price;

    printf("\nStock price updated successfully.\n");
}

void display_all_stocks(struct stock s[], int num_of_stocks){
    printf("\nSymbol\tPrice\n");
    for(int i=0; i<num_of_stocks; i++){
        printf("%s\t%.2f\n", s[i].symbol, s[i].price);
    }
}

void display_stock_details(struct stock s[], int num_of_stocks){
    char symbol[10];

    printf("\nEnter symbol of the stock to be displayed: ");
    scanf("%s", symbol);

    int pos = find_stock_by_symbol(s, symbol, num_of_stocks);
    if(pos == -1){
        printf("\nThis stock does not exist.\n");
        return;
    }

    printf("\nSymbol\tPrice\n");
    printf("%s\t%.2f\n", s[pos].symbol, s[pos].price);
}

int main(){
    struct stock stocks[MAX_STOCKS];
    int num_of_stocks = 0;

    int choice;
    do{
        display_menu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_new_stock(stocks, &num_of_stocks);
                break;
            case 2:
                remove_stock(stocks, &num_of_stocks);
                break;
            case 3:
                update_stock_price(stocks, num_of_stocks);
                break;
            case 4:
                display_all_stocks(stocks, num_of_stocks);
                break;
            case 5:
                display_stock_details(stocks, num_of_stocks);
                break;
            case 6:
                printf("\nThank you for using the Stock Market Tracker!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice (1-6).\n");
                break;
        }

    }while(choice != 6);

    return 0;
}