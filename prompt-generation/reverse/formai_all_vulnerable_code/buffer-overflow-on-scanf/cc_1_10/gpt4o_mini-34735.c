//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    int id;
    int voted; // 1 if voted, 0 otherwise
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void initialize_candidates() {
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);
    getchar(); // To consume newline character
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        fgets(candidates[i].name, 50, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // Remove newline
        candidates[i].votes = 0;
    }
}

void initialize_voters() {
    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);
    for (int i = 0; i < num_voters; i++) {
        voters[i].id = i + 1;
        voters[i].voted = 0; // Initialize to not voted
    }
}

void cast_vote() {
    int voter_id;
    printf("Enter voter ID (1 to %d): ", num_voters);
    scanf("%d", &voter_id);
    
    if (voter_id < 1 || voter_id > num_voters) {
        printf("Invalid voter ID.\n");
        return;
    }

    if (voters[voter_id - 1].voted) {
        printf("Voter has already voted!\n");
        return;
    }

    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int candidate_choice;
    printf("Enter candidate number to vote for: ");
    scanf("%d", &candidate_choice);

    if (candidate_choice < 1 || candidate_choice > num_candidates) {
        printf("Invalid candidate number.\n");
        return;
    }

    candidates[candidate_choice - 1].votes++;
    voters[voter_id - 1].voted = 1;
    printf("Vote casted successfully for %s!\n", candidates[candidate_choice - 1].name);
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void display_menu() {
    printf("\nElectronic Voting System Menu:\n");
    printf("1. Initialize Candidates\n");
    printf("2. Initialize Voters\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initialize_candidates();
                break;
            case 2:
                initialize_voters();
                break;
            case 3:
                cast_vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}