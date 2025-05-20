//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50000

int main()
{
    srand(time(NULL));

    char genome[N];
    int i, j, seqLength, maxSeq, count;
    int A, G, C, T;

    A = G = C = T = 0;
    count = 0;

    printf("Enter the length of genome sequence: ");
    scanf("%d", &seqLength);

    for (i = 0; i < seqLength; i++) {
        int base = rand() % 4;
        if (base == 0) {
            genome[i] = 'A';
            A++;
        }
        else if (base == 1) {
            genome[i] = 'G';
            G++;
        }
        else if (base == 2) {
            genome[i] = 'C';
            C++;
        }
        else if (base == 3) {
            genome[i] = 'T';
            T++;
        }
    }

    printf("Genome sequence: \n%s\n", genome);
    printf("Total length of sequence: %d\n", seqLength);
    printf("A: %d, G: %d, C: %d, T: %d\n", A, G, C, T);

    maxSeq = 0;

    for (i = 0; i < seqLength - 1; i++) {
        int orig = i;
        count = 0;
        while (genome[i] == genome[i + 1]) {
            count++;
            i++;
        }
        if (count > maxSeq)
            maxSeq = count;
        if (count > 0) {
            printf("Sequence %d count: %d\n", orig + 1, count + 1);
            printf("Position %d to %d\n", orig + 1, i + 1);
            printf("Sequence: ");
            for (j = orig; j < i + 1; j++)
                printf("%c", genome[j]);
            printf("\n");
        }
    }

    if (maxSeq > 0)
        printf("The longest sequence length: %d\n", maxSeq + 1);

    return 0;
}