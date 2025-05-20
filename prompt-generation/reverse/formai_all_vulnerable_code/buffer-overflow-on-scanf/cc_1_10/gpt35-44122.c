//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to hold voter data
struct Voter {
    char name[50];
    int age;
    char gender[10];
    int voted;
};

//Function to count the number of voters who have cast their vote
int countVotes(struct Voter voters[], int numVoters) {
    int count = 0;
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].voted == 1) {
            count++;
        }
    }
    return count;
}

//Main function
int main() {
    //Initialize variables
    int numVoters = 0;
    int numCandidates = 0;
    int voteCount[10] = {0};
    char candidateNames[10][50];
    struct Voter voters[100];

    //Get the number of voters
    printf("Welcome to Electronic Voting System 2.0 - Post-Apocalyptic Edition!\n");
    printf("Please enter the number of voters: ");
    scanf("%d", &numVoters);

    //Get the number of candidates
    printf("Please enter the number of candidates: ");
    scanf("%d", &numCandidates);

    //Get the names of the candidates
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidateNames[i]);
    }

    //Get the voter data
    for (int i = 0; i < numVoters; i++) {
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        printf("Enter the age of voter %d: ", i+1);
        scanf("%d", &voters[i].age);
        printf("Enter the gender of voter %d (Male/Female/Other): ", i+1);
        scanf("%s", voters[i].gender);
        voters[i].voted = 0;
    }

    //Start the voting process
    printf("Voting has started! Please cast your vote.\n");

    while (countVotes(voters, numVoters) < numVoters) {
        //Display the candidates
        printf("Candidates:\n");
        for (int i = 0; i < numCandidates; i++) {
            printf("%d. %s\n", i+1, candidateNames[i]);
        }

        //Get the voter's choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Check if the choice is valid
        if (choice < 1 || choice > numCandidates) {
            printf("Invalid choice! Please choose again.\n");
            continue;
        }

        //Update vote count and mark voter as voted
        voteCount[choice-1]++;
        voters[countVotes(voters, numVoters)].voted = 1;
    }

    //Display the results
    printf("Voting has ended! Here are the results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s received %d votes.\n", candidateNames[i], voteCount[i]);
    }

    return 0;
}