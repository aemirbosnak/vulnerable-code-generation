//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int num1, num2, operator, answer, result;
    srand(time(0));

    printf("Welcome to the Surprise Math Exercise program!\n\n");
    printf("Get ready for some math challenges!\n\n");

    for(int i=0; i<10; i++) 
    {
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;
        operator = rand() % 4;

        switch(operator)
        {
            case 0:
                printf("%d + %d = ?\n", num1, num2);
                answer = num1 + num2;
                break;

            case 1:
                printf("%d - %d = ?\n", num1, num2);
                answer = num1 - num2;
                break;

            case 2:
                printf("%d * %d = ?\n", num1, num2);
                answer = num1 * num2;
                break;

            case 3:
                printf("%d / %d = ? (round down)\n", num1, num2);
                answer = num1 / num2;
                break;
        }

        scanf("%d", &result);

        if(result == answer)
        {
            printf("Congratulations, you got it right!\n");
        }
        else
        {
            printf("Sorry, the correct answer is %d.\n", answer);
        }
    }

    printf("\nWow, you made it to the end!\n");
    printf("Thanks for playing and keep practicing math!\n");

    return 0;
}