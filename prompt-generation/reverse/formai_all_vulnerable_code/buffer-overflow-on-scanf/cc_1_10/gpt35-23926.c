//FormAI DATASET v1.0 Category: Digital Auction System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    char name[30];
    float price;
} Item;

int main() {
    srand(time(NULL));
    
    Item items[5] = {{"Dreamy Cloud Pillow", 25.0}, {"Rainbow Unicorn Onesie", 50.0}, {"Magical Wizard Wand", 75.0}, {"Giant Glittery Sneaker", 100.0}, {"Enchanted Crystal Ball", 125.0}};
    
    printf("Welcome to the Digital Auction System! Up for bid today we have five surreal items:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
    printf("Let the bidding begin!\n");
    
    int winner_index = -1;
    float highest_bid = 0.0;
    int num_bids = 0;
    int item_choice;
    float bid_amount;
    while(winner_index == -1) {
        printf("Enter the number of the item you would like to bid on: ");
        scanf("%d", &item_choice);
        item_choice--;
        
        Item chosen_item = items[item_choice];
        if(highest_bid >= chosen_item.price) {
            printf("Sorry, your bid is not high enough.\n");
            continue;
        }
        
        printf("Enter your bid for the %s: $", chosen_item.name);
        scanf("%f", &bid_amount);
        
        if(bid_amount <= highest_bid) {
            printf("Sorry, your bid is not high enough.\n");
            continue;
        }
        
        highest_bid = bid_amount;
        winner_index = item_choice;
        num_bids++;
        printf("Congrats! You are now the highest bidder for the %s at $%.2f.\n", chosen_item.name, highest_bid);
        
        int random_event = rand() % 10;
        switch(random_event) {
            case 0:
                printf("Oh no! A giant banana just fell from the sky and smashed the %s! All bids are now void.\n", chosen_item.name);
                winner_index = -1;
                num_bids = 0;
                break;
            case 1:
                printf("Wow! The spirit of Salvador Dali has blessed your bid. You now get a 10%% discount!\n");
                highest_bid *= 0.9;
                break;
            case 2:
                printf("Oops! It turns out the %s is actually cursed. The auction is now cancelled.\n", chosen_item.name);
                winner_index = -1;
                num_bids = 0;
                break;
            default:
                printf("The bidding continues.\n");
                break;
        }
    }
    
    printf("Congratulations! You have won the %s with a final bid of $%.2f.\n", items[winner_index].name, highest_bid);
    printf("Total number of bids placed: %d\n", num_bids);
    
    return 0;
}