//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 50

int num_candidates;
int num_voters;

typedef struct {
    char name[30];
    int votes;
} Candidate;

typedef struct {
    char name[30];
    bool voted;
    int vote_index;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

void display_candidates() {
    printf("List of Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("\n");
}

void add_candidates() {
    printf("Enter number of candidates (max 10): ");
    scanf("%d", &num_candidates);
    getchar(); // consume newline character

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i+1);
        fgets(candidates[i].name, 30, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // remove newline character
        candidates[i].votes = 0;
    }

    printf("\n");
}

void vote() {
    char vote_str[5];

    while (true) {
        printf("Enter your name: ");
        fgets(voters[num_voters].name, 30, stdin);
        voters[num_voters].name[strcspn(voters[num_voters].name, "\n")] = 0; // remove newline character

        bool duplicate = false;
        for (int i = 0; i < num_voters; i++) {
            if (strcmp(voters[num_voters].name, voters[i].name) == 0) {
                printf("You have already voted!\n\n");
                duplicate = true;
                break;
            }
        }

        if (duplicate) {
            continue;
        }

        voters[num_voters].voted = false;

        printf("Enter number of candidate you want to vote for: ");
        fgets(vote_str, 5, stdin);
        int candidate_index = atoi(vote_str) - 1;

        if (candidate_index < 0 || candidate_index >= num_candidates) {
            printf("Invalid candidate number entered.\n\n");
            continue;
        }

        candidates[candidate_index].votes++;
        voters[num_voters].voted = true;
        voters[num_voters].vote_index = candidate_index;
        num_voters++;

        printf("Thank you for voting!\n\n");

        break;
    }
}

void display_results() {
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int max_votes = -1;
    int max_index = -1;

    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            max_index = i;
        }
    }
    
    printf("\n");
    printf("WINNER: %s\n", candidates[max_index].name);
}

int main() {
    int choice;

    while (true) {
        printf("ELECTRONIC VOTING SYSTEM\n\n");
        printf("1. Add Candidates\n");
        printf("2. Display Candidates\n");
        printf("3. Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character
        printf("\n");

        switch (choice) {
            case 1:
                add_candidates();
                break;
            case 2:
                display_candidates();
                break;
            case 3:
                vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                printf("Thank you for using Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
    return 0;
}