//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of candidates
#define NUM_CANDIDATES 5

// Define the candidate names and corresponding vote counts
char *candidate_names[] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D", "Candidate E"};
int candidate_vote_counts[NUM_CANDIDATES] = {0, 0, 0, 0, 0};

// Function to initialize the candidate vote counts
void init_candidate_vote_counts() {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        candidate_vote_counts[i] = 0;
    }
}

// Function to cast a vote for a candidate
void cast_vote(char *candidate_name) {
    int index = 0;
    for (; index < NUM_CANDIDATES; index++) {
        if (strcmp(candidate_names[index], candidate_name) == 0) {
            break;
        }
    }
    if (index == NUM_CANDIDATES) {
        printf("Invalid candidate name\n");
        return;
    }
    candidate_vote_counts[index]++;
}

// Function to display the current vote count for each candidate
void display_vote_counts() {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d\n", candidate_names[i], candidate_vote_counts[i]);
    }
}

// Function to print the final results
void print_final_results() {
    char *winner = "";
    int max_vote_count = candidate_vote_counts[0];
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (candidate_vote_counts[i] > max_vote_count) {
            max_vote_count = candidate_vote_counts[i];
            winner = candidate_names[i];
        }
    }
    printf("The winner is %s with %d votes\n", winner, max_vote_count);
}

int main() {
    init_candidate_vote_counts();
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the name of the candidate you would like to vote for:\n");
    char candidate_name[50];
    scanf("%s", candidate_name);
    cast_vote(candidate_name);
    printf("Your vote has been recorded!\n");
    printf("Current vote count:\n");
    display_vote_counts();
    printf("Final results:\n");
    print_final_results();
    return 0;
}