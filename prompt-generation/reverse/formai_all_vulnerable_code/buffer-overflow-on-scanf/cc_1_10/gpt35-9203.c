//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    float price;
} Stock;

int main(){
    Stock stocks[3];
    stocks[0].name = "Microsoft";
    stocks[0].price = 182.92;
    stocks[1].name = "Google";
    stocks[1].price = 1180.98;
    stocks[2].name = "Amazon";
    stocks[2].price = 1901.75;
    int option;

    while(1){
        printf("Enter option:\n");
        printf("1) View current stock prices\n");
        printf("2) Update a stock price\n");
        printf("3) Exit\n");
        scanf("%d", &option);

        if(option == 1){
            printf("Current Stock Prices:\n");
            for(int i=0; i<3; i++){
                printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
            }
        }

        else if(option == 2){
            printf("Enter stock name:\n");
            char stockName[20];
            scanf("%s", stockName);
            int flag=0;

            for(int i=0; i<3; i++){
                if(strcmp(stocks[i].name, stockName)==0){
                    printf("Enter new price:\n");
                    scanf("%f", &stocks[i].price);
                    printf("%s updated to $%.2f\n", stocks[i].name, stocks[i].price);
                    flag = 1;
                }
            }

            if(flag == 0){
                printf("Stock not found!\n");
            }
        }

        else if(option == 3){
            printf("Goodbye!\n");
            break;
        }

        else{
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}