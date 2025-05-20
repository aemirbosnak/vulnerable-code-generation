//GPT-4o-mini DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_NUMBER 100
#define MAX_TRIES 10

typedef struct {
    int user_guess;
    int ai_guess;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int game_over;
    int user_number;
} Game;

void* ai_thread(void* arg) {
    Game* game = (Game*)arg;
    int low = 1, high = MAX_NUMBER;
    int tries = 0;

    while (tries < MAX_TRIES && !game->game_over) {
        int guess = (low + high) / 2;
        game->ai_guess = guess;

        printf("AI guesses: %d\n", guess);
        pthread_mutex_lock(&game->mutex);
        pthread_cond_signal(&game->cond);

        if (guess == game->user_number) {
            printf("AI wins! The number was: %d\n", game->user_number);
            game->game_over = 1;
        } else if (guess < game->user_number) {
            low = guess + 1;
        } else {
            high = guess - 1;
        }
        tries++;
        pthread_mutex_unlock(&game->mutex);
        sleep(1); // Simulating thinking time
    }
    return NULL;
}

void* user_thread(void* arg) {
    Game* game = (Game*)arg;

    printf("Welcome to the Number Guessing Game! Choose a number between 1 and 100.\n");
    printf("You need to enter your number: ");
    scanf("%d", &game->user_number);

    if (game->user_number < 1 || game->user_number > MAX_NUMBER) {
        printf("Invalid number! Please enter a number between 1 and 100.\n");
        game->game_over = 1;
        return NULL;
    }

    int tries = 0;
    while (tries < MAX_TRIES && !game->game_over) {
        pthread_mutex_lock(&game->mutex);
        pthread_cond_wait(&game->cond, &game->mutex);
        
        if (game->ai_guess < game->user_number) {
            printf("User: AI's guess is too low.\n");
        } else {
            printf("User: AI's guess is too high.\n");
        }
        tries++;
        pthread_mutex_unlock(&game->mutex);
    }

    if (!game->game_over) {
        printf("User wins! The number was: %d\n", game->user_number);
        game->game_over = 1;
    }
    return NULL;
}

int main() {
    Game game = {0, 0, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, 0, 0};

    pthread_t ai_tid, user_tid;

    srand(time(NULL));
    
    // Create AI and User threads
    pthread_create(&ai_tid, NULL, ai_thread, &game);
    pthread_create(&user_tid, NULL, user_thread, &game);

    // Wait for both threads to complete
    pthread_join(ai_tid, NULL);
    pthread_join(user_tid, NULL);

    // Cleanup resources
    pthread_mutex_destroy(&game.mutex);
    pthread_cond_destroy(&game.cond);

    return 0;
}