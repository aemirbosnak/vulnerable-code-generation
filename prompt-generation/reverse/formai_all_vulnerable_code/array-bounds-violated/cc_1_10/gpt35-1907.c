//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum number of candidates and voters
#define MAX_CANDIDATES 5
#define MAX_VOTERS 50

// define candidate structure
typedef struct candidate {
    char name[20];
    int votes;
} candidate;

// define voter structure
typedef struct voter {
    int id;
    char name[20];
    int voted;
} voter;

// initialize global variables
candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];
int num_candidates = 0, num_voters = 0;

// display menu
void display_menu() {
    printf("\nElectronic Voting System\n");
    printf("----------------------------------\n");
    printf("1. Add Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Vote\n");
    printf("4. Show Results\n");
    printf("5. Exit\n");
}

// add candidate
void add_candidate() {
    if (num_candidates == MAX_CANDIDATES) {
        printf("\nMaximum number of candidates reached!\n");
        return;
    }

    printf("\nEnter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;

    printf("\nCandidate %s added successfully!\n", candidates[num_candidates].name);

    num_candidates++;
}

// register voter
void register_voter() {
    if (num_voters == MAX_VOTERS) {
        printf("\nMaximum number of voters reached!\n");
        return;
    }

    printf("\nEnter voter name: ");
    scanf("%s", voters[num_voters].name);
    voters[num_voters].id = num_voters + 1;
    voters[num_voters].voted = 0;

    printf("\nVoter %s registered successfully!\n", voters[num_voters].name);

    num_voters++;
}

// cast vote
void cast_vote() {
    int voter_id, candidate_id;

    printf("\nEnter voter ID: ");
    scanf("%d", &voter_id);

    // check if voter has already voted
    if (voters[voter_id - 1].voted == 1) {
        printf("\nYou have already voted!\n");
        return;
    }

    printf("\nAvailable candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    printf("\nEnter candidate ID: ");
    scanf("%d", &candidate_id);

    // cast vote
    candidates[candidate_id - 1].votes++;
    voters[voter_id - 1].voted = 1;

    printf("\nVote casted successfully!\n");
}

// show results
void show_results() {
    printf("\nResults:\n");
    printf("-----------------------------\n");

    if (num_candidates == 0) {
        printf("No candidates available!\n");
        return;
    }

    if (num_voters == 0) {
        printf("No voters registered!\n");
        return;
    }

    int max_votes = candidates[0].votes;
    int winner_index = 0;

    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    printf("Total votes casted: %d\n\n", num_voters);

    for (int i = 0; i < num_candidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }

    printf("\nWinner: %s\n", candidates[winner_index].name);
}

// main function
int main() {
    int choice;

    while (1) {
        display_menu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate();
                break;

            case 2:
                register_voter();
                break;

            case 3:
                cast_vote();
                break;

            case 4:
                show_results();
                break;

            case 5:
                printf("\nThank you for using Electronic Voting System!\n\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}