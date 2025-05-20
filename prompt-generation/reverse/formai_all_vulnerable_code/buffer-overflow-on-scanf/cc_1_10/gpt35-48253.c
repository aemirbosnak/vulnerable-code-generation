//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

char* candidates[MAX_CANDIDATES];
int votes[MAX_VOTES];
int numCandidates = 0;
int numVotes = 0;
int voteCasted = 0;

int isDuplicate(char* name) {
  for(int i=0;i<numCandidates;i++){
    if(strcmp(candidates[i],name)==0){
      return 1;
    }
  }
  return 0;
}

void addCandidate(char* name) {
  if(numCandidates>=MAX_CANDIDATES) {
    printf("Unable to add candidate! Maximum limit reached!\n");
    return;
  }
  if(isDuplicate(name)) {
    printf("Unable to add candidate! Candidate already exists!\n");
    return;
  }
  candidates[numCandidates] = strdup(name);
  numCandidates++;
}

void castVote(char* name) {
  int position = -1;
  for(int i=0;i<numCandidates;i++) {
    if(strcmp(candidates[i],name)==0) {
      position = i;
      break;
    }
  }
  if(position==-1) {
    printf("Invalid candidate name! Please try again!\n");
    return;
  }
  voteCasted++;
  votes[position]++;
}

void printResults(){
  printf("\nResults: \n");
  printf("--------------------------------------------------\n");
  for(int i=0;i<numCandidates;i++) {
    printf("| %20s | %10d |\n",candidates[i],votes[i]);
    printf("--------------------------------------------------\n");
  }
  printf("--------------------------------------------------\n");
}

int main() {
  char name[30];
  int choice;
  while(1) {
    printf("Election System\n");
    printf("1. Add Candidate\n");
    printf("2. Cast Vote\n");
    printf("3. Print Results\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter name of the candidate: ");
        scanf("%s", name);
        addCandidate(name);
        break;
      case 2:
        printf("Enter name of the candidate: ");
        scanf("%s", name);
        castVote(name);
        break;
      case 3:
        printResults();
        break;
      case 4:
        printf("Thank you for using the Election System!\n");
        return 0;
      default:
        printf("Invalid choice!\n");
    }
  }
  return 0;
}