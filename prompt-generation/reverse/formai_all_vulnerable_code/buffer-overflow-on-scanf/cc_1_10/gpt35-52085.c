//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct candidate {
    char name[20];
    int votes;
};

struct voter {
    char name[20];
    int has_voted;
    int candidate_id;
};

struct candidate candidates[MAX_CANDIDATES];
struct voter voters[MAX_VOTERS];

int num_candidates = 0;
int num_voters = 0;

void add_candidate(char name[]) {
    struct candidate c;
    strcpy(c.name, name);
    c.votes = 0;
    candidates[num_candidates] = c;
    num_candidates++;
}

void add_voter(char name[]) {
    struct voter v;
    strcpy(v.name, name);
    v.has_voted = 0;
    v.candidate_id = -1;
    voters[num_voters] = v;
    num_voters++;
}

void print_candidates() {
    int i;
    printf("Candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%d. %s (%d votes)\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int i;
    char name[20];
    int choice;
    
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the names of the candidates (up to %d): (type 'done' when finished)\n", MAX_CANDIDATES);
    while (1) {
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        add_candidate(name);
    }
    
    printf("Please enter the names of the voters (up to %d): (type 'done' when finished)\n", MAX_VOTERS);
    while (1) {
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        add_voter(name);
    }
    
    while (1) {
        printf("Menu:\n");
        printf("1. Vote\n");
        printf("2. Print Results\n");
        printf("3. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Please enter your name: ");
                scanf("%s", name);
                
                for (i = 0; i < num_voters; i++) {
                    if (strcmp(voters[i].name, name) == 0) {
                        if (voters[i].has_voted == 0) {
                            printf("Please choose a candidate:\n");
                            print_candidates();
                            printf("Enter candidate number: ");
                            scanf("%d", &(voters[i].candidate_id));
                            if (voters[i].candidate_id >= 1 && voters[i].candidate_id <= num_candidates) {
                                candidates[voters[i].candidate_id-1].votes++;
                                voters[i].has_voted = 1;
                                printf("Thank you for voting!\n");
                            } else {
                                printf("Invalid candidate number!\n");
                            }
                        } else {
                            printf("You have already voted!\n");
                        }
                        break;
                    }
                }
                
                if (i == num_voters) {
                    printf("You are not a registered voter!\n");
                }
                
                break;
            case 2:
                print_candidates();
                break;
            case 3:
                printf("Thank you for using the Electronic Voting System!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}