//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDS 1000
#define MAX_USERS 30

int main()
{
    int num_users, num_items, i, j, k;
    float bid_amount, max_bid;
    char user_names[MAX_USERS][50], item_names[MAX_BIDS][50];
    float bid_prices[MAX_BIDS], user_budgets[MAX_USERS];

    srand(time(NULL));

    printf("*** WELCOME TO THE DIGITAL AUCTION SYSTEM ***\n\n");

    printf("Enter the number of users: ");
    scanf("%d", &num_users);

    for(i = 0; i < num_users; i++){
        printf("Enter name of user %d: ", i+1);
        scanf("%s", user_names[i]);

        printf("Enter budget of user %d: ", i+1);
        scanf("%f", &user_budgets[i]);

        printf("\n");
    }

    printf("Enter the number of items to be auctioned: ");
    scanf("%d", &num_items);

    for(i = 0; i < num_items; i++){
        printf("Enter name of item %d: ", i+1);
        scanf("%s", item_names[i]);

        bid_prices[i] = (rand() % 5000) + 1;

        printf("Minimum bid price for item %d: $%.2f\n\n", i+1, bid_prices[i]);
    }

    printf("***** AUCTION STARTS *****\n\n");

    for(i = 0; i < num_items; i++){
        max_bid = 0;
        printf("Item %d: %s\nMinimum bid price: $%.2f\n", i+1, item_names[i], bid_prices[i]);

        for(j = 0; j < num_users; j++){
            printf("User %d: %s\nBudget available: $%.2f\n", j+1, user_names[j], user_budgets[j]);

            printf("Enter your bid amount: ");
            scanf("%f", &bid_amount);

            if(bid_amount > max_bid && bid_amount >= bid_prices[i] && bid_amount <= user_budgets[j]){
                max_bid = bid_amount;
                k = j;
            }

            printf("\n");
        }

        if(max_bid > 0){
            printf("%s wins the auction for %s with a bid of $%.2f!\n\n", user_names[k], item_names[i], max_bid);
            user_budgets[k] -= max_bid;
        }
        else{
            printf("No one wins the auction for %s.\n\n", item_names[i]);
        }
    }

    printf("***** AUCTION ENDS *****\n\n");

    return 0;
}