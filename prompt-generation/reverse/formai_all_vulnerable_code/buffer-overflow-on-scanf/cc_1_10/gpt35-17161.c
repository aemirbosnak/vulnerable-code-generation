//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// structure to hold candidate information
struct Candidate {
    char name[50];
    int votes;
};

// function to display menu options
void displayMenuOptions() {
    printf("1. Add Candidate\n");
    printf("2. View Candidates\n");
    printf("3. Vote for Candidate\n");
    printf("4. Exit\n");
}

int main() {
    int numCandidates = 0;
    int numVoters = 0;
    int i, j, choice, voteCount;
    struct Candidate candidates[50];
    
    while(1) {
        displayMenuOptions();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            // Add Candidate
            case 1: {
                printf("Enter the name of the candidate: ");
                scanf("%s", candidates[numCandidates].name);
                candidates[numCandidates].votes = 0;
                numCandidates++;
                break;
            }
            
            // View Candidates
            case 2: {
                printf("List of Candidates:\n");
                for(i = 0; i < numCandidates; i++) {
                    printf("%d. %s\n", i+1, candidates[i].name);
                }
                break;
            }
            
            // Vote for Candidate
            case 3: {
                printf("Enter the candidate number you want to vote for: ");
                scanf("%d", &voteCount);
                
                // check if candidate number is valid
                if(voteCount > numCandidates || voteCount <= 0) {
                    printf("Invalid candidate number. Please try again.\n");
                    break;
                }
                
                candidates[voteCount-1].votes++;
                numVoters++;
                printf("Thank you for voting!\n");
                break;
            }
            
            // Exit the program
            case 4: {
                printf("Exiting program...\n");
                return 0;
            }
            
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
    
    return 0;
}