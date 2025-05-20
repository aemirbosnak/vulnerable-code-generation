//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate_t;

typedef struct {
    char name[50];
    int voter_id;
} voter_t;

candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];

int num_candidates = 0;
int num_voters = 0;

void add_candidate(char* name) {
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_voter(char* name) {
    strcpy(voters[num_voters].name, name);
    voters[num_voters].voter_id = num_voters + 1;
    num_voters++;
}

int main() {
    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");

    add_voter("John");
    add_voter("Jane");

    int choice;
    while(1) {
        printf("\nWelcome to the Electronic Voting System\n");
        printf("1. Cast your vote\n2. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            int voter_id;
            printf("Enter your voter ID: ");
            scanf("%d", &voter_id);

            int found = 0;
            for(int i=0; i<num_voters; i++) {
                if(voters[i].voter_id == voter_id) {
                    found = 1;
                    break;
                }
            }

            if(!found) {
                printf("Invalid voter ID\n");
                continue;
            }

            int vote;
            printf("Enter the candidate number you want to vote for:\n");
            for(int i=0; i<num_candidates; i++) {
                printf("%d. %s\n", i+1, candidates[i].name);
            }
            scanf("%d", &vote);

            candidates[vote-1].votes++;
        } else if(choice == 2) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    printf("\nVoting Results:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}