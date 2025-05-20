//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000 // Maximum number of voters
#define MAX_CANDIDATES 10 // Maximum number of candidates

// Define the structure for each candidate
typedef struct {
    char name[20];
    int votes;
} Candidate;

// Define the structure for the election
typedef struct {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates;
    int votes_cast;
} Election;

// Prototype for the function that initializes the election
void init_election(Election *e);

// Prototype for the function that adds a candidate to the election
void add_candidate(Election *e, char *name);

// Prototype for the function that displays the candidates in the election
void display_candidates(Election *e);

// Prototype for the function that handles casting a vote
void cast_vote(Election *e, int candidate_num);

// Prototype for the function that declares the winner of the election
void declare_winner(Election *e);

// Main function
int main() {
    Election e;
    char name[20];
    int vote;

    // Initialize the election
    init_election(&e);

    // Loop through and add candidates
    for (int i = 1; i <= e.num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i);
        scanf("%s", name);
        add_candidate(&e, name);
    }

    // Display the candidates
    display_candidates(&e);

    // Loop through and cast votes
    while (1) {
        printf("Enter your vote (or -1 to end voting): ");
        scanf("%d", &vote);

        if (vote == -1) {
            break;
        }

        cast_vote(&e, vote - 1);
    }

    // Display the winner
    declare_winner(&e);

    return 0;
}

// Function that initializes the election
void init_election(Election *e) {
    e->num_candidates = 0;
    e->votes_cast = 0;
}

// Function that adds a candidate to the election
void add_candidate(Election *e, char *name) {
    if (e->num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    Candidate c;
    strcpy(c.name, name);
    c.votes = 0;

    e->candidates[e->num_candidates++] = c;
}

// Function that displays the candidates in the election
void display_candidates(Election *e) {
    printf("Candidates:\n");

    for (int i = 0; i < e->num_candidates; i++) {
        printf("%d. %s\n", i+1, e->candidates[i].name);
    }

    printf("\n");
}

// Function that handles casting a vote
void cast_vote(Election *e, int candidate_num) {
    if (candidate_num < 0 || candidate_num >= e->num_candidates) {
        printf("Invalid candidate number.\n");
        return;
    }

    e->candidates[candidate_num].votes++;
    e->votes_cast++;
}

// Function that declares the winner of the election
void declare_winner(Election *e) {
    int max_votes = 0;
    int num_winners = 0;
    int winners[MAX_CANDIDATES];

    // Find the candidate(s) with the most votes
    for (int i = 0; i < e->num_candidates; i++) {
        if (e->candidates[i].votes > max_votes) {
            max_votes = e->candidates[i].votes;
            num_winners = 1;
            winners[0] = i;
        } else if (e->candidates[i].votes == max_votes) {
            winners[num_winners++] = i;
        }
    }

    // Display the winner(s)
    if (num_winners == 1) {
        printf("%s is the winner with %d votes.\n", e->candidates[winners[0]].name, max_votes);
    } else {
        printf("There is a tie between:\n");
        for (int i = 0; i < num_winners; i++) {
            printf("%s with %d votes.\n", e->candidates[winners[i]].name, max_votes);
        }
    }

    printf("%d votes were cast in total.\n", e->votes_cast);
}