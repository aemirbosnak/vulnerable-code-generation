//FormAI DATASET v1.0 Category: Stock market tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10

typedef struct {
    char name[20];
    float price;
} Stock;

int main() {
    int num_stocks;
    char choice;
    Stock stocks[MAX_STOCKS];

    printf("Welcome to the Medieval Stock Tracker Program!\n");

    printf("Enter the number of stocks you would like to track: ");
    scanf("%d", &num_stocks);

    printf("Enter details for each stock:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("Stock %d name: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Stock %d price: ", i+1);
        scanf("%f", &stocks[i].price);
    }

    do {
        printf("\nMENU:\n");
        printf("a) View all stocks\n");
        printf("b) Search for specific stock\n");
        printf("c) Exit program\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("\nVIEWING ALL STOCKS:\n");
                printf("Name\tPrice\n");
                printf("-----------------\n");
                for (int i = 0; i < num_stocks; i++) {
                    printf("%s\t%.2f\n", stocks[i].name, stocks[i].price);
                }
                break;
            case 'b':
                printf("\nSEARCH FOR A STOCK:\n");
                char stock_name[20];
                printf("Enter name of stock: ");
                scanf("%s", stock_name);

                for (int i = 0; i < num_stocks; i++) {
                    if (strcmp(stocks[i].name, stock_name) == 0) {
                        printf("Stock found:\n");
                        printf("Name\tPrice\n");
                        printf("-----------------\n");
                        printf("%s\t%.2f\n", stocks[i].name, stocks[i].price);
                        break;
                    }
                    else if (i == num_stocks-1) {
                        printf("Stock not found.\n");
                    }
                }
                break;
            case 'c':
                printf("\nExiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);

    return 0;
}