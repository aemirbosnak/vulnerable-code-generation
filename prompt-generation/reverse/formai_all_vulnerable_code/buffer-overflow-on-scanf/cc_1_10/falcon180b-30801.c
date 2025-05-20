//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void intro();
void game_over(int score);
int play_game();

int main() {
    srand(time(NULL)); // Seed the random number generator
    intro();
    int score = play_game();
    game_over(score);
    return 0;
}

void intro() {
    printf("Welcome to the medieval quest!\n");
    printf("You are a brave knight on a mission to rescue the princess\n");
    printf("from the evil dragon. Good luck!\n\n");
}

void game_over(int score) {
    if (score == 10) {
        printf("Congratulations! You have successfully rescued the princess.\n");
    } else {
        printf("Game over! You scored %d points.\n", score);
    }
    printf("Press enter to exit...\n");
    getchar();
}

int play_game() {
    int score = 0;
    int choice;
    char play_again;

    do {
        printf("\nYou are in a dark forest. What do you want to do?\n");
        printf("1. Move forward\n2. Turn back\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou moved forward.\n");
                score++;
                break;
            case 2:
                printf("\nYou turned back.\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (score < 10 && play_again == 'y');

    return score;
}