//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: portable
// Electronic Voting System in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 50

// Define structure for candidate
typedef struct candidate {
    char name[20];
    int votes;
} Candidate;

// Define structure for voter
typedef struct voter {
    int id;
    int voted;
} Voter;

// Declare global variables
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

// Function to add candidate
void add_candidate() {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum candidates reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

// Function to view candidates
void view_candidates() {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Function to add voter
void add_voter() {
    if (num_voters >= MAX_VOTERS) {
        printf("Maximum voters reached.\n");
        return;
    }
    voters[num_voters].id = num_voters+1;
    voters[num_voters].voted = 0;
    num_voters++;
}

// Function to vote
void vote() {
    int voter_id, candidate_num;
    printf("Enter voter ID: ");
    scanf("%d", &voter_id);
    if (voter_id > num_voters || voter_id <= 0) {
        printf("Invalid voter ID.\n");
        return;
    }
    if (voters[voter_id-1].voted) {
        printf("You have already voted.\n");
        return;
    }
    view_candidates();
    printf("Enter candidate number to vote for: ");
    scanf("%d", &candidate_num);
    if (candidate_num > num_candidates || candidate_num <= 0) {
        printf("Invalid candidate number.\n");
        return;
    }
    candidates[candidate_num-1].votes++;
    voters[voter_id-1].voted = 1;
    printf("Thank you for voting!\n");
}

// Function to view results
void view_results() {
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. View Candidates\n");
        printf("3. Add Voter\n");
        printf("4. Vote\n");
        printf("5. View Results\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                view_candidates();
                break;
            case 3:
                add_voter();
                break;
            case 4:
                vote();
                break;
            case 5:
                view_results();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}