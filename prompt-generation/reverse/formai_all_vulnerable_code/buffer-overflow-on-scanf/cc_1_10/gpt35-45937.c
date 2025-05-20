//FormAI DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 50
#define MAX_NAME 20

// Struct to store stock data
struct stock {
    char name[MAX_NAME];
    double price;
    int volume;
    time_t last_updated;
} stocks[MAX_STOCKS];

// Function to get user menu choice
int get_menu_choice() {
    int choice;
    printf("\nEnter your choice:\n");
    printf("1. Add stock\n");
    printf("2. Delete stock\n");
    printf("3. Update stock price and volume\n");
    printf("4. View all stocks\n");
    printf("5. Exit\n");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new stock
void add_stock() {
    char name[MAX_NAME];
    double price;
    int volume;
    printf("\nEnter stock name:\n");
    scanf("%s", name);
    printf("Enter stock price:\n");
    scanf("%lf", &price);
    printf("Enter stock volume:\n");
    scanf("%d", &volume);
    // Check if stock already exists
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(name, stocks[i].name) == 0) {
            printf("Stock already exists!\n");
            return;
        }
    }
    // Add stock to array
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0] == '\0') {
            strcpy(stocks[i].name, name);
            stocks[i].price = price;
            stocks[i].volume = volume;
            stocks[i].last_updated = time(NULL);
            printf("Stock added successfully!\n");
            return;
        }
    }
    printf("Cannot add stock: maximum number of stocks reached!\n");
}

// Function to delete a stock
void delete_stock() {
    char name[MAX_NAME];
    printf("\nEnter stock name to delete:\n");
    scanf("%s", name);
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(name, stocks[i].name) == 0) {
            stocks[i].name[0] = '\0';
            stocks[i].price = 0;
            stocks[i].volume = 0;
            stocks[i].last_updated = 0;
            printf("Stock deleted successfully!\n");
            return;
        }
    }
    printf("Cannot delete stock: stock not found!\n");
}

// Function to update a stock
void update_stock() {
    char name[MAX_NAME];
    double price;
    int volume;
    printf("\nEnter stock name to update:\n");
    scanf("%s", name);
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(name, stocks[i].name) == 0) {
            printf("Enter new stock price:\n");
            scanf("%lf", &price);
            printf("Enter new stock volume:\n");
            scanf("%d", &volume);
            stocks[i].price = price;
            stocks[i].volume = volume;
            stocks[i].last_updated = time(NULL);
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Cannot update stock: stock not found!\n");
}

// Function to print all stocks
void view_stocks() {
    printf("\n%-20s %-10s %-10s %-25s\n", "Name", "Price", "Volume", "Last updated");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0] != '\0') {
            char buf[30];
            strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&stocks[i].last_updated));
            printf("%-20s $%-9.2f %-10d %-25s\n", stocks[i].name, stocks[i].price, stocks[i].volume, buf);
        }
    }
}

// Main function
int main() {
    int choice;
    printf("Welcome to the stock market tracker!\n");
    while (1) {
        choice = get_menu_choice();
        switch (choice) {
            case 1:
                add_stock();
                break;
            case 2:
                delete_stock();
                break;
            case 3:
                update_stock();
                break;
            case 4:
                view_stocks();
                break;
            case 5:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}