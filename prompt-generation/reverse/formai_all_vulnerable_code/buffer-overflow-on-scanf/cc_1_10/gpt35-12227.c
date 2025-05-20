//FormAI DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stock {
    char name[20];
    float current_price;
    float previous_price;
} stocks[5]; // array of 5 stocks

// function to display the menu and get user choice
int display_menu() {
    int choice;
    printf("\n1. Add stock\n");
    printf("2. Remove stock\n");
    printf("3. Update stock price\n");
    printf("4. View stock details\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to add a new stock
void add_stock() {
    int i = 0;
    while(stocks[i].name[0] != '\0') {
        i++;
    }
    printf("\nEnter stock name: ");
    scanf("%s", stocks[i].name);
    printf("Enter current price: ");
    scanf("%f", &stocks[i].current_price);
    stocks[i].previous_price = stocks[i].current_price;
    printf("\nStock added successfully!\n");
}

// function to remove an existing stock
void remove_stock() {
    char stock_name[20];
    int i, j, flag = 0;
    printf("\nEnter stock name to remove: ");
    scanf("%s", stock_name);
    for(i = 0; i < 5; i++) {
        if(strcmp(stocks[i].name, stock_name) == 0) {
            flag = 1;
            for(j = i; j < 4; j++) {
                stocks[j] = stocks[j+1];
            }
            // set last element as null
            stocks[4].name[0] = '\0';
            stocks[4].current_price = 0;
            stocks[4].previous_price = 0;
            printf("\nStock removed successfully!\n");
            break;
        }
    }
    if(flag == 0) {
        printf("\nStock not found!\n");
    }
}

// function to update an existing stock price
void update_stock() {
    char stock_name[20];
    int i, flag = 0;
    float new_price;
    printf("\nEnter stock name to update: ");
    scanf("%s", stock_name);
    for(i = 0; i < 5; i++) {
        if(strcmp(stocks[i].name, stock_name) == 0) {
            flag = 1;
            printf("Enter new price: ");
            scanf("%f", &new_price);
            stocks[i].previous_price = stocks[i].current_price;
            stocks[i].current_price = new_price;
            printf("\nStock updated successfully!\n");
            break;
        }
    }
    if(flag == 0) {
        printf("\nStock not found!\n");
    }
}

// function to view all stock details
void view_stock() {
    int i;
    printf("\n%-20s%-20s%-20s\n", "Stock Name", "Current Price", "Previous Price");
    for(i = 0; i < 5; i++) {
        if(stocks[i].name[0] != '\0') {
            printf("%-20s%-20.2f%-20.2f\n", stocks[i].name, stocks[i].current_price, stocks[i].previous_price);
        }
    }
}

int main() {
    int choice;
    printf("Welcome to the Stock Market Tracker!\n");
    while(1) {
        choice = display_menu();
        switch(choice) {
            case 1:
                add_stock();
                break;
            case 2:
                remove_stock();
                break;
            case 3:
                update_stock();
                break;
            case 4:
                view_stock();
                break;
            case 5:
                printf("\nThank you for using the Stock Market Tracker!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}