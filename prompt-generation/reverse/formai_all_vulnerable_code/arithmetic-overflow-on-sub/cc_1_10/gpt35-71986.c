//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100    //Maximum number of bidders allowed

//Structure for bidder details
struct bidder {
    char name[50];
    int bid_price;
};

//Function prototype for sorting bidder list based on bid price
void sort_bidders(struct bidder[], int);

int main() {
    int n, i, bid_price, j, highest_bidder = 0;
    char name[50];

    printf("Welcome to Digital Auction System\n");

    //Accept number of bidders
    printf("\nEnter the number of bidders: ");
    scanf("%d", &n);

    //Array of bidder structures
    struct bidder bidders[MAX];

    //Accept details of bidders
    for(i=0; i<n; i++) {
        printf("\nEnter bidder%d name: ", i+1);
        scanf("%s", bidders[i].name);
        printf("Enter bidder%d bid price: ", i+1);
        scanf("%d", &bidders[i].bid_price);
    }

    //Sort bidders based on bid price
    sort_bidders(bidders, n);

    //Display highest bidder and bid price
    printf("\n\nHighest Bidder : %s", bidders[n-1].name);
    printf("\nBid Price : %d", bidders[n-1].bid_price);

    return 0;
}

//Sorting function
void sort_bidders(struct bidder arr[], int n) {
    int i, j;
    struct bidder key;
    for(i=1; i<n; i++) {
        key = arr[i];
        j = i-1;

        //Compare and swap if required
        while(j>=0 && arr[j].bid_price > key.bid_price) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}