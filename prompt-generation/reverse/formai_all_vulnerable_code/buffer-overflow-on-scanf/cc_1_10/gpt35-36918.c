//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: genious
#include <stdio.h>
#include <stdlib.h>

/* Define global variables */
int total_voters = 0;
int total_passed = 0;
int total_failed = 0;

/* Define the structure of a candidate */
struct Candidate {
    char name[50];
    int id;
    int votes;
};

/* Define the structure of a voter */
struct Voter {
    char name[50];
    int id;
    int hasVoted;
};

/* Define the array of candidates */
struct Candidate candidates[10];

/* Define the array of voters */
struct Voter voters[1000];

/* Function to add a candidate */
void addCandidate(char name[], int id) {
    struct Candidate candidate;
    strcpy(candidate.name, name);
    candidate.id = id;
    candidate.votes = 0;
    candidates[id-1] = candidate;
    printf("Added candidate %d with name %s\n", id, name);
}

/* Function to add a voter */
void addVoter(char name[], int id) {
    struct Voter voter;
    strcpy(voter.name, name);
    voter.id = id;
    voter.hasVoted = 0;
    voters[id-1] = voter;
    printf("Added voter %d with name %s\n", id, name);
}

/* Function to display the list of candidates */
void displayCandidates() {
    int i;
    printf("List of candidates:\n");
    for (i = 0; i < 10; i++) {
        if (candidates[i].id != 0) {
            printf("%d. %s\n", candidates[i].id, candidates[i].name);
        }
    }
}

/* Function to display the list of voters */
void displayVoters() {
    int i;
    printf("List of voters:\n");
    for (i = 0; i < total_voters; i++) {
        printf("%d. %s\n", voters[i].id, voters[i].name);
    }
}

/* Function to vote for a candidate */
void vote(int id) {
    int i;
    for (i = 0; i < 10; i++) {
        if (candidates[i].id == id) {
            candidates[i].votes++;
            total_passed++;
            printf("Voted for candidate %d\n", id);
            return;
        }
    }
    total_failed++;
    printf("Invalid candidate id entered!\n");
}

/* Function to check if a voter has already voted */
int hasVoted(int id) {
    int i;
    for (i = 0; i < total_voters; i++) {
        if (voters[i].id == id) {
            if (voters[i].hasVoted == 1) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return -1;
}

/* Main Function */
int main() {
    int choice = 0;
    int candidate_id = 0;
    int voter_id = 0;
    char candidate_name[50];
    char voter_name[50];
    int alreadyVoted;

    while (choice != 5) {
        printf("-------------------------------------------------\n");
        printf("Welcome to the Electronic Voting System\n");
        printf("-------------------------------------------------\n");
        printf("Please select an option:\n");
        printf("1. Add a candidate\n");
        printf("2. Add a voter\n");
        printf("3. Display list of candidates\n");
        printf("4. Display list of voters\n");
        printf("5. Vote for a candidate\n");
        printf("6. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", candidate_name);
                candidate_id++;
                addCandidate(candidate_name, candidate_id);
                break;
            case 2:
                printf("Enter voter name: ");
                scanf("%s", voter_name);
                voter_id++;
                addVoter(voter_name, voter_id);
                total_voters++;
                break;
            case 3:
                displayCandidates();
                break;
            case 4:
                displayVoters();
                break;
            case 5:
                printf("Enter voter id: ");
                scanf("%d", &voter_id);
                alreadyVoted = hasVoted(voter_id);
                if (alreadyVoted == 1) {
                    printf("This voter has already voted!\n");
                } else if (alreadyVoted == 0) {
                    displayCandidates();
                    printf("Enter candidate id: ");
                    scanf("%d", &candidate_id);
                    vote(candidate_id);
                } else {
                    printf("Invalid voter id entered!\n");
                }
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice entered. Please try again.\n");
        }
    }

    printf("Total votes passed: %d\n", total_passed);
    printf("Total votes failed: %d\n", total_failed);

    return 0;
}