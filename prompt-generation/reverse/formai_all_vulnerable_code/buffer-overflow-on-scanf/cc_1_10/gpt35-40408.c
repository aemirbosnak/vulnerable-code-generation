//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 100

typedef struct {
    char name[50];
    int votes;
} candidate;

candidate candidates[MAX_CANDIDATES];

typedef struct {
    char name[50];
    int voted;
} voter;

voter voters[MAX_VOTERS];

int num_voters = 0;
int num_candidates = 0;

void add_candidate(char *name) {
    candidate new_candidate;
    strcpy(new_candidate.name, name);
    new_candidate.votes = 0;
    candidates[num_candidates++] = new_candidate;
}

void add_voter(char *name) {
    voter new_voter;
    strcpy(new_voter.name, name);
    new_voter.voted = 0;
    voters[num_voters++] = new_voter;
}

int get_candidate_index(char *name) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0)
            return i;
    }
    return -1;
}

int vote(char *voter_name, char *candidate_name) {
    int candidate_index = get_candidate_index(candidate_name);
    if (candidate_index == -1)
        return 0; // candidate does not exist
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, voter_name) == 0) {
            if (voters[i].voted == 1)
                return 0; // voter has already voted
            else {
                candidates[candidate_index].votes++;
                voters[i].voted = 1;
                return 1; // vote successful
            }
        }
    }
    return 0; // voter not found
}

void show_results() {
    printf("Candidate\tVotes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    char name[50];

    do {
        printf("Electronic Voting System\n\n");
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. Vote\n");
        printf("4. Show results\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                add_candidate(name);
                break;
            case 2:
                printf("Enter voter name: ");
                scanf("%s", name);
                add_voter(name);
                break;
            case 3:
                printf("Enter voter name: ");
                scanf("%s", name);
                printf("Enter candidate name: ");
                scanf("%s", name);
                if (vote(name, name))
                    printf("Vote successful.\n");
                else
                    printf("Vote failed.\n");
                break;
            case 4:
                show_results();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}