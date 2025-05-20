//FormAI DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

//Declare the structure for storing the auction details
struct auction {
    char name[20];
    int id;
    float price;
    int time_left;
};

//Declare a function for printing the details of auction items
void print_auction_item(struct auction item) {
    printf("Name: %s\n", item.name);
    printf("ID: %d\n", item.id);
    printf("Price: $%.2f\n", item.price);
    printf("Time Left: %d minutes\n", item.time_left);
}

//Declare main function
int main() {
    //Declare variables to store the auction items
    struct auction item1 = {"Watch", 001, 75.00, 10};
    struct auction item2 = {"Laptop", 002, 350.50, 20};
    struct auction item3 = {"Camera", 003, 250.00, 15};

    //Print the details of the auction items
    printf("Auction Items:\n");
    print_auction_item(item1);
    printf("\n");
    print_auction_item(item2);
    printf("\n");
    print_auction_item(item3);
    printf("\n");

    //Declare variables to store the bids
    float bid1, bid2, bid3;

    //Ask for the bids from the users
    printf("Enter your bid for Watch: $");
    scanf("%f", &bid1);

    printf("Enter your bid for Laptop: $");
    scanf("%f", &bid2);

    printf("Enter your bid for Camera: $");
    scanf("%f", &bid3);

    //Update the prices of the auction items based on the bids
    item1.price = bid1 > item1.price ? bid1 : item1.price;
    item2.price = bid2 > item2.price ? bid2 : item2.price;
    item3.price = bid3 > item3.price ? bid3 : item3.price;

    //Print the updated details of the auction items
    printf("Updated Auction Items:\n");
    print_auction_item(item1);
    printf("\n");
    print_auction_item(item2);
    printf("\n");
    print_auction_item(item3);
    printf("\n");

    //Declare variables to store the time left for the auction items
    int time_left1, time_left2, time_left3;

    //Ask for the time left for the auction items from the users
    printf("Enter the time left for Watch (in minutes): ");
    scanf("%d", &time_left1);

    printf("Enter the time left for Laptop (in minutes): ");
    scanf("%d", &time_left2);

    printf("Enter the time left for Camera (in minutes): ");
    scanf("%d", &time_left3);

    //Update the time left for the auction items
    item1.time_left = time_left1;
    item2.time_left = time_left2;
    item3.time_left = time_left3;

    //Print the final details of the auction items
    printf("Final Auction Items:\n");
    print_auction_item(item1);
    printf("\n");
    print_auction_item(item2);
    printf("\n");
    print_auction_item(item3);
    printf("\n");

    return 0;
}