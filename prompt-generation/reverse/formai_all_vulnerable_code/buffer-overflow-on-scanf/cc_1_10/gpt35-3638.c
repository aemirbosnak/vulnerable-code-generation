//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct for Voter Information
struct Voter{
    char name[50];
    int age;
    char gender[50];
    int nationalId;
    int voted;
};

//Struct for Candidate Information
struct Candidate{
    char name[50];
    char party[50];
    int votes;
};

//Function to Add New Voter
void addVoter(struct Voter *voters, int *numVoters){
    printf("Enter Voter Name: ");
    scanf("%s", voters[*numVoters].name);
    printf("Enter Voter Age: ");
    scanf("%d", &voters[*numVoters].age);
    printf("Enter Voter Gender: ");
    scanf("%s", voters[*numVoters].gender);
    printf("Enter Voter National ID Number: ");
    scanf("%d", &voters[*numVoters].nationalId);
    voters[*numVoters].voted = 0;
    *numVoters += 1;
    printf("Voter Added Successfully!\n\n");
}

//Function to Add New Candidate
void addCandidate(struct Candidate *candidates, int *numCandidates){
    printf("Enter Candidate Name: ");
    scanf("%s", candidates[*numCandidates].name);
    printf("Enter Candidate Party: ");
    scanf("%s", candidates[*numCandidates].party);
    candidates[*numCandidates].votes = 0;
    *numCandidates += 1;
    printf("Candidate Added Successfully!\n\n");
}

//Function to Cast Vote
void castVote(struct Voter *voters, int numVoters, struct Candidate *candidates, int numCandidates){
    int id, candidateId;
    printf("Enter National ID Number: ");
    scanf("%d", &id);
    for(int i=0; i<numVoters; i++){
        if(voters[i].nationalId == id){
            if(voters[i].voted == 1){
                printf("You have already voted!\n\n");
                return;
            }
            else{
                printf("Welcome %s!\n", voters[i].name);
                printf("Cast Your Vote:\n");
                for(int j=0; j<numCandidates; j++){
                    printf("%d: %s, %s\n", j+1, candidates[j].name, candidates[j].party);
                }
                printf("Enter Candidate Number: ");
                scanf("%d", &candidateId);
                if(candidateId > numCandidates || candidateId <= 0){
                    printf("Invalid Candidate Number!\n\n");
                    return;
                }
                else{
                    candidates[candidateId-1].votes += 1;
                    voters[i].voted = 1;
                    printf("Your Vote Has Been Casted Successfully!\n\n");
                    return;
                }
            }
        }
    }
    printf("ID Number Not Found!\n\n");
}

//Function to Display Election Results
void displayResults(struct Candidate *candidates, int numCandidates){
    int max = 0;
    printf("Election Results:\n");
    for(int i=0; i<numCandidates; i++){
        printf("%s, %s: %d votes\n", candidates[i].name, candidates[i].party, candidates[i].votes);
        if(candidates[i].votes > candidates[max].votes)
            max = i;
    }
    printf("The Winner is %s!\n\n", candidates[max].name);
}

//Main Function
int main()
{
    struct Voter voters[50];
    struct Candidate candidates[10];
    int numVoters = 0, numCandidates = 0, option;
    while(1){
        printf("\nElectronic Voting System\n");
        printf("1. Add Voter\n");
        printf("2. Add Candidate\n");
        printf("3. Cast Vote\n");
        printf("4. Display Election Results\n");
        printf("5. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option);
        if(option == 1){
            addVoter(voters, &numVoters);
        }
        else if(option == 2){
            addCandidate(candidates, &numCandidates);
        }
        else if(option == 3){
            castVote(voters, numVoters, candidates, numCandidates);
        }
        else if(option == 4){
            displayResults(candidates, numCandidates);
        }
        else if(option == 5){
            exit(0);
        }
        else{
            printf("Invalid Option!\n\n");
        }
    }
    return 0;
}