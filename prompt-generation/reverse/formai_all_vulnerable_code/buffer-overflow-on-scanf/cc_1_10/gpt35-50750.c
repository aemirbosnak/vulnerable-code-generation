//FormAI DATASET v1.0 Category: Image Classification system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_IMAGE_SIZE 100

// define player struct
typedef struct player {
    int player_id;
    char name[50];
    int score;
} player;

// define an image struct
typedef struct image {
    char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE]; // suppose the image is square
    int label;
} image;

// compare two images and return 1 if they are the same, 0 otherwise
int compare_images(image img1, image img2) {
    for (int i = 0; i < MAX_IMAGE_SIZE; i++) {
        for (int j = 0; j < MAX_IMAGE_SIZE; j++) {
            if (img1.pixels[i][j] != img2.pixels[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// classify the given image and return its label 
int classify_image(image img) {
    // some image classification algorithm here...
    return rand() % 10; // just return a random label for now
}

int main() {
    int n_players;
    printf("Enter number of players (2-4): ");
    scanf("%d", &n_players);

    // check if the number of players is valid
    if (n_players < 2 || n_players > 4) {
        printf("Invalid number of players! Exiting...");
        return 1;
    }

    // create array of players
    player players[MAX_PLAYERS];
    for (int i = 0; i < n_players; i++) {
        printf("Enter name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].player_id = i;
        players[i].score = 0;
    }

    // generate array of images
    image images[MAX_IMAGE_SIZE];
    for (int i = 0; i < MAX_IMAGE_SIZE; i++) {
        for (int j = 0; j < MAX_IMAGE_SIZE; j++) {
            images[i].pixels[i][j] = rand() % 256; // randomly generate pixel values
        }
        images[i].label = rand() % 10;
    }

    // start the game
    printf("Starting game...\n");

    // randomize order of players
    int turn_order[MAX_PLAYERS];
    for (int i = 0; i < n_players; i++) {
        turn_order[i] = i;
    }
    for (int i = 0; i < n_players-1; i++) {
        int j = rand() % (n_players-i) + i; // choose random index
        int temp = turn_order[i]; // swap values
        turn_order[i] = turn_order[j];
        turn_order[j] = temp;
    }

    // iterate over turns until all images are classified
    int n_classified = 0;
    int current_player = turn_order[0];
    while (n_classified < MAX_IMAGE_SIZE) {
        // get current player's turn
        printf("%s's turn...\n", players[current_player].name);
        printf("Enter the number of the image you want to classify (1-%d): ", MAX_IMAGE_SIZE);
        int image_num;
        scanf("%d", &image_num);
        if (image_num < 1 || image_num > MAX_IMAGE_SIZE) {
            printf("Invalid image number!\n");
            continue;
        }

        // verify that the image has not already been classified
        if (images[image_num-1].label != -1) {
            printf("Image already classified!\n");
            continue;
        }

        // classify the image
        int predicted_label = classify_image(images[image_num-1]);

        // ask for player's guess and update score
        printf("Your guess (0-9): ");
        int player_guess;
        scanf("%d", &player_guess);
        if (player_guess == predicted_label) {
            printf("Correct!\n");
            players[current_player].score++;
        } else {
            printf("Wrong...\n");
            // if the guess is wrong, iterate over all other players and check if they can steal the point
            for (int i = 0; i < n_players; i++) {
                if (i == current_player) {
                    continue;
                }
                printf("%s, do you want to steal %s's point? (y/n): ", players[i].name, players[current_player].name);
                char answer[2];
                scanf("%s", answer);
                if (strcmp(answer, "y") == 0) {
                    players[i].score++;
                    players[current_player].score--;
                    printf("%s successfully steals %s's point!\n", players[i].name, players[current_player].name);
                    break;
                }
            }
        }

        // update image array
        images[image_num-1].label = predicted_label;
        n_classified++;

        // switch to next player
        current_player++;
        if (current_player == n_players) {
            current_player = 0;
        }
    }

    // print final scores
    printf("Game over! Final scores:\n");
    for (int i = 0; i < n_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}