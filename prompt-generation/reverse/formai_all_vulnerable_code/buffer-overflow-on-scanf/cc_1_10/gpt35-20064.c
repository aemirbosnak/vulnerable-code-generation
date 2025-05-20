//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {

    int num_items, budget;
    printf("Welcome to the Budget Shopping Spree!\n");
    printf("How much money do you have to spend? $");
    scanf("%d", &budget);
    printf("How many items are available on your shopping list? ");
    scanf("%d", &num_items);

    int *prices = malloc(num_items * sizeof(int));
    int i;
    for (i = 0; i < num_items; i++) {
        printf("Enter the price of item #%d: ", i + 1);
        scanf("%d", &prices[i]);
    }

    int total_spent = 0;
    int num_bought = 0;
    printf("Let the shopping spree begin!\n");
    while (total_spent < budget && num_bought < num_items) {
        int best_item = -1;
        int max_saved = 0;
        int j;
        for (j = 0; j < num_items; j++) {
            int saved = prices[j] - prices[best_item];
            if (prices[j] <= budget - total_spent && saved > max_saved) {
                best_item = j;
                max_saved = saved;
            }
        }
        if (best_item == -1) {
            break;
        }
        printf("Buying item #%d for $%d (saved $%d)\n", best_item + 1, prices[best_item], max_saved);
        total_spent += prices[best_item];
        num_bought++;
    }

    if (num_bought == 0) {
        printf("Sorry, you can't afford anything on your list!\n");
    } else if (num_bought == 1) {
        printf("Enjoy your purchase!\n");
    } else {
        printf("Congratulations on your shopping spree!\n");
    }

    free(prices);
    return 0;
}