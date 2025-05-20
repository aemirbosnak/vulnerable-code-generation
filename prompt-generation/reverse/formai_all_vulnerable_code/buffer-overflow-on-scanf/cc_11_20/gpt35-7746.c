//FormAI DATASET v1.0 Category: Image Classification system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 2
#define MAX_ROUNDS 3

int main() {
    // List of image classes
    char classes[5][20] = {"car", "dog", "cat", "flower", "tree"};
    
    // Prompt players to enter their names
    char names[MAX_PLAYERS][50];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", names[i]);
    }
    
    // Set up player scores
    int scores[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        scores[i] = 0;
    }
    
    // Start the game
    printf("\nLet's start the game!\n\n");
    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("ROUND %d\n", round);
        printf("--------------------\n");
        
        // Randomly generate image classes for this round
        int class1_index = rand() % 5;
        int class2_index = rand() % 5;
        while (class2_index == class1_index) {
            class2_index = rand() % 5;
        }
        
        // Display the image classes to the players
        printf("Image classes for this round:\n");
        printf("1. %s\n", classes[class1_index]);
        printf("2. %s\n", classes[class2_index]);
        printf("\n");
        
        // Prompt each player to classify 3 images
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%s, please classify 3 images based on the image classes above.\n", names[i]);
            for (int j = 0; j < 3; j++) {
                char image_class[20];
                printf("Enter image %d class: ", j+1);
                scanf("%s", image_class);
                if (strcmp(image_class, classes[class1_index]) == 0 ||
                    strcmp(image_class, classes[class2_index]) == 0) {
                    scores[i]++;
                }
            }
            printf("\n");
        }
        
        // Display round scores and overall scores
        printf("ROUND %d SCORES\n", round);
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%s: %d\n", names[i], scores[i]);
        }
        printf("\n");
    }
    
    // Display final scores and winner
    printf("FINAL SCORES\n");
    int max_score = -1;
    int winner_index = -1;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", names[i], scores[i]);
        if (scores[i] > max_score) {
            max_score = scores[i];
            winner_index = i;
        } else if (scores[i] == max_score) {
            winner_index = -1; // tie
        }
    }
    if (winner_index == -1) {
        printf("It's a tie!\n");
    } else {
        printf("%s wins the game!\n", names[winner_index]);
    }
    
    return 0;
}