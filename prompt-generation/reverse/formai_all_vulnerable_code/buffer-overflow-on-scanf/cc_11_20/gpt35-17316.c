//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: calm
#include <stdio.h>
#include <string.h>

int main()
{
    //Define variables
    int score = 0;
    char answer[10];

    //Display instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given the symbol of an element and you must provide the full name.\n");
    printf("Type 'quit' to exit.\n\n");

    //Question 1
    printf("What is the symbol for Sodium?\n");
    scanf("%s", answer);
    if (strcmp(answer, "Na") == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else if (strcmp(answer, "quit") == 0)
    {
        printf("You have quit the quiz.\n");
        return 0;
    }
    else
    {
        printf("Incorrect. The correct answer is Sodium.\n");
    }

    //Question 2
    printf("\nWhat is the symbol for Gold?\n");
    scanf("%s", answer);
    if (strcmp(answer, "Au") == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else if (strcmp(answer, "quit") == 0)
    {
        printf("You have quit the quiz.\n");
        return 0;
    }
    else
    {
        printf("Incorrect. The correct answer is Gold.\n");
    }

    //Question 3
    printf("\nWhat is the symbol for Carbon?\n");
    scanf("%s", answer);
    if (strcmp(answer, "C") == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else if (strcmp(answer, "quit") == 0)
    {
        printf("You have quit the quiz.\n");
        return 0;
    }
    else
    {
        printf("Incorrect. The correct answer is Carbon.\n");
    }

    //Question 4
    printf("\nWhat is the symbol for Helium?\n");
    scanf("%s", answer);
    if (strcmp(answer, "He") == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else if (strcmp(answer, "quit") == 0)
    {
        printf("You have quit the quiz.\n");
        return 0;
    }
    else
    {
        printf("Incorrect. The correct answer is Helium.\n");
    }

    //Question 5
    printf("\nWhat is the symbol for Chlorine?\n");
    scanf("%s", answer);
    if (strcmp(answer, "Cl") == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else if (strcmp(answer, "quit") == 0)
    {
        printf("You have quit the quiz.\n");
        return 0;
    }
    else
    {
        printf("Incorrect. The correct answer is Chlorine.\n");
    }

    //Display final score
    printf("\nYou scored %d out of 5.\n", score);

    return 0;
}