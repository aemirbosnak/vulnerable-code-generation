//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 118
#define QUESTIONS 10

int main()
{
    int score = 0;
    int element_nums[QUESTIONS];
    char answers[QUESTIONS];
    char responses[QUESTIONS];

    srand(time(NULL));

    printf("Welcome to the C Periodic Table quiz!\n");
    printf("You will be asked %d questions.\n", QUESTIONS);

    // select random elements for questions
    for (int i = 0; i < QUESTIONS; i++)
    {
        element_nums[i] = rand() % ELEMENTS + 1;
    }

    // ask questions
    for (int i = 0; i < QUESTIONS; i++)
    {
        char symbol[3];
        char name[20];

        // read element data from file
        char filename[20];
        sprintf(filename, "elements/%d.txt", element_nums[i]);
        FILE *file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("Error reading file for element %d\n", element_nums[i]);
            return 1;
        }
        fscanf(file, "%s %s", symbol, name);
        fclose(file);

        printf("\nQuestion %d:\n", i+1);
        printf("What is the atomic symbol for %s?\n", name);
        printf("a) %s\tb) %s\tc) %s\td) %s\n", symbol, "Xe", "Au", "Zn");

        // read answer from user
        printf("Enter your answer (a-d): ");
        scanf(" %c", &responses[i]);
        while (responses[i] < 'a' || responses[i] > 'd')
        {
            printf("Invalid entry. Enter a-d: ");
            scanf(" %c", &responses[i]);
        }

        // determine correct answer
        if (symbol[0] == responses[i])
        {
            score++;
            answers[i] = '+';
        }
        else
        {
            answers[i] = '-';
        }
    }

    // show results
    printf("\nResults:\n");
    for (int i = 0; i < QUESTIONS; i++)
    {
        printf("%d. %c %c\n", i+1, answers[i], responses[i]);
    }
    printf("\nYour score is %d/%d\n", score, QUESTIONS);

    return 0;
}