//FormAI DATASET v1.0 Category: Math exercise ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int shape_shift = rand() % 3 + 1;
    int num1 = rand() % 101;
    int num2 = rand() % 101;
    float num3 = (float)rand() / RAND_MAX * 100;
    int answer;
    float answer_f;

    switch (shape_shift) {
        case 1: // Addition
            printf("What is %d + %d?\n", num1, num2);
            scanf("%d", &answer);

            if (answer == num1 + num2) {
                printf("Correct!\n");
            } else {
                printf("Incorrect, the correct answer is %d.\n", num1 + num2);
            }
            break;

        case 2: // Subtraction
            printf("What is %d - %d?\n", num1, num2);
            scanf("%d", &answer);

            if (answer == num1 - num2) {
                printf("Correct!\n");
            } else {
                printf("Incorrect, the correct answer is %d.\n", num1 - num2);
            }
            break;

        case 3: // Division
            printf("What is %.2f / %d (rounded to two decimal places, if necessary)?\n", num3, num2);
            scanf("%f", &answer_f);

            if (answer_f == (float)num3 / num2) {
                printf("Correct!\n");
            } else {
                printf("Incorrect, the correct answer is %.2f.\n", (float)num3 / num2);
            }
            break;

        default:
            printf("Something went wrong.\n");
            break;
    }

    return 0;
}