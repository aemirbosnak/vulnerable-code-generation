//Code Llama-13B DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
// C program to find the minimum number of platforms required on a railroad track
// to run the maximum number of trains

#include <stdio.h>

int main()
{
    // number of trains
    int n = 5;
    // arrival and departure times of trains
    int arr[] = {0, 1, 3, 4, 6};
    int dep[] = {1, 3, 4, 6, 9};

    // maximum number of trains that can be run simultaneously
    int maxTrains = 0;
    // minimum number of platforms required
    int minPlatforms = 0;

    // sort arrival and departure times in increasing order
    // using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                temp = dep[j];
                dep[j] = dep[j + 1];
                dep[j + 1] = temp;
            }
        }
    }

    // find the maximum number of trains that can be run simultaneously
    // by comparing arrival and departure times
    for (int i = 0; i < n; i++) {
        if (dep[i] <= arr[i + 1]) {
            maxTrains++;
        }
    }

    // find the minimum number of platforms required
    // by comparing the arrival and departure times of trains
    for (int i = 0; i < n; i++) {
        if (dep[i] <= arr[i + 1]) {
            minPlatforms++;
        }
    }

    // print the output
    printf("The minimum number of platforms required is %d\n", minPlatforms);
    printf("The maximum number of trains that can be run simultaneously is %d\n", maxTrains);

    return 0;
}