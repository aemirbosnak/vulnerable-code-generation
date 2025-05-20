//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

struct candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct voter {
    char name[MAX_NAME_LENGTH];
    int voted;
};

void read_candidates(struct candidate candidates[]) {
    int i, j;
    char input[MAX_NAME_LENGTH];

    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter candidate name: ");
        scanf("%s", input);
        strcpy(candidates[i].name, input);
        candidates[i].votes = 0;
    }
}

void read_voters(struct voter voters[]) {
    int i, j;
    char input[MAX_NAME_LENGTH];

    for (i = 0; i < MAX_VOTERS; i++) {
        printf("Enter voter name: ");
        scanf("%s", input);
        strcpy(voters[i].name, input);
        voters[i].voted = 0;
    }
}

void vote(struct candidate candidates[], struct voter voters[]) {
    int i, j, choice;

    for (i = 0; i < MAX_VOTERS; i++) {
        if (!voters[i].voted) {
            printf("Voter %s, please enter your choice: ", voters[i].name);
            scanf("%d", &choice);

            if (choice >= 0 && choice < MAX_CANDIDATES) {
                candidates[choice].votes++;
                voters[i].voted = 1;
            } else {
                printf("Invalid choice.\n");
            }
        }
    }
}

void print_results(struct candidate candidates[]) {
    int i;

    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];

    read_candidates(candidates);
    read_voters(voters);

    vote(candidates, voters);

    print_results(candidates);

    return 0;
}