//Falcon-180B DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_questions = rand() % 10 + 1; // Generate a random number of questions between 1 and 10
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        int num1 = rand() % 100;
        int num2 = rand() % 100;
        int operation = rand() % 4; // Generate a random operation (0 = addition, 1 = subtraction, 2 = multiplication, 3 = division)

        switch (operation) {
            case 0:
                printf("Question %d: %d + %d = ", i+1, num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 + num2) {
                    printf("Incorrect!\n");
                } else {
                    printf("Correct!\n");
                }
                break;
            case 1:
                printf("Question %d: %d - %d = ", i+1, num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 - num2) {
                    printf("Incorrect!\n");
                } else {
                    printf("Correct!\n");
                }
                break;
            case 2:
                printf("Question %d: %d * %d = ", i+1, num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 * num2) {
                    printf("Incorrect!\n");
                } else {
                    printf("Correct!\n");
                }
                break;
            case 3:
                printf("Question %d: %d / %d = ", i+1, num1, num2);
                if (scanf("%d", &score)!= 1 || score!= num1 / num2) {
                    printf("Incorrect!\n");
                } else {
                    printf("Correct!\n");
                }
                break;
            default:
                printf("Invalid operation!\n");
        }
    }

    printf("Your final score is: %d out of %d\n", score, num_questions);

    return 0;
}