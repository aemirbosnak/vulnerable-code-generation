#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void add_candidate() {
    if (candidates[0].votes == 0) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[0].name);
        candidates[0].votes = 1;
    } else {
        printf("Cannot add more candidates.\n");
    }
}

void vote_for_candidate() {
    int choice;
    printf("Choose a candidate:\n");
    for (int i = 0; i < MAX_CANDIDATES && candidates[i].votes != 0; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice > 0 && choice <= MAX_CANDIDATES && candidates[choice - 1].votes != 0) {
        candidates[choice - 1].votes++;
    } else {
        printf("Invalid choice.\n");
    }
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < MAX_CANDIDATES && candidates[i].votes != 0; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Vote for Candidate\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                vote_for_candidate();
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
