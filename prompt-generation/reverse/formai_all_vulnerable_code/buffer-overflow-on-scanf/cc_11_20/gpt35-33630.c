//FormAI DATASET v1.0 Category: Dice Roller ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int s, r;
    char ch;

    printf("Let's roll the dice!\n");

    do {
        srand(time(NULL));

        s = ((rand() % 6) + 1);
        r = ((rand() % 6) + 1);

        printf("You rolled: %d and %d \n", s, r);

        if (s+r == 7 || s+r == 11) {
            printf("You win! \n");
        } else if (s+r == 2 || s+r == 3 || s+r == 12) {
            printf("You lose! \n");
        } else {
            int pt = s+r;
            printf("Your point is %d \n", pt);

            do {
                srand(time(NULL));

                s = ((rand() % 6) + 1);
                r = ((rand() % 6) + 1);

                printf("You rolled: %d and %d \n", s, r);

                if (s+r == pt) {
                    printf("You win! \n");
                    break;
                } else if (s+r == 7) {
                    printf("You lose! \n");
                    break;
                }

            } while (1);
        }

        printf("Do you want to roll again? (Y/N): ");
        scanf("%s", &ch);

    } while (ch == 'Y' || ch == 'y');

    printf("Thanks for playing! \n");

    return 0;
}