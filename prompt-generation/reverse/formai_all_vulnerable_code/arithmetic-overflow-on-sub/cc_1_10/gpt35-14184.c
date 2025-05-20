//FormAI DATASET v1.0 Category: Benchmarking ; Style: Romeo and Juliet
//A Benchmarking tale of Romeo and Juliet

#include <stdio.h>
#include <time.h>

int main() {

    printf("\n\nOnce upon a time, in the land of Benchmarking...\n\n");

    printf("Romeo, a benchmarking enthusiast, came to the town square to show off his benchmarking skills.\n");
    printf("He challenged the citizens of the town to write a program that can calculate the nth Fibonacci number.\n\n");

    printf("With his trusty stopwatch in hand, Romeo waited eagerly for the programmers to complete their code.\n");
    printf("As the first programmer came forward to test their code, Romeo clicked the stopwatch and started timing the program.\n\n");
    
    clock_t start = clock();

    /************Program to calculate the nth Fibonacci number****************/
    int n = 15;
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

    for(int i=2; i<=n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    /***********************************************************************/

    clock_t stop = clock();

    printf("The program took %f seconds to execute.\n", (double)(stop - start) / CLOCKS_PER_SEC);

    printf("\nImpressed by Romeo's benchmarking skills, a beautiful programmer named Juliet approached him.");
    printf("She challenged Romeo to write a program to find the factorial of a number.\n");

    printf("Romeo, with a twinkle in his eyes, agreed to the challenge.\n");
    printf("He quickly wrote the program and ran it.\n\n");

    start = clock();
    
    /************Program to calculate the factorial of a number****************/
    int num = 5;
    int fact = 1;

    for(int i=1; i<=num; i++)
    {
        fact *= i;
    }
    /***************************************************************************/

    stop = clock();

    printf("The program took %f seconds to execute.\n", (double)(stop - start) / CLOCKS_PER_SEC);
    printf("\n\nThus, Romeo and Juliet lived happily ever after in the land of Benchmarking!\n");

    return 0;
}