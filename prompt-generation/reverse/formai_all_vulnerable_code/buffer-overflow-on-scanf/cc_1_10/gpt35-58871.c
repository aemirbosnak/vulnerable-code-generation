//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 25

typedef struct {
    int candidate_id;
    char candidate_name[MAX_NAME_LENGTH];
    int vote_count;
} Candidate;

void print_banner() {
    printf("=================================\n");
    printf("    Electronic Voting System\n");
    printf("=================================\n\n");
}

void print_candidates(Candidate *candidates, int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", candidates[i].candidate_id, candidates[i].candidate_name);
    }
    printf("\n");
}

int get_candidate_id(Candidate *candidates, int num_candidates, int id) {
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].candidate_id == id) {
            return i;
        }
    }
    return -1;
}

void cast_vote(Candidate *candidates, int num_candidates) {
    int candidate_id;
    printf("Enter the ID of the candidate you want to vote for: ");
    scanf("%d", &candidate_id);
    int candidate_index = get_candidate_id(candidates, num_candidates, candidate_id);
    if (candidate_index != -1) {
        candidates[candidate_index].vote_count++;
        printf("Vote cast for candidate %s.\n", candidates[candidate_index].candidate_name);
    } else {
        printf("Invalid candidate ID.\n");
    }
}

void print_result(Candidate *candidates, int num_candidates) {
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].candidate_name, candidates[i].vote_count);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates, max_votes = 0, winner_id = -1;

    print_banner();
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate #%d: ", i+1);
        scanf("%s", candidates[i].candidate_name);
        candidates[i].candidate_id = i+1;
        candidates[i].vote_count = 0;
    }

    printf("\n");

    while (1) {
        printf("Press 1 to cast a vote.\n");
        printf("Press 2 to see the results.\n");
        printf("Press 3 to exit.\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                cast_vote(candidates, num_candidates);
                break;
            }
            case 2: {
                print_result(candidates, num_candidates);
                for (int i = 0; i < num_candidates; i++) {
                    if (candidates[i].vote_count > max_votes) {
                        max_votes = candidates[i].vote_count;
                        winner_id = candidates[i].candidate_id;
                    }
                }
                printf("The winner is candidate #%d.\n\n", winner_id);
                break;
            }
            case 3: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}