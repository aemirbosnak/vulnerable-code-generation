//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>

/* Election Struct */
typedef struct election {
    char candidate_name[20];
    int candidate_id;
    int vote_count;
} Election;

/* Function to display the candidate list */
void display_candidate_list(Election candidates[], int num_candidates) {
    printf("\nCandidate List:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%d. %s\n", candidates[i].candidate_id, candidates[i].candidate_name);
    }
}

/* Function to cast a vote */
void cast_vote(Election candidates[], int num_candidates, int candidate_id) {
    for(int i=0; i<num_candidates; i++) {
        if(candidates[i].candidate_id == candidate_id) {
            candidates[i].vote_count++;
            printf("\nVote casted successfully to %s\n", candidates[i].candidate_name);
            return;
        }
    }
    printf("\nInvalid candidate ID!\n");
}

/* Function to display the vote count */
void display_vote_count(Election candidates[], int num_candidates) {
    printf("\nVote Count:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%s: %d\n", candidates[i].candidate_name, candidates[i].vote_count);
    }
}

int main() {

    /* Initializing the list of candidates */
    Election candidates[] = {
        {"John Doe", 1, 0},
        {"Jane Doe", 2, 0},
        {"Bob Smith", 3, 0},
        {"Alice Brown", 4, 0},
        {"Tom Wilson", 5, 0}
    };
    int num_candidates = sizeof(candidates)/sizeof(candidates[0]);

    /* Displaying the candidate list */
    display_candidate_list(candidates, num_candidates);

    /* Taking the input from the user */
    int candidate_id;
    printf("\nEnter the candidate ID to cast your vote: ");
    scanf("%d", &candidate_id);

    /* Casting the vote */
    cast_vote(candidates, num_candidates, candidate_id);

    /* Displaying the vote count */
    display_vote_count(candidates, num_candidates);

    return 0;
}