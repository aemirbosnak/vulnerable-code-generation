//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));
    int num_problems = rand() % 10 + 1;
    int score = 0;

    printf("Welcome to the post-apocalyptic math challenge!\n");
    printf("You will be presented with %d math problems.\n", num_problems);

    for (int i = 0; i < num_problems; i++) {
        int difficulty = rand() % 4 + 1;
        int num1 = rand() % 50 + 1;
        int num2 = rand() % 50 + 1;
        int operation = rand() % 4;

        switch (operation) {
            case 0:
                printf("Problem %d: %d + %d = ", i+1, num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 + num2) {
                    printf("Incorrect!\n");
                } else {
                    printf("Correct!\n");
                    score++;
                }
                break;
            case 1:
                printf("Problem %d: %d - %d = ", i+1, num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 - num2) {
                    printf("Incorrect!\n");
                } else {
                    printf("Correct!\n");
                    score++;
                }
                break;
            case 2:
                printf("Problem %d: %d * %d = ", i+1, num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 * num2) {
                    printf("Incorrect!\n");
                } else {
                    printf("Correct!\n");
                    score++;
                }
                break;
            case 3:
                printf("Problem %d: %d / %d = ", i+1, num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 / num2) {
                    printf("Incorrect!\n");
                } else {
                    printf("Correct!\n");
                    score++;
                }
                break;
        }
    }

    printf("Congratulations! You have completed the post-apocalyptic math challenge.\n");
    printf("Your final score is %d out of %d.\n", score, num_problems);

    return 0;
}