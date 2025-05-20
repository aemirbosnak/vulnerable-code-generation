//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void printSeq(char seq[], int length);
void generateSeq(char seq[], int length);

int main()
{
    char sequence[SIZE];
    int seqLength;

    srand(time(NULL));

    printf("Welcome to the Genome Sequencing Simulator!\n\n");

    printf("How long do you want the sequence to be? (maximum %d): ", SIZE);
    scanf("%d", &seqLength);

    if (seqLength > SIZE)
    {
        printf("Sorry, length must be maximum %d.\n", SIZE);
        return 0;
    }

    printf("Generating a random sequence of %d nucleotides...\n", seqLength);

    generateSeq(sequence, seqLength);

    printf("\nSequence generated:\n");
    printSeq(sequence, seqLength);

    printf("\n\nThank you for using the Genome Sequencing Simulator!");

    return 0;
}

void generateSeq(char seq[], int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        switch (rand() % 4)
        {
            case 0:
                seq[i] = 'A';
                break;
            case 1:
                seq[i] = 'C';
                break;
            case 2:
                seq[i] = 'G';
                break;
            case 3:
                seq[i] = 'T';
                break;
        }
    }
}

void printSeq(char seq[], int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        printf("%c", seq[i]);
    }
}