//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VOTES 5

int num_candidates = 0;
int num_voters = 0;
char candidates[50][50];
int votes[MAX_VOTES][MAX_VOTES];
bool voted[MAX_VOTES] = { false };

void add_candidate() {
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates++]);
}

void view_candidates() {
    printf("Candidates:\n");
    for(int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i]);
    }
}

void cast_vote(int voter) {
    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > num_candidates) {
            printf("Invalid choice. Please try again.\n");
        } else if(voted[voter] && choice != num_candidates + 1) {
            printf("You have already cast your vote.\n");
            return;
        }
    } while(choice < 1 || choice > num_candidates);
    votes[choice-1][num_voters] = 1;
    if(choice == num_candidates + 1) {
        printf("You have chosen to abstain from voting.\n");
        return;
    }
    printf("Vote cast for %s.\n", candidates[choice-1]);
    voted[voter] = true;
}

void view_results() {
    printf("Results:\n");
    for(int i = 0; i < num_candidates; i++) {
        int vote_count = 0;
        for(int j = 0; j < num_voters; j++) {
            if(votes[i][j] == 1) {
                vote_count++;
            }
        }
        printf("%s: %d votes\n", candidates[i], vote_count);
    }
}

int main() {
    int option, voter_count = 1;
    printf("Welcome to the Electronic Voting System!\n");
    do {
        printf("\n1. Add candidate\n2. View candidates\n3. Cast vote\n4. View results\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_candidate();
                break;
            case 2:
                view_candidates();
                break;
            case 3:
                if(voter_count > MAX_VOTES) {
                    printf("Maximum number of voters have already cast their votes.\n");
                    break;
                }
                cast_vote(voter_count - 1);
                voter_count++;
                break;
            case 4:
                view_results();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(option != 5);
    return 0;
}