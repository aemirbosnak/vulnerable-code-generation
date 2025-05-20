//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>

void move(int, char, char, char);

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\n");

    if (n < 1 || n > 10)
    {
        printf("Invalid number of disks. Enter a number between 1 and 10.\n");
        return 0;
    }
 
    printf("Starting Tower:\n");
    for(int i = 0; i < n; i++)
    {
        printf("|");
        for(int j = 0; j < n-i-1; j++)
            printf(" ");
        for(int j = 0; j < 2*i+1; j++)
            printf("*");
        for(int j = 0; j < n-i-1; j++)
            printf(" ");
        printf("|\n");
    }
    printf("-----\n");
    printf("A   B   C\n\n");
 
    move(n, 'A', 'B', 'C');

    printf("\n");
 
    printf("Ending Tower:\n");
    for(int i = 0; i < n; i++)
    {
        printf("|");
        for(int j = 0; j < n-i-1; j++)
            printf(" ");
        for(int j = 0; j < 2*i+1; j++)
            printf("*");
        for(int j = 0; j < n-i-1; j++)
            printf(" ");
        printf("|\n");
    }
    printf("-----\n");
    printf("A   B   C\n\n");

    return 0;
}

void move(int n, char start, char end, char spare)
{
    if (n == 1)
    {
        printf("Move disk 1 from tower %c to tower %c.\n", start, end);
        return;
    }
 
    move(n-1, start, spare, end);
    printf("Move disk %d from tower %c to tower %c.\n", n, start, end);
    move(n-1, spare, end, start);
}