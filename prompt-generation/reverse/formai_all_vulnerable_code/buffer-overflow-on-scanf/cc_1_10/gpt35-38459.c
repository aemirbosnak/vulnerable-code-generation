//FormAI DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} stock;


stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char* name, double price) {
    if (num_stocks < MAX_STOCKS) {
        strcpy(stocks[num_stocks].name, name);
        stocks[num_stocks].price = price;
        num_stocks++;
    }
}

void remove_stock(char* name) {
    int i = 0;
    while (i < num_stocks) {
        if (strcmp(stocks[i].name, name) == 0) {
            for (int j = i; j < num_stocks-1; j++) {
                strcpy(stocks[j].name, stocks[j+1].name);
                stocks[j].price = stocks[j+1].price;
            }
            num_stocks--;
        }
        else {
            i++;
        }
    }
}

void update_price(char* name, double new_price) {
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price = new_price;
        }
    }
}

void print_stocks() {
    printf("Stocks:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: %.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    double price;
    int choice;

    while (1) {
        printf("Select an option:\n");
        printf("1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. Update price\n");
        printf("4. Print stocks\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter price: ");
                scanf("%lf", &price);
                add_stock(name, price);
                break;

            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                remove_stock(name);
                break;

            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter new price: ");
                scanf("%lf", &price);
                update_price(name, price);
                break;

            case 4:
                print_stocks();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\n");
    }

    return 0;
}