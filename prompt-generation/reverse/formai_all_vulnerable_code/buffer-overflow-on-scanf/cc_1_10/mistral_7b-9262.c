//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_OPTIONS 5

typedef struct {
    char name[50];
    int votes[MAX_OPTIONS];
} Candidate;

typedef struct {
    Candidate candidates[MAX_OPTIONS];
    int total_votes;
} Election;

void register_voter(Election *election, char name[50]);
void cast_vote(Election *election, int option);
void display_results(Election election);

int main() {
    Election election;
    int option;
    char name[50];

    for (int i = 0; i < MAX_OPTIONS; i++) {
        strcpy(election.candidates[i].name, "Option ");
        election.candidates[i].votes[0] = 0;
    }

    election.total_votes = 0;

    while (1) {
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter voter name: ");
                scanf("%s", name);
                register_voter(&election, name);
                break;
            case 2:
                printf("Enter option number: ");
                scanf("%d", &option);
                cast_vote(&election, option - 1);
                break;
            case 3:
                display_results(election);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void register_voter(Election *election, char name[50]) {
    // Check if voter already exists
    // If not, add voter to the list
}

void cast_vote(Election *election, int option) {
    // Check if vote is valid
    // If yes, increment the vote count for the given option
}

void display_results(Election election) {
    // Calculate and display the percentage of votes for each option
}