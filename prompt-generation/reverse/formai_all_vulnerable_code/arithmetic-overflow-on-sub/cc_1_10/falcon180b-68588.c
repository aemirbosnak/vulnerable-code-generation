//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 1000000

typedef struct {
    int value;
    int count;
} IntPair;

void count_pairs(IntPair* pairs, int num_pairs, int target) {
    if (num_pairs == 0) {
        return;
    }

    IntPair current_pair = pairs[num_pairs - 1];
    int current_value = current_pair.value;
    int current_count = current_pair.count;

    if (current_value == target) {
        current_count++;
    } else if (current_value < target) {
        current_value++;
        current_count = 1;
    } else {
        return;
    }

    pairs[num_pairs - 1].value = current_value;
    pairs[num_pairs - 1].count = current_count;

    count_pairs(pairs, num_pairs - 1, target);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <target_value>\n", argv[0]);
        return 1;
    }

    int target_value = atoi(argv[1]);
    int num_pairs = 0;

    IntPair* pairs = malloc(sizeof(IntPair));
    pairs[num_pairs].value = 1;
    pairs[num_pairs].count = 1;

    struct timespec start_time, end_time;
    clock_gettime(CLOCK_REALTIME, &start_time);

    count_pairs(pairs, num_pairs, target_value);

    clock_gettime(CLOCK_REALTIME, &end_time);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;

    printf("Found %d pairs with value %d in %.6f seconds.\n", pairs[num_pairs].count, target_value, elapsed_time);

    free(pairs);
    return 0;
}