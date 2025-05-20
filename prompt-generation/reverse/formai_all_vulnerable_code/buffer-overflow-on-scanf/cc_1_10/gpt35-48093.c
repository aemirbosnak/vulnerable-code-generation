//FormAI DATASET v1.0 Category: Digital Auction System ; Style: creative
#include<stdio.h>
#include<stdlib.h>

// Structure to store item details
struct Item {
    int item_id;
    char item_name[30];
    float base_price;
    int current_bid;
    char bidder_name[30];
};

// Function to display menu and get user input
int displayMenu() {
    int choice;
    printf("\nWelcome to Digital Auction System\n");
    printf("1. Add Item\n");
    printf("2. Bid on Item\n");
    printf("3. View Items\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct Item items[10];
    int num_items = 0;
    int choice, i;

    do {
        choice = displayMenu();

        switch (choice) {
            case 1:
                // Adding an item
                printf("\nAdding a new item...\n");
                printf("Enter item id: ");
                scanf("%d", &items[num_items].item_id);
                printf("Enter item name: ");
                scanf("%s", items[num_items].item_name);
                printf("Enter base price: ");
                scanf("%f", &items[num_items].base_price);
                items[num_items].current_bid = items[num_items].base_price;
                printf("Item added successfully!\n");
                num_items++;
                break;
            case 2:
                // Bidding on an item
                printf("\nBidding on an item...\n");
                printf("Enter item id: ");
                int id;
                scanf("%d", &id);
                for (i = 0; i < num_items; i++) {
                    if (items[i].item_id == id) {
                        printf("Enter your name: ");
                        scanf("%s", items[i].bidder_name);
                        printf("Enter bid amount: ");
                        scanf("%d", &items[i].current_bid);
                        printf("Bidding successful!\n");
                        break;
                    }
                }
                if (i == num_items) {
                    printf("Item not found!\n");
                }
                break;
            case 3:
                // Viewing items
                printf("\nViewing items...\n\n");
                printf("Item ID\tItem Name\tBase Price\tCurrent Bid\tBidder Name\n");
                for (i = 0; i < num_items; i++) {
                    printf("%d\t%s\t%.2f\t\t%d\t\t%s\n", items[i].item_id, items[i].item_name, items[i].base_price, items[i].current_bid, items[i].bidder_name);
                }
                break;
            case 4:
                printf("\nExiting the program...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}