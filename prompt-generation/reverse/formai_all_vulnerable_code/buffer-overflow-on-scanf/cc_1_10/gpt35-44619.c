//FormAI DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 50

struct stock{
    char name[MAX_NAME_LENGTH];
    int id;
    float price;
};

typedef struct stock stock_t;

void print_menu(){
    printf("\nWelcome to the Stock Market Tracker!\n");
    printf("1. Add a stock to the tracker\n");
    printf("2. Remove a stock from the tracker\n");
    printf("3. View all stocks in the tracker\n");
    printf("4. View the current price of a stock\n");
    printf("5. Update the price of a stock\n");
    printf("6. Quit the program\n\n");
}

int add_stock(stock_t *stocks, int num_stocks){
    if(num_stocks == MAX_STOCKS){
        printf("Cannot add more stocks, reached maximum limit.\n");
        return num_stocks;
    }

    printf("Enter stock name: ");
    scanf("%s", stocks[num_stocks].name);

    printf("Enter stock ID: ");
    scanf("%d", &stocks[num_stocks].id);

    printf("Enter stock price: ");
    scanf("%f", &stocks[num_stocks].price);

    printf("Stock added successfully.\n");

    return num_stocks + 1;
}

int remove_stock(stock_t *stocks, int num_stocks, int stock_id){
    int i, found_stock = 0;

    for(i = 0; i < num_stocks; i++){
        if(stocks[i].id == stock_id){
            found_stock = 1;
            break;
        }
    }

    if(!found_stock){
        printf("Stock with ID %d not found in tracker.\n", stock_id);
        return num_stocks;
    }

    for(; i < num_stocks - 1; i++){
        stocks[i] = stocks[i+1];
    }

    printf("Stock with ID %d removed successfully.\n", stock_id);

    return num_stocks - 1;
}

void view_all_stocks(stock_t *stocks, int num_stocks){
    int i;

    printf("Stocks in tracker:\n");

    for(i = 0; i < num_stocks; i++){
        printf("%s (ID: %d) - Price: %.2f\n", stocks[i].name, stocks[i].id, stocks[i].price);
    }
}

void view_stock_price(stock_t *stocks, int num_stocks, int stock_id){
    int i, found_stock = 0;

    for(i = 0; i < num_stocks; i++){
        if(stocks[i].id == stock_id){
            found_stock = 1;
            break;
        }
    }

    if(!found_stock){
        printf("Stock with ID %d not found in tracker.\n", stock_id);
        return;
    }

    printf("Current price of %s (ID: %d) is: %.2f\n", stocks[i].name, stocks[i].id, stocks[i].price);
}

void update_stock_price(stock_t *stocks, int num_stocks, int stock_id){
    int i, found_stock = 0;

    for(i = 0; i < num_stocks; i++){
        if(stocks[i].id == stock_id){
            found_stock = 1;
            break;
        }
    }

    if(!found_stock){
        printf("Stock with ID %d not found in tracker.\n", stock_id);
        return;
    }

    float new_price;

    printf("Enter new price for %s (ID: %d): ", stocks[i].name, stocks[i].id);
    scanf("%f", &new_price);

    stocks[i].price = new_price;

    printf("Price of %s (ID: %d) updated successfully.\n", stocks[i].name, stocks[i].id);
}

int main(){
    stock_t *stocks = malloc(MAX_STOCKS * sizeof(stock_t));
    int num_stocks = 0, choice, id;

    do{
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                num_stocks = add_stock(stocks, num_stocks);
                break;
            case 2:
                printf("Enter the ID of the stock to remove: ");
                scanf("%d", &id);
                num_stocks = remove_stock(stocks, num_stocks, id);
                break;
            case 3:
                view_all_stocks(stocks, num_stocks);
                break;
            case 4:
                printf("Enter the ID of the stock to view: ");
                scanf("%d", &id);
                view_stock_price(stocks, num_stocks, id);
                break;
            case 5:
                printf("Enter the ID of the stock to update: ");
                scanf("%d", &id);
                update_stock_price(stocks, num_stocks, id);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }while(choice != 6);

    free(stocks);

    return 0;
}