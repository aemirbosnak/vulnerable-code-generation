//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN+1];
    int votes;
} Candidate;

void print_candidates(Candidate *candidates, int num_candidates) {
    printf("===== Candidate List =====\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

int cast_vote(Candidate *candidates, int num_candidates) {
    int choice;
    printf("Enter your vote (1-%d): ", num_candidates);
    scanf("%d", &choice);
    if (choice < 1 || choice > num_candidates) {
        printf("Invalid choice: %d\n", choice);
        return -1;
    }
    candidates[choice-1].votes++;
    printf("Your vote for %s has been cast.\n", candidates[choice-1].name);
    return 0;
}

void print_results(Candidate *candidates, int num_candidates) {
    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        total_votes += candidates[i].votes;
    }
    printf("===== Election Results =====\n");
    printf("Total Votes: %d\n", total_votes);
    printf("============================\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s received %d votes (%.2f%%)\n", candidates[i].name,
               candidates[i].votes, (float)candidates[i].votes/total_votes*100);
    }
    printf("============================\n");
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates;
    printf("Enter the number of candidates (1-%d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);
    if (num_candidates > MAX_CANDIDATES || num_candidates < 1) {
        printf("Invalid number of candidates: %d\n", num_candidates);
        return -1;
    }
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d name (max %d characters): ", i+1, MAX_NAME_LEN);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    print_candidates(candidates, num_candidates);
    while (1) {
        int choice;
        printf("1. Cast Vote\n");
        printf("2. Print Candidate List\n");
        printf("3. Print Election Results\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            cast_vote(candidates, num_candidates);
            break;
        case 2:
            print_candidates(candidates, num_candidates);
            break;
        case 3:
            print_results(candidates, num_candidates);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice: %d\n", choice);
            break;
        }
    }
}