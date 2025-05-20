//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int score = 0;
    char answer[100];

    printf("Welcome to the Medieval Periodic Table Quiz!\n\n");
    printf("The objective of the game is to correctly identify the symbols of the elements given their name.\n");
    printf("For every correct answer, you will receive one point. There is no penalty for wrong answers.\n\n");

    printf("Are you ready to begin? (Y/N)\n");

    scanf("%s", answer);

    if (strcmp(answer, "Y") == 0 || strcmp(answer, "y") == 0)
    {
        printf("\n\nLet the quiz begin!\n\n");

        srand(time(NULL));

        for (int i = 0; i < 10; i++)
        {
            int random_number = rand() % 118;

            switch (random_number)
            {
                case 0:
                    printf("Which element has the symbol H?\n");
                    scanf("%s", answer);
                    if (strcmp(answer, "Hydrogen") == 0 || strcmp(answer, "hydrogen") == 0)
                    {
                        printf("Correct!\n");
                        score++;
                    }
                    else
                    {
                        printf("Wrong!\n");
                    }

                    break;

                case 1:
                    printf("Which element has the symbol He?\n");
                    scanf("%s", answer);
                    if (strcmp(answer, "Helium") == 0 || strcmp(answer, "helium") == 0)
                    {
                        printf("Correct!\n");
                        score++;
                    }
                    else
                    {
                        printf("Wrong!\n");
                    }

                    break;
                    //and so on till case 117

                case 117:
                    printf("Which element has the symbol Uuo?\n");
                    scanf("%s", answer);
                    if (strcmp(answer, "Ununoctium") == 0 || strcmp(answer, "ununoctium") == 0)
                    {
                        printf("Correct!\n");
                        score++;
                    }
                    else
                    {
                        printf("Wrong!\n");
                    }

                    break;
            }
        }

        printf("\n\nYour final score is: %d\n", score);
    }
    else
    {
        printf("Maybe next time then. Goodbye!\n");
    }

    return 0;
}