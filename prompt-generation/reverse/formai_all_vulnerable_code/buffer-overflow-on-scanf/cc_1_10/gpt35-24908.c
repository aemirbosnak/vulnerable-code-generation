//FormAI DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bid
struct Bid {
    char name[50];
    int amount;
};

// Recursive function to insert a bid into the auction
void insertBid(struct Bid newBid, struct Bid* bids, int size) {
    // Base case: the list of bids is empty
    if (size == 0) {
        bids[0] = newBid;
        printf("Bid from %s of amount %d inserted.\n", newBid.name, newBid.amount);
        return;
    }
    
    // Recursive case: find the appropriate position to insert the new bid
    int index = size - 1;
    while (index >= 0 && bids[index].amount < newBid.amount) {
        index--;
    }
    
    // Shift all the higher bids up one position to make room for the new bid
    if (index < size - 1) {
        for (int i = size - 1; i > index + 1; i--) {
            bids[i] = bids[i - 1];
        }
    }
    
    // Insert the new bid into the appropriate position
    bids[index + 1] = newBid;
    printf("Bid from %s of amount %d inserted.\n", newBid.name, newBid.amount);
}

// Recursive function to display all bids
void displayBids(struct Bid* bids, int size) {
    if (size == 0) {
        printf("No bids to display.\n");
        return;
    }
    printf("List of bids:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s: %d\n", i + 1, bids[i].name, bids[i].amount);
    }
}

int main() {
    struct Bid bids[50];
    int numBids = 0;
    int choice, amount;
    char name[50];
    struct Bid newBid;
    
    while (1) {
        printf("1. Insert bid\n");
        printf("2. Display bids\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%d", &amount);
                newBid.amount = amount;
                strcpy(newBid.name, name);
                insertBid(newBid, bids, numBids);
                numBids++;
                break;
                
            case 2:
                displayBids(bids, numBids);
                break;
                
            case 3:
                exit(0);
                
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    
    return 0;
}