//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 10000
#define MAX_OPTIONS 5

// Struct for storing a vote
typedef struct {
    int voter_id;
    int option;
} Vote;

// Global variables
int num_voters = 0;
int num_options = 0;
Vote *votes = NULL;

// Function to initialize the system
void init() {
    srand(time(NULL));

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of voters:\n");
    scanf("%d", &num_voters);

    printf("Please enter the number of options:\n");
    scanf("%d", &num_options);

    votes = (Vote*) malloc(num_voters * sizeof(Vote));
}

// Function to generate a random voter ID
int generate_voter_id() {
    return rand() % MAX_VOTERS + 1;
}

// Function to generate a random option number
int generate_option() {
    return rand() % MAX_OPTIONS + 1;
}

// Function to record a vote
void record_vote() {
    votes[num_voters - 1].voter_id = generate_voter_id();
    votes[num_voters - 1].option = generate_option();

    printf("Voter %d has voted for option %d.\n", votes[num_voters - 1].voter_id, votes[num_voters - 1].option);

    num_voters--;
}

// Function to count the votes for each option
void count_votes() {
    int i, votes_for_option[MAX_OPTIONS] = {0};

    for (i = 0; i < num_voters; i++) {
        votes_for_option[votes[i].option - 1]++;
    }

    printf("\nVote count:\n");

    for (i = 0; i < num_options; i++) {
        printf("Option %d: %d votes\n", i + 1, votes_for_option[i]);
    }
}

int main() {
    init();

    for (int i = 0; i < num_voters; i++) {
        record_vote();
    }

    count_votes();

    free(votes);

    return 0;
}