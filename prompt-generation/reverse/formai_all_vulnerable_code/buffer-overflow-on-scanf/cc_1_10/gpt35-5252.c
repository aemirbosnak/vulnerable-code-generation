//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    int id;
    char name[20];
    int votes;
} candidate;

candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;
int voter_ids[MAX_VOTERS];
int num_voters = 0;

void print_menu() {
    printf("\nWelcome to the Electronic Voting System!\n");
    printf("========================================\n");
    printf("1. Add Candidate\n");
    printf("2. Start Voting\n");
    printf("3. View Results\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}

void add_candidate() {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached!\n");
        return;
    }
    
    candidate new_candidate;
    
    printf("Enter candidate ID: ");
    scanf("%d", &new_candidate.id);
    printf("Enter candidate name: ");
    scanf("%s", new_candidate.name);
    
    candidates[num_candidates++] = new_candidate;
    
    printf("Candidate added successfully!\n");
}

void start_voting() {
    int voter_id;
    bool valid = false;

    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);
    
    for (int i = 0; i < num_voters; i++) {
        if (voter_id == voter_ids[i]) {
            printf("Error: You have already voted!\n");
            return;
        }
    }
    
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
    
    int candidate_id;
    
    printf("Enter the ID of the candidate you want to vote for: ");
    scanf("%d", &candidate_id);
    
    for (int i = 0; i < num_candidates; i++) {
        if (candidate_id == candidates[i].id) {
            candidates[i].votes++;
            valid = true;
        }
    }
    
    if (valid) {
        printf("Thank you for voting!\n");
        voter_ids[num_voters++] = voter_id;
    } else {
        printf("Error: Invalid candidate ID!\n");
    }
}

void view_results() {
    printf("Candidate\tVotes\n");
    
    for (int i = 0; i < num_candidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    
    do {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                start_voting();
                break;
            case 3:
                view_results();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid Input\n");
        }
    } while (choice != 4);

    return 0;
}