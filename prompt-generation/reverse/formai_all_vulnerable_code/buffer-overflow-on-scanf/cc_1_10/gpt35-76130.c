//FormAI DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0, num1, num2, answer, user_answer;
    int level = 1, max_level = 5;
    char operator = '+';

    printf("Welcome to the Math Quiz Game!\n\n");

    while (level <= max_level) {
        printf("Level %d\n", level);

        srand(time(NULL));
        num1 = rand() % (level * 10);
        num2 = rand() % (level * 10);

        if (level == max_level) {
            if (operator == '+') {
                operator = '*';
            } else {
                operator = '/';
            }
        }

        printf("%d %c %d = ", num1, operator, num2);
        scanf("%d", &user_answer);

        if (operator == '+') {
            answer = num1 + num2;
        } else if (operator == '-') {
            answer = num1 - num2;
        } else if (operator == '*') {
            answer = num1 * num2;
        } else {
            answer = num1 / num2;
        }

        if (user_answer == answer) {
            printf("Correct! +%d points\n\n", level * 10);
            score += level * 10;
            level++;
        } else {
            printf("Incorrect! The correct answer is %d\n\n", answer);
            level = level - (level > 1 ? 2 : 1);
        }
    }

    printf("Congratulations! You completed all levels! Final score: %d", score);

    return 0;
}