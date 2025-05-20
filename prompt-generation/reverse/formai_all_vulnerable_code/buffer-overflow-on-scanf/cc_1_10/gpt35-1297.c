//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>

// Defining the global variables for the program
int candidate1_votes = 0;
int candidate2_votes = 0;
int candidate3_votes = 0;
int total_votes = 0;

// Defining the functions for the program
void display_menu() {
    printf("Welcome to the Electronic Voting System\n");
    printf("Please select your preferred candidate:\n\n");
    printf("1. Candidate 1\n");
    printf("2. Candidate 2\n");
    printf("3. Candidate 3\n");
}

void cast_vote(int candidate) {
    switch(candidate) {
        case 1:
            candidate1_votes++;
            printf("You have voted for Candidate 1\n");
            break;
        case 2:
            candidate2_votes++;
            printf("You have voted for Candidate 2\n");
            break;
        case 3:
            candidate3_votes++;
            printf("You have voted for Candidate 3\n");
            break;
        default:
            printf("Invalid choice. Please select a valid candidate.\n");
    }
    total_votes++;
}

void display_results() {
    printf("Total votes casted: %d\n", total_votes);
    printf("Candidate 1 votes: %d\n", candidate1_votes);
    printf("Candidate 2 votes: %d\n", candidate2_votes);
    printf("Candidate 3 votes: %d\n", candidate3_votes);
    if(candidate1_votes > candidate2_votes && candidate1_votes > candidate3_votes) {
        printf("Candidate 1 wins!\n");
    } else if(candidate2_votes > candidate1_votes && candidate2_votes > candidate3_votes) {
        printf("Candidate 2 wins!\n");
    } else if(candidate3_votes > candidate1_votes && candidate3_votes > candidate2_votes) {
        printf("Candidate 3 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    char choice;
    do {
        display_menu();
        scanf(" %c", &choice);
        switch(choice) {
            case '1': 
            case '2': 
            case '3':
                cast_vote(choice - '0');
                break;
            case 'R':
            case 'r':
                display_results();
                break;
            case 'Q':
            case 'q':
                printf("Thank you for using the Electronic Voting System\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while(true);
}