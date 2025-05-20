//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the puzzling program!\n");
    printf("Enter the size of the array:\n");
    int size;
    scanf("%d", &size);
    int arr[size];
    printf("Enter the %d elements of the array:\n", size);
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    int max = 0;
    int max_index = -1;
    printf("Choose 'a' for finding maximum sum subarray or 'b' for finding maximum sum subarray with at least 3 elements:\n");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'a') {
        // Kadane's algorithm
        for(int i=0; i<size; i++) {
            sum += arr[i];
            if(sum < 0) {
                sum = 0;
            }
            if(sum > max) {
                max = sum;
            }
        }
        printf("Maximum sum subarray: %d\n", max);
    } else if(choice == 'b') {
        // Custom algorithm
        for(int i=0; i<size; i++) {
            sum += arr[i];
            if(sum < 0) {
                sum = 0;
            }
            if(sum >= max) {
                max = sum;
                max_index = i;
            }
        }
        sum = max;
        int left_sum = 0;
        int left_max = 0;
        for(int i=max_index-1; i>=0; i--) {
            left_sum += arr[i];
            if(left_sum < 0) {
                left_sum = 0;
            }
            if(left_sum > left_max) {
                left_max = left_sum;
            }
        }
        sum += left_max;
        int right_sum = 0;
        int right_max = 0;
        for(int i=max_index+1; i<size; i++) {
            right_sum += arr[i];
            if(right_sum < 0) {
                right_sum = 0;
            }
            if(right_sum > right_max) {
                right_max = right_sum;
            }
        }
        sum += right_max;
        printf("Maximum sum subarray with at least 3 elements: %d\n", sum);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }
    return 0;
}