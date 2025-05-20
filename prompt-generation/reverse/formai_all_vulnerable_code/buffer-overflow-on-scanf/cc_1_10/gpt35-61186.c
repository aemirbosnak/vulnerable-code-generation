//FormAI DATASET v1.0 Category: Computer Biology ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program is about analyzing the DNA sequence and comparing it with other sequences. */

int main()
{
    char sequence1[100], sequence2[100];
    int i, len1, len2, differenceCount = 0;
    float matchPercentage;

    printf("Enter Sequence 1: ");
    scanf("%s", sequence1);
    printf("Enter Sequence 2: ");
    scanf("%s", sequence2);

    len1 = strlen(sequence1);
    len2 = strlen(sequence2);

    if (len1 != len2) {
        printf("Error: Sequences must have the same length.\n");
        exit(1);
    }

    for (i = 0; i < len1; i++) {
        if (sequence1[i] != sequence2[i]) {
            differenceCount++;
        }
    }

    matchPercentage = (float) (len1 - differenceCount) / len1 * 100;

    printf("Sequences:\n%-20s: %s\n%-20s: %s\n\n", "Sequence 1", sequence1, "Sequence 2", sequence2);
    printf("Length of Sequences:\n%-20s: %d\n\n", "Sequence 1", len1);
    printf("Positions with Differences:\n");

    for (i = 0; i < len1; i++) {
        if (sequence1[i] != sequence2[i]) {
            printf("%d ", i + 1);
            if (i % 13 == 0) {
                printf("\n");
            }
        }
    }

    printf("\n\nMatch Percentage: %.2f%%\n", matchPercentage);

    return 0;
}