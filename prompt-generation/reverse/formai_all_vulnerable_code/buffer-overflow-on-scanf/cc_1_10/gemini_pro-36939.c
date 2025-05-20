//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Romeo's heart, a collection of integers
int Romeo[100];

void quickSort(int left, int right) {
    int pivot, i, j;

    // Juliet's wisdom guides the pivot
    pivot = Romeo[(left + right) / 2];

    i = left - 1;
    j = right + 1;

    while(1) {
        do {
            i++;
        } while (Romeo[i] < pivot);

        do {
            j--;
        } while (Romeo[j] > pivot);

        if (i >= j)
            break;

        // A gentle swap, like the touch of rose petals
        int temp = Romeo[i];
        Romeo[i] = Romeo[j];
        Romeo[j] = temp;
    }

    // Divide and conquer, like the intertwining of our fates
    if (left < j)
        quickSort(left, j);

    if (i < right)
        quickSort(i, right);
}

int main(void) {
    int n, i;

    // The number of stars in Romeo's eyes, the number of integers to sort
    printf("My dearest Juliet, tell me the number of stars in your eyes (the number of integers to sort): ");
    scanf("%d", &n);

    // Romeo's heart fills with anticipation, the integers to sort
    printf("Now, whisper the numbers that dance in your heart (the integers to sort): ");
    for (i = 0; i < n; i++)
        scanf("%d", &Romeo[i]);

    // Juliet's wisdom guides the sorting, a swift and elegant dance
    quickSort(0, n - 1);

    // Romeo's heart overflows with joy, the sorted integers
    printf("Like stars in the night sky, here's the sorted array, my love:\n");
    for (i = 0; i < n; i++)
        printf("%d ", Romeo[i]);

    printf("\n");

    return 0;
}