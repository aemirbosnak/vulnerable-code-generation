//FormAI DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100  // maximum number of participants in the auction

struct participant{
    int id;
    char name[50];
    float bid_amount;
};

int main(){
    struct participant auction[MAX]; // array to store participant details
    int num_participants, winning_index;
    float highest_bid = 0.0;  // initialize highest bid value to 0
    
    // seed the random number generator
    srand(time(NULL));
    
    printf("Welcome to the Digital Auction System!\n\n");
    printf("Please enter the number of participants (maximum %d): ", MAX);
    scanf("%d", &num_participants);
    
    // read in participant details
    for(int i=0;i<num_participants;i++){
        printf("\nEnter details for participant %d:\n", i+1);
        auction[i].id = i+1;
        printf("Name: ");
        scanf("%s", auction[i].name);
        printf("Bid Amount: ");
        scanf("%f", &auction[i].bid_amount);
    }
    
    // determine the winner
    for(int i=0;i<num_participants;i++){
        if(auction[i].bid_amount > highest_bid){
            highest_bid = auction[i].bid_amount;
            winning_index = i;
        }
    }
    
    // display the winner
    printf("\nThe winner is %s with a bid of $%.2f!\n", auction[winning_index].name, auction[winning_index].bid_amount);
    
    // generate a random second-place winner
    int second_place_index;
    
    do{
        second_place_index = rand() % num_participants;
    }while(second_place_index == winning_index); // make sure second place is not the same as the first place
    
    printf("\nThe second place winner is %s with a bid of $%.2f\n", auction[second_place_index].name, auction[second_place_index].bid_amount);
    
    return 0;
}