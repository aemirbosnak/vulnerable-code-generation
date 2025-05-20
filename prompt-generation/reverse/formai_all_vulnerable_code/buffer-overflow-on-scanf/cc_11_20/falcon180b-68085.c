//Falcon-180B DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, num, guess, i, j, flag = 0, attempts = 0;
    char name[20];
    int score = 0;
    int high_score = 0;
    int quit = 0;
    FILE *fp;
    struct tm *t;
    time_t now;
    char strftime_buf[80];

    srand(time(NULL));
    now = time(NULL);
    t = localtime(&now);
    strftime(strftime_buf, 80, "%Y-%m-%d %H:%M:%S", t);

    printf("Welcome to the Guessing Game!\n");
    printf("Enter your name: ");
    scanf("%s", name);

    fp = fopen("high_score.txt", "r");
    if (fp!= NULL) {
        fscanf(fp, "%d", &high_score);
        fclose(fp);
    }

    do {
        printf("\n%s, you have %d points.\n", name, score);
        printf("Do you want to play the game? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("\nGuess a number between 1 and 100: ");
            scanf("%d", &num);

            for (i = 1; i <= 10; i++) {
                attempts++;
                guess = rand() % 100 + 1;

                if (guess == num) {
                    printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);
                    score += 10;
                } else if (guess < num) {
                    printf("\nToo low. Guess again: ");
                } else {
                    printf("\nToo high. Guess again: ");
                }

                scanf("%d", &guess);
            }

            if (score > high_score) {
                high_score = score;
                fp = fopen("high_score.txt", "w");
                fprintf(fp, "%d", high_score);
                fclose(fp);
            }

            if (score >= 50) {
                printf("\nYou are a master of the game! Do you want to quit? (y/n): ");
                scanf(" %c", &quit);

                if (quit == 'y' || quit == 'Y') {
                    printf("\nThanks for playing, %s! Your final score is %d.\n", name, score);
                    exit(0);
                }
            }
        } else {
            printf("\nThanks for playing, %s! Your final score is %d.\n", name, score);
            exit(0);
        }
    } while (1);

    return 0;
}