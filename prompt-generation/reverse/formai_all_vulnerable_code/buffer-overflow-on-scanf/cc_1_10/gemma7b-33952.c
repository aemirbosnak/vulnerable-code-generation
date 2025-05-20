//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define BALLOT_SIZE 100

int main()
{
    system("clear");
    printf("Shock me with your vote!\n");

    // Create a ballot
    int ballot[BALLOT_SIZE] = {0};

    // Register candidates
    char candidate_names[NUM_CANDIDATES][20] = {"John Doe", "Jane Doe", "Peter Pan", "Captain America", "Iron Man"};

    // Get the current time
    time_t t = time(NULL);

    // Print the candidates
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        printf("%d. %s\n", i + 1, candidate_names[i]);
    }

    // Vote
    int vote = -1;
    printf("Enter your vote (1-5): ");
    scanf("%d", &vote);

    // Validate the vote
    if (vote < 1 || vote > NUM_CANDIDATES)
    {
        printf("Invalid vote!\n");
        return 1;
    }

    // Record the vote
    ballot[vote - 1]++;

    // Print the results
    printf("The results are:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidate_names[i], ballot[i]);
    }

    // Print a random message
    printf("Thanks for voting! You might have won a prize!\n");

    // Play a sound effect
    system("aplay -f sound.wav");

    return 0;
}