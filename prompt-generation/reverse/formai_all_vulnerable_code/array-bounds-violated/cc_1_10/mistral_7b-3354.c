//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CANDIDATES 5
#define CANDIDATE_NAME_LENGTH 50

typedef struct {
    char name[CANDIDATE_NAME_LENGTH];
    int votes;
} candidate;

candidate candidates[MAX_CANDIDATES];

bool is_valid_candidate(int candidate_number) {
    return candidate_number >= 0 && candidate_number < MAX_CANDIDATES;
}

void print_candidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

void vote(int candidate_number) {
    if (!is_valid_candidate(candidate_number)) {
        printf("Invalid candidate number.\n");
        return;
    }

    candidates[candidate_number].votes++;
}

int main() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter candidate %d name: ", i+1);
        fgets(candidates[i].name, CANDIDATE_NAME_LENGTH, stdin);
        candidates[i].name[strlen(candidates[i].name)-1] = '\0'; // remove newline character
    }

    int choice;
    while (true) {
        printf("\nCandidate list:\n");
        print_candidates();
        printf("\nEnter your choice (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        vote(choice-1);
    }

    printf("\nFinal vote count:\n");
    print_candidates();

    return 0;
}