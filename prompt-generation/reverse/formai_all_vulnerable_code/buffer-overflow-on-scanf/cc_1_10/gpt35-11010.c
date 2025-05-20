//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_CANDIDATES 20 //Maximum number of candidates
#define MAX_VOTERS 1000 //Maximum number of voters

struct candidate { //Candidate struct
    char name[50];
    int votes;
} candidates[MAX_CANDIDATES];

struct voter { //Voter struct
    char name[50];
    int voted;
} voters[MAX_VOTERS];

int num_candidates = 0;
int num_voters = 0;

void add_candidate() { //Function to add a candidate
    printf("\nEnter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void print_candidates() { //Function to print all candidates
    printf("\nCandidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("- %s\n", candidates[i].name);
    }
}

int vote(char *name) { //Function to perform the voting process
    int found = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            found = 1;
            candidates[i].votes++;
            break;
        }
    }
    return found;
}

void add_voter() { //Function to add a voter
    printf("\nEnter voter name: ");
    scanf("%s", voters[num_voters].name);
    voters[num_voters].voted = 0;
    num_voters++;
}

int find_voter(char *name) { //Function to find a voter
    int found = -1;
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(name, voters[i].name) == 0) {
            found = i;
            break;
        }
    }
    return found;
}

int main() {
    int choice;
    char name[50];

    printf("Welcome to the Electronic Voting System!\n");

    while (1) { //Main menu loop
        printf("\nMain Menu:\n");
        printf("1. Add Candidate\n");
        printf("2. Print Candidates\n");
        printf("3. Add Voter\n");
        printf("4. Vote\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) { //Switch statement for menu options
            case 1:
                add_candidate();
                break;
            case 2:
                print_candidates();
                break;
            case 3:
                add_voter();
                break;
            case 4:
                printf("\nEnter your name: ");
                scanf("%s", name);

                int index = find_voter(name);
                if (index == -1) { //Voter not found
                    printf("Sorry, you are not registered!\n");
                } else if (voters[index].voted == 1) { //Voter already voted
                    printf("Sorry, you already voted!\n");
                } else { //Voter eligible to vote
                    printf("Please enter the candidate name: ");
                    scanf("%s", name);

                    if (vote(name)) {
                        voters[index].voted = 1;
                        printf("Thanks for voting!\n");
                    } else { //Invalid candidate entered
                        printf("Sorry, invalid candidate name!\n");
                    }
                }
                break;
            case 5: //Exit program
                printf("\nGoodbye!\n");
                exit(0);
            default: //Invalid menu choice
                printf("\nInvalid choice, please try again!\n");
        }
    }

    return 0;
}