//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int rounds = 3;
    int input;

    printf("\n\nWelcome to the Cryptic Game!\n");
    printf("********************\n");
    printf("You have 3 rounds to score as many points as possible.\n");
    printf("Each round you will be presented with a riddle to solve.\n");
    printf("Each correct answer is worth 10 points.\n");
    printf("********************\n");

    for(int i=0; i<rounds; i++) {

        int r = rand() % 3;

        switch (r) {
            case 0:
                printf("\nRound %d - Cryptic Riddle:\n",i+1);
                printf("My life can be measured in hours,\nI serve by being devoured,\nThin, I am quick,\nFat, I am slow,\nWind is my enemy.\nWhat am I?\n");
                scanf("%d", &input);
                if (input == 2) {
                    score += 10;
                    printf("Correct! You earned 10 points!\n\n");
                }
                else {
                    printf("Sorry, the correct answer was 2. Better luck next time!\n\n");
                }
                break;

            case 1:
                printf("\nRound %d - Cryptic Riddle:\n",i+1);
                printf("I am not alive, but I grow;\nI don't have lungs, but I need air;\nI don't have a mouth, but water kills me.\nWhat am I?\n");
                scanf("%d", &input);
                if (input == 3) {
                    score += 10;
                    printf("Correct! You earned 10 points!\n\n");
                }
                else {
                    printf("Sorry, the correct answer was 3. Better luck next time!\n\n");
                }
                break;

            case 2:
                printf("\nRound %d - Cryptic Riddle:\n",i+1);
                printf("A word I know,\nSix letters it contains,\nTake away the first letter,\nAnd twelve remains.\nWhat is it?\n");
                scanf("%d", &input);
                if (input == 4) {
                    score += 10;
                    printf("Correct! You earned 10 points!\n\n");
                }
                else {
                    printf("Sorry, the correct answer was 4. Better luck next time!\n\n");
                }
                break;
        }
    }

    printf("********************\n");
    printf("Congratulations on finishing the game!\n");
    printf("Your final score is: %d\n", score);

    return 0;
}