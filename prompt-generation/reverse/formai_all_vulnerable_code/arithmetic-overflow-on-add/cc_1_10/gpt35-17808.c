//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//generate surreal numbers as fibonacci sequence limit
int surreal_fib(int limit)
{
    int i, j, sum, surreal_num;
    i = 0;
    j = 1;
    surreal_num = i + j;
    for (int c = 3; c <= limit; c++)
    {
        sum = i + j;
        i = j;
        j = sum;
        surreal_num += abs(sum - surreal_num); //adds sum of absolute differences to surreal number
    }
    return surreal_num;
}

//draw surreal fibonacci sequence using ASCII art
void draw_fibonacci(int num)
{
    int a = 0, b = 1, c;
    for (int i = 1; i <= num; i++)
    {
        c = a + b;
        a = b;
        b = c;
        //generate random ASCII character for each number in sequence
        char ascii_char = 33 + (rand() % 94);
        printf("%c ", ascii_char);
        //break line for easier visualization of sequence
        if (i % 7 == 0)
        {
            printf("\n");
        }
    }
}

int main()
{
    //initialize pseudorandom number generator
    srand(time(NULL));
    //call surreal fibonacci function with limit of 20
    int surreal_num = surreal_fib(20);
    printf("Surreal number: %d\n\nSurreal fibonacci sequence:\n", surreal_num);
    //call ASCII art fibonacci sequence function with surreal number as parameter
    draw_fibonacci(surreal_num);
    return 0;
}