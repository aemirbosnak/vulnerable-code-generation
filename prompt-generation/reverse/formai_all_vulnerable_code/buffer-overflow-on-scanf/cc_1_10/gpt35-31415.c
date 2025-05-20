//FormAI DATASET v1.0 Category: Image Classification system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_PLAYERS 4
#define MAX_FILENAME_LEN 50
#define MAX_CLASSIFICATION_LEN 20

// Structs
typedef struct {
    char name[MAX_FILENAME_LEN];
    char classification[MAX_CLASSIFICATION_LEN];
} Image;

typedef struct {
    Image image;
    int score;
} PlayerImage;

// Function declarations
void classifyImage(char* filename, char* classification);
void playGame(PlayerImage* playerImages, int numPlayers);

int main() {
    PlayerImage playerImages[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the C Image Classification multiplayer game!\n");
    printf("How many players will be playing? (maximum %d) ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    if (numPlayers <= 0 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please try again.\n");
        return 1;
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d, what is your name? ", i+1);
        scanf("%s", playerImages[i].image.name);
        playerImages[i].score = 0;
    }

    printf("The game will now begin!\n");
    playGame(playerImages, numPlayers);

    printf("Game over! Final scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", playerImages[i].image.name, playerImages[i].score);
    }

    return 0;
}

/**
 * Classifies an image and stores the classification in the given variable
 */
void classifyImage(char* filename, char* classification) {
    // TODO: Implement image classification system
    strcpy(classification, "example classification");
}

/**
 * Plays a game with the given player and image data
 */
void playGame(PlayerImage* playerImages, int numPlayers) {
    Image currentImage;
    char input[MAX_CLASSIFICATION_LEN];
    int currentPlayer = 0;

    while (1) {
        // Get next image to classify
        printf("Player %d, it's your turn. Please enter a filename to classify (or 'quit' to stop playing): ", currentPlayer+1);
        scanf("%s", currentImage.name);
        if (strcmp(currentImage.name, "quit") == 0) {
            break;
        }

        // Classify image and get the correct classification
        classifyImage(currentImage.name, currentImage.classification);

        // Get player input and calculate their score
        printf("The image is classified as '%s'. What is your classification? ", currentImage.classification);
        scanf("%s", input);
        if (strcmp(input, currentImage.classification) == 0) {
            playerImages[currentPlayer].score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }

        // Move to the next player
        currentPlayer = (currentPlayer + 1) % numPlayers;
    }
}