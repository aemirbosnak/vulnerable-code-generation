//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include <stdio.h>

void printStar(int num);

void printSpaces(int num);

void printPattern(int row, int col, int size);

int main()
{
    int size;

    printf("Enter size of pattern: ");
    scanf("%d", &size);

    printPattern(0, 0, size);

    return 0;
}

void printStar(int num)
{
    if (num == 0)
        return;

    printf("*");

    printStar(num - 1);
}

void printSpaces(int num)
{
    if (num == 0)
        return;

    printf(" ");

    printSpaces(num - 1);
}

void printPattern(int row, int col, int size)
{
    if (row == size)
        return;

    if (col < (size - row - 1))
    {
        printf(" ");

        printPattern(row, col + 1, size);
    }
    else
    {
        printStar(2 * row + 1);

        printf("\n");

        printPattern(row + 1, 0, size);
    }
}