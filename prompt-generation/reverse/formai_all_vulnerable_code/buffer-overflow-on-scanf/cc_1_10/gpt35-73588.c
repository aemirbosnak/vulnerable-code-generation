//FormAI DATASET v1.0 Category: Memory Game ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int score = 0;
    int lifes = 3;
    int tmp_num;
    int tmp_guess;
    int sequence[10];
    int i, j;
    srand(time(NULL));

    printf("Welcome to the Memory Game!\n");
    printf("You have to remember a sequence of 10 numbers between 0 and 9.\n");
    printf("You have 3 lifes.\n");

    for(i=0; i<10; i++) { // Generate random sequence
        sequence[i] = rand() % 10;
    }

    for(i=0; i<10; i++) { // Play game
        printf("Sequence so far: ");
        for(j=0;j<i;j++) {
            printf("%d ", sequence[j]);
        }
        printf("\n");
        printf("Next number: ");
        scanf("%d", &tmp_guess);

        if(tmp_guess != sequence[i]) { // Wrong guess
            printf("Wrong number! Lost a life.\n");
            lifes--;
            if(lifes == 0) { // Game over
                printf("\nGame Over :(\n");
                printf("Final score: %d\n", score);
                return 0;
            }
            i--;
            continue;
        } else { // Correct guess
            score += 10;
            printf("Correct guess! +10 points.\n");
        }
    }

    printf("\nCongratulations! You won!\n");
    printf("Final score: %d\n", score);
    return 0;
}