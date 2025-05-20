//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct candidate {
    int id;
    char name[20];
    int votes;
} Candidate;

typedef struct voter {
    int id;
    char name[20];
    int vote;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate() {
    Candidate c;
    c.id = candidateCount + 1;
    printf("Enter the name of candidate %d: ", c.id);
    scanf("%s", &c.name);
    c.votes = 0;
    candidates[candidateCount] = c;
    candidateCount++;
}

void displayCandidates() {
    printf("\nList of Candidates:\n");
    for(int i = 0; i < candidateCount; i++) {
        printf("%d %s\n", candidates[i].id, candidates[i].name);
    }
    printf("\n");
}

void registerVoter() {
    Voter v;
    v.id = voterCount + 1;
    printf("Enter the name of voter %d: ", v.id);
    scanf("%s", &v.name);
    v.vote = 0;
    voters[voterCount] = v;
    voterCount++;
}

void castVote() {
    int id;
    printf("Enter Voter ID: ");
    scanf("%d", &id);
    for(int i = 0; i < voterCount; i++) {
        if(voters[i].id == id) {
            if(voters[i].vote != 0) {
                printf("You have already cast your vote!\n");
                return;
            }
            int candidateID;
            printf("Enter the candidate ID you want to vote for: ");
            scanf("%d", &candidateID);
            for(int j = 0; j < candidateCount; j++) {
                if(candidates[j].id == candidateID) {
                    candidates[j].votes++;
                    voters[i].vote = candidateID;
                    printf("Vote cast successfully!\n");
                    return;
                }
            }
            printf("Invalid candidate ID!\n");
            return;
        }
    }
    printf("Invalid Voter ID!\n");
}

void displayResult() {
    printf("\nResult:\n");
    for(int i = 0; i < candidateCount; i++) {
        printf("%d %s %d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    do {
        printf("Electronic Voting System - Main Menu\n");
        printf("1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Register Voter\n");
        printf("4. Cast Vote\n");
        printf("5. Display Result\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                displayCandidates();
                break;
            case 3:
                registerVoter();
                break;
            case 4:
                castVote();
                break;
            case 5:
                displayResult();
                break;
            case 6:
                printf("Thanks for using Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(1);

    return 0;
}