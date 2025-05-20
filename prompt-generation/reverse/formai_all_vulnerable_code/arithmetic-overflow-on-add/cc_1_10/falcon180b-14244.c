//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

candidate candidates[10];
int num_candidates = 0;

void add_candidate() {
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void display_candidates() {
    printf("\nCandidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void vote() {
    int choice;
    printf("\nEnter candidate number to vote for: ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= num_candidates) {
        candidates[choice-1].votes++;
        printf("\nThank you for voting!");
    } else {
        printf("\nInvalid choice. Please try again.");
    }
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    printf("\nWelcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates (1-10): ");
    scanf("%d", &num_candidates);
    for (int i = 0; i < num_candidates; i++) {
        add_candidate();
    }
    display_candidates();
    int choice;
    while (1) {
        printf("\nPress 1 to vote or 0 to exit: ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            vote();
        }
    }
    display_results();
    return 0;
}