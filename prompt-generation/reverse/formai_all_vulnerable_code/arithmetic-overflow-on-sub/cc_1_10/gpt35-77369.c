//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bidder {
    char name[20];
    int bid;
} Bidder;

int num_bidders;
Bidder *bidders;

void get_num_bidders() {
    printf("Enter number of bidders: ");
    scanf("%d", &num_bidders);
    getchar(); // consume newline
}

void get_bidders() {
    bidders = malloc(sizeof(Bidder) * num_bidders);
    for (int i = 0; i < num_bidders; i++) {
        printf("Enter bidder %d name: ", i + 1);
        fgets(bidders[i].name, 20, stdin);
        bidders[i].name[strcspn(bidders[i].name, "\n")] = '\0'; // remove newline
        printf("Enter bidder %d bid: ", i + 1);
        scanf("%d", &bidders[i].bid);
        getchar(); // consume newline
    }
}

void print_bidders() {
    printf("Bidder list:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%d. %s: $%d\n", i + 1, bidders[i].name, bidders[i].bid);
    }
}

void sort_bidders() {
    Bidder temp;
    for (int i = 0; i < num_bidders - 1; i++) {
        for (int j = 0; j < num_bidders - 1 - i; j++) {
            if (bidders[j].bid < bidders[j + 1].bid) {
                temp = bidders[j];
                bidders[j] = bidders[j + 1];
                bidders[j + 1] = temp;
            }
        }
    }
}

void print_winner() {
    printf("The winner is %s with a bid of $%d!\n", bidders[0].name, bidders[0].bid);
}

int main() {
    get_num_bidders();
    get_bidders();
    print_bidders();
    sort_bidders();
    print_winner();
    free(bidders);
    return 0;
}