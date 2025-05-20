//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int level = 1;
    int score = 0;
    int round = 1;
    int chances_left = 3;

    printf("Welcome to the Brave Game!\n");
    printf("========================= \n\n");
    printf("You are a brave warrior on a quest to defeat the evil dragon that is terrorizing the kingdom.\n");
    printf("To defeat the dragon, you must successfully complete a series of challenges and earn enough points.\n");
    printf("Are you ready to begin? Let's go!\n\n");

    srand(time(NULL)); // Seed the random number generator

    while(level <= 5 && chances_left > 0) {
        printf("********** Round %d **********\n\n", round);
        printf("You are in level %d\n", level);
        printf("You have %d chances left.\n", chances_left);

        int question_type = rand() % 3; // Generate a random number between 0 and 2 to decide the type of question

        if(question_type == 0) {
            // Addition challenge
            int num1 = rand() % (level * 10) + 1; // Generate a random number between 1 and level * 10
            int num2 = rand() % (level * 10) + 1; // Generate another random number between 1 and level * 10
            int answer = num1 + num2;

            printf("What is %d + %d? ", num1, num2);

            int user_answer;
            scanf("%d", &user_answer);

            if(user_answer == answer) {
                printf("Correct! You have earned %d points.\n", level);
                score += level;
            } else {
                printf("Incorrect. The correct answer is %d. You have lost a chance.\n", answer);
                chances_left--;
            }
        } else if(question_type == 1) {
            // Subtraction challenge
            int num1 = rand() % (level * 10) + 1; // Generate a random number between 1 and level * 10
            int num2 = rand() % (level * 10) + 1; // Generate another random number between 1 and level * 10
            int answer = num1 - num2;

            printf("What is %d - %d? ", num1, num2);

            int user_answer;
            scanf("%d", &user_answer);

            if(user_answer == answer) {
                printf("Correct! You have earned %d points.\n", level);
                score += level;
            } else {
                printf("Incorrect. The correct answer is %d. You have lost a chance.\n", answer);
                chances_left--;
            }
        } else {
            // Multiplication challenge
            int num1 = rand() % (level * 5) + 1; // Generate a random number between 1 and level * 5
            int num2 = rand() % (level * 5) + 1; // Generate another random number between 1 and level * 5
            int answer = num1 * num2;

            printf("What is %d x %d? ", num1, num2);

            int user_answer;
            scanf("%d", &user_answer);

            if(user_answer == answer) {
                printf("Correct! You have earned %d points.\n", level);
                score += level;
            } else {
                printf("Incorrect. The correct answer is %d. You have lost a chance.\n", answer);
                chances_left--;
            }
        }

        if(score >= level * 10) {
            // Move to the next level
            level++;
            printf("Congratulations! You have advanced to level %d.\n", level);
            chances_left = 3; // Reset chances for the next level
        }

        round++;
        printf("\n");
    }

    if(chances_left == 0) {
        printf("Game over! You have no more chances left. Better luck next time!\n");
    } else {
        printf("Congratulations! You have defeated the dragon and saved the kingdom!\n");
    }

    printf("Final score: %d\n", score);

    return 0;
}