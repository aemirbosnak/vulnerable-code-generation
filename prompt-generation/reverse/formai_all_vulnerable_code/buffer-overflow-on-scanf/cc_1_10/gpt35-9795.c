//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

int candidates[MAX_CANDIDATES];
int voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate() {
    if(num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
    }
    else {
        printf("Enter candidate ID: ");
        scanf("%d", &candidates[num_candidates]);
        num_candidates++;
        printf("Candidate added.\n");
    }
}

void add_voter() {
    if(num_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
    }
    else {
        printf("Enter voter ID: ");
        scanf("%d", &voters[num_voters]);
        num_voters++;
        printf("Voter added.\n");
    }
}

void cast_vote() {
    int voter_id, candidate_id;
    printf("Enter voter ID: ");
    scanf("%d", &voter_id);
    for(int i = 0; i < num_voters; i++) {
        if(voters[i] == voter_id) {
            printf("Enter candidate ID: ");
            scanf("%d", &candidate_id);
            for(int j = 0; j < num_candidates; j++) {
                if(candidates[j] == candidate_id) {
                    printf("Vote casted successfully.\n");
                    return;
                }
            }
            printf("Invalid candidate ID.\n");
            return;
        }
    }
    printf("Invalid voter ID.\n");
}

void view_all_candidates() {
    printf("Candidates:\n");
    for(int i = 0; i < num_candidates; i++) {
        printf("%d\n", candidates[i]);
    }
}

void view_all_voters() {
    printf("Voters:\n");
    for(int i = 0; i < num_voters; i++) {
        printf("%d\n", voters[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. Cast vote\n");
        printf("4. View all candidates\n");
        printf("5. View all voters\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_candidate(); 
                break;
            case 2:
                add_voter(); 
                break;
            case 3:
                cast_vote(); 
                break;
            case 4:
                view_all_candidates(); 
                break;
            case 5:
                view_all_voters(); 
                break;
            case 6:
                printf("Exiting...\n"); 
                break;
            default:
                printf("Invalid choice.\n"); 
                break;
        }
    } while(choice != 6);
    return 0;
}