//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Bucket Sorter!\n");
    printf("Please enter the size of the array you want to sort: ");

    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Sorry, we cannot sort an array of size less than or equal to 0.\n");
        return 0;
    }

    int arr[n];

    printf("Great! Now please enter the %d elements of the array: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Excellent! Initiating the Sort-o-tron 3000...\n");
    
    int max_number = arr[0];
    int min_number = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > max_number) {
            max_number = arr[i];
        } 
        else if (arr[i] < min_number) {
            min_number = arr[i];
        }
    }

    printf("The maximum number in the array is %d, and the minimum number is %d.\n", max_number, min_number);

    printf("It's time to do the ol' bucket sort!\n");
    printf("Creating buckets...\n");

    int num_buckets = (max_number - min_number) / n;

    if (num_buckets <= 0) {
        num_buckets = 1;
    }

    printf("We need %d buckets for this sorting extravaganza!\n", num_buckets);

    int buckets[num_buckets][n];
    int bucket_count[num_buckets];

    for (int i = 0; i < num_buckets; i++) {
        bucket_count[i] = 0;
    }

    printf("Bucket filling commencing...\n");

    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_number) / n;

        buckets[bucket_index][bucket_count[bucket_index]] = arr[i];
        bucket_count[bucket_index]++;
    }

    printf("Buckets filled! Time to spill the beans...\n");

    int index = 0;

    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_count[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }

    printf("Sorting complete! The final array is:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}