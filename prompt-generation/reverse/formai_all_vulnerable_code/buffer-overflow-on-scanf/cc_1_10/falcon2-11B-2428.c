//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
} Candidate;

int main() {
    // Initialize an array of candidate structs
    Candidate candidates[3];
    
    // Set up the candidate structs
    candidates[0].id = 1;
    strcpy(candidates[0].name, "Candidate A");
    candidates[1].id = 2;
    strcpy(candidates[1].name, "Candidate B");
    candidates[2].id = 3;
    strcpy(candidates[2].name, "Candidate C");
    
    // Print out the candidate names
    printf("Candidate A: %s\n", candidates[0].name);
    printf("Candidate B: %s\n", candidates[1].name);
    printf("Candidate C: %s\n", candidates[2].name);
    
    // Ask the user to vote for a candidate
    int choice;
    printf("Choose a candidate to vote for:\n");
    printf("1: Candidate A\n");
    printf("2: Candidate B\n");
    printf("3: Candidate C\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    // Check if the user's choice is valid
    if (choice < 1 || choice > 3) {
        printf("Invalid choice. Please try again.\n");
        return 1;
    }
    
    // Update the candidate's vote count
    candidates[choice - 1].id += 1;
    printf("Candidate %d has received a vote.\n", candidates[choice - 1].id);
    
    // Print out the updated vote counts
    for (int i = 0; i < 3; i++) {
        printf("Candidate %d: %d\n", i + 1, candidates[i].id);
    }
    
    // Exit the program
    return 0;
}