//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Global variables for the program
int numCandidates;
int numVoters;
char candidates[MAX_CANDIDATES][50];
char voters[MAX_VOTERS][50];
int votes[MAX_CANDIDATES] = {0};

// Function prototypes
void addCandidate(char name[]);
void displayCandidates();
void addVoter(char name[]);
void displayVoters();
bool hasVoted(char name[]);
void castVote();

int main() {
  char choice;
  char name[50];
  bool finished = false;
  
  printf("Welcome to the Electronic Voting System!\n\n");
  
  printf("First, let's set up the candidates. How many candidates are there? ");
  scanf("%d", &numCandidates);
  getchar();
  
  for (int i = 0; i < numCandidates; i++) {
    printf("Enter the name of candidate %d: ", i+1);
    fgets(candidates[i], 50, stdin);
    candidates[i][strlen(candidates[i])-1] = '\0';
  }
  
  printf("The candidates are:\n");
  displayCandidates();
  
  printf("\nNow, let's set up the voters. How many voters are there? ");
  scanf("%d", &numVoters);
  getchar();
  
  for (int i = 0; i < numVoters; i++) {
    printf("Enter the name of voter %d: ", i+1);
    fgets(voters[i], 50, stdin);
    voters[i][strlen(voters[i])-1] = '\0';
  }
  
  printf("The voters are:\n");
  displayVoters();
  
  while (!finished) {
    printf("\nWhat would you like to do?\n");
    printf("A - Add a candidate\n");
    printf("B - Add a voter\n");
    printf("C - Cast a vote\n");
    printf("Q - Quit\n");
    printf("Choice: ");
    
    scanf("%c", &choice);
    getchar();
    
    switch (choice) {
      case 'A':
        printf("\nEnter the name of the candidate: ");
        fgets(name, 50, stdin);
        name[strlen(name)-1] = '\0';
        addCandidate(name);
        printf("\nThe candidates are now:\n");
        displayCandidates();
        break;
        
      case 'B':
        printf("\nEnter the name of the voter: ");
        fgets(name, 50, stdin);
        name[strlen(name)-1] = '\0';
        addVoter(name);
        printf("\nThe voters are now:\n");
        displayVoters();
        break;
        
      case 'C':
        castVote();
        break;
        
      case 'Q':
        finished = true;
        printf("\nThank you for using the Electronic Voting System!\n");
        break;
        
      default:
        printf("\nInvalid choice, please try again.\n");
        break;
    }
  }
  
  return 0;
}

void addCandidate(char name[]) {
  if (numCandidates < MAX_CANDIDATES) {
    strcpy(candidates[numCandidates], name);
    numCandidates++;
  } else {
    printf("\nMaximum number of candidates reached.\n");
  }
}

void displayCandidates() {
  for (int i = 0; i < numCandidates; i++) {
    printf("%d. %s\n", i+1, candidates[i]);
  }
}

void addVoter(char name[]) {
  if (numVoters < MAX_VOTERS) {
    strcpy(voters[numVoters], name);
    numVoters++;
  } else {
    printf("\nMaximum number of voters reached.\n");
  }
}

void displayVoters() {
  for (int i = 0; i < numVoters; i++) {
    printf("%d. %s\n", i+1, voters[i]);
  }
}

bool hasVoted(char name[]) {
  for (int i = 0; i < numVoters; i++) {
    if (strcmp(voters[i], name) == 0) {
      if (votes[i] == 0) {
        return false;
      } else {
        return true;
      }
    }
  }
  return false;
}

void castVote() {
  char name[50];
  bool valid = false;
  
  printf("\nEnter the name of the voter: ");
  fgets(name, 50, stdin);
  name[strlen(name)-1] = '\0';
  
  if (hasVoted(name)) {
    printf("\nThis voter has already cast a vote.\n");
  } else {
    printf("\nEnter the name of the candidate: ");
    fgets(name, 50, stdin);
    name[strlen(name)-1] = '\0';
    
    for (int i = 0; i < numCandidates; i++) {
      if (strcmp(candidates[i], name) == 0) {
        votes[i]++;
        printf("\nVote recorded for %s.\n", candidates[i]);
        valid = true;
        break;
      }
    }
    
    if (!valid) {
      printf("\nInvalid candidate name.\n");
    }
  }
}