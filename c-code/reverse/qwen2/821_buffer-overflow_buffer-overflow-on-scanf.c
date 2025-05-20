#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
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
    printf("Enter candidate name: ");
    scanf("%s", candidates[candidate_count].name);
    candidates[candidate_count].votes = 0;
    candidate_count++;
}

void cast_vote() {
    char vote[MAX_NAME_LENGTH];
    printf("Enter your vote: ");
    scanf("%s", vote);
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, vote) == 0) {
            candidates[i].votes++;
            return;
        }
    }
    printf("Invalid candidate name.\n");
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Candidate\n2. Cast Vote\n3. Display Results\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
