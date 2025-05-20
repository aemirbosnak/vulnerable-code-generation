//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int bid;
} Bidder;

void displayBidders(Bidder bidders[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", bidders[i].name, bidders[i].bid);
    }
}

int main() {
    srand(time(0));

    int n;
    printf("Enter number of items for auction: ");
    scanf("%d", &n);

    char items[n][50];
    for (int i = 0; i < n; i++) {
        printf("Enter item %d: ", i + 1);
        scanf("%s", items[i]);
    }

    int m;
    printf("Enter number of bidders: ");
    scanf("%d", &m);

    Bidder bidders[m];
    for (int i = 0; i < m; i++) {
        printf("Enter bidder %d name: ", i + 1);
        scanf("%s", bidders[i].name);
        bidders[i].bid = rand() % 101;
    }

    int maxBid[n];
    for (int i = 0; i < n; i++) {
        maxBid[i] = bidders[0].bid;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (bidders[i].bid > maxBid[j]) {
                maxBid[j] = bidders[i].bid;
            }
        }
    }

    printf("\nAuction Results:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %s sold for %d to ", items[i], maxBid[i]);
        int k = 0;
        for (int j = 0; j < m; j++) {
            if (bidders[j].bid == maxBid[i]) {
                printf("%s ", bidders[j].name);
                k++;
            }
        }
        if (k == 0) {
            printf("no one");
        }
        printf("\n");
    }

    return 0;
}