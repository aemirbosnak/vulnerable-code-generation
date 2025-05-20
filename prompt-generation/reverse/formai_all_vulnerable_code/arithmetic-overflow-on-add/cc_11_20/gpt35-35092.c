//FormAI DATASET v1.0 Category: Funny ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int sizeA, sizeB;

    printf("Enter the size of array A: ");
    scanf("%d", &sizeA);

    int arrA[sizeA];

    printf("Enter the elements of array A:\n");
    for (int i = 0; i < sizeA; i++) {
        scanf("%d", &arrA[i]);
    }

    printf("\nEnter the size of array B: ");
    scanf("%d", &sizeB);

    int arrB[sizeB];

    printf("Enter the elements of array B:\n");
    for (int i = 0; i < sizeB; i++) {
        scanf("%d", &arrB[i]);
    }

    printf("\n\nArray A:");

    for (int i = 0; i < sizeA; i++) {
        printf("%d ", arrA[i]);
    }

    printf("\nArray B:");

    for (int i = 0; i < sizeB; i++) {
        printf("%d ", arrB[i]);
    }

    printf("\n\nSorting array A in ascending order...\n");
    for (int i = 0; i < sizeA - 1; i++) {
        for (int j = i + 1; j < sizeA; j++) {
            if (arrA[i] > arrA[j]) {
                int temp = arrA[i];
                arrA[i] = arrA[j];
                arrA[j] = temp;
            }
        }
    }

    printf("\nSorted array A:\n");
    for (int i = 0; i < sizeA; i++) {
        printf("%d ", arrA[i]);
    }

    printf("\n\nSorting array B in ascending order...\n");
    for (int i = 0; i < sizeB - 1; i++) {
        for (int j = i + 1; j < sizeB; j++) {
            if (arrB[i] > arrB[j]) {
                int temp = arrB[i];
                arrB[i] = arrB[j];
                arrB[j] = temp;
            }
        }
    }

    printf("\nSorted array B:\n");
    for (int i = 0; i < sizeB; i++) {
        printf("%d ", arrB[i]);
    }

    printf("\n\nMerging arrays...\n");
    int sizeC = sizeA + sizeB;
    int arrC[sizeC];
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (arrA[i] < arrB[j]) {
            arrC[k] = arrA[i];
            i++;
        }
        else {
            arrC[k] = arrB[j];
            j++;
        }
        k++;
    }

    while (i < sizeA) {
        arrC[k] = arrA[i];
        i++;
        k++;
    }

    while (j < sizeB) {
        arrC[k] = arrB[j];
        j++;
        k++;
    }

    printf("\nMerged array:\n");
    for (int i = 0; i < sizeC; i++) {
        printf("%d ", arrC[i]);
    }

    printf("\n\nCalculating mean of merged array...\n");
    int sum = 0;
    for (int i = 0; i < sizeC; i++) {
        sum += arrC[i];
    }
    float mean = (float)sum / sizeC;
    printf("\nMean of merged array: %.2f", mean);

    printf("\n\nExiting...\n");
    return 0;
}