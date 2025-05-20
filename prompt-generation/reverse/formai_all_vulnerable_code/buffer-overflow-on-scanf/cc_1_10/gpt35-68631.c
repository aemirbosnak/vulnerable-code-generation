//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold candidate information
struct Candidate {
   char name[30];
   int votes;
};

// Structure to hold voter information
struct Voter {
   int id;
   int has_voted;
};

// Initialize candidates with zero votes
void initialize_candidates(struct Candidate candidates[], int num_candidates) {
   for(int i=0; i<num_candidates; i++) {
      candidates[i].votes = 0;
   }
}

// Initialize voters with no votes cast
void initialize_voters(struct Voter voters[], int num_voters) {
   for(int i=0; i<num_voters; i++) {
      voters[i].has_voted = 0;
   }
}

// Get voter ID input from user
int get_voter_id() {
   int id;
   printf("Enter voter ID: ");
   scanf("%d", &id);
   return id;
}

// Check if a voter with the given ID is eligible to vote
int is_eligible_voter(struct Voter voters[], int num_voters, int voter_id) {
   for(int i=0; i<num_voters; i++) {
      if(voters[i].id == voter_id) {
         if(voters[i].has_voted == 1) {
            printf("Error: Voter already voted\n");
            return 0;
         }
         else {
            voters[i].has_voted = 1;
            return 1;
         }
      }
   }
   printf("Error: Voter not found\n");
   return 0;
}

// Get candidate vote input from user
int get_candidate_vote() {
   int vote;
   printf("Enter candidate vote: ");
   scanf("%d", &vote);
   return vote;
}

// Conduct the election
void conduct_election(struct Candidate candidates[], int num_candidates, struct Voter voters[], int num_voters) {
   printf("Starting election\n");
   while(1) {
      int voter_id = get_voter_id();
      int candidate_vote = get_candidate_vote();

      if(is_eligible_voter(voters, num_voters, voter_id)) {
         if(candidate_vote < 1 || candidate_vote > num_candidates) {
            printf("Error: Invalid candidate number\n");
         }
         else {
            candidates[candidate_vote - 1].votes++;
            printf("Vote for candidate %d recorded\n", candidate_vote);
         }
      }

      int all_voted = 1;
      for(int i=0; i<num_voters; i++) {
         if(voters[i].has_voted == 0) {
            all_voted = 0;
            break;
         }
      }

      if(all_voted) {
         printf("All voters have voted\n");
         break;
      }
   }
}

// Print final election results
void print_results(struct Candidate candidates[], int num_candidates) {
   printf("Election results:\n");
   for(int i=0; i<num_candidates; i++) {
      printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
   }
}

// Main function
int main() {
   int num_candidates = 3;
   int num_voters = 5;

   struct Candidate candidates[num_candidates];
   strcpy(candidates[0].name, "Candidate A");
   strcpy(candidates[1].name, "Candidate B");
   strcpy(candidates[2].name, "Candidate C");

   struct Voter voters[num_voters];
   voters[0].id = 1001;
   voters[1].id = 1002;
   voters[2].id = 1003;
   voters[3].id = 1004;
   voters[4].id = 1005;

   initialize_candidates(candidates, num_candidates);
   initialize_voters(voters, num_voters);

   conduct_election(candidates, num_candidates, voters, num_voters);
   print_results(candidates, num_candidates);

   return 0;
}