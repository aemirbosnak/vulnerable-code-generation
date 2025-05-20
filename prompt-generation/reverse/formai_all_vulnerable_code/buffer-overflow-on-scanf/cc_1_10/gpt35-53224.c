//FormAI DATASET v1.0 Category: Digital Auction System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Auction struct
typedef struct {
    int id; // The ID of the auction
    char title[50]; // The title of the item
    char description[100]; // The description of the item
    float min_bid; // The minimum bid for the item
    int num_bids; // The number of bids received for the item
    float highest_bid; // The highest bid received for the item
} Auction;

// Prototype functions
int displayMenu();
void createAuction(Auction *auctions, int *num_auctions);
void viewAuctions(Auction *auctions, int num_auctions);
void placeBid(Auction *auctions, int num_auctions);

int main() {
    int choice, num_auctions = 0;
    Auction *auctions = malloc(sizeof(Auction)); // Allocate memory for first auction
    
    printf("Welcome to the Digital Auction System!\n");
    do {
        choice = displayMenu();
        switch (choice) {
            case 1:
                createAuction(auctions, &num_auctions);
                break;
            case 2:
                viewAuctions(auctions, num_auctions);
                break;
            case 3:
                placeBid(auctions, num_auctions);
                break;
            case 4:
                printf("Thank you for using the Digital Auction System!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);
    
    free(auctions); // Free memory allocated for auctions
    
    return 0;
}

int displayMenu() {
    int choice;
    printf("\nChoose an option:\n");
    printf("1. Create auction\n");
    printf("2. View auctions\n");
    printf("3. Place bid\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    return choice;
}

void createAuction(Auction *auctions, int *num_auctions) {
    Auction *temp;
    temp = realloc(auctions, (*num_auctions + 1) * sizeof(Auction)); // Expand memory allocation for auctions
    if (temp != NULL) {
        auctions = temp; // Update pointer to new memory allocation
        Auction new_auction;
        printf("Enter item title: ");
        getchar(); // Clear input buffer
        fgets(new_auction.title, sizeof(new_auction.title), stdin);
        printf("Enter item description: ");
        fgets(new_auction.description, sizeof(new_auction.description), stdin);
        printf("Enter minimum bid: $");
        scanf("%f", &new_auction.min_bid);
        printf("Auction created successfully!\n");
        new_auction.id = *num_auctions + 1; // Set auction ID
        new_auction.num_bids = 0; // Initialize number of bids to 0
        new_auction.highest_bid = new_auction.min_bid; // Set highest bid to minimum bid
        auctions[*num_auctions] = new_auction; // Add new auction to array
        *num_auctions += 1; // Increment the number of auctions
    }
    else {
        printf("Memory allocation failed. Auction not created.\n");
    }
}

void viewAuctions(Auction *auctions, int num_auctions) {
    if (num_auctions == 0) {
        printf("No auctions available.\n");
        return;
    }
    printf("\nAvailable auctions:\n");
    printf("ID\tTitle\t\t\t\tMinimum Bid\tNumber of Bids\tHighest Bid\n");
    for (int i = 0; i < num_auctions; i++) {
        printf("%d\t%-30s $%.2f\t\t%d\t\t$%.2f\n", auctions[i].id, auctions[i].title, auctions[i].min_bid, auctions[i].num_bids, auctions[i].highest_bid);
    }
}

void placeBid(Auction *auctions, int num_auctions) {
    if (num_auctions == 0) {
        printf("No auctions available.\n");
        return;
    }
    int auction_id;
    float bid_amount;
    printf("Enter auction ID: ");
    scanf("%d", &auction_id);
    for (int i = 0; i < num_auctions; i++) {
        if (auctions[i].id == auction_id) {
            printf("Enter bid amount: $");
            scanf("%f", &bid_amount);
            if (bid_amount >= auctions[i].highest_bid) {
                auctions[i].highest_bid = bid_amount;
                auctions[i].num_bids += 1;
                printf("Bid placed successfully!\n");
                return;
            }
            else {
                printf("Bid amount must be greater than or equal to $%.2f.\n", auctions[i].highest_bid);
                return;
            }
        }
    }
    printf("Auction ID not found. Try again.\n");
}