//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a player
typedef struct {
    char name[20];
    int score;
} Player;

// Function to calculate the probability of an alien invasion
int calculate_probability(int num_sightings, int num_abductions, int num_years) {
    // Calculate the average number of sightings and abductions per year
    float avg_sightings = (float)num_sightings / num_years;
    float avg_abductions = (float)num_abductions / num_years;

    // Calculate the probability of an alien invasion based on the average number of sightings and abductions per year
    int probability = (int)(avg_sightings * avg_abductions * 100);

    return probability;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of players
    Player players[4];

    // Get the names of the players
    for (int i = 0; i < 4; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Initialize the scores of the players
    for (int i = 0; i < 4; i++) {
        players[i].score = 0;
    }

    // Get the number of sightings, abductions, and years
    int num_sightings, num_abductions, num_years;
    printf("Enter the number of alien sightings: ");
    scanf("%d", &num_sightings);
    printf("Enter the number of alien abductions: ");
    scanf("%d", &num_abductions);
    printf("Enter the number of years: ");
    scanf("%d", &num_years);

    // Calculate the probability of an alien invasion
    int probability = calculate_probability(num_sightings, num_abductions, num_years);

    // Display the probability of an alien invasion
    printf("The probability of an alien invasion is: %d%%\n", probability);

    // Get the guesses from the players
    for (int i = 0; i < 4; i++) {
        int guess;
        printf("%s, guess the probability of an alien invasion (0-100): ", players[i].name);
        scanf("%d", &guess);

        // Calculate the score of the player
        players[i].score += abs(guess - probability);
    }

    // Find the player with the highest score
    int max_score = 0;
    int winner_index = -1;
    for (int i = 0; i < 4; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            winner_index = i;
        }
    }

    // Display the winner
    if (winner_index != -1) {
        printf("The winner is %s with a score of %d!\n", players[winner_index].name, players[winner_index].score);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}