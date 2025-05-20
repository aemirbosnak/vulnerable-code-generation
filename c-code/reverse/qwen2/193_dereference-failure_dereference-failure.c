#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10

typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

void printCandidates(Candidate candidates[], int count) {
    printf("Available Candidates:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {1, "Candidate A", 0},
        {2, "Candidate B", 0},
        {3, "Candidate C", 0}
    };
    int numCandidates = 3;
    int choice;

    while (1) {
        printCandidates(candidates, numCandidates);
        printf("Enter your vote (1-%d) or 0 to exit: ", numCandidates);
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        if (choice >= 1 && choice <= numCandidates) {
            candidates[choice - 1].votes++;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}
