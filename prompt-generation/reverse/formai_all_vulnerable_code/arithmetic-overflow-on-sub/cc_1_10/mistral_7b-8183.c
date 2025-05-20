//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: puzzling
#define MAX_BIDDERS 10
#define MIN_BID 1
#define MAX_BID 1000
#define BID_INCREMENT 10

typedef struct {
    char name[20];
    int bid;
} bidder;

void shuffle(bidder bidders[], int size);
void print_bidders(bidder bidders[], int size);

int main() {
    bidder bidders[MAX_BIDDERS];
    int num_bidders, current_bid = MIN_BID, max_bid = MIN_BID;
    
    printf("Welcome to The Enigmatic Bidder Digital Auction System!\n");

    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    if (num_bidders > MAX_BIDDERS) {
        printf("Sorry, we cannot accommodate that many bidders.\n");
        return 1;
    }

    printf("Bidders, please introduce yourselves:\n");

    for (int i = 0; i < num_bidders; ++i) {
        printf("Bidder %d: ", i + 1);
        scanf("%s", bidders[i].name);
    }

    shuffle(bidders, num_bidders);

    printf("\nThe bidding process will now commence:\n");

    for (int i = 0; i < num_bidders; ++i) {
        bidder current_bidder = bidders[i];

        printf("\nBidder %s's turn:\n", current_bidder.name);

        if (current_bid >= MAX_BID) {
            printf("The auction is closed. The highest bid is %d.\n", max_bid);
            print_bidders(bidders, num_bidders);
            return 0;
        }

        current_bidder.bid = current_bid;
        current_bid += BID_INCREMENT;

        if (current_bidder.bid > max_bid) {
            max_bid = current_bidder.bid;
        }
    }

    print_bidders(bidders, num_bidders);
    printf("\nThe auction is closed. The highest bid is %d.\n", max_bid);

    return 0;
}

void shuffle(bidder bidders[], int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        bidder temp = bidders[i];
        bidders[i] = bidders[j];
        bidders[j] = temp;
    }
}

void print_bidders(bidder bidders[], int size) {
    printf("\nThe bidders in order of their bids are:\n");
    for (int i = 0; i < size; ++i) {
        printf("Bidder %s: %d\n", bidders[i].name, bidders[i].bid);
    }
}