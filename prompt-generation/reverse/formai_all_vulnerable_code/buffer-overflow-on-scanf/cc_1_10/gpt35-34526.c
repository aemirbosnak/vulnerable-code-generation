//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct voting {
    int id;
    char name[50];
    int vote;
} candidates[5];

void initializeCandidates() {
    candidates[0].id = 1;
    strcpy(candidates[0].name, "Candidate 1");
    candidates[0].vote = 0;
    
    candidates[1].id = 2;
    strcpy(candidates[1].name, "Candidate 2");
    candidates[1].vote = 0;
    
    candidates[2].id = 3;
    strcpy(candidates[2].name, "Candidate 3");
    candidates[2].vote = 0;
    
    candidates[3].id = 4;
    strcpy(candidates[3].name, "Candidate 4");
    candidates[3].vote = 0;
    
    candidates[4].id = 5;
    strcpy(candidates[4].name, "Candidate 5");
    candidates[4].vote = 0;
}

void castVote() {
    int id;
    printf("\nEnter the candidate ID to cast vote: ");
    scanf("%d", &id);
    for(int i=0; i<5; i++) {
        if(candidates[i].id == id) {
            candidates[i].vote++;
            printf("\nVote casted successfully for Candidate %d : %s\n", candidates[i].id, candidates[i].name);
            return;
        }
    }
    printf("\nInvalid candidate ID, please try again.\n");
}

void showVoteResults() {
    printf("\n-----------Voting Results-----------\n");
    for(int i=0; i<5; i++) {
        printf("%d. %s : %d votes\n", candidates[i].id, candidates[i].name, candidates[i].vote);
    }
    printf("------------------------------------\n");
}

int main() {
    initializeCandidates();
    int choice = 0;
    printf("*** Welcome to Electronic Voting System ***\n");
    
    do {
        printf("\nPlease select the option from below menu:\n");
        printf("1. Cast Vote\n");
        printf("2. Voting Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: castVote();
                    break;
            case 2: showVoteResults();
                    break;
            case 3: printf("\nThank you for using Electronic Voting System.\n");
                    break;
            default: printf("\nInvalid choice, please try again.\n");
                     break;
        }
    } while(choice != 3);
    return 0;
}