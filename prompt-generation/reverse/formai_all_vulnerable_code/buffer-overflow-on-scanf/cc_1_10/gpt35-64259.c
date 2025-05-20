//FormAI DATASET v1.0 Category: Image Classification system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define IMAGE_SIZE 10
#define NUM_CLASSES 5
#define NUM_PLAYERS 3

// Define global variables
int images[IMAGE_SIZE][IMAGE_SIZE][NUM_CLASSES];
int correct_class[NUM_CLASSES];
int player_scores[NUM_PLAYERS];
int current_player = 0;

// Function to generate random images
void generate_images() {
    srand(time(0));
    for (int i = 0; i < NUM_CLASSES; i++) {
        printf("Generating images for class %d\n", i+1);
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < IMAGE_SIZE; k++) {
                images[j][k][i] = rand() % 256;
            }
        }
    }
}

// Function to set correct class for each image
void set_correct_class() {
    for (int i = 0; i < NUM_CLASSES; i++) {
        correct_class[i] = rand() % NUM_CLASSES + 1;
    }
}

// Function to display an image
void display_image(int image_id) {
    printf("Image %d\n", image_id);
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            printf("%d ", images[i][j][image_id-1]);
        }
        printf("\n");
    }
}

// Function to get player guess for image class
int get_player_guess() {
    int guess;
    printf("Player %d, enter your guess (1-5): ", current_player+1);
    scanf("%d", &guess);
    return guess;
}

// Function to update player score
void update_player_score(int image_id, int guess) {
    if (guess == correct_class[image_id-1]) {
        player_scores[current_player]++;
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }
}

// Function to switch to next player
void switch_player() {
    current_player = (current_player + 1) % NUM_PLAYERS;
}

// Main function
int main() {
    generate_images();
    set_correct_class();

    // Loop through each image
    for (int i = 0; i < IMAGE_SIZE; i++) {
        printf("\n----- Image %d -----\n", i+1);
        display_image(i+1);

        // Loop through each player
        for (int j = 0; j < NUM_PLAYERS; j++) {
            printf("\nPlayer %d's turn...\n", current_player+1);
            int guess = get_player_guess();
            update_player_score(i+1, guess);
            switch_player();
        }
    }

    // Display final scores
    printf("\n----- Final Scores -----\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: %d\n", i+1, player_scores[i]);
    }

    return 0;
}