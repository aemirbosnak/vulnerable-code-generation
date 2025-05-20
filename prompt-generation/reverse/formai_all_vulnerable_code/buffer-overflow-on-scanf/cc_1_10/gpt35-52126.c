//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// data structure for an individual candidate
typedef struct candidate {
    char name[50];
    int votes;
} Candidate;

// data structure for a list of candidates
typedef struct candidateList {
    Candidate candidates[MAX_CANDIDATES];
    int count;
} CandidateList;

// data structure for an individual voter
typedef struct voter {
    char name[50];
    char id[10];
    int hasVoted;
} Voter;

// data structure for a list of voters
typedef struct voterList {
    Voter voters[MAX_VOTERS];
    int count;
} VoterList;

// function to add a candidate to the list
void addCandidate(CandidateList *list, char *name) {
    if(list->count >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached!\n");
        return;
    }
    Candidate newCandidate;
    strcpy(newCandidate.name, name);
    newCandidate.votes = 0;
    list->candidates[list->count++] = newCandidate;
    printf("Candidate added successfully!\n");
}

// function to add a voter to the list
void addVoter(VoterList *list, char *name, char *id) {
    if(list->count >= MAX_VOTERS) {
        printf("Maximum number of voters reached!\n");
        return;
    }
    Voter newVoter;
    strcpy(newVoter.name, name);
    strcpy(newVoter.id, id);
    newVoter.hasVoted = 0;
    list->voters[list->count++] = newVoter;
    printf("Voter added successfully!\n");
}

// function to check if a string is a valid integer
int isInteger(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// function to vote for a candidate
void castVote(CandidateList *list, VoterList *voterList, char *voterId, char *candidateName) {
    // find the voter in the list
    int voterIndex = -1;
    for(int i = 0; i < voterList->count; i++) {
        if(strcmp(voterList->voters[i].id, voterId) == 0) {
            voterIndex = i;
            break;
        }
    }
    if(voterIndex == -1) {
        printf("Voter not found!\n");
        return;
    }
    // make sure this voter hasn't already voted
    if(voterList->voters[voterIndex].hasVoted == 1) {
        printf("You've already voted!\n");
        return;
    }
    // find the candidate in the list
    int candidateIndex = -1;
    for(int i = 0; i < list->count; i++) {
        if(strcmp(list->candidates[i].name, candidateName) == 0) {
            candidateIndex = i;
            break;
        }
    }
    if(candidateIndex == -1) {
        printf("Candidate not found!\n");
        return;
    }
    // increment the candidate's vote count and mark the voter as having voted
    list->candidates[candidateIndex].votes++;
    voterList->voters[voterIndex].hasVoted = 1;
    printf("Your vote has been cast successfully!\n");
}

// function to display the election results
void displayResults(CandidateList *list) {
    printf("Election Results:\n");
    printf("Name\t\tVotes\n");
    for(int i = 0; i < list->count; i++) {
        printf("%s\t\t%d\n", list->candidates[i].name, list->candidates[i].votes);
    }
    printf("\n");
}

int main() {
    CandidateList candidateList;
    candidateList.count = 0;

    VoterList voterList;
    voterList.count = 0;

    int option;
    char name[50], id[10], candidateName[50];

    printf("\t\tELECTRONIC VOTING SYSTEM\n");
    printf("-------------------------------------------------------\n");
    while(1) {
        printf("1. Add Candidate\n");
        printf("2. Add Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                addCandidate(&candidateList, name);
                break;
            case 2:
                printf("Enter voter name: ");
                scanf("%s", name);
                printf("Enter voter ID: ");
                scanf("%s", id);
                addVoter(&voterList, name, id);
                break;
            case 3:
                printf("Enter voter ID: ");
                scanf("%s", id);
                printf("Enter candidate name: ");
                scanf("%s", candidateName);
                castVote(&candidateList, &voterList, id, candidateName);
                break;
            case 4:
                displayResults(&candidateList);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}