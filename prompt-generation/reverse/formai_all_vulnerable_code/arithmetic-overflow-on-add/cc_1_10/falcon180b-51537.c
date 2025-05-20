//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voted;
    int candidate_index;
} Voter;

void print_menu() {
    printf("Electronic Voting System\n");
    printf("1. Register as a candidate\n");
    printf("2. Register as a voter\n");
    printf("3. Vote\n");
    printf("4. Display results\n");
    printf("5. Exit\n");
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates = 0;
    int num_voters = 0;
    int i;

    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }

    while (1) {
        print_menu();
        scanf("%d", &i);

        switch (i) {
        case 1:
            if (num_candidates >= MAX_CANDIDATES) {
                printf("Maximum number of candidates reached.\n");
            } else {
                printf("Enter your name: ");
                scanf("%s", candidates[num_candidates].name);
                num_candidates++;
            }
            break;

        case 2:
            if (num_voters >= MAX_VOTERS) {
                printf("Maximum number of voters reached.\n");
            } else {
                printf("Enter your name: ");
                scanf("%s", voters[num_voters].name);
                num_voters++;
            }
            break;

        case 3:
            printf("Enter the index of the candidate you want to vote for: ");
            scanf("%d", &i);

            if (i >= 0 && i < num_candidates) {
                candidates[i].votes++;
                voters[num_voters - 1].voted = 1;
                voters[num_voters - 1].candidate_index = i;
            } else {
                printf("Invalid candidate index.\n");
            }
            break;

        case 4:
            printf("Candidate\tVotes\n");
            for (i = 0; i < num_candidates; i++) {
                printf("%s\t%d\n", candidates[i].name, candidates[i].votes);
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}