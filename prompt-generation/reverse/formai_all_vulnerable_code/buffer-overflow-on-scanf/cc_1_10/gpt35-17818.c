//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

/* A struct to hold information about a candidate */
struct candidate {
    int id;
    char name[20];
    int votes;
};

/* A struct to hold information about a voter */
struct voter {
    int id;
    char name[20];
    int voted_for;
};

/* Global variables for the candidates and voters */
struct candidate candidates[MAX_CANDIDATES];
struct voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

/* Function to add a candidate */
void add_candidate() {
    if (candidate_count == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    struct candidate new_candidate;

    printf("Enter candidate ID: ");
    scanf("%d", &new_candidate.id);

    printf("Enter candidate name: ");
    scanf("%s", new_candidate.name);

    new_candidate.votes = 0;

    candidates[candidate_count] = new_candidate;
    candidate_count++;

    printf("Candidate added successfully.\n");
}

/* Function to add a voter */
void add_voter() {
    if (voter_count == MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }

    struct voter new_voter;

    printf("Enter voter ID: ");
    scanf("%d", &new_voter.id);

    printf("Enter voter name: ");
    scanf("%s", new_voter.name);

    new_voter.voted_for = -1;

    voters[voter_count] = new_voter;
    voter_count++;

    printf("Voter added successfully.\n");
}

/* Function to display a list of candidates */
void display_candidates() {
    printf("Candidate ID  Candidate Name\n");

    for (int i = 0; i < candidate_count; i++) {
        printf("     %d         %s\n", candidates[i].id, candidates[i].name);
    }
}

/* Function to allow a voter to cast their vote */
void vote() {
    int voter_id, candidate_id, candidate_index;

    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);

    for (int i = 0; i < voter_count; i++) {
        if (voters[i].id == voter_id) {
            if (voters[i].voted_for != -1) {
                printf("You have already voted.\n");
                return;
            }

            printf("Enter the ID of the candidate you want to vote for: ");
            scanf("%d", &candidate_id);

            candidate_index = -1;

            for (int j = 0; j < candidate_count; j++) {
                if (candidates[j].id == candidate_id) {
                    candidate_index = j;
                    break;
                }
            }

            if (candidate_index == -1) {
                printf("Invalid candidate ID.\n");
                return;
            }

            candidates[candidate_index].votes++;
            voters[i].voted_for = candidate_id;

            printf("Vote cast successfully.\n");
            return;
        }
    }

    printf("Invalid voter ID.\n");
}

/* Function to display the voting results */
void display_results() {
    printf("Candidate Name  Votes\n");

    for (int i = 0; i < candidate_count; i++) {
        printf("   %s          %d\n", candidates[i].name, candidates[i].votes);
    }
}

/* Main function */
int main() {
    int choice;

    while (1) {
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. Display candidates\n");
        printf("4. Vote\n");
        printf("5. Display results\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                add_voter();
                break;
            case 3:
                display_candidates();
                break;
            case 4:
                vote();
                break;
            case 5:
                display_results();
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}