//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 20
#define MAX_VOTERS 1000

typedef struct {
    char name[30];
    int vote_count;
} candidate;

candidate candidates[MAX_CANDIDATES];
int num_candidates;

typedef struct {
    int candidate_index;
    int voted;
} voter;

voter voters[MAX_VOTERS];
int num_voters;

void print_candidates() {
    printf("LIST OF CANDIDATES:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("\n");
}

int validate_vote(int v) {
    if (v < 1 || v > num_candidates) { 
        return 0; 
    }
    return 1;
}

void cast_vote() {
    printf("Enter candidate number to cast vote: ");
    int v;
    scanf("%d", &v);

    if (!validate_vote(v)) {
        printf("Invalid candidate number.\n");
        return;
    }
    
    voters[num_voters].candidate_index = v-1;
    candidates[v-1].vote_count++;
    voters[num_voters].voted = 1;
    num_voters++;
    printf("Vote cast for %s.\n", candidates[v-1].name);
}

void calculate_results() {
    printf("\n****** ELECTION RESULTS ******\n\n");
    candidate winner = candidates[0];
    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        total_votes += candidates[i].vote_count;
        if (candidates[i].vote_count > winner.vote_count) {
            winner = candidates[i];
        }
    }
    printf("Total votes: %d\n\n", total_votes);
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes (%.2f%%)\n", candidates[i].name, candidates[i].vote_count, ((float)candidates[i].vote_count / total_votes) * 100);
    }
    printf("\nWinner: %s\n", winner.name);
}

int main() {
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].vote_count = 0;
    }
    printf("\n");

    char choice;
    do {
        printf("Enter 'C' to cast vote, 'R' to view results, or 'E' to exit: ");
        scanf(" %c", &choice);
        switch(choice) {
            case 'C':
                cast_vote();
                break;
            case 'R':
                calculate_results();
                break;
            case 'E':
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while (choice != 'E');
    return 0;
}