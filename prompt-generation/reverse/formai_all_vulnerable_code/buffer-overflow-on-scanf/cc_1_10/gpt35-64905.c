//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct candidate{
    char name[50];
    int num_votes;
}candidates[5];

void reset_votes(){
    for(int i=0; i<5; i++){
        candidates[i].num_votes = 0;
    }
}

void print_candidates(){
    printf("\n\t\t\t\tCANDIDATES\n\n");
    for(int i=0; i<5; i++){
        printf("\t\t\t\t%s\n", candidates[i].name);
    }
}

void print_results(){
    printf("\n\n\t\t\t\tELECTION RESULTS\n\n");
    for(int i=0; i<5; i++){
        printf("\t\t\t\t%s: %d votes\n", candidates[i].name, candidates[i].num_votes);
    }
}

int main(){
    srand(time(0));
    for(int i=0; i<5; i++){
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
    }
    
    bool election_active = true;
    while(election_active){
        int voter_choice = rand() % 5; //randomly selects a candidate
        candidates[voter_choice].num_votes++;
        
        char continue_election;
        printf("Vote casted for %s. Continue election? (y/n): ", candidates[voter_choice].name);
        scanf(" %c", &continue_election); //trick to ignore whitespace
        
        if(continue_election == 'n'){
            election_active = false;
            print_results();
            break;
        }
    }
    return 0;
}