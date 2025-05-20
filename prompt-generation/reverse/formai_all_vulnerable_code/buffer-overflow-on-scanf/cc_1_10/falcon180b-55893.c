//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Function prototypes
void *game_loop(void *arg);

// Game variables
int player_score = 0;
int computer_score = 0;
int total_rounds = 10;
int choice;
int random_number;
int guess;
int win_count = 0;
int lose_count = 0;
int tie_count = 0;

// Lock variable for thread synchronization
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to play a round of the game
void play_round() {
    int min = 1;
    int max = 100;

    // Generate a random number
    random_number = rand_num(min, max);

    // Prompt the player to guess the number
    printf("Guess a number between %d and %d: ", min, max);
    scanf("%d", &guess);

    // Lock the mutex to synchronize with the other thread
    pthread_mutex_lock(&lock);

    // Check if the guess is correct
    if (guess == random_number) {
        printf("You win!\n");
        player_score++;
    } else if (guess < random_number) {
        printf("Too low.\n");
    } else {
        printf("Too high.\n");
    }

    // Unlock the mutex
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t thread_id;

    // Create a new thread for the game loop
    pthread_create(&thread_id, NULL, game_loop, NULL);

    // Play the game
    while (total_rounds > 0) {
        play_round();
        total_rounds--;
    }

    // Print the final score
    printf("Final score: Player %d, Computer %d\n", player_score, computer_score);
    printf("You won %d rounds, lost %d rounds, and tied %d rounds.\n", win_count, lose_count, tie_count);

    return 0;
}

// Function for the game loop
void *game_loop(void *arg) {
    srand(time(NULL));

    // Computer's turn
    while (total_rounds > 0) {
        play_round();
        total_rounds--;
    }

    return NULL;
}