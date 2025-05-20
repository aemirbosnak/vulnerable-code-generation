//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 50

struct candidate {
    int id;
    char name[50];
    int num_votes;
};

struct voter {
    int id;
    bool voted;
    int vote;
};

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];

    int num_candidates = 0;
    int num_voters = 0;
    int vote;

    printf("--- C ELECTRONIC VOTING SYSTEM ---\n\n");

    // Get number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Get candidate details
    for (int i = 0; i < num_candidates; i++) {
        printf("\nEnter Candidate %d Details:\n", i + 1);
        candidates[i].id = i + 1;
        candidates[i].num_votes = 0;
        printf("Name: ");
        scanf("%s", candidates[i].name);
    }

    // Get number of voters
    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);

    // Get voter details
    for (int i = 0; i < num_voters; i++) {
        printf("\nEnter Voter %d Details:\n", i + 1);
        voters[i].id = i + 1;
        voters[i].voted = false;
        voters[i].vote = 0;
    }

    // Voting process
    printf("\n--- VOTING PROCESS ---\n");
    while (true) {
        printf("\nPlease enter your voter ID (or enter 0 to quit): ");
        scanf("%d", &vote);

        if (vote == 0) {
            break;
        }

        // Check if voter has already voted
        if (voters[vote - 1].voted) {
            printf("You have already voted!\n");
        } else {
            printf("\n--- CANDIDATES ---\n");
            printf("ID\tNAME\n");
            for (int i = 0; i < num_candidates; i++) {
                printf("%d\t%s\n", candidates[i].id, candidates[i].name);
            }
            printf("--------------------\n");
            printf("Enter the ID of your chosen candidate: ");
            scanf("%d", &voters[vote - 1].vote);
            if (voters[vote - 1].vote <= num_candidates) {
                candidates[voters[vote - 1].vote - 1].num_votes++;
                voters[vote - 1].voted = true;
                printf("Thank you for voting!\n");
            } else {
                printf("Invalid candidate ID!\n");
            }
        }
    }

    // Display election result
    printf("\n--- ELECTION RESULT ---\n");
    printf("ID\tNAME\t\tVOTES\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d\t%s\t\t%d\n", candidates[i].id, candidates[i].name, candidates[i].num_votes);
    }

    return 0;
}