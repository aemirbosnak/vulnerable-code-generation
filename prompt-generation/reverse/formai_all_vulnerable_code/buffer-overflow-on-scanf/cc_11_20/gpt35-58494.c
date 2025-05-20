//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

//Define the Max Voters and Candidates count
#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

//Define the structure for Candidates
struct Candidate {
    int id; //Unique id for Candidate
    char name[50];
    int votes;
};

//Define the structure for Voter
struct Voter {
    int id; //Unique id for Voter
    char name[50];
    int vote;
};

int main() {
    struct Candidate CandidateList[MAX_CANDIDATES];
    struct Voter VoterList[MAX_VOTERS];
    int candidateCount, voterCount, i, j, voteCount;
    int vote[MAX_CANDIDATES] = {0};
    char choice;
    
    printf("Enter Number of Candidates: ");
    scanf("%d", &candidateCount);
    
    for(i=0; i<candidateCount; i++) {
        printf("\nEnter name of Candidate %d: ", i+1);
        scanf("%s", &CandidateList[i].name);
        CandidateList[i].id = i+1;
    }
    
    printf("\nEnter Number of Voters: ");
    scanf("%d", &voterCount);
    
    for(i=0; i<voterCount; i++) {
        printf("\nEnter name of Voter %d: ", i+1);
        scanf("%s", &VoterList[i].name);
        VoterList[i].id = i+1;
        VoterList[i].vote = 0;
    }
    
    do {
        printf("\nSelect the Candidate Number to cast the Vote:");
        for(i=0; i<candidateCount; i++) {
            printf("\n%d. %s", CandidateList[i].id, CandidateList[i].name);
        }
        printf("\n%d. Review the Votes", candidateCount+1);
        printf("\n%d. Exit", candidateCount+2);
        
        scanf("%d", &voteCount);
        if(voteCount == candidateCount+1) {
            printf("\n----Review the Votes----");
            printf("\n-------- ");
            for(i=0; i<candidateCount; i++) {
                printf("%s -------- ", CandidateList[i].name);
            }
            printf("\n-------- ");
            for(i=0; i<candidateCount; i++) {
                printf("-------- ");
            }
            printf("\n");
            for(i=0; i<voterCount; i++) {
                printf("\n%s", VoterList[i].name);
                for(j=0; j<candidateCount; j++) {
                    if(VoterList[i].vote == CandidateList[j].id) {
                        printf("\t\t\t X ");
                    }
                    else {
                        printf("\t\t\t - ");
                    }
                }
            }
        }
        else if(voteCount == candidateCount+2) {
            printf("\n---- Thankyou for Voting ----");
            break;
        }
        else if(voteCount < 1 || voteCount > candidateCount) {
            printf("\nInvalid Choice! Try again.");
        }
        else {
            for(i=0; i<candidateCount; i++) {
                if(voteCount == CandidateList[i].id) {
                    CandidateList[i].votes++;
                    vote[i]++;
                }
            }
            for(i=0; i<voterCount; i++) {
                if(VoterList[i].vote == 0) {
                    VoterList[i].vote = voteCount;
                    break;
                }
            }
            printf("\nThankyou for Voting!");
        }
        
        printf("\nCast more votes? (Y/N)");
        scanf("%s", &choice);
    } while(choice == 'Y' || choice == 'y');
    
    return 0;
}