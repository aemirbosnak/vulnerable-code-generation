//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 10
#define MAX_TOTAL_COST_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    char quantity[MAX_QUANTITY_LEN];
    char total_cost[MAX_TOTAL_COST_LEN];
} Stock;

int main() {
    int num_stocks;
    Stock stocks[MAX_STOCKS];
    
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &num_stocks);
    
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);
        
        printf("Enter the price of stock %s: ", stocks[i].name);
        scanf("%s", stocks[i].price);
        
        printf("Enter the quantity of stock %s: ", stocks[i].name);
        scanf("%s", stocks[i].quantity);
        
        printf("Enter the total cost of stock %s: ", stocks[i].name);
        scanf("%s", stocks[i].total_cost);
    }
    
    printf("\nStock Tracker\n");
    printf("+-----------------+-----------------+--------------+-----------------\n");
    printf("| Name            | Price           | Quantity     | Total Cost       |\n");
    printf("+-----------------+-----------------+--------------+-----------------\n");
    
    for (int i = 0; i < num_stocks; i++) {
        printf("| %s              | $%s            | %s             | $%s              |\n",
               stocks[i].name, stocks[i].price, stocks[i].quantity, stocks[i].total_cost);
    }
    
    printf("+-----------------+-----------------+--------------+-----------------\n");
    
    return 0;
}