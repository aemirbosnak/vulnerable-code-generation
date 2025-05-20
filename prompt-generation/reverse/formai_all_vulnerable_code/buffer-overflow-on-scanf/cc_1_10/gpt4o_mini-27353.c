//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLAYERS 5
#define MAX_IMAGES 10
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} Player;

typedef struct {
    char imageName[50];
    char classification[50];
} Image;

Image images[MAX_IMAGES] = {
    {"image1.png", "cat"},
    {"image2.png", "dog"},
    {"image3.png", "car"},
    {"image4.png", "flower"},
    {"image5.png", "tree"},
    {"image6.png", "bicycle"},
    {"image7.png", "person"},
    {"image8.png", "building"},
    {"image9.png", "boat"},
    {"image10.png", "plane"}
};

Player players[MAX_PLAYERS];
int playerCount = 0;

void addPlayer() {
    if (playerCount < MAX_PLAYERS) {
        printf("Enter player name: ");
        scanf("%s", players[playerCount].name);
        players[playerCount].score = 0;
        playerCount++;
        printf("Player %s added!\n", players[playerCount - 1].name);
    } else {
        printf("Maximum player limit reached!\n");
    }
}

void classifyImages() {
    for (int i = 0; i < MAX_IMAGES; i++) {
        printf("Classifying %s\n", images[i].imageName);

        for (int j = 0; j < playerCount; j++) {
            char classification[50];
            printf("Player %s, enter your classification: ", players[j].name);
            scanf("%s", classification);

            if (strcmp(classification, images[i].classification) == 0) {
                players[j].score += 10; // Award 10 points for a correct classification
                printf("Correct! %s gets 10 points.\n", players[j].name);
            } else {
                printf("Incorrect! The correct classification is %s.\n", images[i].classification);
            }
        }
    }
}

void displayScores() {
    printf("\nScores:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
}

int main() {
    int choice;
    do {
        printf("\nMultiplayer Image Classification System\n");
        printf("1. Add Player\n");
        printf("2. Classify Images\n");
        printf("3. Display Scores\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                classifyImages();
                break;
            case 3:
                displayScores();
                break;
            case 4:
                printf("Exiting the game. Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
        
    } while (choice != 4);

    return 0;
}