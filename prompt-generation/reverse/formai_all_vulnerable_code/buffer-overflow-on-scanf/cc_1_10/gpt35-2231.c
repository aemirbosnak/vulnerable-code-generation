//FormAI DATASET v1.0 Category: Digital Auction System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10
#define MAX_NAME_LEN 50

struct Bid {
    char name[MAX_NAME_LEN+1];
    int bid;
};

void clear_screen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void print_bid(struct Bid *bids, int num_bids) {
    clear_screen();
    printf("Current Bids:\n");
    for(int i = 0; i < num_bids; i++) {
        printf("%s: $%d\n", bids[i].name, bids[i].bid);
    }
    printf("------------------------\n");
}

void print_winner(struct Bid *bids, int num_bids) {
    clear_screen();
    int max_bid = 0;
    int max_index = -1;
    for(int i = 0; i < num_bids; i++) {
        if(bids[i].bid > max_bid) {
            max_bid = bids[i].bid;
            max_index = i;
        }
    }
    if(max_index != -1) {
        printf("The winner is: %s with a bid of $%d!\n", bids[max_index].name, bids[max_index].bid);
    } else {
        printf("No bids were placed!\n");
    }
}

int main() {
    int num_bids = 0;
    struct Bid bids[MAX_BIDS];
    char input[MAX_NAME_LEN+1];
    do {
        print_bid(bids, num_bids);
        printf("Enter your name or exit to end: ");
        fgets(input, MAX_NAME_LEN+1, stdin);
        input[strcspn(input, "\n")] = 0;
        if(strcmp(input, "exit") == 0) {
            print_winner(bids, num_bids);
            break;
        }
        printf("Enter your bid: ");
        int bid;
        scanf("%d", &bid);
        getchar();
        if(num_bids < MAX_BIDS) {
            strcpy(bids[num_bids].name, input);
            bids[num_bids].bid = bid;
            num_bids++;
        } else {
            printf("Maximum number of bids reached!\n");
        }
    } while(num_bids < MAX_BIDS || strcmp(input, "exit") != 0);
    return 0;
}