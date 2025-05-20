//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

//Candidate structure
struct Candidate {
    int id; //Candidate ID
    char name[30]; //Candidate name
    int votes; //Candidate vote count
};

//Voter structure
struct Voter {
    int id; //Voter ID
    char name[30]; //Voter name
    int voted; //Has voter already voted?
    int vote; //Voter vote
};

//Function to display the nominees
void display_nominees(struct Candidate candidates[], int num_candidates) {
    printf("\nNominees: \n");
    for(int i = 0; i < num_candidates; i++) {
        printf("%d) %s\n", candidates[i].id, candidates[i].name);
    }
}

//Function to display the voters
void display_voters(struct Voter voters[], int num_voters) {
    printf("\nVoters: \n");
    for(int i = 0; i < num_voters; i++) {
        if(voters[i].voted == 0) {
            printf("%d) %s\n", voters[i].id, voters[i].name);
        }
        else {
            printf("%d) %s (Already voted)\n", voters[i].id, voters[i].name);
        }
    }
}

//Function to cast vote
void cast_vote(struct Candidate candidates[], int num_candidates, struct Voter voters[], int num_voters, int voter_id, int candidate_id) {
    for(int i = 0; i < num_candidates; i++) {
        if(candidates[i].id == candidate_id) {
            candidates[i].votes++;
            break;
        }
    }
    for(int i = 0; i < num_voters; i++) {
        if(voters[i].id == voter_id) {
            voters[i].voted = 1;
            voters[i].vote = candidate_id;
            break;
        }
    }
    printf("\nVote casted successfully!\n");
}

//Function to generate unique IDs for candidates and voters
int generate_id(int used_ids[], int max_id) {
    int new_id = rand() % max_id + 1;
    while(used_ids[new_id] == 1) {
        new_id = rand() % max_id + 1;
    }
    used_ids[new_id] = 1;
    return new_id;
}

//Main function
int main() {
    //Seed random number generator
    srand(time(NULL));
    
    //Create candidates and voters array of structures
    struct Candidate candidates[MAX_CANDIDATES];
    struct Voter voters[MAX_VOTERS];
    
    //Initialize used IDs array to 0
    int used_ids[MAX_CANDIDATES + MAX_VOTERS + 1] = {0};
    
    //Prompt for number of candidates and voters
    int num_candidates, num_voters;
    printf("Enter number of nominees: ");
    scanf("%d", &num_candidates);
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);
    
    //Initialize candidates array
    for(int i = 0; i < num_candidates; i++) {
        candidates[i].id = generate_id(used_ids, MAX_CANDIDATES + MAX_VOTERS);
        printf("Enter name of nominee %d: ", candidates[i].id);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    
    //Initialize voters array
    for(int i = 0; i < num_voters; i++) {
        voters[i].id = generate_id(used_ids, MAX_CANDIDATES + MAX_VOTERS);
        printf("Enter name of voter %d: ", voters[i].id);
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
    }
    
    //Display nominees and voters
    display_nominees(candidates, num_candidates);
    display_voters(voters, num_voters);
    
    int voter_id, candidate_id;
    
    //Loop to cast votes until all voters have voted
    while(1) {
        printf("\nEnter ID of voter: ");
        scanf("%d", &voter_id);
        printf("Enter ID of candidate: ");
        scanf("%d", &candidate_id);
        for(int i = 0; i < num_voters; i++) {
            if(voters[i].id == voter_id) {
                if(voters[i].voted == 1) {
                    printf("\nVoter has already voted!\n");
                }
                else {
                    for(int j = 0; j < num_candidates; j++) {
                        if(candidates[j].id == candidate_id) {
                            cast_vote(candidates, num_candidates, voters, num_voters, voter_id, candidate_id);
                            display_nominees(candidates, num_candidates);
                            display_voters(voters, num_voters);
                            break;
                        }
                        else if(j == num_candidates - 1) {
                            printf("\nInvalid candidate ID! Try again.\n");
                        }
                    }
                }
                break;
            }
            else if(i == num_voters - 1) {
                printf("\nInvalid voter ID! Try again.\n");
            }
        }
        int all_voters_voted = 1;
        for(int i = 0; i < num_voters; i++) {
            if(voters[i].voted == 0) {
                all_voters_voted = 0;
                break;
            }
        }
        if(all_voters_voted == 1) {
            printf("\nAll voters have voted. Election over!\n");
            break;
        }
    }
    
    //Display final results
    printf("\nFinal Results: \n");
    for(int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    
    return 0;
}