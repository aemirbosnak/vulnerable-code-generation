//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voter_id[20];
    int has_voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int total_voters, total_candidates;

void initialize_candidates() {
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &total_candidates);
    getchar(); // clear newline character from input buffer

    for (int i = 0; i < total_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // remove newline
        candidates[i].votes = 0;
    }
}

void initialize_voters() {
    printf("Enter the total number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &total_voters);
    getchar(); // clear newline character from input buffer

    for (int i = 0; i < total_voters; i++) {
        printf("Enter voter ID for voter %d: ", i + 1);
        fgets(voters[i].voter_id, sizeof(voters[i].voter_id), stdin);
        voters[i].voter_id[strcspn(voters[i].voter_id, "\n")] = 0; // remove newline
        voters[i].has_voted = 0;
    }
}

void cast_vote() {
    char voter_id[20];
    printf("Enter your voter ID: ");
    scanf("%s", voter_id);

    for (int i = 0; i < total_voters; i++) {
        if (strcmp(voters[i].voter_id, voter_id) == 0) {
            if (voters[i].has_voted) {
                printf("You have already voted!\n");
                return;
            }
            printf("Vote for candidate:\n");
            for (int j = 0; j < total_candidates; j++) {
                printf("[%d] %s\n", j + 1, candidates[j].name);
            }

            int vote;
            printf("Enter candidate number: ");
            scanf("%d", &vote);
            if (vote < 1 || vote > total_candidates) {
                printf("Invalid choice. Vote not counted.\n");
                return;
            }

            candidates[vote - 1].votes++;
            voters[i].has_voted = 1;
            printf("Vote casted successfully for %s!\n", candidates[vote - 1].name);
            return;
        }
    }

    printf("Voter ID not found!\n");
}

void display_results() {
    printf("\n--- Election Results ---\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Determine the winner
    int max_votes = -1;
    int winner_index = -1;
    for (int i = 0; i < total_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    if (winner_index != -1) {
        printf("The winner is %s with %d votes!\n", candidates[winner_index].name, max_votes);
    }
}

int main() {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- E-Voting System Menu ---\n");
        printf("1. Initialize Candidates\n");
        printf("2. Initialize Voters\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("0. Exit\n");
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
            case 0:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}