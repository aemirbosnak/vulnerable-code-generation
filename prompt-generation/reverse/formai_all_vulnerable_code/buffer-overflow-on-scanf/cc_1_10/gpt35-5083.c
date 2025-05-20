//FormAI DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rows, cols;

    printf("Enter number of rows:");
    scanf("%d", &rows);

    printf("Enter number of columns:");
    scanf("%d", &cols);

    int table[rows][cols];

    srand(time(NULL));

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            table[i][j] = rand() % 10; //generating random numbers between 0 to 9
        }
    }

    printf("\n\nHere is your table:\n\n");

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d\t", table[i][j]);
        }

        printf("\n");
    }

    int answer;

    printf("What is the sum of the numbers in the table? ");
    scanf("%d", &answer);

    int sum = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            sum += table[i][j];
        }
    }

    if(sum == answer)
    {
        printf("Congratulations! You got the right answer.\n");
    }
    else
    {
        printf("Sorry, the correct answer is %d.\n", sum);
    }

    return 0;
}