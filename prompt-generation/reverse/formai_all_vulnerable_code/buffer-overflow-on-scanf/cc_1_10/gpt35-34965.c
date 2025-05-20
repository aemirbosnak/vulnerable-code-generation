//FormAI DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, answer;
    int count = 0;

    srand(time(NULL)); //To generate random numbers each time

    printf("Welcome to the C Math Exercise Program!\n");
    printf("You will have 5 questions to answer\n");

    //Loop to generate 5 math questions
    for (int i=0; i<5; i++) {

        //Generating random numbers between 1 and 100
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        //Getting a random operator
        char operator;
        switch (rand() % 4) {
            case 0:
                operator = '+';
                result = num1 + num2;
                break;
            case 1:
                operator = '-';
                result = num1 - num2;
                break;
            case 2:
                operator = '*';
                result = num1 * num2;
                break;
            case 3:
                operator = '/';
                result = num1 / num2;
                break;
        }

        printf("Question %d: What is %d %c %d? ", i+1, num1, operator, num2);
        scanf("%d", &answer);

        if (answer == result) {
            printf("Correct!\n");
            count++;
        } else {
            printf("Incorrect. The correct answer is %d\n", result);
        }
    }

    printf("You have answered %d questions correctly out of 5.\n", count);

    if (count == 5) {
        printf("Excellent! You have passed the C Math Exercise Program.\n");
    } else {
        printf("Sorry, you did not pass the C Math Exercise Program. Please try again later.\n");
    }

    return 0;
}