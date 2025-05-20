//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Ada Lovelace's style naming convention for functions and variables
typedef unsigned int NATURAL;
typedef unsigned char BOOLEAN;

// Voter registration structure
struct VoterRegistration {
  char Name[50];
  NATURAL Age;
  char Address[100];
  char VoterID[15];
};

// Function to register a new voter
void RegisterVoter(struct VoterRegistration* NewVoter) {
  scanf("%s", NewVoter->Name);
  printf("Enter voter's age: ");
  scanf("%u", &NewVoter->Age);
  printf("Enter voter's address: ");
  scanf("%s", NewVoter->Address);
  // Generate a unique voter ID
  int VoterIDLength = strlen(NewVoter->Name) + strlen(NewVoter->Address) + 5;
  NewVoter->VoterID[0] = 'V';
  strncat(NewVoter->VoterID, NewVoter->Name, VoterIDLength - 1);
  strncat(NewVoter->VoterID, NewVoter->Address, VoterIDLength - strlen(NewVoter->Name) - strlen(NewVoter->Address) - 1);
  NewVoter->VoterID[VoterIDLength - 1] = (VoterIDLength % 26) + 'A';

  printf("New voter registered successfully.\n");
  printf("Voter ID: %s\n", NewVoter->VoterID);
}

// Function to check if a voter is eligible to vote
BOOLEAN IsEligibleToVote(struct VoterRegistration* Voter) {
  return Voter->Age >= 18;
}

// Function to cast a vote
void CastVote(struct VoterRegistration* Voter, char Candidate) {
  if (IsEligibleToVote(Voter)) {
    printf("%s has cast their vote for %c.\n", Voter->Name, Candidate);
  } else {
    printf("%s is not eligible to vote.\n", Voter->Name);
  }
}

int main() {
  struct VoterRegistration NewVoter;
  char Candidate;

  printf("Welcome to the Electronic Voting System!\n");

  RegisterVoter(&NewVoter);

  printf("Enter candidate symbol (A or B): ");
  scanf(" %c", &Candidate);

  CastVote(&NewVoter, Candidate);

  return 0;
}