//FormAI DATASET v1.0 Category: Stock market tracker ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// declare struct for stock information
struct stockInfo{
    int stockID;
    char stockName[20];
    float stockPrice;
    int stockQuantity;
};

// function for generating random stock information
void generateStockInfo(struct stockInfo *stocks, int numStocks){
    char stockNames[5][20]={"Apple Inc.","Microsoft","Amazon","Tesla","Facebook"};
    float minPrice=10.00, maxPrice=5000.00;
    int minQuantity=100, maxQuantity=1000;
    
    srand(time(NULL)); //set seed value based on current time
    
    // generate random stock information
    for(int i=0; i<numStocks; i++){
        stocks[i].stockID=i+1;
        strcpy(stocks[i].stockName,stockNames[rand()%5]);
        stocks[i].stockPrice=((float)rand()/(float)(RAND_MAX))*(maxPrice-minPrice)+minPrice;
        stocks[i].stockQuantity=rand()%(maxQuantity-minQuantity+1)+minQuantity;
    }
}

// function for displaying stock information
void displayStockInfo(struct stockInfo *stocks, int numStocks){
    printf("StockID\t| Stock Name\t\t| Price\t\t| Quantity\t\n");
    printf("------------------------------------------------------\n");
    for(int i=0; i<numStocks; i++){
        printf("%d\t| %-20s| $%.2f\t| %d\t\t\n", stocks[i].stockID, stocks[i].stockName, stocks[i].stockPrice, stocks[i].stockQuantity);
    }
}

// function for updating stock price
void updateStockPrice(struct stockInfo *stocks, int numStocks, int stockID, float newPrice){
    for(int i=0; i<numStocks; i++){
        if(stocks[i].stockID==stockID){
            stocks[i].stockPrice=newPrice;
            printf("Price of %s (stockID: %d) updated to $%.2f!\n",stocks[i].stockName, stocks[i].stockID, stocks[i].stockPrice);
            return;
        }
    }
    printf("StockID %d does not exist!\n", stockID);
}

// main function
int main(){
    int numStocks=5;
    struct stockInfo stocks[numStocks];
    
    // generate and display initial stock information
    generateStockInfo(stocks, numStocks);
    displayStockInfo(stocks, numStocks);
    
    // prompt user for stockID and new price to update
    int stockID;
    float newPrice;
    printf("\nEnter stockID to update price: ");
    scanf("%d",&stockID);
    printf("Enter new price: ");
    scanf("%f",&newPrice);
    
    // update stock price
    updateStockPrice(stocks,numStocks,stockID,newPrice);
    
    // display updated stock information
    displayStockInfo(stocks,numStocks);
    
    return 0;
}