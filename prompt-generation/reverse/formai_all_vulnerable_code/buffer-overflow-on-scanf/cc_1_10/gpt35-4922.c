//FormAI DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_statistics(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    double mean = (double)sum / size;
    printf("Mean: %.2f\n", mean);

    int max = arr[0], min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    double std_dev = 0;
    for (int i = 0; i < size; i++) {
        std_dev += pow((double)arr[i] - mean, 2);
    }
    std_dev = sqrt(std_dev / size);
    printf("Standard deviation: %.2f\n", std_dev);

    // Find mode
    int freq[size];
    for (int i = 0; i < size; i++) {
        freq[i] = 1;
    }
    int max_freq = 0, mode = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                freq[i]++;
            }
        }
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            mode = arr[i];
        }
    }
    if (max_freq == 1) {
        printf("No mode found.\n");
    } else {
        printf("Mode: %d\n", mode);
        printf("Frequency: %d\n", max_freq);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    print_statistics(arr, size);
    return 0;
}