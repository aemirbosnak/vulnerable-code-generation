//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>

int main()
{
    int n, i, j, k, l, m, sum = 0, avg = 0;
    float average, fsum = 0.0f;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for student marks
    int *marks = (int *)malloc(n * sizeof(int));

    // Get student marks
    for (i = 0; i < n; i++)
    {
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    // Calculate the total sum of marks
    for (i = 0; i < n; i++)
    {
        sum += marks[i];
    }

    // Calculate the average mark
    average = (float)sum / n;

    // Calculate the cumulative frequency of marks
    int *freq = (int *)malloc(n * sizeof(int));
    freq[0] = 1;
    for (i = 1; i < n; i++)
    {
        freq[i] = freq[i - 1] + 1;
    }

    // Print the results
    printf("\nThe total sum of marks is: %d", sum);
    printf("\nThe average mark is: %.2f", average);
    printf("\nThe cumulative frequency of marks is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", freq[i]);
    }

    // Free memory
    free(marks);
    free(freq);

    return 0;
}