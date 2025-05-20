//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float currentPrice;
    int quantity;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int count;
} Portfolio;

// Function prototypes
void addStock(Portfolio *portfolio);
void viewPortfolio(const Portfolio *portfolio);
void updateStockPrices(Portfolio *portfolio);
void displayHappyMessage();

int main() {
    Portfolio myPortfolio = { .count = 0 };
    int choice;

    displayHappyMessage();

    do {
        printf("\nWelcome to the Happy Stock Market Tracker 🌟 \n");
        printf("1. Add Stock\n");
        printf("2. View Portfolio\n");
        printf("3. Update Stock Prices\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStock(&myPortfolio);
                break;
            case 2:
                viewPortfolio(&myPortfolio);
                break;
            case 3:
                updateStockPrices(&myPortfolio);
                break;
            case 4:
                printf("Thank you for using the Happy Stock Market Tracker! Goodbye! 😊\n");
                break;
            default:
                printf("Oops! Please enter a valid option (1-4).\n");
        }
        
    } while (choice != 4);

    return 0;
}

void addStock(Portfolio *portfolio) {
    if (portfolio->count >= MAX_STOCKS) {
        printf("Sorry, you cannot add more stocks! Limit reached. 🌈\n");
        return;
    }
    Stock newStock;

    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    
    printf("Enter current stock price: ");
    scanf("%f", &newStock.currentPrice);
    
    printf("Enter quantity of stocks: ");
    scanf("%d", &newStock.quantity);
    
    portfolio->stocks[portfolio->count] = newStock;
    portfolio->count++;
    
    printf("Yay! You successfully added %s to your portfolio! 🎉\n", newStock.name);
}

void viewPortfolio(const Portfolio *portfolio) {
    if (portfolio->count == 0) {
        printf("Your portfolio is empty. Let's add some stocks! 🌼\n");
        return;
    }

    printf("\nYour Stock Portfolio:\n");
    printf("---------------------\n");
    for (int i = 0; i < portfolio->count; i++) {
        printf("Stock Name: %s | Price: $%.2f | Quantity: %d\n",
               portfolio->stocks[i].name,
               portfolio->stocks[i].currentPrice,
               portfolio->stocks[i].quantity);
    }
    printf("---------------------\n");
}

void updateStockPrices(Portfolio *portfolio) {
    if (portfolio->count == 0) {
        printf("Your portfolio is empty! Add some stocks first! ❌\n");
        return;
    }

    for (int i = 0; i < portfolio->count; i++) {
        float priceChange = ((float)(rand() % 200 - 100)) / 100; // Random change between -1.00 to 0.99
        portfolio->stocks[i].currentPrice += priceChange;

        if (priceChange > 0) {
            printf("Stock %s has increased by $%.2f! 🌞\n", portfolio->stocks[i].name, priceChange);
        } else {
            printf("Oh no! Stock %s has decreased by $%.2f. 😢\n", portfolio->stocks[i].name, -priceChange);
        }
    }
}

void displayHappyMessage() {
    printf("Welcome to the land of stocks and sunshine! 🌞\n");
    printf("Get ready to track your favorite stocks with a smile! 😄\n\n");
}