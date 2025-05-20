//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_GUESS 10
#define MIN_VALUE 1
#define MAX_VALUE 100

// Structure to store player information
typedef struct {
    char name[MAX_NAME_LEN];
    int score;
    int lives;
} Player;

// Function to generate a random number between MIN_VALUE and MAX_VALUE
int generate_random_number() {
    return (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
}

// Function to get player information
void get_player_info(Player *player) {
    printf("Enter your name: ");
    fgets(player->name, MAX_NAME_LEN, stdin);
    player->name[strcspn(player->name, "\n")] = '\0';
    player->score = 0;
    player->lives = 3;
}

// Function to play the game
void play_game(Player *player) {
    int random_number = generate_random_number();
    int guess = 0;
    int count = 0;

    while (count < MAX_GUESS) {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        if (guess < random_number) {
            printf("Too low!\n");
        } else if (guess > random_number) {
            printf("Too high!\n");
        } else {
            printf("You guessed it!\n");
            player->score++;
            break;
        }
        count++;
    }

    if (count == MAX_GUESS) {
        printf("You lost! The correct answer was %d\n", random_number);
        player->lives--;
    }
}

// Function to display the game results
void display_results(Player *player) {
    printf("You scored %d points with %d lives remaining.\n", player->score, player->lives);
}

int main() {
    Player player;

    // Initialize random number generator
    srand(time(NULL));

    // Get player information
    get_player_info(&player);

    // Play the game
    play_game(&player);

    // Display the game results
    display_results(&player);

    return 0;
}