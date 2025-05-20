//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

typedef struct Voter {
    char name[20];
    int age;
    int voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

int num_candidates = 0;
int num_voters = 0;

void add_candidate() {
    if (num_candidates == MAX_CANDIDATES) {
        printf("Sorry, the maximum number of candidates has been reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_voter() {
    if (num_voters == MAX_VOTERS) {
        printf("Sorry, the maximum number of voters has been reached.\n");
        return;
    }
    printf("Enter voter name: ");
    scanf("%s", voters[num_voters].name);
    printf("Enter voter age: ");
    scanf("%d", &voters[num_voters].age);
    voters[num_voters].voted = 0;
    num_voters++;
}

void cast_vote() {
    char name[20];
    int i, flag = 0;
    printf("Enter voter name: ");
    scanf("%s", name);
    for (i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            flag = 1;
            if (voters[i].voted == 1) {
                printf("Sorry, this voter has already cast a vote.\n");
                return;
            }
            int j;
            char candidate[20];
            printf("Enter preferred candidate name: ");
            scanf("%s", candidate);
            for (j = 0; j < num_candidates; j++) {
                if (strcmp(candidates[j].name, candidate) == 0) {
                    candidates[j].votes++;
                    voters[i].voted = 1;
                    printf("Vote casted successfully!\n");
                    return;
                }
            }
            printf("Sorry, the entered candidate name is not correct.\n");
            return;
        }
    }
    if (flag == 0) {
        printf("Sorry, the entered voter name is not correct.\n");
    }
}

void display_results() {
    int i;
    printf("----------------------------------------\n");
    printf("| Candidate Name | Total Votes Received |\n");
    printf("----------------------------------------\n");
    for (i = 0; i < num_candidates; i++) {
        printf("| %14s | %19d |\n", candidates[i].name, candidates[i].votes);
    }
    printf("----------------------------------------\n");
}

void menu() {
    printf("------------------------------------------------\n");
    printf("|                  MAIN MENU                   |\n");
    printf("------------------------------------------------\n");
    printf("| Options:                                     |\n");
    printf("|        1. Add a candidate                    |\n");
    printf("|        2. Add a voter                        |\n");
    printf("|        3. Cast a vote                        |\n");
    printf("|        4. Display voting results             |\n");
    printf("|        5. Exit the program                   |\n");
    printf("------------------------------------------------\n");
}

int main() {
    menu();
    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                display_results();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}