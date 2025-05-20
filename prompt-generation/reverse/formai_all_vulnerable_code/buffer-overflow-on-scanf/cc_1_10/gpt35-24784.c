//FormAI DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>

// define the maximum number of stocks the program can track
#define MAX_STOCKS 10

// structure to represent a single stock
typedef struct Stock {
    char name[20];
    float price;
    int quantity;
} Stock;

// function to display the menu of options
void displayMenu() {
    printf("\nChoose an option:\n");
    printf("1. Add a stock\n");
    printf("2. Remove a stock\n");
    printf("3. Display all stocks\n");
    printf("4. Update a stock price\n");
    printf("5. Update a stock quantity\n");
    printf("6. Quit\n");
}

// function to add a stock to the tracker
void addStock(Stock stocks[], int *numStocks) {
    // check if the maximum number of stocks has been reached
    if (*numStocks == MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }

    // get the name, price, and quantity of the new stock from the user
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[*numStocks].name);
    printf("Enter the price of the stock: ");
    scanf("%f", &stocks[*numStocks].price);
    printf("Enter the quantity of the stock: ");
    scanf("%d", &stocks[*numStocks].quantity);

    // increment the number of stocks counter
    (*numStocks)++;
}

// function to remove a stock from the tracker
void removeStock(Stock stocks[], int *numStocks) {
    // get the name of the stock to remove from the user
    char name[20];
    printf("Enter the name of the stock to remove: ");
    scanf("%s", name);

    // find the index of the stock with the given name
    int index = -1;
    for (int i = 0; i < *numStocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // if the stock is not found, display an error message
    if (index == -1) {
        printf("Stock not found.\n");
        return;
    }

    // remove the stock by shifting all subsequent stocks to the left
    for (int i = index; i < *numStocks - 1; i++) {
        stocks[i] = stocks[i + 1];
    }

    // decrement the number of stocks counter
    (*numStocks)--;
}

// function to display all of the stocks in the tracker
void displayStocks(Stock stocks[], int numStocks) {
    // display the header row
    printf("%-20s%-20s%-20s\n", "Name", "Price", "Quantity");
    printf("------------------------------------------------\n");

    // display the data for each stock
    for (int i = 0; i < numStocks; i++) {
        printf("%-20s%-20.2f%-20d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
}

// function to update the price of a stock
void updatePrice(Stock stocks[], int numStocks) {
    // get the name of the stock to update from the user
    char name[20];
    printf("Enter the name of the stock to update: ");
    scanf("%s", name);

    // find the index of the stock with the given name
    int index = -1;
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // if the stock is not found, display an error message
    if (index == -1) {
        printf("Stock not found.\n");
        return;
    }

    // get the new price from the user
    printf("Enter the new price: ");
    scanf("%f", &stocks[index].price);
}

// function to update the quantity of a stock
void updateQuantity(Stock stocks[], int numStocks) {
    // get the name of the stock to update from the user
    char name[20];
    printf("Enter the name of the stock to update: ");
    scanf("%s", name);

    // find the index of the stock with the given name
    int index = -1;
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // if the stock is not found, display an error message
    if (index == -1) {
        printf("Stock not found.\n");
        return;
    }

    // get the new quantity from the user
    printf("Enter the new quantity: ");
    scanf("%d", &stocks[index].quantity);
}

int main() {
    // initialize the array of stocks and the number of stocks counter
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    // loop until the user chooses to quit
    int choice = 0;
    while (choice != 6) {
        // display the menu and get the user's choice
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // execute the chosen option
        switch (choice) {
            case 1:
                addStock(stocks, &numStocks);
                break;
            case 2:
                removeStock(stocks, &numStocks);
                break;
            case 3:
                displayStocks(stocks, numStocks);
                break;
            case 4:
                updatePrice(stocks, numStocks);
                break;
            case 5:
                updateQuantity(stocks, numStocks);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}