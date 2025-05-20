//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
/* Statistical Memory Management Program */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, sum = 0;
    float mean, sd, variance = 0;

    printf("Enter the number of integers you want to store: ");
    scanf("%d", &n);

    /* Allocate memory dynamically */
    int *arr = (int*) malloc(n * sizeof(int));

    if(arr == NULL) {
        printf("Memory allocation failed. Please try again.\n");
        return 0;
    }

    /* Input the integers from the user */
    printf("Enter %d integers:\n", n);

    for(i=0; i < n; i++) {
        scanf("%d", arr + i);
        sum += *(arr + i);
    }
    
    /* Calculate Mean */
    mean = (float)sum/n;

    /* Calculate Variance */
    for(i=0; i<n; i++) {
        variance += (*(arr + i) - mean) * (*(arr + i) - mean);
    }
    
    variance /= n;

    /* Calculate Standard Deviation */
    sd = sqrt(variance);

    /* Output the results */
    printf("The mean of the given integers is: %.2f\n", mean);
    printf("The variance of the given integers is: %.2f\n", variance);
    printf("The standard deviation of the given integers is: %.2f\n", sd);

    /* Free memory */
    free(arr);

    return 0;
}