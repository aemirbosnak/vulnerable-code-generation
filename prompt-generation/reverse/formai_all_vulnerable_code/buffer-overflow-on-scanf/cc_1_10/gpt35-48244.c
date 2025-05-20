//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

struct candidate{
    int id;
    char name[50];
    int vote_count;
};

struct voter{
    int id;
    int vote;
};

struct candidate candidates[MAX_CANDIDATES];
struct voter voters[MAX_VOTERS];

int num_candidates = 0, num_voters = 0;

void add_candidate(){
    if(num_candidates == MAX_CANDIDATES){
        printf("\nMaximum number of candidates already added.");
        return;
    }

    printf("\nEnter candidate name: ");
    scanf(" %[^\n]", candidates[num_candidates].name);

    candidates[num_candidates].id = num_candidates+1;
    candidates[num_candidates].vote_count = 0;

    num_candidates++;

    printf("\nCandidate added successfully.\n\n");
}

void list_candidates(){
    printf("\nList of candidates: \n\n");

    for(int i=0; i<num_candidates; i++){
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }

    printf("\n");
}

void add_voter(){
    if(num_voters == MAX_VOTERS){
        printf("\nMaximum number of voters already added.");
        return;
    }

    printf("\nEnter voter ID: ");
    scanf("%d", &voters[num_voters].id);

    if(voters[num_voters].id < 1 || voters[num_voters].id > MAX_VOTERS){
        printf("\nInvalid voter ID. Try again.\n\n");
        return;
    }

    printf("\nList of candidates: \n\n");

    for(int i=0; i<num_candidates; i++){
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }

    printf("\n");

    printf("Enter candidate ID to vote for: ");
    scanf("%d", &voters[num_voters].vote);

    if(voters[num_voters].vote < 1 || voters[num_voters].vote > MAX_CANDIDATES){
        printf("\nInvalid candidate ID. Try again.\n\n");
        return;
    }

    candidates[voters[num_voters].vote-1].vote_count++;

    num_voters++;

    printf("\nVote casted successfully.\n\n");
}

void view_result(){
    printf("\nResult of the election: \n\n");

    for(int i=0; i<num_candidates; i++){
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }

    printf("\n");
}

int main(){
    int choice;

    printf("Welcome to Electronic Voting System.\n");

    while(1){
        printf("Choose an option: \n");
        printf("1. Add candidate\n");
        printf("2. List candidates\n");
        printf("3. Add voter\n");
        printf("4. View result\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_candidate();
                break;

            case 2:
                list_candidates();
                break;

            case 3:
                add_voter();
                break;

            case 4:
                view_result();
                break;

            case 5:
                printf("\nThank you for using Electronic Voting System.\n\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Try again.\n\n");
        }
    }

    return 0;
}