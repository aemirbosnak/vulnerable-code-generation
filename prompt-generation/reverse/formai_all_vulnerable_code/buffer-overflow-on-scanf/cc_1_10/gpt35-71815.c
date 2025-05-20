//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STOCKS 1000
#define MAX_NAME_LENGTH 100
#define MAX_INVESTOR_NAME_LENGTH 50

typedef struct StockInfo{
    char name[MAX_NAME_LENGTH];
    float price;
    float dividend;
    float earnings;
}StockInfo;

typedef struct Investor{
    char name[MAX_INVESTOR_NAME_LENGTH];
    int stocks_bought[MAX_STOCKS];
    float invested[MAX_STOCKS];
    int num_stocks;
    float balance;
}Investor;

int n_stocks = 0;
StockInfo stocks[MAX_STOCKS];

int n_investors = 0;
Investor investors[MAX_STOCKS];

void display_menu(){
    printf("Welcome to the stock market tracker!\n");
    printf("1. Add stock\n");
    printf("2. Add investor\n");
    printf("3. Buy stock\n");
    printf("4. Sell stock\n");
    printf("5. Display stocks\n");
    printf("6. Display investors\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void add_stock(){
    if(n_stocks == MAX_STOCKS){
        printf("Sorry, maximum stocks reached.\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[n_stocks].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[n_stocks].price);
    printf("Enter stock dividend: ");
    scanf("%f", &stocks[n_stocks].dividend);
    printf("Enter stock earnings: ");
    scanf("%f", &stocks[n_stocks].earnings);
    n_stocks++;
    printf("Stock added successfully!\n");
}

void add_investor(){
    if(n_investors == MAX_STOCKS){
        printf("Sorry, maximum investors reached.\n");
        return;
    }
    printf("Enter investor name: ");
    scanf("%s", investors[n_investors].name);
    printf("Enter investor balance: ");
    scanf("%f", &investors[n_investors].balance);
    investors[n_investors].num_stocks = 0;
    memset(investors[n_investors].stocks_bought, -1, sizeof(investors[n_investors].stocks_bought));
    memset(investors[n_investors].invested, 0, sizeof(investors[n_investors].invested));
    n_investors++;
    printf("Investor added successfully!\n");
}

void buy_stock(){
    char investor_name[MAX_INVESTOR_NAME_LENGTH];
    char stock_name[MAX_NAME_LENGTH];
    float investment;
    int stock_index = -1;
    int investor_index = -1;
    int i, j;
    printf("Enter investor name: ");
    scanf("%s", investor_name);
    for(i = 0; i < n_investors; i++){
        if(strcmp(investors[i].name, investor_name) == 0){
            investor_index = i;
            break;
        }
    }
    if(investor_index == -1){
        printf("Investor not found.\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stock_name);
    for(i = 0; i < n_stocks; i++){
        if(strcmp(stocks[i].name, stock_name) == 0){
            stock_index = i;
            break;
        }
    }
    if(stock_index == -1){
        printf("Stock not found.\n");
        return;
    }
    printf("Enter investment amount: ");
    scanf("%f", &investment);
    if(investment > investors[investor_index].balance){
        printf("Sorry, balance is insufficient.\n");
        return;
    }
    float num_stocks_float = investment / stocks[stock_index].price;
    int num_stocks = (int)(num_stocks_float);
    if(num_stocks == 0){
        printf("Sorry, investment is too low.\n");
        return;
    }
    if(num_stocks + investors[investor_index].num_stocks > MAX_STOCKS){
        printf("Sorry, maximum stocks per investor is %d\n", MAX_STOCKS);
        return;
    }
    investors[investor_index].balance -= investment;
    investors[investor_index].num_stocks += num_stocks;
    for(i = 0; i < num_stocks; i++){
        for(j = 0; j < MAX_STOCKS; j++){
            if(investors[investor_index].stocks_bought[j] == -1){
                investors[investor_index].stocks_bought[j] = stock_index;
                investors[investor_index].invested[j] = stocks[stock_index].price;
                break;
            }
        }
    }
    printf("Stock purchased successfully!\n");
}

void sell_stock(){
    char investor_name[MAX_INVESTOR_NAME_LENGTH];
    char stock_name[MAX_NAME_LENGTH];
    float investment;
    int stock_index = -1;
    int investor_index = -1;
    int i, j;
    printf("Enter investor name: ");
    scanf("%s", investor_name);
    for(i = 0; i < n_investors; i++){
        if(strcmp(investors[i].name, investor_name) == 0){
            investor_index = i;
            break;
        }
    }
    if(investor_index == -1){
        printf("Investor not found.\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stock_name);
    for(i = 0; i < n_stocks; i++){
        if(strcmp(stocks[i].name, stock_name) == 0){
            stock_index = i;
            break;
        }
    }
    if(stock_index == -1){
        printf("Stock not found.\n");
        return;
    }
    printf("Enter investment amount: ");
    scanf("%f", &investment);
    if(investment > investors[investor_index].invested[stock_index]){
        printf("Sorry, cannot sell more stocks than bought.\n");
        return;
    }
    int num_stocks = (int)(investment / investors[investor_index].invested[stock_index]);
    if(num_stocks == 0){
        printf("Sorry, investment is too low.\n");
        return;
    }
    investors[investor_index].balance += investment;
    investors[investor_index].num_stocks -= num_stocks;
    for(i = 0; i < num_stocks; i++){
        for(j = 0; j < MAX_STOCKS; j++){
            if(investors[investor_index].stocks_bought[j] == stock_index){
                investors[investor_index].stocks_bought[j] = -1;
                investors[investor_index].invested[j] = 0;
                break;
            }
        }
    }
    printf("Stock sold successfully!\n");
}

void display_stocks(){
    int i;
    printf("Stocks:\n");
    for(i = 0; i < n_stocks; i++){
        printf("%s: price=%.2f, dividend=%.2f, earnings=%.2f\n", stocks[i].name, stocks[i].price, stocks[i].dividend, stocks[i].earnings);
    }
}

void display_investors(){
    int i, j;
    printf("Investors:\n");
    for(i = 0; i < n_investors; i++){
        printf("%s: balance=%.2f, stocks_bought=[", investors[i].name, investors[i].balance);
        for(j = 0; j < MAX_STOCKS; j++){
            if(investors[i].stocks_bought[j] != -1){
                printf("%s,", stocks[investors[i].stocks_bought[j]].name);
            }
        }
        printf("]\n");
    }
}

int main(){
    int choice;
    do{
        display_menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_stock();
                break;
            case 2:
                add_investor();
                break;
            case 3:
                buy_stock();
                break;
            case 4:
                sell_stock();
                break;
            case 5:
                display_stocks();
                break;
            case 6:
                display_investors();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }while(choice != 7);
    return 0;
}