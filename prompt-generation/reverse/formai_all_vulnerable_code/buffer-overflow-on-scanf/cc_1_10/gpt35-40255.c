//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int vote;
} Candidate;

Candidate candidates[5]; //Defining maximum of 5 candidates
int numCandidates = 0;

void addCandidate() {
    printf("Enter Candidate Name: ");
    char name[50];
    scanf("%s", name);
    
    for(int i = 0; i < numCandidates; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            printf("Candidate already exists!\n");
            return;
        }
    }
    
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].vote = 0;
    numCandidates++;
    printf("Candidate added successfully!\n");
}

void castVote() {
    printf("Enter Candidate Name: ");
    char name[50];
    scanf("%s", name);
    
    for(int i = 0; i < numCandidates; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            candidates[i].vote++;
            printf("Vote casted successfully to %s!\n", name);
            return;
        }
    }
    
    printf("Candidate does not exist!\n");
}

void displayResult() {
    int maxIndex = 0;
    for(int i = 0; i < numCandidates; i++) {
        if(candidates[i].vote > candidates[maxIndex].vote)
            maxIndex = i;
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote);
    }
    printf("%s wins with %d votes!\n", candidates[maxIndex].name, candidates[maxIndex].vote);
}

int main() {
    int option;
    do {
        printf("1. Add Candidate\n2. Cast Vote\n3. Display Result\n4. Exit\nEnter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                addCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResult();
                break;
            case 4:
                printf("Thank You!");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while(option != 4);
    return 0;
}