//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Custom data types
typedef struct candidate {
    int id;
    char name[20];
    int votes;
} Candidate;

//Global Variables
int num_candidates;
Candidate* candidates;
int* voter_ids;
int* voter_votes;

//Function Declarations
void initialize();
void display_candidates();
void cast_votes();
void tally_votes();
void announce_winner();

int main() {
    //Welcome Message
    printf("Welcome to the Electronic Voting System!\n");

    //Initialize System
    initialize();

    //Display Candidates
    printf("\n\nList of Candidates:\n");
    display_candidates();

    //Cast Votes
    cast_votes();

    //Tally Votes
    tally_votes();

    //Announce Winner
    announce_winner();

    return 0;
}

void initialize() {
    //Number of Candidates
    printf("\nEnter number of candidates: ");
    scanf("%d", &num_candidates);

    //Allocate Memory
    candidates = (Candidate*) malloc(num_candidates * sizeof(Candidate));
    voter_ids = (int*) malloc(num_candidates * sizeof(int));
    voter_votes = (int*) malloc(num_candidates * sizeof(int));

    //Enter Candidate Information
    for(int i=0; i<num_candidates; i++) {
        printf("\nEnter details for Candidate %d:\n", (i+1));
        candidates[i].id = (i+1);
        printf("  Name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    //Confirmation Message
    printf("\nSystem Initialized!\n");
}

void display_candidates() {
    for(int i=0; i<num_candidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
}

void cast_votes() {
    //Number of Voters
    int num_voters;
    printf("\nEnter number of voters: ");
    scanf("%d", &num_voters);

    //Cast the Votes
    for(int i=0; i<num_voters; i++) {
        printf("\nVote #%d\n", (i+1));
        int voter_id;
        printf("  ID: ");
        scanf("%d", &voter_id);

        //Check if voter ID already voted
        for(int j=0; j<i; j++) {
            if(voter_ids[j] == voter_id) {
                printf("\nYou have already voted.\n");
                i--;
                sleep(1);
                break;
            }
        }

        //Vote Validity
        int flag=0;
        int candidate_id;
        printf("  Candidate ID: ");
        scanf("%d", &candidate_id);

        //Check if candidate exists
        for(int j=0; j<num_candidates; j++) {
            if(candidates[j].id == candidate_id) {
                candidates[j].votes++;
                voter_votes[i] = candidate_id;
                voter_ids[i] = voter_id;
                flag = 1;
                break;
            }
        }

        //Invalid candidate ID
        if(flag==0) {
            printf("\nInvalid Candidate. Vote not counted.\n");
            i--;
            sleep(1);
        }
    }

    //Confirmation Message
    printf("\nVoting Closed!\n");
}

void tally_votes() {
    //Retrieve Voting Results
    int max_votes = -1;
    int winner_id = -1;
    for(int i=0; i<num_candidates; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_id = candidates[i].id;
        }
    }

    //Display Results
    printf("\n\nFinal Voting Results:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    //Confirmation Message
    sleep(2);
    printf("\nVotes Tally Completed!\n");
}

void announce_winner() {
    //Retrieve Winner
    int max_votes = -1;
    int winner_id = -1;
    for(int i=0; i<num_candidates; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_id = candidates[i].id;
        }
    }

    //Display Winner
    printf("\n\nAnd the Winner is:\n");
    for(int i=0; i<num_candidates; i++) {
        if(candidates[i].id == winner_id) {
            printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
            break;
        }
    }
    printf("\nCongratulations!\n");

    //Confirmation Message
    sleep(3);
    printf("\nWinner Announced!\n");
}