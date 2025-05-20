//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, op, answer, user_answer, correct = 0, total = 0;
    srand(time(0));

    printf("\nWelcome to the Math Exercise program! You will be asked to do some math calculations.");
    while (1) {
        a = rand() % 10;
        b = rand() % 10;
        op = rand() % 4;

        switch(op) {
            case 0:
                answer = a + b;
                printf("\n%d + %d = ", a, b);
                break;
            case 1:
                answer = a - b;
                printf("\n%d - %d = ", a, b);
                break;
            case 2:
                answer = a * b;
                printf("\n%d * %d = ", a, b);
                break;
            case 3:
                answer = a / b;
                printf("\n%d / %d = ", a, b);
                break;
        }

        scanf("%d", &user_answer);

        if (user_answer == answer) {
            correct++;
            printf("Correct! Well done.");
        } else {
            printf("Wrong answer. Try again.");
        }

        total++;

        if (total == 10) {
            printf("\n\nYou answered %d of the 10 exercises. You got %d right and %d wrong.", total, correct, total-correct);
            if (correct == 10) {
                printf("Wow! You are really good at math. Keep up the good work!");
            } else if (correct >= 7) {
                printf("Good job, you did well. Keep practicing and you'll get even better!");
            } else if (correct >= 4) {
                printf("You need to practice more, but you're on the right track. Keep it up!");
            } else {
                printf("You need to work harder on your math skills. Don't give up, keep practicing!");
            }
            break;
        }
    }

    return 0;
}