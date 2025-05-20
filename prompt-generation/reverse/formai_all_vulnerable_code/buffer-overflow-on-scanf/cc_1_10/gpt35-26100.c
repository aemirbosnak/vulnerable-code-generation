//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_CANDIDATE 10
#define MAX_VOTERS 1000

// Structure for each candidate
struct Candidate{
    int ID;
    char name[20];
    int vote_count;
};

// Global variables
int num_candidates = 0; // number of candidates
int num_voters = 0; // number of voters
int votes[MAX_VOTERS]; // Array to hold the vote choices
struct Candidate candidate_list[MAX_CANDIDATE]; // Array of candidates

// Function prototypes
void print_menu();
int get_choice();
void add_candidate();
void view_candidates();
void cast_vote();
void view_results();

// Main function
int main(){
    printf("\n*** Electronic Voting System ***\n");
    int choice;
    while(1){
        print_menu();
        choice = get_choice();
        
        switch(choice){
            case 1:
                add_candidate();
                break;
            case 2:
                view_candidates();
                break;
            case 3:
                cast_vote();
                break;
            case 4:
                view_results();
                break;
            case 5:
                printf("\nExiting the Electronic Voting System. Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;  
        }
    }
    return 0;
}

// Function to print the menu
void print_menu(){
    printf("\n---Menu---\n");
    printf("\n1. Add a Candidate");
    printf("\n2. View Candidates");
    printf("\n3. Cast Vote");
    printf("\n4. View Results");
    printf("\n5. Exit");
}

// Function to get the user choice
int get_choice(){
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    getchar(); // clearing the input buffer
    return choice;
}

// Function to add a candidate
void add_candidate(){
    if(num_candidates == MAX_CANDIDATE){
        printf("\nMaximum number of candidates reached. Cannot add more.\n");
        return;
    }
    printf("\nEnter candidate details:");
    printf("\nCandidate Name: ");
    fgets(candidate_list[num_candidates].name, 20, stdin);
    candidate_list[num_candidates].name[strcspn(candidate_list[num_candidates].name, "\n")] = 0; // removing the newline character
    
    candidate_list[num_candidates].ID = num_candidates + 1;
    candidate_list[num_candidates].vote_count = 0;
    
    num_candidates++;
    printf("\nCandidate added successfully!\n");
}

// Function to view the list of candidates
void view_candidates(){
    if(num_candidates == 0){
        printf("\nNo candidates added yet.\n");
        return;
    }
    printf("\n---List of Candidates---\n");
    for(int i=0; i<num_candidates; i++){
        printf("\nCandidate ID: %d", candidate_list[i].ID);
        printf("\nName: %s", candidate_list[i].name);
        printf("\nTotal Votes: %d\n", candidate_list[i].vote_count);
    }
}

// Function to cast a vote
void cast_vote(){
    if(num_candidates == 0){
        printf("\nNo candidates added yet.\n");
        return;
    }
    if(num_voters == MAX_VOTERS){
        printf("\nMaximum number of voters reached. Cannot cast more votes.\n");
        return;
    }
    int cand_choice;
    printf("\n---Voting---\n");
    printf("\nEnter Candidate ID to vote: ");
    scanf("%d", &cand_choice);
    getchar(); // clearing the input buffer
    
    // Validating candidate choice
    if(cand_choice<1 || cand_choice>num_candidates){
        printf("\nInvalid Candidate ID. Please try again.\n");
        return; 
    }
    
    // Registering the vote choice
    votes[num_voters] = cand_choice;
    num_voters++;
    candidate_list[cand_choice-1].vote_count++;
    
    printf("\nVote casted successfully!\n");
}

// Function to view the results
void view_results(){
    if(num_candidates == 0){
        printf("\nNo candidates added yet.\n");
        return;
    }
    if(num_voters == 0){
        printf("\nNo votes have been casted yet.\n");
        return;   
    }
    printf("\n---Voting Results---\n");
    for(int i=0; i<num_candidates; i++){
        printf("\nCandidate ID: %d", candidate_list[i].ID);
        printf("\nName: %s", candidate_list[i].name);
        printf("\nTotal Votes: %d\n", candidate_list[i].vote_count);
    }
}