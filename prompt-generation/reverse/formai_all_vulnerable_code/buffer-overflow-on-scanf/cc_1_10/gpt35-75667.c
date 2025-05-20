//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quiz()
{
    char ans;
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Are you ready to test your knowledge of the elements? (y/n)\n");
    scanf(" %c", &ans);

    if (ans == 'y' || ans == 'Y')
    {
        printf("Great! Let's begin.\n");

        int i, j, numQs = 10, min = 1, max = 118;

        srand(time(NULL));

        for (i = 0; i < numQs; i++)
        {
            int randNum = (rand() % (max - min + 1)) + min;
            printf("\nQuestion %d:\n", i + 1);

            switch(randNum)
            {
                case 1:
                {
                    printf("What is the symbol for hydrogen?\n");
                    printf("a) He\nb) H\nc) O\nd) N\n");
                    scanf(" %c", &ans);
                    if (ans == 'b' || ans == 'B')
                    {
                        printf("Correct!\n");
                        score++;
                    }
                    else
                    {
                        printf("Sorry, the correct answer is B.\n");
                    }
                    break;
                }
                case 2:
                {
                    printf("What is the symbol for helium?\n");
                    printf("a) He\nb) H\nc) O\nd) N\n");
                    scanf(" %c", &ans);
                    if (ans == 'a' || ans == 'A')
                    {
                        printf("Correct!\n");
                        score++;
                    }
                    else
                    {
                        printf("Sorry, the correct answer is A.\n");
                    }
                    break;
                }
                // Add more cases for other elements... up to 118 cases total
                default:
                {
                    printf("Error: invalid random number generated.\n");
                    break;
                }
            }
        }

        printf("\nCongratulations! You scored %d out of %d.\n", score, numQs);
    }
    else
    {
        printf("No problem, come back when you're ready to play!\n");
    }
}

int main()
{
    quiz();

    return 0;
}