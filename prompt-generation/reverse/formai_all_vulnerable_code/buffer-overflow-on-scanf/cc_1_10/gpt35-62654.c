//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
char voters[MAX_VOTERS][50];
int num_candidates = 0;
int num_voters = 0;

// function declarations
void add_candidate(char *name);
void add_voter(char *name);
void cast_vote(char *voter, char *name);
int verify_voter(char *name);

int main() {
    int choice;
    char name[50], candidate[50], voter[50];

    printf("*** Welcome to the Paranoid Electoral Commission Electronic Voting System ***\n\n");
    while (1) {
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. Cast vote\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter candidate name: ");
                scanf("%s", name);
                add_candidate(name);
                break;
            case 2:
                printf("\nEnter voter name: ");
                scanf("%s", name);
                add_voter(name);
                break;
            case 3:
                printf("\nEnter voter name: ");
                scanf("%s", voter);
                if (verify_voter(voter)) {
                    printf("Enter candidate name: ");
                    scanf("%s", candidate);
                    cast_vote(voter, candidate);
                } else {
                    printf("Your name does not appear in the voter list. You are not allowed to cast your vote!\n");
                }
                break;
            case 4:
                printf("\nThank you for using the Paranoid Electoral Commission Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// function to add a candidate to the list
void add_candidate(char *name) {
    if (num_candidates == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached. Cannot add any more candidates!\n");
        return;
    }
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            printf("Candidate with the same name already exists. Cannot add.\n");
            return;
        }
    }
    Candidate c;
    strcpy(c.name, name);
    c.votes = 0;
    candidates[num_candidates++] = c;
    printf("Candidate added successfully.\n");
}

// function to add a voter to the list
void add_voter(char *name) {
    if (num_voters == MAX_VOTERS) {
        printf("Maximum number of voters reached. Cannot add any more voters!\n");
        return;
    }
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(name, voters[i]) == 0) {
            printf("Voter with the same name already exists. Cannot add.\n");
            return;
        }
    }
    strcpy(voters[num_voters++], name);
    printf("Voter added successfully.\n");
}

// function to cast a vote
void cast_vote(char *voter, char *name) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            candidates[i].votes++;
            printf("Vote cast successfully.\n");
            return;
        }
    }
    printf("Candidate with the given name does not exist. Please try again.\n");
}

// function to verify a voter
int verify_voter(char *name) {
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(name, voters[i]) == 0) {
            return 1;
        }
    }
    return 0;
}