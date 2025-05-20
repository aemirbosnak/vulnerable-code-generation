//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct voter {
    char name[50];
    int age;
    char address[100];
    int voted;
};

struct candidate {
    char name[50];
    int votes;
};

int main() {
    struct voter voters[100];
    struct candidate candidates[100];

    int n_voters, n_candidates;

    printf("Enter number of voters: ");
    scanf("%d", &n_voters);

    printf("Enter number of candidates: ");
    scanf("%d", &n_candidates);

    for (int i = 0; i < n_voters; i++) {
        printf("Enter voter %d's name: ", i + 1);
        scanf("%s", voters[i].name);

        printf("Enter voter %d's age: ", i + 1);
        scanf("%d", &voters[i].age);

        printf("Enter voter %d's address: ", i + 1);
        scanf("%s", voters[i].address);

        voters[i].voted = 0;
    }

    for (int i = 0; i < n_candidates; i++) {
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidates[i].name);

        candidates[i].votes = 0;
    }

    printf("\nWelcome to the voting system!\n");
    printf("You have %d voters and %d candidates.\n", n_voters, n_candidates);
    printf("Enter the name of the voter you want to vote for: ");
    scanf("%s", voters[0].name);

    for (int i = 0; i < n_voters; i++) {
        if (strcmp(voters[i].name, voters[0].name) == 0) {
            printf("You have already voted!\n");
            return 0;
        }
    }

    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", candidates[0].name);

    for (int i = 0; i < n_candidates; i++) {
        if (strcmp(candidates[i].name, candidates[0].name) == 0) {
            printf("You have already voted for this candidate!\n");
            return 0;
        }
    }

    voters[0].voted = 1;
    candidates[0].votes++;

    printf("Voting successful!\n");
    printf("You have voted for %s and %s has %d votes.\n", voters[0].name, candidates[0].name, candidates[0].votes);

    return 0;
}