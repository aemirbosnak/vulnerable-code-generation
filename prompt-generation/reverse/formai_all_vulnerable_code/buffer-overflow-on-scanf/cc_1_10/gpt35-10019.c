//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

int count_candidates = 0;
Candidate candidates[10];
int total_votes = 0;

void add_candidate(char name[]) {
    strcpy(candidates[count_candidates].name, name);
    candidates[count_candidates].votes = 0;
    count_candidates++;
    printf("Candidate added successfully!\n");
}

void print_candidates() {
    for (int i = 0; i < count_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void vote(int choice) {
    if (choice <= count_candidates && choice > 0) {
        candidates[choice - 1].votes++;
        total_votes++;
        printf("Your vote has been recorded for %s\n", candidates[choice - 1].name);
    } else {
        printf("Invalid choice! Please try again.\n");
    }
}

void print_results() {
    printf("Total votes: %d\n", total_votes);
    printf("Candidate Votes\n");
    for (int i = 0; i < count_candidates; i++) {
        printf("%s %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    char name[50];
    int choice;
    int num_voters = 0;
    printf("Welcome to the Electronic Voting System!\n");

    while (1) {
        printf("Menu:\n");
        printf("1. Add candidate\n");
        printf("2. Print candidates\n");
        printf("3. Vote\n");
        printf("4. Print results\n");
        printf("5. Exit\n");

        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of candidate: ");
                scanf("%s", name);
                add_candidate(name);
                break;

            case 2:
                print_candidates();
                break;

            case 3:
                num_voters++;
                printf("Voter #%d, Please choose candidate from the list: \n", num_voters);
                print_candidates();
                printf("Enter your choice: ");
                scanf("%d", &choice);
                vote(choice);
                break;

            case 4:
                print_results();
                break;

            case 5:
                printf("Thank you for using the Electronic Voting System!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}