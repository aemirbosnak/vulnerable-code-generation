//Falcon-180B DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_questions = rand() % 10 + 1;
    int score = 0;
    int i;

    for (i = 0; i < num_questions; i++) {
        int num1 = rand() % 100;
        int num2 = rand() % 100;
        int operation = rand() % 4;

        switch (operation) {
            case 0:
                printf("What is %d + %d? ", num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 + num2) {
                    printf("Incorrect answer.\n");
                } else {
                    printf("Correct answer.\n");
                }
                break;
            case 1:
                printf("What is %d - %d? ", num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 - num2) {
                    printf("Incorrect answer.\n");
                } else {
                    printf("Correct answer.\n");
                }
                break;
            case 2:
                printf("What is %d * %d? ", num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 * num2) {
                    printf("Incorrect answer.\n");
                } else {
                    printf("Correct answer.\n");
                }
                break;
            case 3:
                printf("What is %d / %d? ", num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 / num2) {
                    printf("Incorrect answer.\n");
                } else {
                    printf("Correct answer.\n");
                }
                break;
        }
    }

    printf("You got %d out of %d questions correct.\n", score, num_questions);

    return 0;
}