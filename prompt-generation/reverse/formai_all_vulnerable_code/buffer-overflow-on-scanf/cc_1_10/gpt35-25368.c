//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 20

typedef struct candidate {
    int id;
    char name[MAX_NAME_LENGTH];
    int vote_count;
} Candidate;

int num_candidates = 0;
Candidate candidates[MAX_CANDIDATES];

int register_candidate(char* name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return -1;
    }
    Candidate new_candidate;
    new_candidate.id = num_candidates + 1;
    strcpy(new_candidate.name, name);
    new_candidate.vote_count = 0;
    candidates[num_candidates] = new_candidate;
    num_candidates++;
    printf("Candidate %s registered successfully.\n", name);
    return 0;
}

int cast_vote(int candidate_id) {
    if (candidate_id <= 0 || candidate_id > num_candidates) {
        printf("Error: Invalid candidate id.\n");
        return -1;
    }
    candidates[candidate_id - 1].vote_count++;
    printf("Vote casted successfully for candidate %d.\n", candidate_id);
    return 0;
}

void print_results() {
    printf("===== ELECTION RESULTS =====\n");
    printf("Candidate votes:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf(" %d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].vote_count);
    }
}

int main() {
    printf("Welcome to the Electronic Voting System.\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);
    getchar(); // flush newline character
    
    for (int i = 0; i < num_candidates; i++) {
        printf("\nEnter the name of candidate %d: ", i+1);
        char name[MAX_NAME_LENGTH];
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0; // remove trailing newline character
        register_candidate(name);
    }

    while (1) {
        printf("\n\nEnter your choice:\n");
        printf(" 1. Cast vote\n");
        printf(" 2. Print results\n");
        printf(" 3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the candidate id: ");
                int candidate_id;
                scanf("%d", &candidate_id);
                cast_vote(candidate_id);
                break;
            case 2:
                print_results();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}