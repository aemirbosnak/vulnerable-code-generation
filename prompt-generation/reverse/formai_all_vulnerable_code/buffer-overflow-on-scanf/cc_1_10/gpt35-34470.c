//FormAI DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STR_LEN 50

typedef struct stock_t{
    char stock_name[MAX_STR_LEN];
    float current_price;
    float open_price;
    float close_price;
} stock;

stock* init_stock(int num){
    stock* ptr;
    ptr = (stock*) malloc(num * sizeof(stock));
    if(ptr == NULL){
        printf("Allocation failed!\n");
        exit(1);
    }
    return ptr;
}

void get_stock_info(stock* ptr, int num){
    for(int i=0; i<num; ++i){
        printf("Enter stock name: ");
        scanf("%s", &(ptr+i)->stock_name);
        printf("Enter current price: ");
        scanf("%f", &(ptr+i)->current_price);
        printf("Enter open price: ");
        scanf("%f", &(ptr+i)->open_price);
        printf("Enter close price: ");
        scanf("%f", &(ptr+i)->close_price);
    }
}

void display_stock_info(stock* ptr, int num){
    printf("%-15s %-15s %-15s %-15s\n", "Stock Name", "Current Price", "Open Price", "Close Price");
    for(int i=0; i<num; ++i){
        printf("%-15s %-15.2f %-15.2f %-15.2f\n", (ptr+i)->stock_name, (ptr+i)->current_price, (ptr+i)->open_price, (ptr+i)->close_price);
    }
}

float get_highest_price(stock* ptr, int num){
    float highest_price = (ptr+0)->current_price;
    for(int i=0; i<num; ++i){
        if((ptr+i)->current_price > highest_price)
            highest_price = (ptr+i)->current_price;
    }
    return highest_price;
}

float get_lowest_price(stock* ptr, int num){
    float lowest_price = (ptr+0)->current_price;
    for(int i=0; i<num; ++i){
        if((ptr+i)->current_price < lowest_price)
            lowest_price = (ptr+i)->current_price;
    }
    return lowest_price;
}

int main(){
    int num;
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &num);

    stock* stocks = init_stock(num);

    printf("Please enter the stock information:\n");
    get_stock_info(stocks, num);

    printf("\n========== Summary ==========\n");
    display_stock_info(stocks, num);

    float highest_price = get_highest_price(stocks, num);
    float lowest_price = get_lowest_price(stocks, num);
    printf("\nHighest Price: %.2f\n", highest_price);
    printf("Lowest Price: %.2f\n", lowest_price);

    free(stocks);

    return 0;
}