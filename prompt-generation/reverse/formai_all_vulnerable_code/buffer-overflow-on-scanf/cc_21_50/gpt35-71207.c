//FormAI DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#define MAX_STOCKS 5

struct stock {
    char name[20];
    float price;
};

int main() {
    struct stock stocks[MAX_STOCKS];
    int i, choice, num_stocks = 0;

    do {
        printf("\n1. Add a stock\n");
        printf("2. View all stocks\n");
        printf("3. Search for a stock\n");
        printf("4. Edit a stock\n");
        printf("5. Remove a stock\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                if(num_stocks < MAX_STOCKS) {
                    printf("\nEnter the name of the stock: ");
                    scanf("%s", stocks[num_stocks].name);
                    printf("Enter the price of the stock: ");
                    scanf("%f", &stocks[num_stocks].price);
                    num_stocks++;
                    printf("\nStock added successfully!\n");
                }
                else {
                    printf("\nMaximum limit of stocks reached!\n");
                }
                break;

            case 2:
                printf("\nAll stocks in the market:\n");
                for(i = 0; i < num_stocks; i++) {
                    printf("\nStock #%d\n", i+1);
                    printf("Name: %s\n", stocks[i].name);
                    printf("Price: $%.2f\n", stocks[i].price);
                }
                break;

            case 3:
                if(num_stocks == 0) {
                    printf("\nThere are no stocks to search in the market!\n");
                    break;
                }
                char search_name[20];
                int found_flag = 0;
                printf("\nEnter the name of the stock you want to search for: ");
                scanf("%s", search_name);
                for(i = 0; i < num_stocks; i++) {
                    if(strcmp(stocks[i].name, search_name) == 0) {
                        found_flag = 1;
                        printf("\nStock found!\n");
                        printf("Name: %s\n", stocks[i].name);
                        printf("Price: $%.2f\n", stocks[i].price);
                        break;
                    }
                }
                if(found_flag == 0) {
                    printf("\nStock not found in the market!\n");
                }
                break;

            case 4:
                if(num_stocks == 0) {
                    printf("\nThere are no stocks to edit in the market!\n");
                    break;
                }
                char edit_name[20];
                int edit_flag = 0;
                printf("\nEnter the name of the stock you want to edit: ");
                scanf("%s", edit_name);
                for(i = 0; i < num_stocks; i++) {
                    if(strcmp(stocks[i].name, edit_name) == 0) {
                        edit_flag = 1;
                        printf("\nEnter the new price of the stock: ");
                        scanf("%f", &stocks[i].price);
                        printf("\nStock edited successfully!\n");
                        break;
                    }
                }
                if(edit_flag == 0) {
                    printf("\nStock not found in the market!\n");
                }
                break;

            case 5:
                if(num_stocks == 0) {
                    printf("\nThere are no stocks to remove from the market!\n");
                    break;
                }
                char remove_name[20];
                int remove_flag = 0;
                printf("\nEnter the name of the stock you want to remove: ");
                scanf("%s", remove_name);
                for(i = 0; i < num_stocks; i++) {
                    if(strcmp(stocks[i].name, remove_name) == 0) {
                        remove_flag = 1;
                        for(int j = i; j < num_stocks - 1; j++) {
                            strcpy(stocks[j].name, stocks[j+1].name);
                            stocks[j].price = stocks[j+1].price;
                        }
                        num_stocks--;
                        printf("\nStock removed successfully!\n");
                        break;
                    }
                }
                if(remove_flag == 0) {
                    printf("\nStock not found in the market!\n");
                }
                break;

            case 6:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }

    } while(choice != 6);

    return 0;
}