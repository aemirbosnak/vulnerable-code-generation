//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int id;
    int bid;
} bidder;

int main() {
    int i, j, n, max_bid = 0, bid;
    char ch;
    bidder bidders[MAX];

    printf("Enter the number of bidders: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the name of bidder %d: ", i + 1);
        scanf("%s", bidders[i].name);
        bidders[i].id = i + 1;
        bidders[i].bid = 0;
    }

    printf("\nItem up for auction:\n");
    printf("--------------------\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("--------------------\n\n");

    while (1) {
        printf("\nCurrent highest bid: $%d by bidder %d\n", max_bid, bidders[0].id);
        printf("Enter your bid (0 to quit): ");
        scanf("%d", &bid);

        if (bid == 0) {
            break;
        }

        if (bid > max_bid) {
            max_bid = bid;
            bidders[0].bid = bid;
        } else {
            printf("Your bid is too low.\n");
        }
    }

    printf("\nAuction over! Item sold to bidder %d for $%d.\n", bidders[0].id, max_bid);

    return 0;
}