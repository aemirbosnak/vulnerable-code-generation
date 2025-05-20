//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: paranoid
// **Paranoid Digital Auction System**

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// **Data Structures**

typedef struct {
    char *item;
    float price;
    int bidder_id;
    time_t timestamp;
} bid_t;

typedef struct {
    int id;
    char *name;
    char *email;
    char *phone;
} bidder_t;

// **Global Variables**

bid_t all_bids[1000];
bidder_t all_bidders[100];
int num_bids = 0;
int num_bidders = 0;

// **Functions**

void add_bid(char *item, float price, int bidder_id) {
    // Check for invalid input
    if (item == NULL || price <= 0 || bidder_id <= 0) {
        printf("Invalid input. Please try again.\n");
        return;
    }

    // Check if the bidder exists
    int bidder_index = -1;
    for (int i = 0; i < num_bidders; i++) {
        if (all_bidders[i].id == bidder_id) {
            bidder_index = i;
            break;
        }
    }
    if (bidder_index == -1) {
        printf("Bidder does not exist. Please register first.\n");
        return;
    }

    // Add the bid to the array
    all_bids[num_bids].item = item;
    all_bids[num_bids].price = price;
    all_bids[num_bids].bidder_id = bidder_id;
    all_bids[num_bids].timestamp = time(NULL);
    num_bids++;
}

void add_bidder(int id, char *name, char *email, char *phone) {
    // Check for invalid input
    if (id <= 0 || name == NULL || email == NULL || phone == NULL) {
        printf("Invalid input. Please try again.\n");
        return;
    }

    // Check if the bidder already exists
    for (int i = 0; i < num_bidders; i++) {
        if (all_bidders[i].id == id) {
            printf("Bidder already exists. Please try again.\n");
            return;
        }
    }

    // Add the bidder to the array
    all_bidders[num_bidders].id = id;
    all_bidders[num_bidders].name = name;
    all_bidders[num_bidders].email = email;
    all_bidders[num_bidders].phone = phone;
    num_bidders++;
}

void print_bids(void) {
    printf("**All Bids**\n");
    for (int i = 0; i < num_bids; i++) {
        printf("%s: $%.2f (Bidder ID: %d, Timestamp: %s)\n",
               all_bids[i].item, all_bids[i].price, all_bids[i].bidder_id,
               ctime(&all_bids[i].timestamp));
    }
}

void print_bidders(void) {
    printf("**All Bidders**\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%d: %s (%s, %s)\n",
               all_bidders[i].id, all_bidders[i].name, all_bidders[i].email,
               all_bidders[i].phone);
    }
}

int main(void) {
    // **Initialization**

    // Seed the random number generator for generating secret IDs
    srand(time(NULL));

    // **User Interface**

    int choice = 0;
    while (choice != 4) {
        printf("\n**Paranoid Digital Auction System**\n");
        printf("1. Add a Bid\n");
        printf("2. Add a Bidder\n");
        printf("3. Print All Bids\n");
        printf("4. Print All Bidders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 1:
                printf("Enter the item: ");
                char item[100];
                scanf("%s", item);
                printf("Enter the price: ");
                float price;
                scanf("%f", &price);
                printf("Enter the bidder ID: ");
                int bidder_id;
                scanf("%d", &bidder_id);
                add_bid(item, price, bidder_id);
                break;
            case 2:
                printf("Enter the bidder ID: ");
                int id;
                scanf("%d", &id);
                printf("Enter the bidder's name: ");
                char name[100];
                scanf("%s", name);
                printf("Enter the bidder's email: ");
                char email[100];
                scanf("%s", email);
                printf("Enter the bidder's phone: ");
                char phone[100];
                scanf("%s", phone);
                add_bidder(id, name, email, phone);
                break;
            case 3:
                print_bids();
                break;
            case 4:
                print_bidders();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}