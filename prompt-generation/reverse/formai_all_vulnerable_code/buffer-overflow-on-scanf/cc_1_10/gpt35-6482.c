//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Global variables
int score = 0;
int lives = 3;
int position = 30;
const int max_position = 70;

// Function to display game data
void display_game() {
    printf("Score: %d\tLives: %d\t", score, lives);
    for(int i = 0; i < max_position; i++) {
        if(i == position) printf("X");
        else printf(" ");
    }
    printf("\n");
}

// Function for player thread
void* player_thread(void* arg) {
    char input;
    while(lives > 0) {
        printf("Enter position: L(left) / R(right)\n");
        scanf("%c", &input);
        if(input == 'L' && position > 0) position--;
        else if(input == 'R' && position < max_position) position++;
    }
    return NULL;
}

// Function for enemy thread
void* enemy_thread(void* arg) {
    srand(time(0));
    while(lives > 0) {
        int rand_pos = rand() % (max_position + 1);
        if(rand_pos == position) {
            lives--;
            printf("Enemy hit! Lives left: %d\n", lives);
        }
        sleep(1);
    }
    return NULL;
}

// Function for score thread
void* score_thread(void* arg) {
    while(lives > 0) {
        score++;
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t player_id, enemy_id, score_id;
    
    // Create player thread
    pthread_create(&player_id, NULL, player_thread, NULL);

    // Create enemy thread
    pthread_create(&enemy_id, NULL, enemy_thread, NULL);

    // Create score thread
    pthread_create(&score_id, NULL, score_thread, NULL);

    // Display game data in main thread
    while(lives > 0) {
        display_game();
        sleep(1);
        system("clear");  // Clear terminal
    }

    // Wait for threads to join
    pthread_join(player_id, NULL);
    pthread_join(enemy_id, NULL);
    pthread_join(score_id, NULL);

    // Game over
    printf("Game Over! Final Score: %d\n", score);

    return 0;
}