//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int has_voted;
    int vote;
} Voter;

int num_candidates;
Candidate candidates[MAX_CANDIDATES];

int num_voters;
Voter voters[MAX_VOTERS];

void register_candidates() {
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

int get_candidate_index(char *name) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void register_voters() {
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        voters[i].has_voted = 0;
        voters[i].vote = -1;
    }
}

void cast_vote(int voter_index, char *candidate_name) {
    int candidate_index = get_candidate_index(candidate_name);
    if (candidate_index == -1) {
        printf("Invalid candidate name!\n");
        return;
    }
    if (voters[voter_index].has_voted) {
        printf("This voter has already cast a vote!\n");
        return;
    }
    voters[voter_index].has_voted = 1;
    voters[voter_index].vote = candidate_index;
    candidates[candidate_index].votes++;
    printf("Vote casted successfully!\n");
}

void print_results() {
    printf("Voting Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void print_candidates() {
    printf("List of Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s\n", candidates[i].name);
    }
}

void print_voters() {
    printf("List of Voters:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%s\n", voters[i].name);
    }
}

int main() {
    register_candidates();
    register_voters();
    int choice;
    do {
        printf("Select an option:\n");
        printf("1. Cast Vote\n");
        printf("2. View Candidates\n");
        printf("3. View Voters\n");
        printf("4. Print Results\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the name of the voter: ");
                char voter_name[MAX_NAME_LENGTH];
                scanf("%s", voter_name);
                int voter_index = -1;
                for (int i = 0; i < num_voters; i++) {
                    if (strcmp(voters[i].name, voter_name) == 0) {
                        voter_index = i;
                        break;
                    }
                }
                if (voter_index == -1) {
                    printf("Invalid voter name!\n");
                    break;
                }
                printf("Enter the name of the candidate: ");
                char candidate_name[MAX_NAME_LENGTH];
                scanf("%s", candidate_name);
                cast_vote(voter_index, candidate_name);
                break;
            case 2:
                print_candidates();
                break;
            case 3:
                print_voters();
                break;
            case 4:
                print_results();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);
    return 0;
}