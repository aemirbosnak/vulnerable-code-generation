//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20

// Structure to hold stock details
typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int volume;
} stock_t;

int main() {
    stock_t stocks[MAX_STOCKS];
    int num_stock = 0;
    char choice;

    printf("*** C Stock Market Tracker ***\n\n");

    while(1) {
        // Display menu
        printf("Please choose from the following options:\n");
        printf("1. Add a stock\n");
        printf("2. View all stocks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1': // Add stock
                if(num_stock >= MAX_STOCKS) {
                    printf("Error: Maximum number of stocks reached!\n");
                    break;
                }
                printf("Enter name of stock (max %d characters): ", MAX_NAME_LEN-1);
                scanf("%s", stocks[num_stock].name);
                printf("Enter price of stock: ");
                scanf("%f", &stocks[num_stock].price);
                printf("Enter volume of stock: ");
                scanf("%d", &stocks[num_stock].volume);
                num_stock++;
                printf("Stock added successfully!\n");
                break;

            case '2': // View all stocks
                if(num_stock == 0) {
                    printf("No stocks added yet!\n");
                    break;
                }
                printf("Stocks in the market:\n");
                for(int i=0; i<num_stock; i++) {
                    printf("%s - Price: %.2f, Volume: %d\n", stocks[i].name, stocks[i].price, stocks[i].volume);
                }
                break;

            case '3': // Exit
                printf("Exiting...\n");
                exit(0);

            default: // Invalid choice
                printf("Invalid choice\n");
                break;
        }

        printf("\n");
    }

    return 0;
}