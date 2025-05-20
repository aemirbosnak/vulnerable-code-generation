//FormAI DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function for generating random bid numbers within a range
int generate_bid(int min, int max){
    return rand()%(max-min+1) + min;
}

int main(){
    int num_bids;
    printf("Welcome to the Digital Auction System!\n\n");
    printf("Enter the number of bids you wish to place: ");
    scanf("%d", &num_bids);

    //Dynamic memory allocation for storing bid amounts and usernames
    float *bid_amounts = (float*) malloc(num_bids*sizeof(float));
    char **usernames = (char**) malloc(num_bids*sizeof(char*));

    //Loop for accepting bids and usernames from the users
    for(int i=0; i<num_bids; i++){
        printf("\nEnter your username and bid amount (separated by a space): ");
        usernames[i] = (char*) malloc(20*sizeof(char));
        scanf("%s %f", usernames[i], &bid_amounts[i]);
    }

    //Seed for generating random bid numbers
    srand(time(0));

    printf("\n\nGenerating highest bid...\n");
    float highest_bid = 0;
    char *winner_username = (char*) malloc(20*sizeof(char));

    //Loop for finding the highest bid and winner username
    for(int i=0; i<num_bids; i++){
        int rand_num = generate_bid(1, 100);
        if(bid_amounts[i] > highest_bid){
            highest_bid = bid_amounts[i];
            winner_username = usernames[i];
        }else if(bid_amounts[i] == highest_bid){
            if(rand_num <= 50){
                highest_bid = bid_amounts[i];
                winner_username = usernames[i];
            }
        }
    }

    printf("\n\nThe highest bid is %.2f made by user %s\n\n", highest_bid, winner_username);

    //Freeing the dynamically allocated memory
    free(bid_amounts);
    for(int i=0; i<num_bids; i++){
        free(usernames[i]);
    }
    free(usernames);

    return 0;
}