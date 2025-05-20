//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 1000

typedef struct {
    char name[50];
    int votes;
} candidate_t;

typedef struct {
    int voter_id;
    int candidate_id;
} vote_t;

candidate_t candidates[MAX_CANDIDATES];
vote_t votes[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate(char* name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_vote(int voter_id, int candidate_id) {
    if (num_voters >= MAX_VOTERS) {
        printf("Error: Maximum number of voters reached.\n");
        return;
    }
    votes[num_voters].voter_id = voter_id;
    votes[num_voters].candidate_id = candidate_id;
    num_voters++;
}

void display_results() {
    int i;
    printf("Election Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(0));
    int choice;
    char name[50];

    do {
        printf("1. Add candidate\n2. Add vote\n3. Display results\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                add_candidate(name);
                break;
            case 2:
                printf("Enter voter ID: ");
                scanf("%d", &num_voters);
                printf("Enter candidate ID: ");
                scanf("%d", &votes[num_voters-1].candidate_id);
                break;
            case 3:
                display_results();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}