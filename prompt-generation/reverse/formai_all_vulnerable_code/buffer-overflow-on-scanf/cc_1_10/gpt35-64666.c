//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;

    printf("Welcome to the Energizing Math Exercise!\n\n");
    printf("Get ready to solve some energizing math problems!\n\n");

    printf("Round 1:\n");
    printf("What is %d + %d?\n", num1, num2);
    int answer1;
    scanf("%d", &answer1);

    if (answer1 == num1 + num2) {
        printf("Correct! You got 5 points!\n\n");
    } else {
        printf("Incorrect. The correct answer is %d. You got 0 points.\n\n", num1+num2);
    }

    printf("Round 2:\n");
    int num3 = rand() % 100 + 1;
    int num4 = rand() % 100 + 1;
    printf("What is %d * %d?\n", num3, num4);
    int answer2;
    scanf("%d", &answer2);

    if (answer2 == num3 * num4) {
        printf("Correct! You got 10 points!\n\n");
    } else {
        printf("Incorrect. The correct answer is %d. You got 0 points.\n\n", num3*num4);
    }

    printf("Round 3:\n");
    int num5 = rand() % 100 + 1;
    int num6 = rand() % 100 + 1;
    printf("What is %d - %d?\n", num5, num6);
    int answer3;
    scanf("%d", &answer3);

    if (answer3 == num5-num6) {
        printf("Correct! You got 15 points!\n\n");
    } else {
        printf("Incorrect. The correct answer is %d. You got 0 points.\n\n", num5-num6);
    }

    printf("Final Round:\n");
    int num7 = rand() % 100 + 1;
    int num8 = rand() % 100 + 1;
    int num9 = rand() % 100 + 1;
    printf("What is %d + %d - %d?\n", num7, num8, num9);
    int answer4;
    scanf("%d", &answer4);

    if (answer4 == num7+num8-num9) {
        printf("Correct! You got 25 points!\n\n");
    } else {
        printf("Incorrect. The correct answer is %d. You got 0 points.\n\n", num7+num8-num9);
    }

    printf("Thank you for playing the Energizing Math Exercise!\n");
    printf("Your total score is %d out of 55 points.\n", (answer1==num1+num2?5:0)+(answer2==num3*num4?10:0)+(answer3==num5-num6?15:0)+(answer4==num7+num8-num9?25:0));

    return 0;
}