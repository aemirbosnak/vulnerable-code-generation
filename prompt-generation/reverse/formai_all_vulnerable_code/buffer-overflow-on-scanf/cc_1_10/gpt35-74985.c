//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Candidate {
    char name[20];
    int votes;
};

void cast_vote(struct Candidate candidates[], int num_candidates) {
    printf("Please enter the candidate number you wish to vote for: \n");
    for (int i=0; i<num_candidates; i++) {
        printf("%d - %s\n", i+1, candidates[i].name);
    }

    int vote;
    scanf("%d", &vote);

    if (vote <= num_candidates && vote > 0) {
        candidates[vote-1].votes += 1;
        printf("Thank you for casting your vote!\n");
    } else {
        printf("Invalid candidate number. Please try again.\n");
        cast_vote(candidates, num_candidates);
    }
}

int main() {
    int num_candidates;
    printf("Please enter the number of candidates in the election: \n");
    scanf("%d", &num_candidates);

    struct Candidate candidates[num_candidates];
    for (int i=0; i<num_candidates; i++) {
        printf("Please enter the name of candidate %d: \n", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("\nWelcome to the Electronic Voting System!\n");
    int num_voters;
    printf("Please enter the number of voters: \n");
    scanf("%d", &num_voters);

    for (int i=0; i<num_voters; i++) {
        printf("\nVoter %d, please enter your name: \n", i+1);
        char voter_name[20];
        scanf("%s", voter_name);

        printf("Hello %s! It is time to cast your vote!\n", voter_name);
        cast_vote(candidates, num_candidates);
    }

    printf("\n=====ELECTION RESULTS=====\n");
    for (int i=0; i<num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    printf("\nThank you for using the Electronic Voting System!\n");
    return 0;
}