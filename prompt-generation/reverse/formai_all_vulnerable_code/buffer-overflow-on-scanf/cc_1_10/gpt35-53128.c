//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

struct Voter {
    int id;
    char name[50];
    int age;
    bool hasVoted;
};

struct Candidate {
    int id;
    char name[50];
    char party[50];
    int voteCount;
};

struct Voter voters[MAX_VOTERS];
struct Candidate candidates[MAX_CANDIDATES];

int numVoters = 0;
int numCandidates = 0;

void addVoter(int id, char name[], int age) {
    struct Voter voter = {id, "", age, false};
    strcpy(voter.name, name);
    voters[numVoters] = voter;
    numVoters++;
}

void addCandidate(int id, char name[], char party[]) {
    struct Candidate candidate = {id, "", "", 0};
    strcpy(candidate.name, name);
    strcpy(candidate.party, party);
    candidates[numCandidates] = candidate;
    numCandidates++;
}

void listVoters() {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%d\t%s\t%d\n", voters[i].id, voters[i].name, voters[i].age);
    }
}

void listCandidates() {
    printf("ID\tName\tParty\tVote Count\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d\t%s\t%s\t%d\n", candidates[i].id, candidates[i].name, candidates[i].party, candidates[i].voteCount);
    }
}

bool isRegisteredVoter(int voterId) {
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].id == voterId) {
            return true;
        }
    }
    return false;
}

bool isRegisteredCandidate(int candidateId) {
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].id == candidateId) {
            return true;
        }
    }
    return false;
}

void vote(int voterId, int candidateId) {
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].id == voterId) {
            if (voters[i].hasVoted) {
                printf("Error: Voter has already cast a vote.\n");
                return;
            }
            voters[i].hasVoted = true;
            break;
        }
    }
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].id == candidateId) {
            candidates[i].voteCount++;
            break;
        }
    }
    printf("Voting successful!\n");
}

void printMenu() {
    printf("\n=====Electronic Voting System=====\n");
    printf("1. Add Voter\n");
    printf("2. Add Candidate\n");
    printf("3. List Voters\n");
    printf("4. List Candidates\n");
    printf("5. Vote\n");
    printf("6. Exit\n");
    printf("==================================\n");
}

int main() {
    int choice;
    do {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    int id, age;
                    char name[50];

                    printf("\nEnter voter ID: ");
                    scanf("%d", &id);
                    if (isRegisteredVoter(id)) {
                        printf("Error: Voter ID is already registered.\n");
                        break;
                    }

                    printf("Enter voter name: ");
                    scanf("%s", name);

                    printf("Enter voter age: ");
                    scanf("%d", &age);

                    addVoter(id, name, age);
                    printf("Voter added successfully!\n");
                }
                break;

            case 2:
                {
                    int id;
                    char name[50];
                    char party[50];

                    printf("\nEnter candidate ID: ");
                    scanf("%d", &id);
                    if (isRegisteredCandidate(id)) {
                        printf("Error: Candidate ID is already registered.\n");
                        break;
                    }

                    printf("Enter candidate name: ");
                    scanf("%s", name);

                    printf("Enter candidate party: ");
                    scanf("%s", party);

                    addCandidate(id, name, party);
                    printf("Candidate added successfully!\n");
                }
                break;

            case 3:
                listVoters();
                break;

            case 4:
                listCandidates();
                break;

            case 5:
                {
                    int voterId, candidateId;
                    printf("\nEnter voter ID: ");
                    scanf("%d", &voterId);
                    if (!isRegisteredVoter(voterId)) {
                        printf("Error: Voter ID is not registered.\n");
                        break;
                    }

                    printf("Enter candidate ID: ");
                    scanf("%d", &candidateId);
                    if (!isRegisteredCandidate(candidateId)) {
                        printf("Error: Candidate ID is not registered.\n");
                        break;
                    }

                    vote(voterId, candidateId);
                }
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}