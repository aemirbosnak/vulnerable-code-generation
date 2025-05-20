//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100

int main() {
    int num_size = 0;
    int nums[MAX_NUM] = {0};
    int i, j, k, num, max_val = 0;

    // read in the number of integers
    printf("Enter the number of integers: ");
    scanf("%d", &num_size);

    // read in the integers
    for (i = 0; i < num_size; i++) {
        printf("Enter integer #%d: ", i + 1);
        scanf("%d", &nums[i]);

        // update the maximum value
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }

    // initialize the greedy algorithm
    for (i = 0; i < num_size; i++) {
        nums[i] = -1;
    }

    // find the largest sum of non-adjacent numbers
    int sum = 0;
    for (i = 0; i < num_size; i++) {
        if (nums[i] > 0) {
            int max_sum = 0;
            for (j = i + 1; j < num_size; j++) {
                if (nums[j] > 0) {
                    k = j - i;
                    if (k > max_val) {
                        break;
                    }
                    if (k == 0) {
                        if (nums[j] > max_sum) {
                            max_sum = nums[j];
                        }
                    } else {
                        if (nums[j] > max_sum) {
                            max_sum = nums[j];
                        }
                    }
                }
            }
            if (max_sum > 0) {
                nums[i] = max_sum;
                sum += max_sum;
            }
        }
    }

    printf("The largest sum of non-adjacent numbers is: %d\n", sum);

    return 0;
}