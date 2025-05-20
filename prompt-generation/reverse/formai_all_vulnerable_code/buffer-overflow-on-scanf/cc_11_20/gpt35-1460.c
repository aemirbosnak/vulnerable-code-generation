//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include<stdio.h> // standard input/output header file
#include<stdlib.h> // header file for functions involving memory allocation, process control, conversions and others
#include<string.h> // header file for string functions

#define MAXVOTES 10 // maximum number of votes

struct candidate // structure for candidate data
{
    int id;
    char name[20];
    int voteCount;
};

struct vote // structure for vote data
{
    int voterId;
    int candidateId;
    int isVoted;
};

int main()
{
    struct candidate candidates[] = {
        {1, "John Doe", 0},
        {2, "Jane Smith", 0},
        {3, "Bob Johnson", 0},
        {4, "Amy Lee", 0},
        {5, "Joe Brown", 0}
        // Add more candidates here if needed
    };
    struct vote votes[MAXVOTES]; // array of votes
    int numVotes = 0; // number of votes casted
    int numCandidates = sizeof(candidates) / sizeof(candidates[0]); // number of candidates
    int loggedInVoterId = -1; // ID of the voter currently logged in
    
    printf("Welcome to Electronic Voting System!\n");
    
    while(1) // main loop
    {
        int choice;
        printf("\nPlease select an option:\n");
        printf("1. Login as Voter\n");
        printf("2. Vote for Candidate\n");
        printf("3. View Election Results\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: // login as voter
            {
                int voterId;
                printf("\nEnter your Voter ID: ");
                scanf("%d", &voterId);
                
                int isFound = 0;
                for(int i=0; i<numVotes; i++) // check if voter has already logged in
                {
                    if(votes[i].voterId == voterId)
                    {
                        printf("\nSorry, you have already logged in\n");
                        isFound = 1;
                        break;
                    }
                }
                
                if(!isFound) // if voter has not logged in, store id and mark as voted as false
                {
                    if(numVotes == MAXVOTES) // check if max votes limit has been reached
                    {
                        printf("\nSorry, maximum number of votes limit has been reached\n");
                    }
                    else
                    {
                        votes[numVotes].voterId = voterId;
                        votes[numVotes].isVoted = 0;
                        printf("\nWelcome Voter %d!\n", voterId);
                        loggedInVoterId = voterId;
                    }
                }
                break;
            }
            case 2: // vote for candidate
            {
                if(loggedInVoterId == -1) // check if voter has logged in
                {
                    printf("\nSorry, you need to login first!\n");
                    break;
                }
                
                int candidateId;
                printf("\nList of Candidates:\n");
                for(int i=0; i<numCandidates; i++) // print list of candidates
                {
                    printf("%d. %s\n", candidates[i].id, candidates[i].name);
                }
                printf("\nEnter Candidate ID to Vote: ");
                scanf("%d", &candidateId);
                
                if(candidateId < 1 || candidateId > numCandidates) // check if candidate id is valid
                {
                    printf("\nSorry, invalid Candidate ID!\n");
                    break;
                }
                
                for(int i=0; i<numVotes; i++) // check if voter has already voted
                {
                    if(votes[i].voterId == loggedInVoterId && votes[i].isVoted)
                    {
                        printf("\nSorry, you have already voted!\n");
                        break;
                    }
                }
                
                candidates[candidateId-1].voteCount++; // increment vote count of candidate
                printf("\nThank you for voting!\n");
                
                for(int i=0; i<numVotes; i++) // mark voter as voted
                {
                    if(votes[i].voterId == loggedInVoterId)
                    {
                        votes[i].isVoted = 1;
                        break;
                    }
                }
                
                loggedInVoterId = -1; // log out voter
                numVotes++; // increase number of votes casted
                break;
            }
            case 3: // view election results
            {
                printf("\nElection Results:\n");
                for(int i=0; i<numCandidates; i++) // print results
                {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].voteCount);
                }
                break;
            }
            case 4: // exit program
            {
                printf("\nThank you for using Electronic Voting System!\n\n");
                exit(0);
            }
            default: // invalid input
            {
                printf("\nInvalid Input!\n");
                break;
            }
        }
    }
    
    return 0;
}