//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>

#define WIDTH 20
#define HEIGHT 10
#define NUM_PLAYERS 2
#define BRICK_OFFSET 3

char screen[HEIGHT][WIDTH + 1];
int player_positions[NUM_PLAYERS];
int ball_position[2] = {1, 1};  // Ball starting position
int ball_direction[2] = {1, 1};  // Ball moving direction (down-right)
int game_active = 1;

void initialize_screen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i < BRICK_OFFSET) {
                screen[i][j] = '#';  // Bricks
            } else {
                screen[i][j] = ' ';
            }
        }
        screen[i][WIDTH] = '\0'; // Null-terminate each row
    }
}

void draw_screen() {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", screen[i]);
    }
}

void update_ball() {
    // Move the ball
    ball_position[0] += ball_direction[0];
    ball_position[1] += ball_direction[1];

    // Check for collision with walls
    if (ball_position[0] >= HEIGHT || ball_position[0] < 0) {
        ball_direction[0] *= -1; // Reverse vertical direction
    }
    if (ball_position[1] >= WIDTH || ball_position[1] < 0) {
        ball_direction[1] *= -1; // Reverse horizontal direction
    }

    // Check for collision with players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (ball_position[0] == HEIGHT - 1 && ball_position[1] >= player_positions[i] && ball_position[1] < player_positions[i] + 3) {
            // Reverse ball direction
            ball_direction[0] *= -1;
        }
    }
}

void *player_input(void *arg) {
    int player_id = *(int*)arg;
    while (game_active) {
        char input;
        if (read(STDIN_FILENO, &input, 1) > 0) {
            if (input == 'a' && player_positions[player_id] > 0) {
                player_positions[player_id]--; // Move left
            } else if (input == 'd' && player_positions[player_id] < WIDTH - 3) {
                player_positions[player_id]++; // Move right
            }
        }
    }
    return NULL;
}

void update_player_positions() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        int pos = player_positions[i];
        if (pos < 0) pos = 0;
        if (pos > WIDTH - 3) pos = WIDTH - 3;
        player_positions[i] = pos;

        for (int j = 0; j < 3; j++) {
            screen[HEIGHT - 1][pos + j] = '='; // Player Paddle
        }
    }
}

int main() {
    // Initialize game
    for (int i = 0; i < NUM_PLAYERS; i++) {
        player_positions[i] = WIDTH / 2 - 1;
    }

    initialize_screen();
    pthread_t threads[NUM_PLAYERS];
    int player_ids[NUM_PLAYERS];

    // Create threads for player input
    for (int i = 0; i < NUM_PLAYERS; i++) {
        player_ids[i] = i;
        pthread_create(&threads[i], NULL, player_input, (void*)&player_ids[i]);
    }

    while (game_active) {
        // Update game state
        update_ball();
        update_player_positions();
        
        // Clear players' paddle in screen
        for (int i = 0; i < NUM_PLAYERS; i++) {
            int pos = player_positions[i];
            for (int j = 0; j < 3; j++) {
                screen[HEIGHT - 1][pos + j] = ' '; // Clear previous paddle position
            }
        }

        // Place the ball on the screen
        screen[ball_position[0]][ball_position[1]] = 'O';

        // Draw the screen
        draw_screen();

        // Reset ball position for next frame
        screen[ball_position[0]][ball_position[1]] = ' '; // Clear ball position
        usleep(100000); // Frame delay
    }

    // Join player input threads
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}