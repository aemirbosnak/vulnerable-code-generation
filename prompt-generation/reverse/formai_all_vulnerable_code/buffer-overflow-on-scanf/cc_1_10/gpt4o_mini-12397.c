//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100
#define VOTER_ID_LENGTH 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voterID[VOTER_ID_LENGTH];
    int voted; // 1 if voted, 0 if not voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int total_voters = 0;
int total_candidates = 0;

void initialize_candidates() {
    printf("==== Candidate Registration ====\n");
    printf("Enter the number of candidates (Max %d): ", MAX_CANDIDATES);
    scanf("%d", &total_candidates);
    getchar(); // to consume newline

    if (total_candidates > MAX_CANDIDATES) {
        printf("Exceeded maximum candidates. Setting to %d\n", MAX_CANDIDATES);
        total_candidates = MAX_CANDIDATES;
    }
    
    for (int i = 0; i < total_candidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // remove newline
        candidates[i].votes = 0;
    }
}

void register_voters() {
    printf("==== Voter Registration ====\n");
    printf("Enter the number of voters (Max %d): ", MAX_VOTERS);
    scanf("%d", &total_voters);
    getchar(); // to consume newline

    if (total_voters > MAX_VOTERS) {
        printf("Exceeded maximum voters. Setting to %d\n", MAX_VOTERS);
        total_voters = MAX_VOTERS;
    }

    for (int i = 0; i < total_voters; i++) {
        printf("Enter voter ID for voter %d: ", i + 1);
        fgets(voters[i].voterID, sizeof(voters[i].voterID), stdin);
        voters[i].voterID[strcspn(voters[i].voterID, "\n")] = 0; // remove newline
        voters[i].voted = 0;
    }
}

int find_voter(char* voterID) {
    for (int i = 0; i < total_voters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0)
            return i;
    }
    return -1; // not found
}

void cast_vote() {
    char voterID[VOTER_ID_LENGTH];
    printf("Enter your voter ID: ");
    fgets(voterID, sizeof(voterID), stdin);
    voterID[strcspn(voterID, "\n")] = 0; // remove newline

    int voter_index = find_voter(voterID);
    
    if (voter_index == -1) {
        printf("Voter ID not found!\n");
        return;
    }
    
    if (voters[voter_index].voted) {
        printf("You have already voted!\n");
        return;
    }

    printf("==== Vote for Your Candidate ====\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("Choose candidate number: ");
    int choice;
    scanf("%d", &choice);
    
    if (choice < 1 || choice > total_candidates) {
        printf("Invalid choice!\n");
    } else {
        candidates[choice - 1].votes++;
        voters[voter_index].voted = 1;
        printf("Thank you for voting!\n");
    }
}

void display_results() {
    printf("==== Election Results ====\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    printf("Welcome to the Electronic Voting System\n");
    srand(time(0)); // using random seed for future enhancements

    while (1) {
        printf("\n==== Main Menu ====\n");
        printf("1. Register Candidates\n");
        printf("2. Register Voters\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline from previous input

        switch (choice) {
            case 1:
                initialize_candidates();
                break;
            case 2:
                register_voters();
                break;
            case 3:
                cast_vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}