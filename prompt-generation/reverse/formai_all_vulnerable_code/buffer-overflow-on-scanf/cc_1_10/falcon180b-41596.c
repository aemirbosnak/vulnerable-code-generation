//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    char name[50];
    int vote;
};

void generate_candidates(struct candidate candidates[]) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
        sprintf(candidates[i].name, "Candidate %d", i + 1);
    }
}

void generate_voters(struct voter voters[], int num_voters) {
    int i;
    for (i = 0; i < num_voters; i++) {
        voters[i].vote = -1;
        sprintf(voters[i].name, "Voter %d", i + 1);
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];
    int num_voters = 0;
    int num_candidates = 0;
    int i, j, choice;

    srand(time(NULL));

    // Generate candidates
    generate_candidates(candidates);
    printf("Candidates:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    // Generate voters
    printf("\nHow many voters? ");
    scanf("%d", &num_voters);
    generate_voters(voters, num_voters);

    // Vote
    printf("\nVoting...\n");
    for (i = 0; i < num_voters; i++) {
        do {
            printf("\n%s, please enter your vote (1-%d): ", voters[i].name, MAX_CANDIDATES);
            scanf("%d", &choice);
            if (choice < 1 || choice > MAX_CANDIDATES) {
                printf("Invalid choice.\n");
            }
        } while (choice < 1 || choice > MAX_CANDIDATES);
        candidates[choice - 1].votes++;
        voters[i].vote = choice;
    }

    // Display results
    printf("\nResults:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }

    return 0;
}