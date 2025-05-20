//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int voted; // 0: not voted, 1: voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

void load_candidates() {
    FILE *file = fopen("candidates.txt", "r");
    if (file == NULL) {
        perror("Failed to open candidates file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%49s", candidates[candidate_count].name) != EOF && candidate_count < MAX_CANDIDATES) {
        candidates[candidate_count].votes = 0;
        candidate_count++;
    }
    fclose(file);
}

void save_results() {
    FILE *file = fopen("results.txt", "w");
    if (file == NULL) {
        perror("Failed to open results file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < candidate_count; i++) {
        fprintf(file, "%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    fclose(file);
}

void register_voter(const char *name) {
    if (voter_count >= MAX_VOTERS) {
        printf("Maximum voter limit reached.\n");
        return;
    }
    strcpy(voters[voter_count].name, name);
    voters[voter_count].voted = 0;
    voter_count++;
    printf("Voter %s registered successfully.\n", name);
}

void cast_vote(const char *name) {
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            if (voters[i].voted) {
                printf("Voter %s has already voted.\n", name);
                return;
            }
            char candidate_name[50];
            printf("Available candidates:\n");
            for (int j = 0; j < candidate_count; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }
            printf("Enter candidate number to vote for: ");
            int candidate_number;
            scanf("%d", &candidate_number);
            if (candidate_number < 1 || candidate_number > candidate_count) {
                printf("Invalid candidate number.\n");
                return;
            }
            candidates[candidate_number - 1].votes++;
            voters[i].voted = 1;
            printf("Vote cast for %s successfully.\n", candidates[candidate_number - 1].name);
            return;
        }
    }
    printf("Voter %s is not registered.\n", name);
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    load_candidates();
    int choice;

    do {
        printf("\nElectronic Voting System\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char voter_name[50];
                printf("Enter voter name: ");
                scanf("%s", voter_name);
                register_voter(voter_name);
                break;
            }
            case 2: {
                char voter_name[50];
                printf("Enter voter name: ");
                scanf("%s", voter_name);
                cast_vote(voter_name);
                break;
            }
            case 3:
                display_results();
                save_results();
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}