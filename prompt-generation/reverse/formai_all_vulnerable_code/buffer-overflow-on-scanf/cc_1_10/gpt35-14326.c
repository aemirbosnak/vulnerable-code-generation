//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define NUM_CANDIDATES 4
#define NUM_VOTERS 10

struct candidate{
char name[40];
int vote_count;
};

bool voter_has_voted[NUM_VOTERS] = {false};

struct candidate candidates[NUM_CANDIDATES] = {
    {"Candidate A", 0},
    {"Candidate B", 0},
    {"Candidate C", 0},
    {"Candidate D", 0}
};

void print_candidates(){
    printf("=== List of Candidates ===\n\n");
    for(int i=0; i<NUM_CANDIDATES; i++){
        printf("%s\n", candidates[i].name);
    }
    printf("\n");
}

void print_results(){
    printf("=== Election Results ===\n\n");
    for(int i=0; i<NUM_CANDIDATES; i++){
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
    printf("\n");
}

bool vote(int voter_id, int candidate_id){
    if(voter_id < 0 || voter_id >= NUM_VOTERS){
        printf("Error: Invalid voter ID.\n");
        return false;
    }
    if(voter_has_voted[voter_id]){
        printf("Error: This voter has already voted.\n");
        return false;
    }
    if(candidate_id < 0 || candidate_id >= NUM_CANDIDATES){
        printf("Error: Invalid candidate ID.\n");
        return false;
    }
    candidates[candidate_id].vote_count++;
    voter_has_voted[voter_id] = true;
    printf("Success: Voter %d has voted for %s.\n", voter_id, candidates[candidate_id].name);
    return true;
}

void reset(){
    for(int i=0; i<NUM_CANDIDATES; i++){
        candidates[i].vote_count = 0;
    }
    for(int i=0; i<NUM_VOTERS; i++){
        voter_has_voted[i] = false;
    }
    printf("Success: Election data has been reset.\n");
}

int main(){
    printf("Welcome to the Electronic Voting System!\n");
    reset();
    while(true){
        printf("Please select an operation:\n");
        printf("1. Display list of candidates\n");
        printf("2. Vote for a candidate\n");
        printf("3. Display election results\n");
        printf("4. Reset election data\n");
        printf("5. Exit\n");
        int choice = 0;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                print_candidates();
                break;
            case 2:
                printf("Enter voter ID: ");
                int voter_id = 0;
                scanf("%d", &voter_id);
                printf("Enter candidate ID: ");
                int candidate_id = 0;
                scanf("%d", &candidate_id);
                vote(voter_id, candidate_id);
                break;
            case 3:
                print_results();
                break;
            case 4:
                reset();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
                break;
        }
    }
    return 0;
}