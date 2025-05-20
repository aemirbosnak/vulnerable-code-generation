//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for voter details
struct Voter {
    char name[50];
    int age;
    char address[100];
    char vote[50];
};

// Declare global variables
struct Voter voters[100];
int num_voters = 0;

// Declare function to add voter
void add_voter() {
    struct Voter new_voter;
    printf("\nEnter voter's name: ");
    gets(new_voter.name);
    printf("Enter voter's age: ");
    scanf("%d", &new_voter.age);
    printf("Enter voter's address: ");
    fflush(stdin);
    gets(new_voter.address);
    sprintf(new_voter.vote, "%s", "Not voted yet");
    voters[num_voters] = new_voter;
    num_voters++;
    printf("\nVoter added successfully!\n");
}

// Declare function to display all voters
void display_voters() {
    printf("\nList of voters:\n\n");
    for (int i = 0; i < num_voters; i++) {
        printf("Voter #%d:\n", i+1);
        printf("Name: %s\n", voters[i].name);
        printf("Age: %d\n", voters[i].age);
        printf("Address: %s\n", voters[i].address);
        printf("Vote: %s\n\n", voters[i].vote);
    }
}

// Declare function to get index of voter by name
int get_voter_index(char voter_name[50]) {
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, voter_name) == 0) {
            return i;
        }
    }
    return -1;
}

// Declare function to cast vote
void cast_vote() {
    char voter_name[50];
    int index;
    printf("\nEnter your name: ");
    fflush(stdin);
    gets(voter_name);
    index = get_voter_index(voter_name);
    if (index == -1) {
        printf("\nSorry, voter not found.\n");
    } else if (strcmp(voters[index].vote, "Not voted yet") != 0) {
        printf("\nSorry, you have already cast your vote.\n");
    } else {
        printf("\nEnter your vote: ");
        fflush(stdin);
        gets(voters[index].vote);
        printf("\nVote cast successfully!\n");
    }
}

// Declare function to display voting results
void display_results() {
    int num_candidates = 0;
    char candidates[50][50];
    int num_votes[50] = {0};
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].vote, "Not voted yet") != 0) {
            int candidate_found = 0;
            for (int j = 0; j < num_candidates; j++) {
                if (strcmp(candidates[j], voters[i].vote) == 0) {
                    num_votes[j]++;
                    candidate_found = 1;
                    break;
                }
            }
            if (!candidate_found) {
                sprintf(candidates[num_candidates], "%s", voters[i].vote);
                num_votes[num_candidates]++;
                num_candidates++;
            }
        }
    }
    if (num_candidates == 0) {
        printf("\nNo votes have been cast yet.\n");
    } else {
        printf("\nVoting Results:\n\n");
        for (int i = 0; i < num_candidates; i++) {
            printf("%s: %d vote(s)\n", candidates[i], num_votes[i]);
        }
        printf("\n");
    }
}

// Declare main function
int main() {
    int choice;
    while (1) {
        printf("=================================================================\n");
        printf("                    ELECTRONIC VOTING SYSTEM                       \n");
        printf("=================================================================\n");
        printf("1. Add voter\n");
        printf("2. Display all voters\n");
        printf("3. Cast vote\n");
        printf("4. Display voting results\n");
        printf("5. Exit\n");
        printf("\nEnter your choice [1-5]: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_voter();
                break;
            case 2:
                display_voters();
                break;
            case 3:
                cast_vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}