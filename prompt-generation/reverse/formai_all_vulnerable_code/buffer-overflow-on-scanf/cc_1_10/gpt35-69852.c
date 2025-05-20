//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

/* Struct to store candidate information */
typedef struct{
    int id;
    char name[50];
    int votes;
}Candidate;

/* Struct to store voter information */
typedef struct{
    int id;
    char name[50];
    int hasVoted;
}Voter;

/* Function declarations */
int addCandidate(Candidate[], int);
void viewCandidates(Candidate[], int);
int deleteCandidate(Candidate[], int);
void initiateVoting(Voter[], int);
void castVote(Voter[], int, Candidate[], int);
void displayResults(Candidate[], int);

int main(){
    int choice, candidateCount=0, voterCount=0, i;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    /* Print a welcome message */
    printf("Welcome to the Electronic Voting System\n");

    /* Infinite loop until user chooses to exit */
    while(1){
        printf("\n----------------------------------------------\n");
        printf("Choose an option from the following:\n1. Add Candidate\n2. View Candidates\n3. Delete Candidate\n4. Start Voting\n5. Display Results\n6. Exit\n");
        printf("----------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            /* Add a candidate */
            case 1:
                candidateCount = addCandidate(candidates, candidateCount);
                break;

            /* View all candidates */
            case 2:
                viewCandidates(candidates, candidateCount);
                break;

            /* Delete a candidate */
            case 3:
                candidateCount = deleteCandidate(candidates, candidateCount);
                break;

            /* Start Voting */
            case 4:
                initiateVoting(voters, voterCount);
                castVote(voters, voterCount, candidates, candidateCount);
                break;

            /* Display results */
            case 5:
                displayResults(candidates, candidateCount);
                break;

            /* Exit the program */
            case 6:
                printf("Thank you for using the Electronic Voting System\n");
                exit(0);

            /* Default case when an invalid option is chosen */
            default:
                printf("Invalid Option\n");
        }
    }
}

/* Function to add a candidate */
int addCandidate(Candidate candidates[], int candidateCount){
    int i;

    /* Check if the maximum number of candidates has been reached */
    if(candidateCount == MAX_CANDIDATES){
        printf("Maximum candidates limit reached. Cannot add more candidates.\n");
        return candidateCount;
    }

    printf("Enter the details of the candidate:\n");

    printf("ID: ");
    scanf("%d", &candidates[candidateCount].id);

    printf("Name: ");
    scanf("%s", candidates[candidateCount].name);

    candidates[candidateCount].votes = 0;

    candidateCount++;

    printf("Candidate added successfully\n");

    /* Sort candidates by ID */
    for(i=0; i<candidateCount-1; i++){
        if(candidates[i].id > candidates[i+1].id){
            Candidate temp = candidates[i];
            candidates[i] = candidates[i+1];
            candidates[i+1] = temp;
        }
    }

    return candidateCount;
}

/* Function to view all candidates */
void viewCandidates(Candidate candidates[], int candidateCount){
    int i;

    if(candidateCount == 0){
        printf("No candidates added yet.\n");
        return;
    }

    printf("Name\tID\tVotes\n");

    for(i=0; i<candidateCount; i++){
        printf("%s\t%d\t%d\n", candidates[i].name, candidates[i].id, candidates[i].votes);
    }
}

/* Function to delete a candidate */
int deleteCandidate(Candidate candidates[], int candidateCount){
    int id, i, j;

    if(candidateCount == 0){
        printf("No candidates added yet.\n");
        return candidateCount;
    }

    printf("Enter the ID of the candidate you want to delete: ");
    scanf("%d", &id);

    /* Search for the candidate with the given ID */
    for(i=0; i<candidateCount; i++){
        if(candidates[i].id == id){
            /* Delete the candidate */
            for(j=i; j<candidateCount-1; j++){
                candidates[j] = candidates[j+1];
            }

            candidateCount--;

            printf("Candidate deleted successfully\n");

            return candidateCount;
        }
    }

    /* Candidate with the given ID not found */
    printf("Candidate with ID %d not found\n", id);
    return candidateCount;
}

/* Function to initiate voting */
void initiateVoting(Voter voters[], int voterCount){
    int i, n;

    /* Seed the random number generator */
    srand(time(NULL));

    printf("Enter the number of voters: ");
    scanf("%d", &n);

    /* Add voters */
    for(i=voterCount; i<voterCount+n; i++){
        printf("Enter the details of voter %d:\n", i+1);

        printf("ID: ");
        scanf("%d", &voters[i].id);

        printf("Name: ");
        scanf("%s", voters[i].name);

        voters[i].hasVoted = 0;

        printf("%s added as a voter successfully\n", voters[i].name);
    }

    voterCount += n;
}

/* Function to cast a vote */
void castVote(Voter voters[], int voterCount, Candidate candidates[], int candidateCount){
    int i, j, n, candidateID;

    printf("Enter the number of votes to be cast: ");
    scanf("%d", &n);

    /* Check if all voters have voted */
    for(i=0; i<voterCount; i++){
        if(voters[i].hasVoted == 0){
            break;
        }
    }

    /* If all voters have already voted, stop the voting process */
    if(i == voterCount){
        printf("All voters have already voted\n");
        return;
    }

    /* Cast votes */
    for(i=0; i<n; i++){
        /* Generate a random ID between 1 and MAX_CANDIDATES */
        candidateID = rand() % MAX_CANDIDATES + 1;

        /* Search for the candidate with the given ID */
        for(j=0; j<candidateCount; j++){
            if(candidates[j].id == candidateID){
                candidates[j].votes++;
                break;
            }
        }

        /* Mark the voter as having voted */
        voters[i].hasVoted = 1;
    }

    printf("%d votes cast successfully\n", n);
}

/* Function to display the results */
void displayResults(Candidate candidates[], int candidateCount){
    int i, winner=0;

    if(candidateCount == 0){
        printf("No candidates added yet.\n");
        return;
    }

    printf("Name\tID\tVotes\n");

    for(i=0; i<candidateCount; i++){
        printf("%s\t%d\t%d\n", candidates[i].name, candidates[i].id, candidates[i].votes);

        /* Check if this candidate has more votes than the current winner */
        if(candidates[i].votes > candidates[winner].votes){
            winner = i;
        }
    }

    printf("%s is the winner with %d votes\n", candidates[winner].name, candidates[winner].votes);
}