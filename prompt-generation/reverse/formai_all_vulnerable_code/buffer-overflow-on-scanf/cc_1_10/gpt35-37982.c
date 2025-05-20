//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int score = 0;
int totalQuestions = 0;

void takeQuiz();
void checkAnswer(int answer, int correctAnswer);
void showResult();

int main()
{
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Press enter to start the quiz!");
    getchar();
    takeQuiz();
    return 0;
}

void takeQuiz()
{
    int answer, correctAnswer;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int atomicNumber = rand() % 118 + 1;
        char symbol[3];
        if (atomicNumber >= 1 && atomicNumber <= 118)
        {
            switch (atomicNumber)
            {
            case 1:
                strcpy(symbol, "H");
                break;
            case 2:
                strcpy(symbol, "He");
                break;
            case 3:
                strcpy(symbol, "Li");
                break;
            // Rest of the cases omitted for brevity
            case 117:
                strcpy(symbol, "Ts");
                break;
            case 118:
                strcpy(symbol, "Og");
                break;
            }
            printf("\nWhat element has an atomic number of %d and a symbol of %s?\n", atomicNumber, symbol);
            scanf("%d", &answer);
            correctAnswer = atomicNumber;
            checkAnswer(answer, correctAnswer);
            totalQuestions++;
        }
    }
    showResult();
}

void checkAnswer(int answer, int correctAnswer)
{
    if (answer == correctAnswer)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! The correct answer is %d\n", correctAnswer);
    }
}

void showResult()
{
    printf("\nYou answered %d out of %d questions correctly!\n", score, totalQuestions);
    printf("Your percentage is %.2f %%\n", ((float)score / totalQuestions) * 100);
    printf("Thank you for taking the quiz!\n");
}