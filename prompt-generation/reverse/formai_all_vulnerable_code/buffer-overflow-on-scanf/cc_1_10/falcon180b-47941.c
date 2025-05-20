//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    int i, j, k, n;
    double x, y, z, w, t, u, v;
    char c;

    srand(time(NULL));

    printf("Welcome to the surreal world of arithmetic!\n");
    printf("In this world, numbers dance and equations sing.\n");
    printf("Are you ready to join the dance? (y/n) ");
    scanf("%c", &c);

    if (c == 'y' || c == 'Y')
    {
        printf("Great! Let's start with some basic arithmetic operations.\n");

        for (i = 0; i < 10; i++)
        {
            x = rand() % 100;
            y = rand() % 100;

            printf("Problem %d: %d + %d = ", i + 1, x, y);
            scanf("%d", &n);

            if (n == x + y)
            {
                printf("Correct!\n");
            }
            else
            {
                printf("Incorrect. The correct answer is %d.\n", x + y);
            }
        }

        printf("\nNow let's move on to some more advanced arithmetic.\n");

        for (j = 0; j < 5; j++)
        {
            x = rand() % 1000;
            y = rand() % 1000;
            z = rand() % 1000;

            printf("Equation %d: %d * %d + %d = ", j + 1, x, y, z);
            scanf("%d", &n);

            if (n == x * y + z)
            {
                printf("Correct!\n");
            }
            else
            {
                printf("Incorrect. The correct answer is %d.\n", x * y + z);
            }
        }

        printf("\nCongratulations! You have completed the arithmetic challenges.\n");
    }
    else
    {
        printf("That's okay. Perhaps another time.\n");
    }

    return 0;
}