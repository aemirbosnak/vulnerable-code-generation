//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

int main()
{  
   int vote_count[NUM_CANDIDATES] = {0}; // Array to keep track of vote counts
   int candidate_number; // Variable to hold the candidate number selected by the voter

   printf("--- Welcome to the Electronic Voting System ---\n");

   for(int i = 1; i <= NUM_VOTERS; i++)
   {
      printf("\nVoter %d, please select your candidate from the following options:\n", i);
      printf("1. Candidate 1\n");
      printf("2. Candidate 2\n");
      printf("3. Candidate 3\n");
      printf("4. Candidate 4\n");
      printf("5. Candidate 5\n");
      printf("Enter candidate number: ");
      
      // Get input from the voter and increase the vote count of the selected candidate
      scanf("%d", &candidate_number);
      vote_count[candidate_number-1]++;
      printf("Thank you for your vote!\n");
   }

   printf("\n--- Voting Summary ---\n");

   // Print the vote count for each candidate
   for(int i = 0; i < NUM_CANDIDATES; i++)
   {
      printf("Candidate %d: %d\n", i+1, vote_count[i]);
   }

   // Determine the winner by finding the candidate with the highest vote count
   int winner_index = 0;
   for(int i = 1; i < NUM_CANDIDATES; i++)
   {
      if(vote_count[i] > vote_count[winner_index])
      {
         winner_index = i;
      }
   }

   // Print the winner
   printf("\nThe winner is Candidate %d with %d votes!\n", winner_index+1, vote_count[winner_index]);

   return 0;
}