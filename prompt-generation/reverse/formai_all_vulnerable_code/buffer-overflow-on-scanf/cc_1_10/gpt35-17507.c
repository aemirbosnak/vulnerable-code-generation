//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

// Structure to hold candidate details
typedef struct candidate{
    char name[30];
    int votes;
} candidate;

// Function to display menu and get choice from user
int get_choice(){
    int choice;
    printf("\n-----------------------\n");
    printf("1. Add Candidate\n");
    printf("2. Remove Candidate\n");
    printf("3. Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a candidate
void add_candidate(candidate* candidates, int* num_candidates){
    char name[30];
    printf("Enter the name of the candidate: ");
    scanf("%s", name);
    candidates[*num_candidates].votes = 0;
    strcpy(candidates[*num_candidates].name, name);
    (*num_candidates)++;
}

// Function to remove a candidate
void remove_candidate(candidate* candidates, int* num_candidates){
    int i;
    char name[30];
    printf("Enter the name of the candidate to be removed: ");
    scanf("%s", name);
    for(i=0;i<*num_candidates;i++){
        if(strcmp(candidates[i].name, name)==0){
            int j;
            for(j=i;j<(*num_candidates)-1;j++){
                candidates[j] = candidates[j+1];
            }
            (*num_candidates)--;
            printf("%s has been removed from the candidates.\n", name);
            return;
        }
    }
    printf("No candidate with the given name exists.\n");
}

// Function to cast a vote
void cast_vote(candidate* candidates, int num_candidates){
    int i;
    char name[30];
    printf("Enter the name of the candidate to vote: ");
    scanf("%s", name);
    for(i=0;i<num_candidates;i++){
        if(strcmp(candidates[i].name, name)==0){
            candidates[i].votes++;
            printf("Your vote has been registered for %s.\n", name);
            return;
        }
    }
    printf("No candidate with the given name exists.\n");
}

// Function to display the results
void display_results(candidate* candidates, int num_candidates){
    int i;
    printf("Candidate\t\tVotes\n");
    for(i=0;i<num_candidates;i++){
        printf("%s\t\t\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main(){
    candidate candidates[10];
    int num_candidates = 0;
    int choice = get_choice();
    while(choice!=5){
        switch(choice){
            case 1: add_candidate(candidates, &num_candidates); break;
            case 2: remove_candidate(candidates, &num_candidates); break;
            case 3: cast_vote(candidates, num_candidates); break;
            case 4: display_results(candidates, num_candidates); break;
            default: printf("Invalid choice.\n");
        }
        choice = get_choice();
    }
    return 0;
}