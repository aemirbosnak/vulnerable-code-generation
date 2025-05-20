//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char answer;
    int score = 0;
    srand(time(NULL));

    printf("Welcome to the C Periodic Table Quiz!\n\n");

    printf("Question 1:\nWhat is the symbol for helium?\n");
    printf("(a) He\n(b) Hl\n(c) Hm\n(d) Hy\n");
    scanf(" %c", &answer);
    if(answer == 'a')
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("\nQuestion 2:\nWhat is the symbol for oxygen?\n");
    printf("(a) O2\n(b) Ox\n(c) Oz\n(d) O\n");
    scanf(" %c", &answer);
    if(answer == 'd')
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("\nQuestion 3:\nWhat is the symbol for sodium?\n");
    printf("(a) So\n(b) Sa\n(c) Sn\n(d) Na\n");
    scanf(" %c", &answer);
    if(answer == 'd')
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("\nQuestion 4:\nWhat is the symbol for potassium?\n");
    printf("(a) K\n(b) Pk\n(c) Po\n(d) Ka\n");
    scanf(" %c", &answer);
    if(answer == 'a')
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("\nQuestion 5:\nWhat is the symbol for gold?\n");
    printf("(a) Au\n(b) Ag\n(c) Gd\n(d) Al\n");
    scanf(" %c", &answer);
    if(answer == 'a')
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("\nYour final score is %d out of 5.\n", score);

    if(score == 5)
    {
        printf("Congratulations, you are a C Periodic Table master!\n");
    }
    else if(score >= 3)
    {
        printf("Not bad, but there is still room for improvement.\n");
    }
    else
    {
        printf("Looks like you have some studying to do.\n");
    }

    return 0;
}