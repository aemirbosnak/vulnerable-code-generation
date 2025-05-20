//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10   // Maximum number of candidates
#define MAX_VOTERS 100      // Maximum number of voters

// Candidate structure
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Voter structure
typedef struct {
    char name[50];
    int candidate_id;
    bool voted;
} Voter;

int num_candidates = 0;     // Tracks the number of candidates 
int num_voters = 0;         // Tracks the number of voters 

// Array to store the candidates
Candidate candidates[MAX_CANDIDATES];

// Array to store the voters
Voter voters[MAX_VOTERS];

// Displays the menu to the user
void display_menu() {
    printf("Welcome to the Electronic Voting System!\n");
    printf("1. Add Candidate\n");
    printf("2. Vote\n");
    printf("3. Results\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

// Adds a candidate to the candidates array
void add_candidate() {
    Candidate candidate;
    printf("Enter the name of the candidate: ");
    scanf("%s", candidate.name);
    candidate.votes = 0;
    candidates[num_candidates++] = candidate;
    printf("Candidate added successfully!\n");
}

// Casts a vote for a candidate
void cast_vote() {
    Voter voter;
    printf("Enter your name: ");
    scanf("%s", voter.name);
    while (true) {
        printf("Enter the number of the candidate you want to vote for (1-%d): ", num_candidates);
        scanf("%d", &voter.candidate_id);
        if (voter.candidate_id < 1 || voter.candidate_id > num_candidates) {
            printf("Invalid candidate number. Please try again.\n");
        } else {
            break;
        }
    }
    voter.voted = true;
    voters[num_voters++] = voter;
    printf("Vote cast successfully!\n");
}

// Displays the results of the election
void display_results() {
    printf("\nResults of the Election:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d) %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

int main() {
    int choice;
    while (true) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                cast_vote();
                break;
            case 3:
                display_results();
                break;
            case 4:
                printf("Thanks for using the Electronic Voting System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}