//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int candidate_count = 0;

void add_candidate() {
    if (candidate_count >= MAX_CANDIDATES) {
        printf("Cannot add more candidates.\n");
        return;
    }
    
    Candidate new_candidate;
    printf("Enter name of the candidate: ");
    scanf(" %[^\n]", new_candidate.name);
    new_candidate.votes = 0;

    candidates[candidate_count++] = new_candidate;
    printf("Candidate '%s' added successfully!\n", new_candidate.name);
}

void cast_vote() {
    printf("Choose a candidate to vote for:\n");
    for (int i = 0; i < candidate_count; ++i) {
        printf("%d: %s\n", i + 1, candidates[i].name);
    }

    int choice;
    printf("Enter candidate number: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > candidate_count) {
        printf("Invalid candidate number. Vote not cast.\n");
    } else {
        candidates[choice - 1].votes++;
        printf("Vote cast for '%s'.\n", candidates[choice - 1].name);
    }
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; ++i) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int option;
    do {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_candidate();
                break;
            case 2:
                cast_vote();
                break;
            case 3:
                display_results();
                break;
            case 4:
                printf("Exiting the voting system. Thank you for participating!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}