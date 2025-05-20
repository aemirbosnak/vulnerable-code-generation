//FormAI DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct to store auction details
struct auction {
    int id;
    char item[50];
    float initial_bid;
    float current_bid;
    char bidder[50];
};

// function to add an auction item to the system
void add_auction(struct auction auctions[], int *num_auctions) {
    printf("\nEnter details of the item to be auctioned:\n");
    printf("ID: ");
    scanf("%d", &(auctions[*num_auctions].id));
    getchar(); // to consume trailing newline character
    printf("Item name: ");
    fgets(auctions[*num_auctions].item, 50, stdin);
    auctions[*num_auctions].item[strcspn(auctions[*num_auctions].item, "\n")] = '\0'; // to remove trailing newline character
    printf("Initial bid: ");
    scanf("%f", &(auctions[*num_auctions].initial_bid));
    auctions[*num_auctions].current_bid = auctions[*num_auctions].initial_bid;
    printf("Bidder name: ");
    getchar(); // to consume trailing newline character
    fgets(auctions[*num_auctions].bidder, 50, stdin);
    auctions[*num_auctions].bidder[strcspn(auctions[*num_auctions].bidder, "\n")] = '\0'; // to remove trailing newline character
    (*num_auctions)++;
    printf("\nItem added to the auction system successfully!\n");
}

// function to display all auction items in the system
void display_auctions(struct auction auctions[], int num_auctions) {
    if(num_auctions == 0) {
        printf("\nThere are no auction items in the system.\n");
    } else {
        printf("\nAll auction items in the system:\n");
        printf("ID\tItem name\tInitial bid\tCurrent bid\tBidder name\n");
        for(int i=0; i<num_auctions; i++) {
            printf("%d\t%s\t$%.2f\t\t$%.2f\t\t%s\n", auctions[i].id, auctions[i].item, auctions[i].initial_bid, auctions[i].current_bid, auctions[i].bidder);
        }
    }
}

// function to start bidding process for an auction item
void start_bid(struct auction auctions[], int num_auctions) {
    int id;
    printf("\nEnter the ID of the auction item for bidding: ");
    scanf("%d", &id);
    int i;
    for(i=0; i<num_auctions && auctions[i].id!=id; i++);
    if(i == num_auctions) {
        printf("\nInvalid ID! There is no auction item with ID %d.\n", id);
    } else {
        float bid;
        printf("\nEnter your bid for the item (must be greater than current bid of $%.2f): ", auctions[i].current_bid);
        scanf("%f", &bid);
        if(bid > auctions[i].current_bid) {
            auctions[i].current_bid = bid;
            printf("\nYour bid of $%.2f for the item \"%s\" has been accepted and recorded successfully!\n", bid, auctions[i].item);
            printf("Bidder name: ");
            getchar(); // to consume trailing newline character
            fgets(auctions[i].bidder, 50, stdin);
            auctions[i].bidder[strcspn(auctions[i].bidder, "\n")] = '\0'; // to remove trailing newline character
        } else {
            printf("\nYour bid of $%.2f for the item \"%s\" is not valid. The current bid is $%.2f. Please try again with a higher bid.\n", bid, auctions[i].item, auctions[i].current_bid);
        }
    }
}

int main() {
    int num_auctions = 0; // to keep track of number of auctions in the system
    struct auction auctions[50]; // array to store auction details, with maximum size of 50
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add an auction item\n");
        printf("2. Display all auction items\n");
        printf("3. Start bidding process for an auction item\n");
        printf("4. Exit\n");
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_auction(auctions, &num_auctions);
                break;
            case 2:
                display_auctions(auctions, num_auctions);
                break;
            case 3:
                start_bid(auctions, num_auctions);
                break;
            case 4:
                printf("\nExiting the system...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}