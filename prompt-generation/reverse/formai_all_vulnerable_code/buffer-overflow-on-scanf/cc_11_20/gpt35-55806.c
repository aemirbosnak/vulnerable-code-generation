//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_OF_CANDIDATES 5
#define NUM_OF_VOTERS 100

struct Candidate {
    char name[20];
    int votes;
};

struct Voter {
    int id;
    int voted_for;
    int voted;
};

int main() {
    struct Candidate candidates[NUM_OF_CANDIDATES] = {{"John", 0}, {"Jane", 0}, {"Michael", 0}, {"Emily", 0}, {"David", 0}};
    struct Voter voters[NUM_OF_VOTERS];
    int num_of_voters = 0;
    int num_of_votes = 0;
    int choice;
    int i, j;
    
    while (1) {
        printf("1. Add Voter\n2. Cast Vote\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (num_of_voters == NUM_OF_VOTERS) {
                    printf("Max number of voters reached.\n");
                } else {
                    voters[num_of_voters].id = num_of_voters + 1;
                    voters[num_of_voters].voted = 0;
                    num_of_voters++;
                    printf("Voter %d added.\n", num_of_voters);
                }
                break;
            case 2:
                printf("Enter voter ID: ");
                scanf("%d", &choice);
                
                if (choice < 1 || choice > num_of_voters) {
                    printf("Invalid voter ID.\n");
                } else if (voters[choice-1].voted == 1) {
                    printf("This voter has already cast a vote.\n");
                } else {
                    printf("Candidates:\n");
                    for (i = 0; i < NUM_OF_CANDIDATES; i++) {
                        printf("%d. %s\n", i+1, candidates[i].name);
                    }
                    printf("Enter candidate number: ");
                    scanf("%d", &choice);
                    
                    if (choice < 1 || choice > NUM_OF_CANDIDATES) {
                        printf("Invalid candidate number.\n");
                    } else {
                        candidates[choice-1].votes++;
                        voters[choice-1].voted = 1;
                        voters[choice-1].voted_for = choice;
                        num_of_votes++;
                        printf("Vote casted for %s.\n", candidates[choice-1].name);
                    }
                }
                
                break;
            case 3:
                printf("Results:\n");
                for (i = 0; i < NUM_OF_CANDIDATES; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
                }
                
                printf("Voter list:\n");
                for (i = 0; i < num_of_voters; i++) {
                    printf("Voter %d voted for ", voters[i].id);
                    if (voters[i].voted == 1) {
                        printf("%s\n", candidates[voters[i].voted_for-1].name);
                    } else {
                        printf("no one\n");
                    }
                }
                
                printf("Total number of votes casted: %d\n", num_of_votes);
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}