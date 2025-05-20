//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10 // maximum number of candidates

// structure to store candidate information
struct candidate {
    int id;
    char name[50];
    int votes;
};

// function to display candidate information
void display_candidate(struct candidate c) {
    printf("Candidate %d: %s\n", c.id, c.name);
}

// function to display all candidates in the array
void display_all_candidates(struct candidate candidates[], int num_candidates) {
    printf("List of Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        display_candidate(candidates[i]);
    }
}

// function to get user input and validate it
int get_user_input(int min, int max) {
    int input;
    printf(">>> ");
    scanf("%d", &input);
    while (input < min || input > max) {
        printf("Invalid input, please enter between %d and %d: ", min, max);
        scanf("%d", &input);
    }
    return input;
}

// function to cast vote
void cast_vote(struct candidate candidates[], int num_candidates) {
    display_all_candidates(candidates, num_candidates);
    printf("Enter the ID of the candidate you want to vote for:\n");
    int candidate_id = get_user_input(1, num_candidates);
    candidates[candidate_id - 1].votes++;
    printf("Thank you for casting your vote!\n");
}

// function to display the winner(s)
void display_winner(struct candidate candidates[], int num_candidates) {
    int max_votes = 0;
    printf("Winner(s):\n");
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes == max_votes) {
            display_candidate(candidates[i]);
        }
    }
}

int main() {
    // initialize candidate information
    struct candidate candidates[MAX_CANDIDATES] = {
        {1, "John Smith", 0},
        {2, "Jane Doe", 0},
        {3, "Bob Johnson", 0},
        // add more candidates here if desired
    };
    int num_candidates = 3; // update if more candidates added

    // main program loop
    while (1) {
        printf("\nWelcome to the Electronic Voting System!\n");
        printf("1. Cast a vote\n");
        printf("2. Display winner\n");
        printf("0. Exit\n");
        int choice = get_user_input(0, 2);
        switch (choice) {
            case 1:
                cast_vote(candidates, num_candidates);
                break;
            case 2:
                display_winner(candidates, num_candidates);
                break;
            case 0:
                printf("Thank you for using the Electronic Voting System! Goodbye!\n");
                return 0;
        }
    }
}