//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 50 // max number of products in the auction

// Structure for holding the product information
struct Product {
    char name[50];
    float currentPrice;
    float startPrice;
    int timeLeft;
    char status[20];
};

// Function prototypes
void displayMenu();
void addProduct(struct Product products[]);
void printProducts(struct Product products[]);
void bid(struct Product products[]);

int main() {
    struct Product products[MAX_PRODUCTS];
    int choice;
    int numProducts = 0;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products);
                numProducts++;
                break;
            case 2:
                printProducts(products);
                break;
            case 3:
                bid(products);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

// Function for displaying the menu options
void displayMenu() {
    printf("\n******* DIGITAL AUCTION SYSTEM *******\n");
    printf("1. Add a product to auction\n");
    printf("2. Print all products in auction\n");
    printf("3. Bid on a product\n");
    printf("4. Exit\n");
}

// Function for adding a new product to the auction
void addProduct(struct Product products[]) {
    int i = 0;

    while(products[i].startPrice != 0) {
        i++;
    }

    printf("Enter product name: ");
    scanf("%s", products[i].name);
    printf("Enter starting price: ");
    scanf("%f", &products[i].startPrice);
    products[i].currentPrice = products[i].startPrice;
    printf("Enter time left (in seconds): ");
    scanf("%d", &products[i].timeLeft);
    sprintf(products[i].status, "Active");
}

// Function for printing all products in the auction
void printProducts(struct Product products[]) {
    printf("\n******* PRODUCTS IN AUCTION *******\n");
    printf("Name\t\tCurrent Price\tTime Left\tStatus\n");

    for(int i = 0; i < MAX_PRODUCTS; i++) {
        if(products[i].startPrice == 0) {
            continue;
        }
        printf("%s\t\t%.2f\t\t%d\t\t%s\n", products[i].name, products[i].currentPrice, products[i].timeLeft, products[i].status);
    }
}

// Function for placing a bid on a product
void bid(struct Product products[]) {
    char productName[50];
    float bidAmount;

    printf("Enter the name of the product you want to bid on: ");
    scanf("%s", productName);

    // Find the product in the list
    int i;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(strcmp(products[i].name, productName) == 0) {
            break;
        }
    }

    if(i == MAX_PRODUCTS) {
        printf("Product not found.\n");
        return;
    }

    // Check if product is still active
    if(strcmp(products[i].status, "Active") != 0) {
        printf("%s is no longer active for bidding.\n", productName);
        return;
    }

    // Place bid
    printf("Enter bid amount: ");
    scanf("%f", &bidAmount);

    if(bidAmount <= products[i].currentPrice) {
        printf("Bid amount must be higher than current price.\n");
        return;
    }

    products[i].currentPrice = bidAmount;
    printf("Bid accepted for %s at %.2f\n", productName, bidAmount);
}