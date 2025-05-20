//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define STOCK_NAME_LENGTH 30

typedef struct {
    char name[STOCK_NAME_LENGTH];
    float price;
} Stock;

Stock stockMarket[MAX_STOCKS];
int stockCount = 0;

void viewStocks() {
    printf("\n--- Grateful Stock Market Tracker ---\n");
    printf("Here are your stocks, cherished user:\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Stock %d: %s - Price: $%.2f\n", i + 1, stockMarket[i].name, stockMarket[i].price);
    }
    printf("------------------------------------\n");
}

void addStock() {
    if (stockCount >= MAX_STOCKS) {
        printf("Thank you for your enthusiasm, but we can't add more stocks!\n");
        return;
    }
    
    Stock newStock;
    
    printf("Let's add a new stock to our listing. Please enter the stock name (max %d characters): ", STOCK_NAME_LENGTH - 1);
    scanf("%s", newStock.name);
    printf("How much is %s worth? $", newStock.name);
    scanf("%f", &newStock.price);
    
    stockMarket[stockCount] = newStock;
    stockCount++;
    printf("We are thankful! You have successfully added %s at $%.2f.\n", newStock.name, newStock.price);
}

void updateStock() {
    if (stockCount == 0) {
        printf("It seems you don't have any stocks right now to update. Please add some first!\n");
        return;
    }
    
    viewStocks();
    
    int index;
    printf("Which stock would you like to update? Please enter the stock number: ");
    scanf("%d", &index);
    
    if (index < 1 || index > stockCount) {
        printf("We appreciate your intention, but that stock number is out of bounds.\n");
        return;
    }
    
    index--; // Adjust for 0-based index
    printf("What is the new price for %s? $", stockMarket[index].name);
    scanf("%f", &stockMarket[index].price);
    printf("Thank you! The price of %s has been updated to $%.2f.\n", stockMarket[index].name, stockMarket[index].price);
}

void showMenu() {
    printf("\n--- Stock Market Tracker Menu ---\n");
    printf("1. Add a Stock\n");
    printf("2. Update a Stock Price\n");
    printf("3. View All Stocks\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                updateStock();
                break;
            case 3:
                viewStocks();
                break;
            case 4:
                printf("Thank you for using the Stock Market Tracker! Have a wonderful day!\n");
                exit(0);
                break;
            default:
                printf("Your choice is appreciated, but please select a valid option.\n");
                break;
        }
    }

    return 0;
}