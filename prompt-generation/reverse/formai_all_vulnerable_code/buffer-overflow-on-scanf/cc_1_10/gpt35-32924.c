//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_NAME_LENGTH 20

typedef struct candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate;

typedef struct voter {
    char name[MAX_NAME_LENGTH];
    int has_voted;
    int vote;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];

int num_candidates = 0;
int num_voters = 0;

void print_candidates() {
    printf("Available candidates:\n");
    for(int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void print_voters() {
    printf("Voters who have not voted yet:\n");
    for(int i = 0; i < num_voters; i++) {
        if(voters[i].has_voted == 0) {
            printf("%d. %s\n", i+1, voters[i].name);
        }
    }
}

int authenticate_voter(char *voter_name) {
    for(int i = 0; i < num_voters; i++) {
        if(strcmp(voters[i].name, voter_name) == 0) {
            if(voters[i].has_voted == 0) {
                printf("Authentication successful.\n");
                return i;
            } else {
                printf("You have already voted.\n");
                return -1;
            }
        }
    }
    printf("Your name is not on the voter list.\n");
    return -1;
}

void vote(char *voter_name) {
    int voter_index = authenticate_voter(voter_name);
    if(voter_index != -1) {
        printf("Enter the number of the candidate you want to vote for:\n");
        print_candidates();
        int candidate_num;
        scanf("%d", &candidate_num);
        if(candidate_num < 1 || candidate_num > num_candidates) {
            printf("Invalid candidate number.\n");
        } else {
            candidates[candidate_num-1].votes++;
            voters[voter_index].vote = candidate_num;
            voters[voter_index].has_voted = 1;
            printf("Thank you for voting.\n");
        }
    }
}

void print_results() {
    printf("Election results:\n");
    for(int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    printf("Welcome to the Electronic Voting System.\n");
    printf("Enter the number of candidates:\n");
    scanf("%d", &num_candidates);
    for(int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d:\n", i+1);
        scanf("%s", candidates[i].name);
    }
    printf("Enter the number of voters:\n");
    scanf("%d", &num_voters);
    for(int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d:\n", i+1);
        scanf("%s", voters[i].name);
        voters[i].has_voted = 0;
        voters[i].vote = -1;
    }
    while(1) {
        printf("What would you like to do?\n");
        printf("1. Authenticate voter\n");
        printf("2. Vote\n");
        printf("3. Print results\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                char voter_name[MAX_NAME_LENGTH];
                printf("Enter your name:\n");
                scanf("%s", voter_name);
                authenticate_voter(voter_name);
                break;
            }
            case 2: {
                char voter_name[MAX_NAME_LENGTH];
                printf("Enter your name:\n");
                scanf("%s", voter_name);
                vote(voter_name);
                break;
            }
            case 3: {
                print_results();
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
    return 0;
}