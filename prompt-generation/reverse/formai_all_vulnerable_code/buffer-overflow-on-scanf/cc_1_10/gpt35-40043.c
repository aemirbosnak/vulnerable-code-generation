//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

/*
 * Structure for storing a single candidate
 */
typedef struct candidate {
    char name[30];
    int votes;
} Candidate;

/*
 * Structure for storing the entire election
 */
typedef struct election {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates;
    int num_votes;
} Election;

/*
 * Function to print the list of candidates
 */
void print_candidates(Election *e) {
    printf("\nList of Candidates:\n");
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%d. %s\n", i+1, e->candidates[i].name);
    }
    printf("\n");
}

/*
 * Function to cast a vote
 */
void vote(Election *e, int candidate_index) {
    if (candidate_index < 1 || candidate_index > e->num_candidates) {
        printf("Invalid Candidate Index\n");
        return;
    }
    e->candidates[candidate_index - 1].votes++;
    e->num_votes++;
    printf("Vote Cast for %s\n\n", e->candidates[candidate_index - 1].name);
}

/*
 * Function to print the current vote count
 */
void print_vote_count(Election *e) {
    printf("\nVote Count:\n");
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%s: %d\n", e->candidates[i].name, e->candidates[i].votes);
    }
    printf("\n");
}

/*
 * Main Function
 */
int main(int argc, char *argv[]) {

    // Create an Election
    Election e;
    e.num_candidates = 0;
    e.num_votes = 0;

    // Read the Candidates from the user
    while (1) {
        printf("Enter Candidate Name (0 to Quit): ");
        char name[30];
        scanf("%s", name);
        if (strcmp(name, "0") == 0) {
            break;
        }
        strcpy(e.candidates[e.num_candidates].name, name);
        e.candidates[e.num_candidates].votes = 0;
        e.num_candidates++;
    }

    // Print the Candidates
    print_candidates(&e);

    // Start Voting
    while (1) {
        printf("(Press 0 to Quit)\n");
        printf("Enter Candidate Index to Vote: ");
        int candidate_index;
        scanf("%d", &candidate_index);
        if (candidate_index == 0) {
            break;
        }
        vote(&e, candidate_index);
        print_vote_count(&e);
    }

    // Print the Final Vote Count
    printf("\nFinal Vote Count:\n");
    print_vote_count(&e);

    return 0;
}