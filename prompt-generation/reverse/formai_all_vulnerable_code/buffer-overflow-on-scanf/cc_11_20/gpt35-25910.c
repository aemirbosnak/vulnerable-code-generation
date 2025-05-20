//FormAI DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int a, b, sum, answer;
    char operator;
    int correct_answers = 0, total_questions = 0;

    printf("Welcome to Medieval Math Exercises!\n");
    printf("What is your name, young squire?\n");
    char name[20];
    scanf("%s", name);
    printf("Greetings, %s! Prepare yourself for an adventure in math.\n", name);

    while (1) {
        a = rand() % 100 + 1;
        b = rand() % 100 + 1;
        switch (rand() % 4) {
            case 0:
                operator = '+';
                sum = a + b;
                break;
            case 1:
                operator = '-';
                sum = a - b;
                break;
            case 2:
                operator = '*';
                sum = a * b;
                break;
            case 3:
                operator = '/';
                if (b == 0 || a % b != 0) {
                    continue;
                }
                sum = a / b;
                break;
        }
        char question[50];
        sprintf(question, "%d %c %d = ", a, operator, b);
        printf("\n%s\n", question);
        
        scanf("%d", &answer);
        total_questions++;
        if (answer == sum) {
            correct_answers++;
            printf("The answer is correct, well done %s!\n", name);
        } else {
            printf("Sorry %s, the correct answer is %d.\n", name, sum);
        }

        printf("You have answered %d of %d questions correctly.\n", correct_answers, total_questions);
        
        if (total_questions % 5 == 0) {
            float success_rate = (float)correct_answers / total_questions * 100;
            printf("\nAfter %d questions, your success rate is %.2f%%.\n", total_questions, success_rate);
            if (success_rate < 50.0) {
                printf("You have not proven yourself worthy yet, %s. Try again!\n", name);
            } else if (success_rate < 80.0) {
                printf("You are doing well, %s. Keep it up!\n", name);
            } else {
                printf("Incredible, %s! You are a true mathematician.\n", name);
            }
        }
    }
    return 0;
}