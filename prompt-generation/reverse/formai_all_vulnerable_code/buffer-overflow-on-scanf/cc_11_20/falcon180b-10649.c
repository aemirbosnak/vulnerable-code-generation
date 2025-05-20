//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 10

struct item{
    char name[50];
    int bid;
    int bidder;
};

struct item items[MAX];

int main(){
    int i, j, n, choice, bid, bidder;
    char name[50];

    printf("Enter the number of items to be auctioned: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("\nEnter item name: ");
        scanf(" %[^\n]", items[i].name);
        items[i].bid = 0;
        items[i].bidder = -1;
    }

    while(1){
        printf("\n\nDigital Auction System\n");
        printf("1. Place bid\n2. View bids\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter item name: ");
                scanf(" %[^\n]", name);

                for(i=0; i<n; i++){
                    if(strcmp(name, items[i].name) == 0){
                        printf("\nEnter your bid: ");
                        scanf("%d", &bid);

                        if(items[i].bid == 0){
                            items[i].bid = bid;
                            items[i].bidder = 1;
                        }
                        else if(items[i].bid < bid){
                            items[i].bid = bid;
                            items[i].bidder = 1;
                        }

                        break;
                    }
                }

                if(i == n){
                    printf("\nItem not found!");
                }

                break;

            case 2:
                printf("\n\nCurrent bids:\n");

                for(i=0; i<n; i++){
                    if(items[i].bid!= 0){
                        printf("\n%s: Bid - %d, Bidder - %d\n", items[i].name, items[i].bid, items[i].bidder);
                    }
                }

                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}