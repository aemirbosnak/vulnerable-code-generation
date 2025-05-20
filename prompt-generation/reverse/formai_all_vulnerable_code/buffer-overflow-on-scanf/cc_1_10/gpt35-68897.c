//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold the candidates information
struct candidate {
    int id;
    char name[50];
    int votes;
};

// List of candidates
struct candidate candidates[] = {
    {1, "John Doe", 0},
    {2, "Jane Smith", 0},
    {3, "Bob Johnson", 0},
    {4, "Sara Lee", 0}
};

// Function to display the list of candidates
void display_candidates() {
    printf("List of candidates:\n");
    for(int i=0; i<4; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
}

// Function to cast the vote by the voter
void cast_vote() {
    int selected_candidate;
    printf("Enter the id of candidate you want to vote for: ");
    scanf("%d", &selected_candidate);
    if(selected_candidate < 1 || selected_candidate > 4) {
        printf("Invalid candidate id. Please select a valid candidate.\n");
    } else {
        candidates[selected_candidate-1].votes++;
        printf("Your vote has been cast for %s\n", candidates[selected_candidate-1].name);
    }
}

// Function to count the votes and display the winner
void count_votes() {
    int max_votes = 0;
    int winner_count = 0;
    int winner_ids[4] = {0};
    for(int i=0; i<4; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_count = 1;
            winner_ids[0] = candidates[i].id;
        } else if(candidates[i].votes == max_votes) {
            winner_ids[winner_count] = candidates[i].id;
            winner_count++;
        }
    }
    printf("Total votes counted: %d\n", max_votes);
    if(winner_count == 1) {
        printf("The winner is %s with %d votes\n", candidates[winner_ids[0]-1].name, max_votes);
    } else {
        printf("There was a tie between %d candidates\n", winner_count);
        printf("The winners are: ");
        for(int i=0; i<winner_count; i++) {
            printf("%s ", candidates[winner_ids[i]-1].name);
        }
        printf("with %d votes each\n", max_votes);
    }
}

int main() {
    time_t t;
    srand((unsigned) time(&t)); // Seed the random number generator
    int choice;
    int passcode;
    int random_passcode = rand() % 9999 + 1000; // Generate a random passcode between 1000 and 9999
    printf("Welcome to the Electronic Voting System\n");
    printf("Please enter the passcode to access the system: ");
    scanf("%d", &passcode);
    if(passcode != random_passcode) {
        printf("Invalid passcode. You cannot access the system.\n");
        return 0;
    } else {
        printf("Passcode accepted.\n");
    }
    while(1) {
        printf("Choose an option:\n");
        printf("1. Display list of candidates\n");
        printf("2. Cast a vote\n");
        printf("3. Count the votes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_candidates();
                break;
            case 2:
                cast_vote();
                break;
            case 3:
                count_votes();
                break;
            case 4:
                printf("Exiting the system.\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}