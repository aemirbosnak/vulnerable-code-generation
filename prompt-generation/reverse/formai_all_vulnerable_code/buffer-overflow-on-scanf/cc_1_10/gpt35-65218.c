//FormAI DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Global variables
float basePrice = 100.0f; //base price for each auction item
int totalItems = 5; //total number of items to be auctioned

//Function declarations
float generateRandomBid(float highestBid);
void displayWinner(float* bids, int numBids);

int main(){

    float bids[totalItems]; //array to store all the bids for each item

    printf("Welcome to the Digital Auction System!\n\n");

    //Loop to process each auction item
    for(int i=0; i<totalItems; i++){

        float highestBid = basePrice; //initialize the highest bid to the base price
        printf("Item %d is up for auction! The starting price is $%.2f\n", i+1, basePrice);

        //Loop to process each bid for the current item
        while(1){
            float currentBid = generateRandomBid(highestBid); //call function to generate a random bid
            printf("The current bid is $%.2f.\n", currentBid);

            char response[5];
            printf("Would you like to place a bid? (yes or no): ");
            scanf("%s", response);

            if(strcmp(response, "yes") == 0){
                highestBid = currentBid;
                printf("Your bid of $%.2f has been placed!\n", highestBid);
            }
            else{
                printf("The auction for item %d has ended! The highest bid was $%.2f\n\n", i+1, highestBid);
                bids[i] = highestBid; //store the highest bid for the current item
                break; //exit the loop for processing bids for the current item
            }
        }
    }

    displayWinner(bids, totalItems); //call function to display the winner for each item

    return 0; //exit program
}

float generateRandomBid(float highestBid){
    srand(time(NULL));
    float range = (highestBid * 0.5f) + (highestBid * 0.3f); //define the range for the random bid
    float randomBid = (((float)rand() / RAND_MAX) * range) + highestBid; //generate random bid within the range
    return randomBid;
}

void displayWinner(float* bids, int numBids){
    printf("The auction has ended! The following bids were placed:\n\n");

    //Loop to display all the bids for each item
    for(int i=0; i<numBids; i++){
        printf("Item %d: $%.2f\n", i+1, bids[i]);
    }

    printf("\n");
    float maxBid = bids[0]; //initialize the max bid to the first bid in the array
    int maxIndex = 0; //initialize the max index to 0

    //Loop to find the index of the max bid
    for(int i=1; i<numBids; i++){
        if(bids[i] > maxBid){
            maxBid = bids[i];
            maxIndex = i;
        }
    }

    printf("The winner of the auction is item %d with a bid of $%.2f!\n", maxIndex+1, maxBid);
}