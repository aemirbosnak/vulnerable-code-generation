//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voter_id;
    int vote;
} Voter;

Voter voters[MAX_VOTERS];
int num_voters = 0;
int candidate1_votes = 0;
int candidate2_votes = 0;

void register_voter() {
    if (num_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }

    printf("Enter voter name: ");
    fgets(voters[num_voters].name, MAX_NAME_LENGTH, stdin);
    voters[num_voters].name[strcspn(voters[num_voters].name, "\n")] = '\0';

    voters[num_voters].voter_id = num_voters + 1;
    voters[num_voters].vote = 0;

    num_voters++;
}

void cast_vote(int voter_id) {
    int i;

    for (i = 0; i < num_voters; i++) {
        if (voters[i].voter_id == voter_id) {
            if (voters[i].vote == 0) {
                printf("Enter your candidate number (1 or 2): ");
                int candidate;
                scanf("%d", &candidate);

                if (candidate == 1) {
                    candidate1_votes++;
                    voters[i].vote = 1;
                } else if (candidate == 2) {
                    candidate2_votes++;
                    voters[i].vote = 2;
                } else {
                    printf("Invalid candidate number.\n");
                    voters[i].vote = 0;
                }

                break;
            } else {
                printf("You have already voted.\n");
                return;
            }
        }
    }
}

void view_results() {
    printf("\nVote Count:\n");
    printf("------------\n");
    printf("Candidate 1: %d\n", candidate1_votes);
    printf("Candidate 2: %d\n", candidate2_votes);
}

int main() {
    int choice;
    int voter_id;

    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_voter();
                break;
            case 2:
                printf("Enter your voter ID: ");
                scanf("%d", &voter_id);
                cast_vote(voter_id);
                break;
            case 3:
                view_results();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}