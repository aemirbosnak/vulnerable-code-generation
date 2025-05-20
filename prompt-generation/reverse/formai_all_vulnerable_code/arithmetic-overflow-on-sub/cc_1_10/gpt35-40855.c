//FormAI DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[100];
    int starting_price;
    int current_price;
    char description[1000];
};

int main() {
    struct Product products[10];
    int product_count = 0;

    int option = -1;
    while (option != 0) {
        printf("Enter 0 to exit, 1 to add new product, 2 to view all products: ");
        scanf("%d", &option);

        if (option == 1) {
            struct Product p;
            p.id = product_count + 1;

            printf("Enter product name: ");
            scanf("%s", p.name);

            printf("Enter starting price: ");
            scanf("%d", &p.starting_price);

            p.current_price = p.starting_price;

            printf("Enter product description: ");
            scanf("%s", p.description);

            products[product_count] = p;
            product_count++;
        } else if (option == 2) {
            printf("ID\tNAME\tSTARTING PRICE\tCURRENT PRICE\tDESCRIPTION\n");

            for (int i = 0; i < product_count; i++) {
                struct Product p = products[i];
                printf("%d\t%s\t%d\t\t%d\t\t%s\n", p.id, p.name, p.starting_price, p.current_price, p.description);
            }

            int product_id;
            printf("\nEnter product ID to bid on: ");
            scanf("%d", &product_id);

            struct Product p = products[product_id - 1];

            int bid_amount;
            printf("Enter bid amount for %s: ", p.name);
            scanf("%d", &bid_amount);

            if (bid_amount > p.current_price) {
                p.current_price = bid_amount;
                products[product_id - 1] = p;

                printf("Bid accepted for %s at $%d\n", p.name, p.current_price);
            } else {
                printf("Bid rejected for %s. Current bid price is $%d\n", p.name, p.current_price);
            }
        }
    }

    return 0;
}