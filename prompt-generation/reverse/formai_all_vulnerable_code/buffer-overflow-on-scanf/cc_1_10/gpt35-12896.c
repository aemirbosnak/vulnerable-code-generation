//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[50];
    int votes;
};

struct Voter {
    char name[50];
    int voted;
};

int main() {
    int num_candidates, num_voters, i, j, k, candidate_voted;
    struct Candidate candidates[10];
    struct Voter voters[50];
    
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);
    
    printf("Enter the names of the candidates:\n");
    for(i=0; i<num_candidates; i++) {
        printf("Candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    
    printf("Please enter the number of voters: ");
    scanf("%d", &num_voters);
    
    printf("Enter the names of the voters:\n");
    for(i=0; i<num_voters; i++) {
        printf("Voter %d: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
    }
    
    printf("\nVoting starts now!\n");
    
    for(i=0; i<num_voters; i++) {
        printf("Voter %s, please choose your candidate:\n", voters[i].name);
        for(j=0; j<num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        printf("Enter your choice: ");
        scanf("%d", &candidate_voted);
        
        while(candidate_voted < 1 || candidate_voted > num_candidates) {
            printf("Invalid choice. Please enter a valid candidate: ");
            scanf("%d", &candidate_voted);
        }
        
        for(k=0; k<num_candidates; k++) {
            if(k == candidate_voted-1) {
                candidates[k].votes++;
            }
        }
        
        voters[i].voted = 1;
        printf("Thank you for voting!\n");
    }
    
    printf("\nVoting has ended. Here are the results:\n");
    for(i=0; i<num_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
    
    printf("Thank you for using the Electronic Voting System!\n");
    
    return 0;
}