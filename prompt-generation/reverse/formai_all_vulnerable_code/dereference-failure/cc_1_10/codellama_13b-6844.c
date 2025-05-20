//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
/*
 * Decentralized Bucket Sort Implementation
 *
 * Author: [Your Name]
 * Date:   [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BUCKETS 10
#define MAX_NUM 100

typedef struct {
    int num;
    int bucket;
} num_t;

int compare_nums(const void *a, const void *b) {
    num_t *num_a = (num_t *)a;
    num_t *num_b = (num_t *)b;
    return num_a->num - num_b->num;
}

void bucket_sort(num_t *nums, int num_count) {
    // Initialize the buckets
    int buckets[NUM_BUCKETS] = {0};

    // Count the number of elements in each bucket
    for (int i = 0; i < num_count; i++) {
        int bucket = nums[i].bucket;
        buckets[bucket]++;
    }

    // Sort the elements in each bucket
    for (int i = 0; i < NUM_BUCKETS; i++) {
        num_t *bucket_nums = malloc(buckets[i] * sizeof(num_t));
        int j = 0;
        for (int k = 0; k < num_count; k++) {
            if (nums[k].bucket == i) {
                bucket_nums[j++] = nums[k];
            }
        }
        qsort(bucket_nums, buckets[i], sizeof(num_t), compare_nums);
        for (int k = 0; k < buckets[i]; k++) {
            nums[k] = bucket_nums[k];
        }
        free(bucket_nums);
    }
}

int main() {
    srand(time(NULL));
    int num_count = 100;
    num_t *nums = malloc(num_count * sizeof(num_t));
    for (int i = 0; i < num_count; i++) {
        nums[i].num = rand() % MAX_NUM;
        nums[i].bucket = rand() % NUM_BUCKETS;
    }

    bucket_sort(nums, num_count);

    for (int i = 0; i < num_count; i++) {
        printf("%d ", nums[i].num);
    }
    printf("\n");

    free(nums);
    return 0;
}