//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    int id;
    char name[50];
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate(char *name) {
    candidates[num_candidates].name[0] = '\0';
    strcat(candidates[num_candidates].name, name);
    num_candidates++;
}

void add_voter(char *name) {
    strcpy(voters[num_voters].name, name);
    num_voters++;
}

int main() {
    srand(time(NULL));

    int choice;
    char name[50];

    printf("Welcome to the Electronic Voting System\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Please enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
    }

    printf("\nPlease enter the number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Please enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
    }

    printf("\nVoting has started!\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Vote\n2. View Results\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int voter_id = rand() % num_voters;
            int candidate_id = rand() % num_candidates;

            strcpy(name, voters[voter_id].name);
            candidates[candidate_id].votes++;
        } else if (choice == 2) {
            printf("\nResults:\n");
            for (int i = 0; i < num_candidates; i++) {
                printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
            }
        } else if (choice == 3) {
            printf("Thank you for using the Electronic Voting System\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}