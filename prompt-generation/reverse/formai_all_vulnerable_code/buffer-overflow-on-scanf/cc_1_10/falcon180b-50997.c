//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

struct Voter {
    char name[50];
    int age;
    int voterID;
};

struct Candidate {
    char name[50];
    int votes;
};

void addVoter(struct Voter voters[], int n) {
    printf("Enter name of voter: ");
    scanf("%s", voters[n].name);
    printf("Enter age of voter: ");
    scanf("%d", &voters[n].age);
    printf("Enter voter ID: ");
    scanf("%d", &voters[n].voterID);
}

void displayVoters(struct Voter voters[], int n) {
    printf("\nList of voters:\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s (%d years old) - Voter ID: %d\n", i+1, voters[i].name, voters[i].age, voters[i].voterID);
    }
}

void addCandidate(struct Candidate candidates[], int n) {
    printf("\nEnter name of candidate: ");
    scanf("%s", candidates[n].name);
    candidates[n].votes = 0;
}

void displayCandidates(struct Candidate candidates[], int n) {
    printf("\nList of candidates:\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s - Votes: %d\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

void vote(struct Voter voters[], struct Candidate candidates[], int n) {
    int choice;
    printf("\nEnter your choice of candidate: ");
    scanf("%d", &choice);
    candidates[choice-1].votes++;
}

int main() {
    int n;
    printf("Enter number of voters: ");
    scanf("%d", &n);
    struct Voter voters[n];
    for(int i=0; i<n; i++) {
        addVoter(voters, i);
    }
    int m;
    printf("\nEnter number of candidates: ");
    scanf("%d", &m);
    struct Candidate candidates[m];
    for(int i=0; i<m; i++) {
        addCandidate(candidates, i);
    }
    int choice;
    printf("\nSelect an option:\n1. Display list of voters\n2. Display list of candidates\n3. Vote\n4. Exit\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            displayVoters(voters, n);
            break;
        case 2:
            displayCandidates(candidates, m);
            break;
        case 3:
            printf("\nEnter your voter ID: ");
            int voterID;
            scanf("%d", &voterID);
            for(int i=0; i<n; i++) {
                if(voters[i].voterID == voterID) {
                    vote(voters, candidates, m);
                    break;
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
    return 0;
}