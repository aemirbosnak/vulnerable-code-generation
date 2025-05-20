//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 1000

typedef struct Candidate {
    char name[20];
    int voteCount;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

typedef struct Voter {
    char name[20];
    int votedFor;
    int hasVoted;
} Voter;

Voter voters[MAX_VOTERS];

int candidateCount = 0;
int voterCount = 0;

void addCandidate(char name[]) {
    Candidate candidate;
    strcpy(candidate.name, name);
    candidate.voteCount = 0;
    candidates[candidateCount] = candidate;
    candidateCount++;
}

int getCandidateByName(char name[]) {
    for (int i = 0; i < candidateCount; i++) {
        Candidate candidate = candidates[i];
        if (strcmp(candidate.name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printCandidates() {
    printf("\t-- Candidates --\n");
    for (int i = 0; i < candidateCount; i++) {
        Candidate candidate = candidates[i];
        printf("\t%i: %s\n", i + 1, candidate.name);
    }
    printf("\n");
}

void addVoter(char name[]) {
    Voter voter;
    strcpy(voter.name, name);
    voter.hasVoted = 0;
    voterCount++;
    voters[voterCount - 1] = voter;
}

int getVoterByName(char name[]) {
    for (int i = 0; i < voterCount; i++) {
        Voter voter = voters[i];
        if (strcmp(voter.name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printVoters() {
    printf("\t-- Voters --\n");
    for (int i = 0; i < voterCount; i++) {
        Voter voter = voters[i];
        printf("\t%i: %s\n", i + 1, voter.name);
    }
    printf("\n");
}

void castVote(char voterName[], char candidateName[]) {
    int voterIndex = getVoterByName(voterName);
    int candidateIndex = getCandidateByName(candidateName);

    if (voters[voterIndex].hasVoted) {
        printf("Voter has already cast their vote.\n");
    } else if (voterIndex == -1) {
        printf("Voter not found.\n");
    } else if (candidateIndex == -1) {
        printf("Candidate not found.\n");
    } else {
        candidates[candidateIndex].voteCount++;
        voters[voterIndex].hasVoted = 1;
        voters[voterIndex].votedFor = candidateIndex;
        printf("Vote for %s cast successfully.\n", candidateName);
    }
}

void printResults() {
    printf("\n\t-- Results --\n");
    for (int i = 0; i < candidateCount; i++) {
        Candidate candidate = candidates[i];
        printf("\t%s: %i votes\n", candidate.name, candidate.voteCount);
    }
    printf("\n");
}

int validateOption(char* input, int maxNum) {

    int option = -1;
    while (option == -1) {
        printf("Enter option you want to select: ");

        fgets(input, 100, stdin);
        if (sscanf(input, "%d", &option) != 1) {
            option = -1;
        } else {
            if (option < 1 || option > maxNum) {
                printf("Invalid input!\n");
                option = -1;
            }
        }
    }

    return option;
}

int main() {
    printf("***** Welcome to E-Voting Application *****\n");

    while(1) {
        printf("Enter Your Choice \n");
        printf("1 - Add Candidate\n");
        printf("2 - View All Candidates\n");
        printf("3 - Add Voter\n");
        printf("4 - View All Voters\n");
        printf("5 - Cast Vote\n");
        printf("6 - View Results\n");

        char input[100] = "";
        int selection = validateOption(input, 6);

        switch (selection) {
            case 1: {
                printf("Enter Candidate Name: ");
                char name[20];
                fgets(name, 20, stdin);
                addCandidate(name);
                printf("%s added successfully!\n", name);
                break;
            }
            case 2: {
                printCandidates();
                break;
            }
            case 3: {
                printf("Enter Voter Name: ");
                char name[20];
                fgets(name, 20, stdin);
                addVoter(name);
                printf("%s added successfully!\n", name);
                break;
            }
            case 4: {
                printVoters();
                break;
            }
            case 5: {
                printf("Enter Voter Name: ");
                char voterName[20];
                fgets(voterName, 20, stdin);
                printf("Enter Candidate Name: ");
                char candidateName[20];
                fgets(candidateName, 20, stdin);
                castVote(voterName, candidateName);
                break;
            }
            case 6: {
                printResults();
                break;
            }
            default: {
                printf("Invalid option selected!\n");
            }
        }
    }

    return 0;
}