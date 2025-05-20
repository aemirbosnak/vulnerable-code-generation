//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>

// Structures to hold candidate information and voter information
struct candidate {
    int id;
    char name[50];
    int votes;
};

struct voter {
    int id;
    char name[50];
    int voted;
};

// Global variables
struct candidate candidates[10];
struct voter voters[100];
int num_candidates = 0;
int num_voters = 0;

// Function to add a new candidate to the system
void add_candidate() {
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].id = num_candidates + 1;
    candidates[num_candidates].votes = 0;
    num_candidates++;
    printf("Candidate added successfully!\n");
}

// Function to display all the candidates in the system
void display_candidates() {
    printf("\n");
    printf("Candidate ID   Candidate Name   Votes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d              %-15s %d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

// Function to add a new voter to the system
void add_voter() {
    printf("Enter voter name: ");
    scanf("%s", voters[num_voters].name);
    voters[num_voters].id = num_voters + 1;
    voters[num_voters].voted = 0;
    num_voters++;
    printf("Voter added successfully!\n");
}

// Function to display all the voters in the system
void display_voters() {
    printf("\n");
    printf("Voter ID   Voter Name   Voted\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%d         %-10s   %d\n", voters[i].id, voters[i].name, voters[i].voted);
    }
    printf("\n");
}

// Function to handle the voting process
void vote() {
    int voter_id, candidate_id;
    printf("Enter voter ID: ");
    scanf("%d", &voter_id);
    int found = 0;
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == voter_id) {
            found = 1;
            if (voters[i].voted) {
                printf("This voter has already voted!\n");
                return;
            }
            break;
        }
    }
    if (!found) {
        printf("Voter not found!\n");
        return;
    }
    printf("Enter candidate ID: ");
    scanf("%d", &candidate_id);
    found = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == candidate_id) {
            found = 1;
            candidates[i].votes++;
            voters[voter_id - 1].voted = 1;
            printf("Vote casted successfully!\n");
            return;
        }
    }
    if (!found) {
        printf("Candidate not found!\n");
        return;
    }
}

// Main function to run the program
int main() {
    int choice = 0;
    while (1) {
        printf("Electronic Voting System\n");
        printf("========================\n");
        printf("1. Add candidate\n");
        printf("2. Display candidates\n");
        printf("3. Add voter\n");
        printf("4. Display voters\n");
        printf("5. Vote\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                display_candidates();
                break;
            case 3:
                add_voter();
                break;
            case 4:
                display_voters();
                break;
            case 5:
                vote();
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}