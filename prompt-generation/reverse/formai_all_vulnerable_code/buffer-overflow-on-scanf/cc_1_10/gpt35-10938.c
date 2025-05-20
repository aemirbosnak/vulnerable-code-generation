//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 5

struct candidate {
    char name[20];
    int count;
};

struct voter {
    char name[20];
    int id;
    bool voted;
    int voted_for;
};

struct candidate candidates[MAX_CANDIDATES];
struct voter voters[MAX_VOTERS];
int num_voters = 0;
int num_candidates = 0;

// adds a new candidate to the system
void add_candidate() {
    printf("Enter candidate name: ");
    fgets(candidates[num_candidates].name, 20, stdin);
    candidates[num_candidates].count = 0;
    num_candidates++;
}

// displays a list of candidates and their vote counts
void print_results() {
    printf("\nElection Results:\n\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].count);
    }
}

// prompts the user to enter the ID of the voter they wish to vote for
// and then updates the candidate's vote count
void cast_vote(int voter_id) {
    int candidate_id;
    printf("Enter candidate ID: ");
    scanf("%d", &candidate_id);
    getchar();
    if (candidate_id >= 0 && candidate_id < num_candidates) {
        candidates[candidate_id].count++;
        voters[voter_id].voted_for = candidate_id;
        printf("Vote cast for %s\n", candidates[candidate_id].name);
    } else {
        printf("Invalid candidate ID.\n");
    }
}

int main() {
    int choice;
    char name[20];
    int id;
    bool found_voter = false;

    printf("Welcome to the Electronic Voting System!\n\n");

    // add initial candidates
    strcpy(candidates[0].name, "Abe");
    strcpy(candidates[1].name, "Bill");
    num_candidates = 2;

    // loop until user chooses to exit
    do {
        printf("\nMenu:\n");
        printf("1. Register to vote\n");
        printf("2. Cast a vote\n");
        printf("3. Add a candidate\n");
        printf("4. Print election results\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("\nEnter your full name: ");
                fgets(name, 20, stdin);
                printf("Enter your voter ID: ");
                scanf("%d", &id);
                getchar();
                found_voter = false;
                for (int i = 0; i < num_voters; i++) {
                    if (strcmp(voters[i].name, name) == 0 && voters[i].id == id) {
                        found_voter = true;
                        if (voters[i].voted == true) {
                            printf("You have already voted.\n");
                        } else {
                            printf("You are registered to vote.\n");
                            voters[i].voted = true;
                            cast_vote(i);
                        }
                        break;
                    }
                }
                if (!found_voter) {
                    printf("You are not registered to vote. Please see an election official.\n");
                }
                break;
            case 2:
                printf("\nEnter your full name: ");
                fgets(name, 20, stdin);
                printf("Enter your voter ID: ");
                scanf("%d", &id);
                getchar();
                found_voter = false;
                for (int i = 0; i < num_voters; i++) {
                    if (strcmp(voters[i].name, name) == 0 && voters[i].id == id) {
                        found_voter = true;
                        if (voters[i].voted == true) {
                            printf("You have already voted.\n");
                        } else {
                            printf("Please cast your vote.\n");
                            voters[i].voted = true;
                            cast_vote(i);
                        }
                        break;
                    }
                }
                if (!found_voter) {
                    printf("You are not registered to vote. Please see an election official.\n");
                }
                break;
            case 3:
                add_candidate();
                break;
            case 4:
                print_results();
                break;
            case 5:
                printf("\nThank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}