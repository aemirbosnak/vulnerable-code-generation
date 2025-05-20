//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define Candidate Structure
typedef struct {
    char name[30];
    int votes;
} Candidate;

// Define Voter Structure
typedef struct {
    char name[30];
    int candidate_id;
    bool voted;
} Voter;

// Define Election Structure
typedef struct {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
} Election;

// Initialize Election Variables
Election election = {{
    {"Candidate 1", 0},
    {"Candidate 2", 0},
    {"Candidate 3", 0}
}, {}, 3, 0};

// Function to display the list of candidates
void display_candidates() {
    printf("List of Candidates:\n");
    for (int i = 0; i < election.num_candidates; i++) {
        printf("%d. %s\n", i+1, election.candidates[i].name);
    }
}

// Function to get voter details and cast vote
void cast_vote() {
    char voter_name[30];
    int candidate_id;
    printf("Enter your name: ");
    scanf("%s", voter_name);
    for (int i = 0; i < election.num_voters; i++) {
        if (strcmp(election.voters[i].name, voter_name) == 0) {
            printf("You have already voted!\n");
            return;
        }
    }
    display_candidates();
    printf("Enter the candidate ID you want to vote for: ");
    scanf("%d", &candidate_id);
    if (candidate_id < 1 || candidate_id > election.num_candidates) {
        printf("Invalid candidate ID!\n");
        return;
    }
    // Update candidate vote count
    election.candidates[candidate_id-1].votes++;
    // Add voter to voter list
    strcpy(election.voters[election.num_voters].name, voter_name);
    election.voters[election.num_voters].candidate_id = candidate_id;
    election.voters[election.num_voters].voted = true;
    // Update number of voters
    election.num_voters++;
    printf("Thank you for voting!\n");
}

// Function to display election results
void display_results() {
    printf("Election Results:\n");
    for (int i = 0; i < election.num_candidates; i++) {
        printf("%s: %d votes\n", election.candidates[i].name, election.candidates[i].votes);
    }
}

int main() {
    int choice;
    do {
        printf("Electronic Voting System\n");
        printf("1. Cast Vote\n");
        printf("2. View Election Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                cast_vote();
                break;
            case 2:
                display_results();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}