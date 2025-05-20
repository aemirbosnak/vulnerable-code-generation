//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char name[20];
    int score = 0, level = 1, lives = 3, answer, guess, secretNum, range=10;
    srand(time(0));

    printf("Welcome to Cryptic Game!\n");
    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello, %s! Your journey begins now.\n", name);

    while (lives > 0) {
        secretNum = rand() % range + 1;
        printf("LEVEL %d: Guess the secret number between 1 and %d in less than 5 attempts.\n", level, range);
        for (int i = 0; i < 5; i++) {
            printf("Attempt %d: ", i+1);
            scanf("%d", &guess);
            if (guess == secretNum) {
                printf("Congratulations! You found the correct answer.\n");
                score += (range * 10);
                level += 1;
                break;
            } else if (guess > secretNum) {
                printf("The secret number is lower than %d.\n", guess);
            } else {
                printf("The secret number is higher than %d.\n", guess);
            }
        }
        lives -= 1;
        if (lives > 0) {
            printf("You lost a life! Remaining lives: %d\n", lives);
        } else {
            printf("You lost all your lives. GAME OVER.\n");
            printf("Final Score: %d\n", score);
            break;
        }

        printf("Do you want to continue to next level? (1 for yes, 0 for no) ");
        scanf("%d", &answer);
        if (answer == 0) {
            printf("Thank you for playing Cryptic Game, %s!\n", name);
            break;
        } else {
            range += 5;
            printf("Next level will be in range 1 to %d.\n", range);
        }
    }

    return 0;
}