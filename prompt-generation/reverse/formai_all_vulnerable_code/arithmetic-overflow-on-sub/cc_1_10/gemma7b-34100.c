//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <time.h>

int main()
{
    int i, j, n, t, score = 0;
    char str[100];

    time_t start, end;

    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    for (i = 0; i < t; i++)
    {
        printf("Enter a string: ");
        scanf("%s", str);

        start = clock();
        for (j = 0; str[j] != '\0'; j++)
        {
            switch (str[j])
            {
                case 'a':
                    score++;
                    break;
                case 'e':
                    score++;
                    break;
                case 'i':
                    score++;
                    break;
                case 'o':
                    score++;
                    break;
                case 'u':
                    score++;
                    break;
                default:
                    break;
            }
        }
        end = clock();

        printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
        printf("Number of characters typed: %d\n", score);
        printf("Score: %d\n", score * 5);
        printf("\n");
    }

    return 0;
}