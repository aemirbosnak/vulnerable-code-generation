//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Candidate {
    char name[30];
    int votes;
};

int main() {

    int i, voter_count, candidate_count, choice;
    struct Candidate candidates[10];
    char voter_district[50];

    printf("Welcome to the Electronic Voting System\n");
    printf("---------------------------------------\n");

    printf("Enter your district name: ");
    scanf("%s", &voter_district);

    printf("Enter the number of candidates: ");
    scanf("%d", &candidate_count);

    // initialize candidates
    for(i=0;i<candidate_count;i++) {
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", &candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &voter_count);

    // begin voting process
    for(i=0;i<voter_count;i++) {
        printf("\nVoter %d in district %s, please cast your vote!\n", i+1, voter_district);

        printf("Candidates:\n");
        for(int j=0;j<candidate_count;j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // validate choice
        if(choice <= 0 || choice > candidate_count) {
            printf("Invalid choice.\n");
            i--; // vote does not count, try again
            continue;
        }

        // update candidate with vote
        candidates[choice-1].votes++;

        printf("Thank you for voting!\n");
    }

    // print election results
    printf("\nElection Results:\n");
    for(i=0;i<candidate_count;i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // determine winner
    int max_votes = 0, winner_index;
    for(i=0;i<candidate_count;i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    printf("\n%s won the election with %d votes!\n", candidates[winner_index].name, candidates[winner_index].votes);

    return 0;
}