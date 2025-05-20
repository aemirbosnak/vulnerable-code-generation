//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void startGame(void);
void playGame(void);
void endGame(int score);

int main() {
    srand(time(0));
    startGame();
    return 0;
}

void startGame() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the lost treasure.\n");
    printf("Are you ready to begin? (y/n) ");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y') {
        playGame();
    } else {
        printf("Thanks for playing!\n");
        exit(0);
    }
}

void playGame() {
    int score = 0;
    int room = 1;
    char choice;

    while (room <= 5) {
        printf("\nYou are in room %d.\n", room);
        printf("What would you like to do?\n");
        printf("1. Look around\n");
        printf("2. Search for clues\n");
        printf("3. Move to another room\n");
        printf("4. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("You look around and see...\n");
            printf("A dusty old book on a shelf.\n");
            printf("A flickering candle on a table.\n");
            printf("A mysterious locked chest in the corner.\n");
            break;
        case '2':
            printf("You search for clues and find...\n");
            printf("A piece of paper with a riddle:\n");
            printf("I am not alive, but I grow;\n");
            printf("I don't have lungs, but I need air;\n");
            printf("I don't have a mouth, but I need water to live.\n");
            printf("What am I?\n");
            char answer[20];
            scanf("%s", answer);
            if (strcmp(answer, "fire") == 0) {
                printf("You solved the riddle! Score: +10\n");
                score += 10;
            } else {
                printf("Wrong answer. Score: 0\n");
            }
            break;
        case '3':
            printf("You move to another room.\n");
            room++;
            break;
        case '4':
            printf("Thanks for playing! Your final score is %d.\n", score);
            exit(0);
        default:
            printf("Invalid choice. Score: 0\n");
        }
    }
}

void endGame(int score) {
    if (score >= 50) {
        printf("Congratulations! You found the lost treasure!\n");
    } else {
        printf("Sorry, you did not find the lost treasure.\n");
    }
}