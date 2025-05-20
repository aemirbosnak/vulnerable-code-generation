//FormAI DATASET v1.0 Category: Computer Biology ; Style: satisfied
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    // Find the maximum element of the array
    int max = a[0];
    for(int i=1; i<n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    printf("The maximum element of the array is %d\n", max);

    // Count the number of even elements in the array
    int count = 0;
    for(int i=0; i<n; i++) {
        if(a[i] % 2 == 0) {
            count++;
        }
    }
    printf("The number of even elements in the array is %d\n", count);

    // Calculate the sum of all elements in the array
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += a[i];
    }
    printf("The sum of all elements in the array is %d\n", sum);

    // Calculate the average of all elements in the array
    float avg = (float)sum / n;
    printf("The average of all elements in the array is %.2f\n", avg);

    // Bubble sort the array in ascending order
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("The sorted array in ascending order is: ");
    for(int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}