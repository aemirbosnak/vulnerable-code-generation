//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

typedef struct Voter {
    char name[50];
    int voted;
} Voter;

void welcome() {
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please choose an option below:\n");
    printf("1. View candidates\n");
    printf("2. Cast vote\n");
    printf("3. View results\n");
    printf("4. Exit\n");
}

void view_candidates(Candidate candidates[], int num_candidates) {
    printf("List of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

int cast_vote(Candidate candidates[], int num_candidates, Voter voters[], int num_voters) {
    char voter_name[50];

    printf("Enter your name: ");
    scanf("%s", voter_name);

    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voter_name, voters[i].name) == 0) {
            printf("Sorry, you have already voted.\n");
            return 0;
        }
    }

    int candidate_choice;
    printf("Enter your candidate choice: ");
    scanf("%d", &candidate_choice);

    if (candidate_choice < 1 || candidate_choice > num_candidates) {
        printf("Invalid choice.\n");
        return 0;
    }

    candidates[candidate_choice-1].votes++;
    voters[num_voters].voted = candidate_choice;
    strcpy(voters[num_voters].name, voter_name);
    printf("Thank you for voting!\n");

    return 1;
}

void view_results(Candidate candidates[], int num_candidates) {
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s: %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[5] = {{"John Doe", 0}, {"Jane Smith", 0}, {"Bob Johnson", 0}, {"Alice Lee", 0}, {"Dave Davis", 0}};
    int num_candidates = 5;
    Voter voters[100];
    int num_voters = 0;
    int choice;

    welcome();

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_candidates(candidates, num_candidates);
                break;
            case 2:
                cast_vote(candidates, num_candidates, voters, num_voters);
                num_voters++;
                break;
            case 3:
                view_results(candidates, num_candidates);
                break;
            case 4:
                printf("Thank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}