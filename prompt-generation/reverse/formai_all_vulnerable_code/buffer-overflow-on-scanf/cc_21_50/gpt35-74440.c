//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <string.h>

int main()
{
    char answer[20];
    int score;
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("Instructions:\n");
    printf("1. Answer each question with the symbol of the corresponding element.\n");
    printf("2. Each correct answer will add 10 points to your score.\n\n");
    printf("Are you ready to start? (Y/N): ");
    scanf("%s", answer);
    if (strcmp(answer, "Y") == 0 || strcmp(answer, "y") == 0)
    {
        printf("\nLet's begin!\n\n");
        printf("Question 1) What is the symbol for Hydrogen?: ");
        scanf("%s", answer);
        if (strcmp(answer, "H") == 0 || strcmp(answer, "h") == 0)
        {
            printf("Correct!\n");
            score += 10;
        }
        else
        {
            printf("Incorrect. The correct answer is H.\n");
        }
        printf("Score: %d\n\n", score);

        printf("Question 2) What is the symbol for Sodium?: ");
        scanf("%s", answer);
        if (strcmp(answer, "Na") == 0 || strcmp(answer, "na") == 0)
        {
            printf("Correct!\n");
            score += 10;
        }
        else
        {
            printf("Incorrect. The correct answer is Na.\n");
        }
        printf("Score: %d\n\n", score);

        printf("Question 3) What is the symbol for Oxygen?: ");
        scanf("%s", answer);
        if (strcmp(answer, "O") == 0 || strcmp(answer, "o") == 0)
        {
            printf("Correct!\n");
            score += 10;
        }
        else
        {
            printf("Incorrect. The correct answer is O.\n");
        }
        printf("Score: %d\n\n", score);

        printf("Question 4) What is the symbol for Gold?: ");
        scanf("%s", answer);
        if (strcmp(answer, "Au") == 0 || strcmp(answer, "au") == 0)
        {
            printf("Correct!\n");
            score += 10;
        }
        else
        {
            printf("Incorrect. The correct answer is Au.\n");
        }
        printf("Score: %d\n\n", score);

        printf("Question 5) What is the symbol for Iron?: ");
        scanf("%s", answer);
        if (strcmp(answer, "Fe") == 0 || strcmp(answer, "fe") == 0)
        {
            printf("Correct!\n");
            score += 10;
        }
        else
        {
            printf("Incorrect. The correct answer is Fe.\n");
        }
        printf("Score: %d\n\n", score);

        printf("Question 6) What is the symbol for Calcium?: ");
        scanf("%s", answer);
        if (strcmp(answer, "Ca") == 0 || strcmp(answer, "ca") == 0)
        {
            printf("Correct!\n");
            score += 10;
        }
        else
        {
            printf("Incorrect. The correct answer is Ca.\n");
        }
        printf("Score: %d\n\n", score);

        printf("Question 7) What is the symbol for Nitrogen?: ");
        scanf("%s", answer);
        if (strcmp(answer, "N") == 0 || strcmp(answer, "n") == 0)
        {
            printf("Correct!\n");
            score += 10;
        }
        else
        {
            printf("Incorrect. The correct answer is N.\n");
        }
        printf("Score: %d\n\n", score);

        printf("Question 8) What is the symbol for Carbon?: ");
        scanf("%s", answer);
        if (strcmp(answer, "C") == 0 || strcmp(answer, "c") == 0)
        {
            printf("Correct!\n");
            score += 10;
        }
        else
        {
            printf("Incorrect. The correct answer is C.\n");
        }
        printf("Score: %d\n\n", score);

        printf("Question 9) What is the symbol for Silver?: ");
        scanf("%s", answer);
        if (strcmp(answer, "Ag") == 0 || strcmp(answer, "ag") == 0)
        {
            printf("Correct!\n");
            score += 10;
        }
        else
        {
            printf("Incorrect. The correct answer is Ag.\n");
        }
        printf("Score: %d\n\n", score);

        printf("Question 10) What is the symbol for Helium?: ");
        scanf("%s", answer);
        if (strcmp(answer, "He") == 0 || strcmp(answer, "he") == 0)
        {
            printf("Correct!\n");
            score += 10;
        }
        else
        {
            printf("Incorrect. The correct answer is He.\n");
        }
        printf("Score: %d\n\n", score);

        printf("Congratulations! You have completed the quiz.\n");
        printf("Final Score: %d\n\n", score);
    }
    else
    {
        printf("\nGoodbye!\n");
    }
    return 0;
}