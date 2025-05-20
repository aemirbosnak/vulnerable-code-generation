//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES 5

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    char name[50];
    int age;
    int votes[MAX_CANDIDATES];
};

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    struct candidate candidates[MAX_CANDIDATES];
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    struct voter voters[MAX_VOTERS];
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        printf("Enter the age of voter %d: ", i + 1);
        scanf("%d", &voters[i].age);
    }

    printf("Enter the votes for each candidate:\n");
    for (int i = 0; i < num_candidates; i++) {
        for (int j = 0; j < num_voters; j++) {
            printf("Enter the vote for candidate %s by voter %s (0 to %d): ", candidates[i].name, voters[j].name, MAX_CANDIDATES);
            scanf("%d", &voters[j].votes[i]);
            candidates[i].votes += voters[j].votes[i];
        }
    }

    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}