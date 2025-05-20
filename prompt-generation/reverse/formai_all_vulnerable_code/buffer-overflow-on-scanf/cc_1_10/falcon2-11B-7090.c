//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_STOCK_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10

typedef struct {
    char stock_name[MAX_STOCK_NAME_LENGTH];
    int stock_price;
} Stock;

typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    int price;
} StockInfo;

Stock stock_list[MAX_STOCKS];
int num_stocks;

void print_stock_list() {
    printf("Stock List:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s %d\n", stock_list[i].stock_name, stock_list[i].stock_price);
    }
}

void update_stock_price(int index, int new_price) {
    stock_list[index].stock_price = new_price;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int choice;
    do {
        print_stock_list();
        printf("\n1. Add a stock\n2. Update a stock's price\n3. View stock prices\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("\nEnter stock name: ");
                fgets(stock_list[num_stocks].stock_name, MAX_STOCK_NAME_LENGTH, stdin);
                stock_list[num_stocks].stock_price = rand() % 1000 + 1;
                num_stocks++;
                break;
            }
            case 2: {
                int index;
                printf("\nEnter stock index: ");
                scanf("%d", &index);
                int new_price;
                printf("\nEnter new price: ");
                scanf("%d", &new_price);
                update_stock_price(index, new_price);
                break;
            }
            case 3: {
                print_stock_list();
                break;
            }
            case 4: {
                exit(0);
            }
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice!= 4);

    return 0;
}