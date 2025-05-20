//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Surreal Electronic Voting System!\n");
    printf("Are you ready to cast your vote?\n");
    printf("Choose the candidate you want to vote for:\n");
    printf("1. A giant octopus named Greg\n");
    printf("2. A sentient cloud of gas called Daisy\n");
    printf("3. An anthropomorphic toaster named Steve\n");

    int vote = 0;
    int count_greg = 0;
    int count_daisy = 0;
    int count_steve = 0;
    int total_votes = 0;

    srand(time(NULL));
    int random_voter = rand() % 5;

    if(random_voter == 2) {
        printf("Oh, it looks like a space-time anomaly has opened up and an alternate universe version of you has appeared!\n");
        printf("This alternate version of you will be casting their vote instead. Surreal, right?\n");
        printf("Don't worry, the results will still count. Time is a construct anyway.\n");

        int alt_vote = rand() % 3 + 1;
        if(alt_vote == 1) {
            printf("The alternate version of you has voted for Greg the giant octopus! How exciting!\n");
            count_greg++;
            total_votes++;
        } else if(alt_vote == 2) {
            printf("The alternate version of you has voted for Daisy the sentient cloud of gas! How ethereal!\n");
            count_daisy++;
            total_votes++;
        } else {
            printf("The alternate version of you has voted for Steve the anthropomorphic toaster! How quirky!\n");
            count_steve++;
            total_votes++;
        }
    } else {
        scanf("%d", &vote);

        if(vote == 1) {
            printf("You have cast your vote for Greg the giant octopus! How surreal!\n");
            count_greg++;
            total_votes++;
        } else if(vote == 2) {
            printf("You have cast your vote for Daisy the sentient cloud of gas! How abstract!\n");
            count_daisy++;
            total_votes++;
        } else if(vote == 3) {
            printf("You have cast your vote for Steve the anthropomorphic toaster! How avant-garde!\n");
            count_steve++;
            total_votes++;
        } else {
            printf("Sorry, that is not a valid option. Please try again.\n");
        }
    }

    printf("Thank you for casting your vote! Here are the current results:\n");
    printf("Greg the giant octopus: %d votes\n", count_greg);
    printf("Daisy the sentient cloud of gas: %d votes\n", count_daisy);
    printf("Steve the anthropomorphic toaster: %d votes\n", count_steve);
    printf("Total number of votes: %d\n", total_votes);

    return 0;
}