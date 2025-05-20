//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

struct Candidate {
    char name[20];
    int votes;
};

void print_menu() {
    printf("\nWelcome to the Electronic Voting System\n\n");
    printf("1. Register voter\n");
    printf("2. Display registered voters\n");
    printf("3. Add candidate\n");
    printf("4. Display candidates\n");
    printf("5. Vote for candidate\n");
    printf("6. Display election results\n");
    printf("7. Exit\n\n");
}

int main() {
    struct Candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;
    char candidate_name[20];
    int candidate_found = 0;
    int vote_count[MAX_CANDIDATES] = {0};
    char registered_voters[MAX_VOTERS][20];
    int num_voters = 0;
    char voter_name[20];
    int voter_found = 0;
    int candidate_voted = 0;

    while (1) {
        print_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of voter to register: ");
                scanf("%s", &voter_name);
                for (int i = 0; i < num_voters; i++) {
                    if (strcmp(registered_voters[i], voter_name) == 0) {
                        printf("Voter already registered.\n");
                        voter_found = 1;
                        break;
                    }
                }
                if (!voter_found) {
                    strcpy(registered_voters[num_voters], voter_name);
                    num_voters++;
                    printf("Voter registered successfully!\n");
                }
                break;
            case 2:
                printf("Registered Voters:\n");
                for (int i = 0; i < num_voters; i++) {
                    printf("%s\n", registered_voters[i]);
                }
                break;
            case 3:
                printf("Enter name of candidate to add: ");
                scanf("%s", &candidate_name);
                for (int i = 0; i < num_candidates; i++) {
                    if (strcmp(candidates[i].name, candidate_name) == 0) {
                        printf("Candidate already exists.\n");
                        candidate_found = 1;
                        break;
                    }
                }
                if (!candidate_found) {
                    struct Candidate new_candidate;
                    strcpy(new_candidate.name, candidate_name);
                    new_candidate.votes = 0;
                    candidates[num_candidates] = new_candidate;
                    num_candidates++;
                    printf("Candidate added successfully!\n");
                }
                break;
            case 4:
                printf("Election Candidates:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s\n", candidates[i].name);
                }
                break;
            case 5:
                printf("Enter name of voter: ");
                scanf("%s", &voter_name);
                for (int i = 0; i < num_voters; i++) {
                    if (strcmp(registered_voters[i], voter_name) == 0) {
                        printf("Enter name of candidate to vote for: ");
                        scanf("%s", &candidate_name);
                        for (int j = 0; j < num_candidates; j++) {
                            if (strcmp(candidates[j].name, candidate_name) == 0) {
                                candidate_voted = 1;
                                candidates[j].votes++;
                                vote_count[j]++;
                                printf("Vote cast successfully!\n");
                                break;
                            }
                        }
                        if (!candidate_voted) {
                            printf("Candidate not found.\n");
                        }
                        voter_found = 1;
                        break;
                    }
                }
                if (!voter_found) {
                    printf("Voter not registered.\n");
                }
                break;
            case 6:
                printf("Election Results:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
                }
                int max_votes = 0;
                for (int i = 0; i < num_candidates; i++) {
                    if (candidates[i].votes > max_votes) {
                        max_votes = candidates[i].votes;
                    }
                }
                printf("\nWinner(s):\n");
                for (int i = 0; i < num_candidates; i++) {
                    if (candidates[i].votes == max_votes) {
                        printf("%s\n", candidates[i].name);
                    }
                }
                printf("\nVote count:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes\n", candidates[i].name, vote_count[i]);
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}