//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 50

// candidate struct
typedef struct {
    int id;
    char name[20];
    int votes;
} Candidate;

// voter struct
typedef struct {
    int id;
    char name[20];
    bool has_voted;
    int vote;
} Voter;

// global variables
Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;
Voter voters[MAX_VOTERS];
int num_voters = 0;

// function prototypes
void add_candidate();
void vote();
void check_results();
void display_menu();

int main() {
    printf("Welcome to the Electronic Voting System\n");
    display_menu();
    return 0;
}

void display_menu() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Candidate\n");
        printf("2. Vote\n");
        printf("3. Check Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                vote();
                break;
            case 3:
                check_results();
                break;
            case 4:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice. Please try again.\n");
        }
    } while (choice != 4);
}

void add_candidate() {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum Number of Candidates Reached.\n");
        return;
    }
    candidates[num_candidates].id = num_candidates + 1;
    printf("Enter Candidate Name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
    printf("Candidate Added.\n");
}

void vote() {
    if (num_candidates == 0) {
        printf("There are no Candidates. Please Add Candidates First.\n");
        return;
    }
    if (num_voters >= MAX_VOTERS) {
        printf("Maximum Number of Voters Reached.\n");
        return;
    }
    printf("Enter Voter Name: ");
    scanf("%s", voters[num_voters].name);
    voters[num_voters].has_voted = false;
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
    printf("Enter Candidate ID to Vote: ");
    scanf("%d", &voters[num_voters].vote);
    if (voters[num_voters].vote < 1 || voters[num_voters].vote > num_candidates) {
        printf("Invalid Candidate ID. Please try again.\n");
        return;
    }
    candidates[voters[num_voters].vote - 1].votes++;
    printf("Vote Counted.\n");
    voters[num_voters].has_voted = true;
    num_voters++;
}

void check_results() {
    if (num_candidates == 0) {
        printf("No Candidates.\n");
        return;
    }
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d Votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
    int total_votes = 0;
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].has_voted) {
            total_votes++;
        }
    }
    printf("%d Total Votes.\n", total_votes);
}