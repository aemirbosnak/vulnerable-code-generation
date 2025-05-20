//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS     100

// Data structures
typedef struct {
   char name[30];
   int votes;
} Candidate;

typedef struct {
   char name[30];
   bool has_voted;
} Voter;

// Global variables
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int total_votes = 0;
int num_candidates = 0;
int num_voters = 0;

// Function prototypes
void addCandidate(char* name);
void vote();
void displayResults();
void addVoter(char* name);

// Main function
int main() {
   printf("Welcome to the Electronic Voting System!\n\n");
   printf("How many candidates are running for the election? ");
   scanf("%d", &num_candidates);
   getchar(); // Remove the newline character
   printf("\n");

   for(int i = 0; i < num_candidates; i++) {
      printf("Enter the name of Candidate %d: ", i + 1);
      fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
      candidates[i].name[strlen(candidates[i].name) - 1] = '\0'; // Remove the newline character
      candidates[i].votes = 0;
   }
   printf("\n");

   printf("How many voters are there? ");
   scanf("%d", &num_voters);
   getchar(); // Remove the newline character
   printf("\n");

   for(int i = 0; i < num_voters; i++) {
      printf("Enter the name of Voter %d: ", i + 1);
      fgets(voters[i].name, sizeof(voters[i].name), stdin);
      voters[i].name[strlen(voters[i].name) - 1] = '\0'; // Remove the newline character
      voters[i].has_voted = false;
   }
   printf("\n");

   while(true) {
      printf("1. Add Candidate\n");
      printf("2. Vote\n");
      printf("3. Display Results\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      int choice;
      scanf("%d", &choice);
      printf("\n");

      switch(choice) {
         case 1: {
            char name[30];
            printf("Enter the name of the candidate: ");
            getchar(); // Remove the newline character
            fgets(name, sizeof(name), stdin);
            name[strlen(name) - 1] = '\0'; // Remove the newline character
            addCandidate(name);
            break;
         }
         case 2:
            vote();
            break;
         case 3:
            displayResults();
            break;
         case 4:
            printf("Thank you for using the Electronic Voting System!\n");
            return 0;
         default:
            printf("Invalid choice. Please try again.\n");
      }
      printf("\n");
   }

   return 0;
}

// Function to add a candidate
void addCandidate(char* name) {
   if(num_candidates == MAX_CANDIDATES) {
      printf("The maximum number of candidates (%d) has been reached.\n", MAX_CANDIDATES);
      return;
   }

   for(int i = 0; i < num_candidates; i++) {
      if(strcmp(name, candidates[i].name) == 0) {
         printf("A candidate with the same name already exists.\n");
         return;
      }
   }

   strcpy(candidates[num_candidates].name, name);
   candidates[num_candidates].votes = 0;
   num_candidates++;

   printf("Candidate added successfully.\n");
}

// Function to cast a vote
void vote() {
   char name[30];
   printf("Enter your name: ");
   fgets(name, sizeof(name), stdin);
   name[strlen(name) - 1] = '\0'; // Remove the newline character
   printf("\n");

   for(int i = 0; i < num_voters; i++) {
      if(strcmp(name, voters[i].name) == 0) {
         if(voters[i].has_voted) {
            printf("You have already voted.\n");
            return;
         }
         voters[i].has_voted = true;
         break;
      }
   }

   int choice;
   printf("Please select a candidate:\n");
   for(int i = 0; i < num_candidates; i++) {
      printf("%d. %s\n", i + 1, candidates[i].name);
   }
   printf("Enter your choice: ");
   scanf("%d", &choice);
   printf("\n");

   if(choice < 1 || choice > num_candidates) {
      printf("Invalid choice. Please try again.\n");
      return;
   }

   candidates[choice - 1].votes++;
   total_votes++;

   printf("Thank you for voting.\n");
}

// Function to display the election results
void displayResults() {
   if(total_votes == 0) {
      printf("No votes have been cast yet.\n");
      return;
   }

   printf("Election Results:\n");
   for(int i = 0; i < num_candidates; i++) {
      printf("%s: %d votes (%.2f%%)\n", candidates[i].name, candidates[i].votes,
             (float)candidates[i].votes / total_votes * 100);
   }
   printf("Total Votes: %d\n", total_votes);
}