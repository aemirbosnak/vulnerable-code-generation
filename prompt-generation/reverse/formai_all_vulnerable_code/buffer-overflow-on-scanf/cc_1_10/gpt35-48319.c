//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

// Define structs
struct Voter {
    char name[50];
    int age;
    char gender;
    int voted;
};
typedef struct Voter Voter;

struct Candidate {
    char name[50];
    int votes;
};
typedef struct Candidate Candidate;

// Define functions
void printMenu();
void registerVoter(Voter *voters, int *numVoters);
void viewVoters(Voter *voters, int numVoters);
void addCandidate(Candidate *candidates, int *numCandidates);
void viewCandidates(Candidate *candidates, int numCandidates);
int vote(Voter *voter, Candidate *candidates, int numCandidates);
void printResult(Candidate *candidates, int numCandidates, int numVoters);

int main() {
    // Declare variables
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_CANDIDATES];
    int numVoters = 0;
    int numCandidates = 0;
    
    // Loop through program until user exits
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                registerVoter(voters, &numVoters);
                break;
            case 2:
                viewVoters(voters, numVoters);
                break;
            case 3:
                addCandidate(candidates, &numCandidates);
                break;
            case 4:
                viewCandidates(candidates, numCandidates);
                break;
            case 5:
                if (numCandidates == 0) {
                    printf("No candidate registered yet.\n");
                } else if (numVoters == 0) {
                    printf("No voter registered yet.\n");
                } else {
                    int voted = vote(voters, candidates, numCandidates);
                    if (voted) {
                        printf("Thank you for voting.\n");
                    } else {
                        printf("You have already voted.\n");
                    }
                }
                break;
            case 6:
                printResult(candidates, numCandidates, numVoters);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 7);
    
    return 0;
}

// Function definitions

void printMenu() {
    printf("===================\n");
    printf("Electronic Voting System\n");
    printf("===================\n");
    printf("1 - Register Voter\n");
    printf("2 - View Voters\n");
    printf("3 - Add Candidate\n");
    printf("4 - View Candidates\n");
    printf("5 - Vote\n");
    printf("6 - View Result\n");
    printf("7 - Exit\n");
}

void registerVoter(Voter *voters, int *numVoters) {
    printf("Enter voter name: ");
    scanf("%s", &(voters[*numVoters].name));
    printf("Enter voter age: ");
    scanf("%d", &(voters[*numVoters].age));
    printf("Enter voter gender (M/F): ");
    scanf(" %c", &(voters[*numVoters].gender));
    voters[*numVoters].voted = 0;
    (*numVoters)++;
    printf("Voter registered successfully.\n");
}

void viewVoters(Voter *voters, int numVoters) {
    if (numVoters == 0) {
        printf("No voter registered yet.\n");
    } else {
        printf("Registered Voters:\n");
        for (int i = 0; i < numVoters; i++) {
            printf("%s, Age: %d, Gender: %c\n", voters[i].name, voters[i].age, voters[i].gender);
        }
    }
}

void addCandidate(Candidate *candidates, int *numCandidates) {
    printf("Enter candidate name: ");
    scanf("%s", &(candidates[*numCandidates].name));
    candidates[*numCandidates].votes = 0;
    (*numCandidates)++;
    printf("Candidate added successfully.\n");
}

void viewCandidates(Candidate *candidates, int numCandidates) {
    if (numCandidates == 0) {
        printf("No candidate registered yet.\n");
    } else {
        printf("Registered Candidates:\n");
        for (int i = 0; i < numCandidates; i++) {
            printf("%s\n", candidates[i].name);
        }
    }
}

int vote(Voter *voters, Candidate *candidates, int numCandidates) {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    for (int i = 0; i < MAX_VOTERS; i++) {
        if (strcmp(name, voters[i].name) == 0) {
            if (voters[i].voted == 1) {
                return 0;
            } else {
                voters[i].voted = 1;
                printf("Select a candidate:\n");
                for (int j = 0; j < numCandidates; j++) {
                    printf("%d - %s\n", j+1, candidates[j].name);
                }
                int choice;
                printf("Enter your choice: ");
                scanf("%d", &choice);
                (candidates[choice-1].votes)++;
                return 1;
            }
        }
    }
    printf("Voter not found.\n");
    return 0;
}

void printResult(Candidate *candidates, int numCandidates, int numVoters) {
    if (numVoters == 0) {
        printf("No voter registered yet.\n");
    } else if (numCandidates == 0) {
        printf("No candidate registered yet.\n");
    } else {
        printf("Result:\n");
        int totalVotes = 0;
        for (int i = 0; i < numCandidates; i++) {
            totalVotes += candidates[i].votes;
        }
        for (int i = 0; i < numCandidates; i++) {
            printf("%s: %.2f %%\n", candidates[i].name, (float)candidates[i].votes*100/totalVotes);
        }
    }
}