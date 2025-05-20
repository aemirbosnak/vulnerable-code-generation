//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
/* 
This is an example program for an electronic voting system. 
For simplicity, we will simulate only one election with three candidates.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50 // maximum length of a candidate's name
#define NUM_CANDIDATES 3 // number of candidates in the election

// a struct to represent a candidate
typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate;

int main() {
    candidate candidates[NUM_CANDIDATES]; // an array of candidates
    int voterCount = 0; // number of voters who have cast their ballots
    
    // initialize the candidates' names and vote counts
    strcpy(candidates[0].name, "Alice");
    strcpy(candidates[1].name, "Bob");
    strcpy(candidates[2].name, "Charlie");
    candidates[0].votes = 0;
    candidates[1].votes = 0;
    candidates[2].votes = 0;
    
    printf("Welcome to the electronic voting system!\n");
    while (1) {
        printf("Enter your voter ID (or q to quit): ");
        char input[10];
        scanf("%9s", input); // read at most 9 characters
        
        if (strcmp(input, "q") == 0) {
            break; // user wants to quit
        }
        
        // for simplicity, assume any input other than "q" is a valid voter ID
        printf("You are logged in as voter %s.\n", input);
        
        // check if the voter has already cast their ballot
        if (voterCount < NUM_CANDIDATES) {
            // allow the voter to cast their ballot
            printf("Cast your vote for one of the following candidates:\n");
            for (int i = 0; i < NUM_CANDIDATES; i++) {
                printf("%d. %s\n", i+1, candidates[i].name);
            }
            printf("Enter your choice (1-%d): ", NUM_CANDIDATES);
            int choice;
            while (1) {
                scanf("%d", &choice);
                if (choice < 1 || choice > NUM_CANDIDATES) {
                    printf("Invalid choice. Enter a number between 1 and %d: ", NUM_CANDIDATES);
                } else {
                    break;
                }
            }
            candidates[choice-1].votes++; // record the vote
            voterCount++;
            printf("Thank you for casting your vote!\n");
        } else {
            // voter has already cast their ballot
            printf("You have already cast your ballot in this election.\n");
        }
    }
    
    // print the election results
    printf("Election Results:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    
    printf("Thank you for using the electronic voting system!\n");
    
    return 0;
}