//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

void display_candidates(Candidate candidates[], int count) {
    printf("\nCandidates:\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s, Votes: %d\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

void cast_vote(Candidate candidates[], int count) {
    int choice;
    printf("\nEnter candidate number to vote (1 to %d): ", count);
    scanf("%d", &choice);

    if(choice < 1 || choice > count) {
        printf("Invalid choice. Please try again.\n");
    } else {
        candidates[choice - 1].votes++;
        printf("Vote casted for %s successful!\n", candidates[choice - 1].name);
    }
}

void display_results(Candidate candidates[], int count) {
    printf("\nVoting Results:\n");
    for(int i = 0; i < count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"Diana", 0},
        {"Eva", 0}
    };
    int candidate_count = 5;
    int option;

    while(1) {
        printf("\nElectronic Voting System\n");
        printf("1. Cast Vote\n");
        printf("2. Display Candidates\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                cast_vote(candidates, candidate_count);
                break;
            case 2:
                display_candidates(candidates, candidate_count);
                break;
            case 3:
                display_results(candidates, candidate_count);
                break;
            case 4:
                printf("Exiting the voting system.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}