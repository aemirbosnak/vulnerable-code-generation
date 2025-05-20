//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int candidates, voters, i, j;
   srand(time(0)); // seed for random number generator

   printf("Welcome to the Electronic Voting System!\n");

   // get number of candidates
   do {
      printf("Enter the number of candidates (maximum 5): ");
      scanf("%d", &candidates);
   } while (candidates <= 0 || candidates > 5);
   
   // get number of voters
   do {
      printf("Enter the number of voters: ");
      scanf("%d", &voters);
   } while (voters <= 0);

   // initialize candidate names and votes to zero
   char candidate_names[candidates][20];
   int votes[candidates];
   for (i = 0; i < candidates; i++) {
      printf("Enter the name of candidate %d: ", i+1);
      scanf("%s", candidate_names[i]);
      votes[i] = 0; // initialize votes to zero
   }

   // loop through each voter and cast a random vote
   for (i = 0; i < voters; i++) {
      int candidate_idx = rand() % candidates;
      votes[candidate_idx]++;
      printf("Voter %d has cast their vote for %s.\n", i+1, candidate_names[candidate_idx]);
   }

   // print out the results
   printf("\nELECTION RESULTS:\n");
   for (i = 0; i < candidates; i++) {
      printf("%s: %d votes\n", candidate_names[i], votes[i]);
   }

   // determine the winning candidate
   int max_votes = votes[0];
   int winner_idx = 0;
   for (i = 1; i < candidates; i++) {
      if (votes[i] > max_votes) {
         max_votes = votes[i];
         winner_idx = i;
      } else if (votes[i] == max_votes) {
         printf("There is a tie between %s and %s.\n", candidate_names[winner_idx], candidate_names[i]);
      }
   }

   printf("\nThe winner of the election is %s with %d votes!\n", candidate_names[winner_idx], max_votes);

   return 0;
}