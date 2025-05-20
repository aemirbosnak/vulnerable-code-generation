//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5

typedef struct Voter {
    char name[20];
    int vote_choice;
    time_t vote_time;
} Voter;

int main()
{
    // Create an array of voters
    Voter voters[100];

    // Initialize the voters
    for (int i = 0; i < 100; i++)
    {
        voters[i].name[0] = '\0';
        voters[i].vote_choice = -1;
        voters[i].vote_time = 0;
    }

    // Get the number of voters
    int num_voters = 0;

    // Get the voter's name and vote choice
    printf("Enter your name: ");
    scanf("%s", voters[num_voters].name);

    printf("Select your vote choice (1-5): ");
    scanf("%d", &voters[num_voters].vote_choice);

    // Record the voter's vote time
    voters[num_voters].vote_time = time(NULL);

    // Increment the number of voters
    num_voters++;

    // Print the voter list
    for (int i = 0; i < num_voters; i++)
    {
        printf("%s voted for candidate %d at %s\n", voters[i].name, voters[i].vote_choice, voters[i].vote_time);
    }

    return 0;
}