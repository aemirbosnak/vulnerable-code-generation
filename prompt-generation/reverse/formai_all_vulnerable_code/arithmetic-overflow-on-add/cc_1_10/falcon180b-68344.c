//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_OF_CANDIDATES 10
#define MAX_NUM_OF_VOTERS 100
#define MAX_STR_LEN 50

typedef struct {
    char name[MAX_STR_LEN];
    int num_of_votes;
} Candidate;

typedef struct {
    char name[MAX_STR_LEN];
    int voted;
} Voter;

Candidate candidates[MAX_NUM_OF_CANDIDATES];
Voter voters[MAX_NUM_OF_VOTERS];
int num_of_candidates = 0;
int num_of_voters = 0;

void add_candidate() {
    if (num_of_candidates >= MAX_NUM_OF_CANDIDATES) {
        printf("Sorry, the maximum number of candidates has been reached.\n");
        return;
    }
    printf("Enter the name of the candidate: ");
    scanf("%s", candidates[num_of_candidates].name);
    num_of_candidates++;
}

void add_voter() {
    if (num_of_voters >= MAX_NUM_OF_VOTERS) {
        printf("Sorry, the maximum number of voters has been reached.\n");
        return;
    }
    printf("Enter the name of the voter: ");
    scanf("%s", voters[num_of_voters].name);
    num_of_voters++;
}

void vote() {
    printf("Enter the name of the voter: ");
    scanf("%s", voters[num_of_voters - 1].name);
    voters[num_of_voters - 1].voted = 1;
    printf("Enter the name of the candidate: ");
    scanf("%s", candidates[num_of_candidates - 1].name);
    candidates[num_of_candidates - 1].num_of_votes++;
}

void display_results() {
    printf("The results of the election are:\n");
    for (int i = 0; i < num_of_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].num_of_votes);
    }
}

int main() {
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please choose an option:\n");
    printf("1. Add a candidate\n");
    printf("2. Add a voter\n");
    printf("3. Vote\n");
    printf("4. Display results\n");
    printf("0. Exit\n");
    int choice;
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_candidate();
            break;
        case 2:
            add_voter();
            break;
        case 3:
            vote();
            break;
        case 4:
            display_results();
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}