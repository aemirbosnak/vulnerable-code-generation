//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int vote_count;
} candidate_t;

typedef struct {
    candidate_t candidates[MAX_CANDIDATES];
    int num_candidates;
    int num_votes;
} election_t;

void print_candidates(candidate_t *candidates, int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("\n");
}

void print_results(candidate_t *candidates, int num_candidates, int num_votes) {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s - %d votes (%.2f%%)\n", candidates[i].name, candidates[i].vote_count, (float)candidates[i].vote_count/num_votes*100);
    }
}

void vote(candidate_t *candidates, int num_candidates) {
    char name[MAX_NAME_LEN];
    printf("Enter candidate name: ");
    scanf("%s", name);

    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            candidates[i].vote_count++;
            printf("You have voted for %s!\n\n", candidates[i].name);
            return;
        }
    }

    printf("Candidate not found. Please try again.\n\n");
}

int main() {
    election_t election;
    memset(&election, 0, sizeof(election_t));

    printf("Welcome to the Electronic Voting System!\n");

    printf("How many candidates are running in this election? (max %d) ", MAX_CANDIDATES);
    scanf("%d", &election.num_candidates);

    if (election.num_candidates <= 0 || election.num_candidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates. Please try again.\n");
        return 1;
    }

    for (int i = 0; i < election.num_candidates; i++) {
        printf("Enter name for candidate %d: ", i+1);
        scanf("%s", election.candidates[i].name);
        election.candidates[i].vote_count = 0;
    }

    printf("\n");

    while (1) {
        printf("1 - Vote\n");
        printf("2 - Print candidates\n");
        printf("3 - Print results\n");
        printf("4 - Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice) {
            case 1:
                vote(election.candidates, election.num_candidates);
                election.num_votes++;
                break;
            case 2:
                print_candidates(election.candidates, election.num_candidates);
                break;
            case 3:
                print_results(election.candidates, election.num_candidates, election.num_votes);
                break;
            case 4:
                printf("Thank you for using the Electronic Voting System!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}