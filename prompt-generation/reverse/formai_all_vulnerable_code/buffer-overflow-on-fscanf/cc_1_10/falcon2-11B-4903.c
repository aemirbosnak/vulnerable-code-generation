//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* name;
    char* email;
    char* phone;
    char* address;
    char* password;
} Candidate;

typedef struct{
    int candidates;
    Candidate* candidatesArray;
} Election;

void printCandidate(Candidate candidate) {
    printf("Candidate Name: %s\n", candidate.name);
    printf("Candidate Email: %s\n", candidate.email);
    printf("Candidate Phone: %s\n", candidate.phone);
    printf("Candidate Address: %s\n", candidate.address);
    printf("Candidate Password: %s\n", candidate.password);
}

void addCandidate(Election* election) {
    Candidate candidate;
    printf("Enter Candidate Name: ");
    fgets(candidate.name, sizeof(candidate.name), stdin);
    printf("Enter Candidate Email: ");
    fgets(candidate.email, sizeof(candidate.email), stdin);
    printf("Enter Candidate Phone: ");
    fgets(candidate.phone, sizeof(candidate.phone), stdin);
    printf("Enter Candidate Address: ");
    fgets(candidate.address, sizeof(candidate.address), stdin);
    printf("Enter Candidate Password: ");
    fgets(candidate.password, sizeof(candidate.password), stdin);

    election->candidates++;
    election->candidatesArray = (Candidate*)realloc(election->candidatesArray, election->candidates * sizeof(Candidate));
    memcpy(&(election->candidatesArray[election->candidates - 1]), &candidate, sizeof(Candidate));
}

void printCandidates(Election* election) {
    for (int i = 0; i < election->candidates; i++) {
        printf("Candidate %d:\n", i + 1);
        printCandidate(election->candidatesArray[i]);
        printf("\n");
    }
}

void vote(Election* election) {
    printf("Enter Candidate Number: ");
    int candidateNumber;
    fscanf(stdin, "%d", &candidateNumber);

    if (candidateNumber > 0 && candidateNumber <= election->candidates) {
        printf("Vote for Candidate %d? (Y/N): ", candidateNumber);
        char answer;
        fscanf(stdin, "%c", &answer);

        if (answer == 'Y' || answer == 'y') {
            printf("Candidate %d has been voted!\n", candidateNumber);
        }
    } else {
        printf("Invalid Candidate Number!\n");
    }
}

int main() {
    Election election;
    election.candidates = 0;
    election.candidatesArray = NULL;

    while (1) {
        printf("1. Add Candidate\n");
        printf("2. Print Candidates\n");
        printf("3. Vote\n");
        printf("4. Exit\n");
        int choice;
        printf("Enter your choice: ");
        fscanf(stdin, "%d", &choice);

        switch (choice) {
            case 1:
                addCandidate(&election);
                break;
            case 2:
                printCandidates(&election);
                break;
            case 3:
                vote(&election);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }

    return 0;
}