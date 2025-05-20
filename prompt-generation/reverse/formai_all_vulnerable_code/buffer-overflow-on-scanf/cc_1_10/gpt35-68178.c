//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random integer between two values
int generateRandomInt(int min, int max){
    return ( rand() % (max + 1 - min) ) + min;
}

// function to print the current highest bidder and their bid
void printCurrentBid(char *name, int highestBid){
    printf("The current highest bidder is %s with a bid of $%d.\n", name, highestBid);
}

int main(){
    // initializing variables for auction
    char *item = "rare painting of Sherlock Holmes";
    int startingPrice = 500;
    int minBidIncrement = 50;
    int currentBid = startingPrice;
    char *currentBidder = "no one yet";
    int randomNumber;

    // generating a random seed based on current time
    srand(time(NULL));

    // print the starting information for the auction
    printf("Welcome to the digital auction system for the %s.\n", item);
    printf("The starting price for this item is $%d.\n", startingPrice);
    printf("Bidders must increase their bid by at least $%d.\n", minBidIncrement);

    // loop for placing bids until auction is closed
    while(1){
        // generating a random number between 1-10 to simulate new bids or pausing the auction
        randomNumber = generateRandomInt(1,10);

        // case for when a new bidder places a bid
        if(randomNumber <= 8){
            char *name = malloc(sizeof(char)*50);
            int bid;

            // obtain bidder's name and desired bid
            printf("A new bidder has entered the auction.\n");
            printf("What is your name? ");
            scanf("%s", name);
            printf("What is your desired bid? ");
            scanf("%d", &bid);

            // check if bid is high enough to surpass current highest bid
            if(bid >= currentBid + minBidIncrement){
                printf("Congratulations %s, your bid of $%d is the new highest bid!\n", name, bid);
                currentBid = bid;
                currentBidder = name;
            }
            else{
                printf("I'm sorry %s, your bid of $%d did not exceed the current highest bid of $%d.\n", name, bid, currentBid);
            }
            free(name);
            printCurrentBid(currentBidder, currentBid);
        }
        // case for when the auction is paused for 5 seconds to simulate a break in bidding
        else if(randomNumber == 9){
            printf("The auction is paused for 5 seconds.\n");
            sleep(5);
        }
        // case for when the auction is closed and winner is declared
        else{
            printf("The auction for the %s is now closed.\n", item);
            if(strcmp(currentBidder, "no one yet") == 0){
                printf("There were no bids placed for this item.\n");
            }
            else{
                printf("The winner of the auction is %s with a final bid of $%d for the %s.\n", currentBidder, currentBid, item);
            }
            break;
        }
    }

    return 0;
}