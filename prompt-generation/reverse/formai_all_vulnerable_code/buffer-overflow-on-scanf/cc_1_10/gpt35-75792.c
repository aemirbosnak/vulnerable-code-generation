//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>

//Structure for storing candidate data
typedef struct {
    char name[30];
    int votes;
} Candidate;

//Structure for storing election data
typedef struct {
    char name[50]; //Election name
    int num_candidates; //Number of candidates
    Candidate candidates[10]; //Array for storing candidates
} Election;

int main() {
    Election election;
    
    //Get election name from user
    printf("Enter election name: ");
    fgets(election.name, sizeof(election.name), stdin);
    strtok(election.name, "\n"); //Removing newline character from input
    
    //Get number of candidates from user
    printf("Enter number of candidates: ");
    scanf("%d", &(election.num_candidates));
    getchar(); //Clearing input buffer
    
    //Get candidate names from user and store in array
    for(int i=0; i<election.num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        fgets(election.candidates[i].name, sizeof(election.candidates[i].name), stdin);
        strtok(election.candidates[i].name, "\n"); //Removing newline character from input
        election.candidates[i].votes = 0; //Initializing votes to 0
    }
    
    //Display menu for voting
    int choice = 0;
    while(choice != 2) {
        printf("\nMENU:\n1. Vote\n2. Exit\n\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: { //Vote
                int candidate_choice = 0;
                printf("\nCANDIDATES:\n");
                for(int i=0; i<election.num_candidates; i++) {
                    printf("%d. %s\n", i+1, election.candidates[i].name);
                }
                printf("\nEnter candidate number to vote: ");
                scanf("%d", &candidate_choice);
                if(candidate_choice < 1 || candidate_choice > election.num_candidates) {
                    printf("\nInvalid candidate number.\n");
                } else {
                    election.candidates[candidate_choice-1].votes++;
                    printf("\nVote recorded.\n");
                }
                break;
            }
            case 2: //Exit
                break;
            default: //Invalid choice
                printf("\nInvalid choice.\n");
                break;
        }
    }
    
    //Display election results
    printf("\nELECTION RESULTS:\n");
    printf("Name of election: %s\n", election.name);
    for(int i=0; i<election.num_candidates; i++) {
        printf("%s: %d votes\n", election.candidates[i].name, election.candidates[i].votes);
    }
    
    return 0;    
}