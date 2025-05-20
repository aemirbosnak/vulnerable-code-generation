//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// The noble structure of a merchant's trade
typedef struct {
    char name[50];
    float price;
    int quantity;
    float market_value;
} MerchantStock;

// The grand court where stocks are managed
void display_market(MerchantStock stocks[], int count) {
    printf("=========================================\n");
    printf("   THE ROYAL STOCK MARKET OF MEADHALL  \n");
    printf("=========================================\n");
    printf(" Merchant Name        | Price  | Quantity | Market Value \n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf(" %-20s | %-6.2f | %-8d | %-12.2f\n", stocks[i].name, stocks[i].price, stocks[i].quantity, stocks[i].market_value);
    }
    printf("=========================================\n");
}

// A clever merchant who updates his wares
void update_stock(MerchantStock *stock) {
    printf("Updating stock for %s\n", stock->name);
    printf("Enter new price: ");
    scanf("%f", &(stock->price));
    printf("Enter new quantity: ");
    scanf("%d", &(stock->quantity));
    // Calculate market value as price times quantity
    stock->market_value = stock->price * stock->quantity;
}

// The wise wizard who generates a new stock
void create_stock(MerchantStock *stock) {
    printf("Enter the name of the merchant's wares: ");
    scanf("%s", stock->name);
    printf("Enter initial price: ");
    scanf("%f", &(stock->price));
    printf("Enter initial quantity: ");
    scanf("%d", &(stock->quantity));
    stock->market_value = stock->price * stock->quantity;
}

// A noble function where stocks are bought
void buy_stock(MerchantStock *stock) {
    int quantity_to_buy;
    printf("How many to buy of %s? ", stock->name);
    scanf("%d", &quantity_to_buy);
    stock->quantity += quantity_to_buy;
    stock->market_value = stock->price * stock->quantity;
    printf("You have successfully purchased %d of %s.\n", quantity_to_buy, stock->name);
}

// A noble function where stocks are sold
void sell_stock(MerchantStock *stock) {
    int quantity_to_sell;
    printf("How many to sell of %s? ", stock->name);
    scanf("%d", &quantity_to_sell);
    if (quantity_to_sell > stock->quantity) {
        printf("Alas! You do not possess enough stock!\n");
    } else {
        stock->quantity -= quantity_to_sell;
        stock->market_value = stock->price * stock->quantity;
        printf("You have successfully sold %d of %s.\n", quantity_to_sell, stock->name);
    }
}

// The grand decision maker, the court of the stock market
int main() {
    MerchantStock stocks[10]; // The royal inventory
    int stock_count = 0;
    int choice;
    char continue_choice;

    do {
        printf("\nWelcome to the Royal Stock Market!\n");
        printf("1. Create Stock\n2. Update Stock\n3. Buy Stock\n4. Sell Stock\n5. Display Market\n6. Exit\n");
        printf("Choose your noble action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (stock_count < 10) {
                    create_stock(&stocks[stock_count]);
                    stock_count++;
                } else {
                    printf("The inventory is full! Seek not more merchants.\n");
                }
                break;
            case 2:
                for (int i = 0; i < stock_count; i++) {
                    printf("%d. %s\n", i + 1, stocks[i].name);
                }
                printf("Choose stock to update (1 - %d): ", stock_count);
                int update_choice;
                scanf("%d", &update_choice);
                if (update_choice >= 1 && update_choice <= stock_count) {
                    update_stock(&stocks[update_choice - 1]);
                } else {
                    printf("Invalid choice, choose wisely!\n");
                }
                break;
            case 3:
                for (int i = 0; i < stock_count; i++) {
                    printf("%d. %s\n", i + 1, stocks[i].name);
                }
                printf("Choose stock to buy (1 - %d): ", stock_count);
                int buy_choice;
                scanf("%d", &buy_choice);
                if (buy_choice >= 1 && buy_choice <= stock_count) {
                    buy_stock(&stocks[buy_choice - 1]);
                } else {
                    printf("Invalid choice, choose wisely!\n");
                }
                break;
            case 4:
                for (int i = 0; i < stock_count; i++) {
                    printf("%d. %s\n", i + 1, stocks[i].name);
                }
                printf("Choose stock to sell (1 - %d): ", stock_count);
                int sell_choice;
                scanf("%d", &sell_choice);
                if (sell_choice >= 1 && sell_choice <= stock_count) {
                    sell_stock(&stocks[sell_choice - 1]);
                } else {
                    printf("Invalid choice, choose wisely!\n");
                }
                break;
            case 5:
                display_market(stocks, stock_count);
                break;
            case 6:
                printf("Farewell, noble merchant!\n");
                exit(0);
                break;
            default:
                printf("Nay! An unknown action hath been chosen!\n");
        }

        printf("Desire to continue? (y/n): ");
        scanf(" %c", &continue_choice);

    } while (continue_choice == 'y');

    return 0;
}