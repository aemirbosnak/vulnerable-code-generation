//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_CANDIDATES 4
#define NUM_VOTERS 20

/* candidate struct */
typedef struct {
    char name[20];
    int votes;
} candidate;

/* voter struct */
typedef struct {
    int id;
    bool voted;
} voter;

/* function to print candidate names */
void print_candidates(candidate candidates[]) {
    for(int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

/* function to print current votes for each candidate */
void print_vote_count(candidate candidates[]) {
    for(int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    /* initialize candidates */
    candidate candidates[NUM_CANDIDATES];
    strcpy(candidates[0].name, "John Smith");
    strcpy(candidates[1].name, "Jane Doe");
    strcpy(candidates[2].name, "Bob Johnson");
    strcpy(candidates[3].name, "Mary Lee");
    
    /* initialize voters */
    voter voters[NUM_VOTERS];
    for(int i = 0; i < NUM_VOTERS; i++) {
        voters[i].id = i+1;
        voters[i].voted = false;
    }
    
    /* print instructions */
    printf("Welcome to the Retro Electronic Voting System!\n");
    printf("Please select a candidate by entering their number:\n");
    print_candidates(candidates);
    printf("Press 0 to exit.\n");
    
    /* start voting */
    int candidate_selection;
    while(true) {
        /* get input */
        printf("\nEnter your selection: ");
        scanf("%d", &candidate_selection);
        
        /* exit if 0 is selected */
        if(candidate_selection == 0) {
            printf("\nThank you for voting!\n");
            break;
        }
        
        /* error handling for invalid input */
        if(candidate_selection < 1 || candidate_selection > NUM_CANDIDATES) {
            printf("\nInvalid selection. Please try again.\n");
            continue;
        }
        
        /* increment candidate's vote count and mark voter as voted */
        candidates[candidate_selection-1].votes++;
        voters[rand() % NUM_VOTERS].voted = true;
        
        /* print current vote count */
        printf("\nCurrent vote count:\n");
        print_vote_count(candidates);
        
        /* check if all voters have voted */
        bool all_voted = true;
        for(int i = 0; i < NUM_VOTERS; i++) {
            if(voters[i].voted == false) {
                all_voted = false;
                break;
            }
        }
        
        /* if all voters have voted, end voting */
        if(all_voted == true) {
            printf("\nAll voters have voted. Thank you for voting!\n");
            break;
        }
    }
    
    return 0;
}