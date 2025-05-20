//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct candidate {
    char name[20];
    int votes;
};

struct voter {
    int id;
    int voted;
    int age;
};

struct candidate candidates[MAX_CANDIDATES];
struct voter voters[MAX_VOTERS];

int candidateCount = 0;
int voterCount = 0;

int addCandidate(char name[]) {
    if(candidateCount >= MAX_CANDIDATES) {
        printf("Max candidate limit reached!\n");
        return -1;
    }
    strcpy(candidates[candidateCount].name, name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    return 0;
}

int addVoter(int age) {
    if(voterCount >= MAX_VOTERS) {
        printf("Max voter limit reached!\n");
        return -1;
    }
    voters[voterCount].id = voterCount + 1;
    voters[voterCount].voted = 0;
    voters[voterCount].age = age;
    voterCount++;
    return 0;
}

void castVote(int voterID, int candidateID) {
    if(voters[voterID].voted) {
        printf("Error: This voter has already cast their vote!\n");
    } else {
        candidates[candidateID].votes++;
        voters[voterID].voted = 1;
        printf("Vote successfully cast!\n");
    }
}

void displayResults() {
    if(candidateCount == 0 || voterCount == 0) {
        printf("No results to show!\n");
        return;
    }
    printf("Candidate\tVotes Received\n");
    for(int i=0; i < candidateCount; i++) {
        printf("%s\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    printf("Welcome to the electronic voting system!\n");
    printf("Please enter candidate names:\n");
    char candidateName[20];
    int i=0;
    while(1) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidateName);
        if(strlen(candidateName) == 0) {
            break;
        }
        addCandidate(candidateName);
        i++;
    }
    printf("Please enter voter details:\n");
    int voterAge;
    i=0;
    while(1) {
        printf("Enter age of voter %d: ", i+1);
        scanf("%d", &voterAge);
        if(voterAge < 18) {
            printf("The minimum voting age is 18!\n");
            continue;
        }
        if(addVoter(voterAge) == -1) {
            break;
        }
        i++;
    }
    printf("Voting in progress!\n");
    printf("Please enter your voter ID and the candidate ID you want to vote for:\n");
    int voterID, candidateID;
    while(1) {
        printf("Voter ID: ");
        scanf("%d", &voterID);
        printf("Candidate ID: ");
        scanf("%d", &candidateID);
        if(voterID < 1 || voterID > voterCount) {
            printf("Invalid voter ID!\n");
            continue;
        }
        if(candidateID < 1 || candidateID > candidateCount) {
            printf("Invalid candidate ID!\n");
            continue;
        }
        castVote(voterID-1, candidateID-1);
        printf("Would you like to continue voting? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if(choice == 'n') {
            break;
        }
    }
    printf("Voting has ended! Here are the results:\n");
    displayResults();
    return 0;
}