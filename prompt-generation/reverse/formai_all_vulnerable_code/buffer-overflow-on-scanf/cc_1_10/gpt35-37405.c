//FormAI DATASET v1.0 Category: Digital Auction System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[100];
    float price;
    char description[500];
} Product;

typedef struct Bid {
    char bidder[100];
    float amount;
} Bid;

int main() {
    Product product;
    Bid bid;
    int num_bids = 0;
    Bid highest_bid;
    highest_bid.amount = 0.0;

    printf("Enter product name: ");
    fgets(product.name, 100, stdin);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    printf("Enter product description: ");
    getchar(); // consume the newline
    fgets(product.description, 500, stdin);

    int num_products = 1;
    Product *products = malloc(num_products * sizeof(Product));
    products[0] = product;

    int option;
    while (1) {
        printf("\n");
        printf("Select an option:\n");
        printf("1. Add a product\n");
        printf("2. Auction a product\n");
        printf("3. Quit\n");
        scanf("%d", &option);
        getchar(); // consume the newline

        if (option == 1) {
            printf("Enter product name: ");
            fgets(product.name, 100, stdin);
            printf("Enter product price: ");
            scanf("%f", &product.price);
            printf("Enter product description: ");
            getchar(); // consume the newline
            fgets(product.description, 500, stdin);

            num_products++;
            products = realloc(products, num_products * sizeof(Product));
            products[num_products - 1] = product;
        }
        else if (option == 2) {
            printf("Which product would you like to auction?\n");
            for (int i = 0; i < num_products; i++) {
                printf("%d. %s, $%.2f\n", i + 1, products[i].name, products[i].price);
            }
            int product_choice;
            scanf("%d", &product_choice);
            getchar(); // consume the newline
            Product selected_product = products[product_choice - 1];

            printf("Auctioning %s...\n", selected_product.name);
            printf("Starting bid: $%.2f\n", selected_product.price);
            printf("Enter bidder name: ");
            fgets(bid.bidder, 100, stdin);
            bid.amount = selected_product.price;
            printf("Enter bid amount: ");
            scanf("%f", &bid.amount);

            while (bid.amount > highest_bid.amount) {
                printf("%s is the current highest bidder with a bid of $%.2f\n", bid.bidder, bid.amount);
                num_bids++;
                highest_bid = bid;

                printf("Enter new bidder name (or quit to stop bidding): ");
                fgets(bid.bidder, 100, stdin);
                if (strcmp(bid.bidder, "quit\n") == 0) {
                    break;
                }
                printf("Enter bid amount: ");
                scanf("%f", &bid.amount);
            }

            printf("The auction for %s has ended\n", selected_product.name);
            printf("%s won with a bid of $%.2f\n", highest_bid.bidder, highest_bid.amount);
        }
        else if (option == 3) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid option\n");
        }
    }

    free(products);

    return 0;
}