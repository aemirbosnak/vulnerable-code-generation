//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

/* Define the number of buckets */
#define BUCKET_SIZE 10

/* Define the maximum number of digits in the input */
#define MAX_DIGITS 100000

/* Define a structure to hold each bucket's size and contents */
typedef struct {
    int size;
    int* contents;
} Bucket;

/* Define a helper function to initialize a bucket */
Bucket initBucket() {
    Bucket bucket = {0, NULL};
    bucket.contents = calloc(BUCKET_SIZE, sizeof(int));
    return bucket;
}

/* Define the bucket sort function */
void bucketSort(int* input, int size) {
    
    /* Create the buckets */
    Bucket buckets[BUCKET_SIZE];
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = initBucket();
    }
    
    /* Calculate the maximum value in the input */
    int max = input[0];
    for (int i = 1; i < size; i++) {
        if (input[i] > max) max = input[i];
    }
    
    /* Calculate the number of digits in the maximum value */
    int num_digits = 0;
    while (max > 0) {
        max /= 10;
        num_digits++;
    }
    
    /* Put each element into the appropriate bucket */
    for (int digit = 1; digit <= num_digits; digit++) {
        for (int i = 0; i < size; i++) {
            int current_digit = (input[i] / (int)pow(10, digit-1)) % 10;
            buckets[current_digit].contents[buckets[current_digit].size++] = input[i];
        }
        
        /* Copy the contents of the buckets back into the input */
        int j = 0;
        for (int i = 0; i < BUCKET_SIZE; i++) {
            for (int k = 0; k < buckets[i].size; k++) {
                input[j++] = buckets[i].contents[k];
            }
            buckets[i].size = 0;
        }
    }
    
    /* Free the contents of each bucket */
    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i].contents);
    }
}

/* Main function for testing */
int main() {
    int input[MAX_DIGITS];
    int size;
    
    /* Get input from the user */
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &input[i]);
    }
    
    /* Sort the input using bucket sort */
    bucketSort(input, size);
    
    /* Print the sorted array */
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");
    
    return 0;
}