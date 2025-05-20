//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

void fibonacci(int num)
{
    int a = 0, b = 1, c = 0;
    printf("%d %d ", a, b);
    for(int i = 3; i <= num; i++)
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

void drawPyramid(int num)
{ 
    int currentRow = 1; 
    int rowsToDraw = 1;

    //Loop through all the rows we need to draw
    while(rowsToDraw <= num)
    {
        //Draw spaces on the row
        for(int i = 1; i <= num - rowsToDraw; i++)
        {
            printf(" ");
        }

        //Draw the numbers on the row
        for(int i = 1; i <= rowsToDraw; i++)
        {
            printf("%d ", i);
        }
        
        //Draw spaces before the fibonacci numbers
        int spacesBeforeFib = rowsToDraw * 2;
        for(int i = 1; i <= spacesBeforeFib; i++)
        {
            printf(" ");
        }

        //Print the fibonacci sequence for this row
        fibonacci(rowsToDraw);

        printf("\n");

        //Move on to the next row
        rowsToDraw++;
        currentRow++;
    }
}

int main()
{ 
    int num; 
    printf("Enter the number of rows: ");
    scanf("%d", &num);

    drawPyramid(num);

    return 0;
}