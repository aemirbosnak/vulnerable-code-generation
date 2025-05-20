//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES 100

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    char name[50];
    int vote;
    int voterID;
} vote;

candidate candidates[MAX_CANDIDATES];
vote votes[MAX_VOTERS][MAX_VOTES];

void addCandidate() {
    int i;
    for(i=0;i<MAX_CANDIDATES;i++) {
        if(candidates[i].name[0]=='\0') {
            printf("Enter the name of the candidate: ");
            scanf("%s", candidates[i].name);
            printf("Candidate added successfully!\n");
            return;
        }
    }
    printf("Maximum number of candidates reached!\n");
}

void addVoter() {
    int i;
    for(i=0;i<MAX_VOTERS;i++) {
        if(votes[i][0].name[0]=='\0') {
            printf("Enter the name of the voter: ");
            scanf("%s", votes[i][0].name);
            printf("Voter added successfully!\n");
            return;
        }
    }
    printf("Maximum number of voters reached!\n");
}

void castVote() {
    int i,j,k,count=0;
    printf("Enter the voter ID: ");
    scanf("%d", &k);
    for(i=0;i<MAX_VOTERS;i++) {
        if(votes[i][0].voterID==k) {
            printf("Enter the candidate name: ");
            scanf("%s", votes[i][count].name);
            votes[i][count].vote=1;
            count++;
        }
    }
    printf("Vote cast successfully!\n");
}

void displayVotes() {
    int i,j,max=0,count=0;
    for(i=0;i<MAX_CANDIDATES;i++) {
        if(candidates[i].name[0]!='\0') {
            printf("%s has %d vote(s)\n", candidates[i].name, candidates[i].votes);
        }
    }
    printf("\n");
    for(i=0;i<MAX_VOTERS;i++) {
        if(votes[i][0].name[0]!='\0') {
            printf("Voter %s voted for:\n", votes[i][0].name);
            for(j=0;j<MAX_VOTES;j++) {
                if(votes[i][j].name[0]!='\0') {
                    printf("%s\n", votes[i][j].name);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. Cast vote\n");
        printf("4. Display votes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                addVoter();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayVotes();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!=5);
    return 0;
}