//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Sherlock Holmes
#include <stdio.h>

#define VOTE_SUCCESS 0
#define VOTE_FAILURE 1

// Function to get user input
void get_input(char* input) {
    printf("Enter your choice: ");
    scanf("%s", input);
}

// Function to validate user input
int validate_input(char* input) {
    if (strcmp(input, "yes") == 0 || strcmp(input, "no") == 0) {
        return VOTE_SUCCESS;
    } else {
        return VOTE_FAILURE;
    }
}

// Function to count votes
int count_votes(int* votes, int num_candidates) {
    int i = 0;
    for (i = 0; i < num_candidates; i++) {
        if (votes[i] > 0) {
            printf("Candidate %d wins with %d votes!\n", i + 1, votes[i]);
            return i + 1;
        }
    }
    printf("No candidate received a majority of votes.\n");
    return -1;
}

// Main function
int main() {
    int num_candidates;
    char input[10];
    int votes[10] = {0};
    int i = 0;

    // Get number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Get candidate names
    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate name %d: ", i + 1);
        scanf("%s", input);
        printf("Candidate %s added to ballot.\n", input);
    }

    // Start voting
    printf("\nVoting has begun!\n");
    while (1) {
        printf("\nPlease select a candidate by entering their number:\n");
        for (i = 0; i < num_candidates; i++) {
            printf("%d. %s\n", i + 1, input[i]);
        }
        get_input(input);
        int candidate_num = atoi(input) - 1;
        if (candidate_num < 0 || candidate_num >= num_candidates) {
            printf("Invalid candidate number. Please try again.\n");
            continue;
        }
        int vote_result = validate_input(input);
        if (vote_result == VOTE_SUCCESS) {
            votes[candidate_num]++;
            printf("Your vote has been counted!\n");
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Count votes and determine winner
    count_votes(votes, num_candidates);

    return 0;
}