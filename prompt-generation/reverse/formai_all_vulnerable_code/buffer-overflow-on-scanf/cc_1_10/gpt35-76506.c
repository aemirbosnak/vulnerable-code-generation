//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Define the maximum number of candidates */
#define MAX_CANDIDATES 10

/* Define the maximum number of voters */
#define MAX_VOTERS 100

/* Define the maximum length of a candidate name */
#define MAX_NAME_LENGTH 20

/* Define the structure for a candidate*/
typedef struct Candidate {
    int id;
    char name[MAX_NAME_LENGTH];
    int vote_count;
} Candidate;

/* Declare Global Variables */
Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;
int num_voters = 0;

/* Declare Functions */
void add_candidate();
void display_candidates();
void vote();

/* Main Function */
int main() {
    /* Declare Variables */
    int choice;
    
    /* Display Menu and Options */
    printf("---Welcome to the Electronic Voting System---\n");
    printf("Please choose an option below:\n");
    printf("1. Add Candidate\n2. Display Candidates\n3. Vote\n4. Quit\n\n");
    printf("Enter your choice: ");
    
    /* Get User's Choice */
    scanf("%d", &choice);
    
    /* Process User's Choice */
    switch(choice) {
        case 1:
            add_candidate();
            break;
        case 2:
            display_candidates();
            break;
        case 3:
            vote();
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please choose again.\n");
    }
    
    /* Return 0 to indicate normal termination */
    return 0;
}

/* Function to Add Candidate */
void add_candidate() {
    /* Check if Max Candidates Already */
    if(num_candidates >= MAX_CANDIDATES) {
        printf("Maximum candidates already added!\n");
        return;
    }
    
    /* Get Candidate Name */
    char name[MAX_NAME_LENGTH];
    printf("Enter the candidate's name: ");
    scanf("%s", name);

    /* Add Candidate */
    Candidate c;
    c.id = num_candidates+1;
    strncpy(c.name, name, MAX_NAME_LENGTH);
    c.vote_count = 0;
    candidates[num_candidates] = c;
    num_candidates++;
    
    printf("Candidate successfully added!\n");
}

/* Function to Display Candidates */
void display_candidates() {
    /* Check if Any Candidates */
    if(num_candidates == 0) {
        printf("No candidates added yet!\n");
        return;
    }
    
    /* Display Candidates */
    printf("Candidates List:\n");
    printf("%-4s%-20s%-5s\n", "ID", "Name", "Votes");
    for(int i=0; i<num_candidates; i++) {
        printf("%-4d%-20s%-5d\n", candidates[i].id, candidates[i].name, candidates[i].vote_count);
    }
}

/* Function to Vote */
void vote() {
    /* Check if Any Candidates */
    if(num_candidates == 0) {
        printf("No candidates added yet!\n");
        return;
    }
    
    /* Check if Max Voters Reached */
    if(num_voters >= MAX_VOTERS) {
        printf("Maximum voters already voted!\n");
        return;
    }
    
    /* Get Voter's Choice */
    int choice;
    printf("Please choose a candidate ID to vote: ");
    scanf("%d", &choice);
    
    /* Validate Candidate */
    int candidate_index = -1;
    for(int i=0; i<num_candidates; i++) {
        if(candidates[i].id == choice) {
            candidate_index = i;
            break;
        }
    }
    
    /* Check Valid Candidate */
    if(candidate_index == -1) {
        printf("Invalid candidate ID! Please choose again.\n");
        return;
    }
    
    /* Increment Candidate's Vote Count */
    candidates[candidate_index].vote_count++;
    num_voters++;
    
    printf("Thank you for voting!\n");
}