//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[20];
    int vote;
    time_t timestamp;
} Voter;

int main() {
    // Create a list of voters
    Voter voters[MAX_VOTES];

    // Initialize the voters
    for (int i = 0; i < MAX_VOTES; i++) {
        voters[i].name[0] = '\0';
        voters[i].vote = -1;
        voters[i].timestamp = 0;
    }

    // Get the number of voters
    int num_voters = 0;

    // Get the voter's name and vote
    printf("Enter your name: ");
    scanf("%s", voters[num_voters].name);

    printf("Enter your vote (1-5): ");
    scanf("%d", &voters[num_voters].vote);

    // Increment the number of voters
    num_voters++;

    // Print the voter list
    for (int i = 0; i < num_voters; i++) {
        printf("%s voted for candidate %d at %ld\n", voters[i].name, voters[i].vote, voters[i].timestamp);
    }

    // Calculate the winner
    int winner = -1;
    int max_votes = 0;

    for (int i = 0; i < num_voters; i++) {
        if (voters[i].vote > max_votes) {
            max_votes = voters[i].vote;
            winner = i;
        }
    }

    // Print the winner
    if (winner != -1) {
        printf("The winner is: %s\n", voters[winner].name);
    } else {
        printf("No winner\n");
    }

    return 0;
}