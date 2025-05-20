//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Candidate {
    int candId;
    char candName[50];
    int votes;
} Candidate;

// function declarations
int getOption();
void addCandidate(Candidate *candList, int *totalCandidates);
void displayCandidates(Candidate *candList, int totalCandidates);
void deleteCandidates(Candidate *candList, int *totalCandidates);
void castVote(Candidate *candList, int totalCandidates);
void showResult(Candidate *candList, int totalCandidates);


int main() {
    Candidate candList[100];
    int totalCandidates = 0;
    int option;

    do {
        option = getOption();
        switch(option) {
            case 1:
                addCandidate(candList, &totalCandidates);
                break;
            case 2:
                displayCandidates(candList, totalCandidates);
                break;
            case 3:
                deleteCandidates(candList, &totalCandidates);
                break;
            case 4:
                castVote(candList, totalCandidates);
                break;
            case 5:
                showResult(candList, totalCandidates);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while(option != 6);

    return 0;
}

// function to display menu and get user option
int getOption() {
    int option;

    printf("\n=== Electronic Voting System ===\n");
    printf("\n1. Add Candidate\n2. Display Candidates\n3. Delete Candidates\n");
    printf("4. Cast Vote\n5. Show Result\n6. Exit\n");
    printf("\nEnter your option: ");
    scanf("%d", &option);

    return option;
}

// function to add candidate
void addCandidate(Candidate *candList, int *totalCandidates) {
    Candidate c;
    printf("\nEnter candidate ID: ");
    scanf("%d", &c.candId);
    printf("Enter candidate name: ");
    scanf("%s", c.candName);
    c.votes = 0;
    candList[*totalCandidates] = c;
    printf("\nCandidate added successfully!\n");
    (*totalCandidates)++;
}

// function to display candidates
void displayCandidates(Candidate *candList, int totalCandidates) {
    if(totalCandidates == 0) {
        printf("\nNo candidates present!\n");
    } else {
        printf("\nCandidate ID     Candidate Name\n");
        for(int i=0; i<totalCandidates; i++) {
            printf("%-16d%s\n", candList[i].candId, candList[i].candName);
        }
    }
}

// function to delete candidate
void deleteCandidates(Candidate *candList, int *totalCandidates) {
    int id, found=0;

    printf("\nEnter candidate ID to delete: ");
    scanf("%d", &id);

    for(int i=0; i<*totalCandidates; i++) {
        if(candList[i].candId == id) {
            found = 1;
            *totalCandidates -= 1;
            for(int j=i; j<*totalCandidates; j++) {
                candList[j] = candList[j+1];
            }
            printf("\nCandidate deleted successfully!\n");
            break;
        }
    }

    if(found == 0) {
        printf("\nCandidate not found!\n");
    }
}

// function to cast vote
void castVote(Candidate *candList, int totalCandidates) {
    int id, found=0;

    printf("\nEnter candidate ID to cast vote: ");
    scanf("%d", &id);

    for(int i=0; i<totalCandidates; i++) {
        if(candList[i].candId == id) {
            found = 1;
            candList[i].votes++;
            printf("\nVote casted successfully!\n");
            break;
        }
    }

    if(found == 0) {
        printf("\nCandidate not found!\n");
    }
}

// function to display result
void showResult(Candidate *candList, int totalCandidates) {
    Candidate winner = candList[0];
    int maxVotes = candList[0].votes;
    int totalCount = 0;

    for(int i=1; i<totalCandidates; i++) {
        totalCount += candList[i].votes;
        if(candList[i].votes > maxVotes) {
            winner = candList[i];
            maxVotes = candList[i].votes;
        }
    }

    if(totalCount == 0) {
        printf("\nNo votes casted yet!\n");
    } else {
        printf("\nCandidate having highest votes:\n");
        printf("Candidate ID: %d\nCandidate Name: %s\nTotal Votes: %d\n",
               winner.candId, winner.candName, winner.votes);
    }
}