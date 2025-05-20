//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 100

void printSequence(int sequence[], int length);

int main()
{
    int sequence[MAX_SEQUENCE_LENGTH];
    int length, index;

    printf("Enter the number of Fibonacci sequence elements to be generated:\n");
    scanf("%d", &length);

    if (length > MAX_SEQUENCE_LENGTH)
    {
        printf("Error: Sequence length exceeds maximum allowed (%d)\n", MAX_SEQUENCE_LENGTH);
        return 1;
    }

    if (length < 1)
    {
        printf("Error: Invalid sequence length: %d\n", length);
        return 1;
    }

    sequence[0] = 0;
    sequence[1] = 1;

    printf("\n\n");
    printSequence(sequence, length);

    for (index = 2; index < length; index++)
    {
        sequence[index] = sequence[index - 1] + sequence[index - 2];

        printf("\n");
        printSequence(sequence, index + 1);
    }

    return 0;
}

void printSequence(int sequence[], int length)
{
    int index;

    for (index = 0; index < length; index++)
    {
        printf("%d", sequence[index]);

        if (index != length - 1)
        {
            printf(", ");
        }
    }

    printf("\n");
}