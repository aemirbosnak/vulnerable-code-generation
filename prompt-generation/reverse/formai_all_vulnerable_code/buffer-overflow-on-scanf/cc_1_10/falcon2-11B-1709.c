//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>

int main() {
    char input[10];
    int score = 0;
    int level = 1;

    while (1) {
        printf("Level %d:\n", level);
        printf("Score: %d\n", score);
        printf("Enter your guess: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        else if (strcmp(input, "rock") == 0) {
            printf("You chose rock!\n");
            if (rand() % 2 == 0) {
                printf("Computer chose scissors!\n");
                score++;
            }
            else {
                printf("Computer chose paper!\n");
                score--;
            }
        }
        else if (strcmp(input, "paper") == 0) {
            printf("You chose paper!\n");
            if (rand() % 2 == 0) {
                printf("Computer chose rock!\n");
                score--;
            }
            else {
                printf("Computer chose scissors!\n");
                score++;
            }
        }
        else if (strcmp(input, "scissors") == 0) {
            printf("You chose scissors!\n");
            if (rand() % 2 == 0) {
                printf("Computer chose paper!\n");
                score--;
            }
            else {
                printf("Computer chose rock!\n");
                score++;
            }
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
        level++;
    }

    printf("Thanks for playing!\n");
    return 0;
}