//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 10

// Struct to represent a candidate
typedef struct {
    int number;
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

// Function to initialize candidates with their names and zero votes
void init_candidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter candidate %d's number and name: ", i + 1);
        scanf("%d%s", &candidates[i].number, candidates[i].name);
        candidates[i].votes = 0;
    }
}

// Function to allow users to cast their votes
void cast_vote() {
    int candidate;

    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &candidate);

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].number == candidate) {
            candidates[i].votes++;
            break;
        }
    }
}

// Function to display current vote counts for all candidates
void display_votes() {
    printf("\nCurrent vote counts:\n");

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    init_candidates();

    do {
        printf("\n1. Cast your vote\n2. View current vote counts\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                cast_vote();
                break;
            case 2:
                display_votes();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}