//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: creative
#include <stdio.h>

int main() {
    int n, i, j;
    int *ptr, *ptr2, *ptr3;

    printf("Enter the number of elements to be displayed: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));
    ptr2 = (int *)malloc(n * sizeof(int));
    ptr3 = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("Elements in ascending order: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (ptr[j] > ptr[i]) {
                ptr2[j] = ptr[i];
                ptr2[i] = ptr[j];
            }
        }
    }

    printf("Elements in descending order: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (ptr2[j] > ptr2[i]) {
                ptr3[j] = ptr2[i];
                ptr3[i] = ptr2[j];
            }
        }
    }

    printf("\nElements in ascending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr3[i]);
    }
    printf("\nElements in descending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr3[n - i - 1]);
    }

    free(ptr);
    free(ptr2);
    free(ptr3);

    return 0;
}