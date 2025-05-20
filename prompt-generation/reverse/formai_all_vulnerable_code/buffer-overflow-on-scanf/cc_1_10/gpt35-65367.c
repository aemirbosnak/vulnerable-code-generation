//FormAI DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum number of products that can be auctioned
#define MAX_PRODUCTS 100

// define product structure
struct product {
    char name[50];
    int starting_price;
    int current_bid;
    char highest_bidder[50];
    int time_remaining;
};

// define function to print product information
void print_product_info(struct product p) {
    printf("\nProduct Name: %s\n", p.name);
    printf("Starting Price: %d\n", p.starting_price);
    printf("Current Bid: %d\n", p.current_bid);
    printf("Highest Bidder: %s\n", p.highest_bidder);
    printf("Time Remaining: %d minutes\n", p.time_remaining);
}

int main() {
    // initialize array of products
    struct product products[MAX_PRODUCTS];

    // initialize counter for number of products
    int num_products = 0;

    // start auction menu loop
    while(1) {
        // print auction menu
        printf("\nWelcome to the Digital Auction System!\n");
        printf("1. Add a product\n");
        printf("2. View product information\n");
        printf("3. Place a bid\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // get user choice
        int choice;
        scanf("%d", &choice);

        // read newline left in input buffer
        getchar();

        if(choice == 1) {
            // add a product
            // check if maximum number of products has been reached
            if(num_products == MAX_PRODUCTS) {
                printf("Error: Maximum number of products reached.\n");
            } else {
                // get product name
                printf("Enter product name: ");
                fgets(products[num_products].name, 50, stdin);
                products[num_products].name[strcspn(products[num_products].name, "\n")] = 0;

                // get starting price
                printf("Enter starting price: ");
                scanf("%d", &products[num_products].starting_price);

                // set current bid to starting price
                products[num_products].current_bid = products[num_products].starting_price;

                // set highest bidder to "none"
                strcpy(products[num_products].highest_bidder, "none");

                // get time remaining
                printf("Enter time remaining (in minutes): ");
                scanf("%d", &products[num_products].time_remaining);

                // increment number of products
                num_products++;

                // confirmation message
                printf("Product added successfully!\n");
            }
        } else if(choice == 2) {
            // view product information
            // check if there are any products
            if(num_products == 0) {
                printf("Error: No products available.\n");
            } else {
                // get product index
                printf("Enter product index: ");
                int index;
                scanf("%d", &index);

                // check if product index is valid
                if(index < 0 || index >= num_products) {
                    printf("Error: Invalid product index.\n");
                } else {
                    // print product information
                    print_product_info(products[index]);
                }
            }
        } else if(choice == 3) {
            // place a bid
            // check if there are any products
            if(num_products == 0) {
                printf("Error: No products available.\n");
            } else {
                // get product index
                printf("Enter product index: ");
                int index;
                scanf("%d", &index);

                // check if product index is valid
                if(index < 0 || index >= num_products) {
                    printf("Error: Invalid product index.\n");
                } else {
                    // get bid amount
                    printf("Enter bidding amount: ");
                    int amount;
                    scanf("%d", &amount);

                    // check if bid amount is greater than current bid
                    if(amount <= products[index].current_bid) {
                        printf("Error: Bid amount should be greater than current bid.\n");
                    } else {
                        // update current bid and highest bidder
                        products[index].current_bid = amount;
                        printf("Enter your name: ");
                        fgets(products[index].highest_bidder, 50, stdin);
                        products[index].highest_bidder[strcspn(products[index].highest_bidder, "\n")] = 0;

                        // confirmation message
                        printf("Bid placed successfully!\n");
                    }
                }
            }
        } else if(choice == 4) {
            // exit program
            printf("Exiting Digital Auction System.\n");
            break;
        } else {
            // invalid choice
            printf("Invalid choice.\n");
        }
    }

    return 0;
}