//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int questionCount = 10;
    const int maxNumber = 20;
    const int maxTime = 30;

    int questions[questionCount];
    int answers[questionCount];
    int inputAnswers[questionCount];

    int correctAnswers = 0;
    float percent = 0.0;

    printf("Welcome to Math Typing Speed Test!\n\n");
    printf("You will have %d seconds to answer %d questions.\n", maxTime, questionCount);
    printf("Each question will be addition of two random numbers between 1 and %d.\n", maxNumber);
    printf("Begin test by pressing ENTER key!\n");
    getchar();

    srand((unsigned) time(NULL));

    for (int i = 0; i < questionCount; i++){
        int num1 = rand() % maxNumber + 1;
        int num2 = rand() % maxNumber + 1;
        questions[i] = num1 + num2;

        printf("%d + %d = ", num1, num2);
        scanf("%d", &inputAnswers[i]);
    }

    time_t startTime = time(NULL);

    for (int i = 0; i < questionCount; i++){
        answers[i] = questions[i] == inputAnswers[i];
        if(answers[i]) correctAnswers++;
    }

    time_t endTime = time(NULL);

    percent = ((float) correctAnswers / (float) questionCount) * 100.0;

    printf("\nCongratulations, you answered %d correctly out of %d in %ld seconds.\n", correctAnswers, questionCount, endTime - startTime);
    printf("That's %.1f%%.\n", percent);

    if(percent >= 80){
        printf("You have a great Math Typing Speed!\n");
    } else if (percent >= 50){
        printf("You have a good Math Typing Speed. Practice more!\n");
    } else {
        printf("You need to practice a lot. Keep trying!\n");
    }

    return 0;
}