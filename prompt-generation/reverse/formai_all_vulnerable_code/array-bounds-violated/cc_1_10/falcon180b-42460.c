//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define max_size 1000
#define max_tries 1000

int main() {
    int size, tries = 0;
    double list[max_size];
    double target;
    int index;
    srand(time(NULL));

    // Get size of list from user
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    // Generate random list of doubles
    for (int i = 0; i < size; i++) {
        list[i] = rand() % 1000 / 1000.0;
    }

    // Get target value from user
    printf("Enter the target value: ");
    scanf("%lf", &target);

    // Binary search algorithm
    int start = 0;
    int end = size - 1;

    while (tries < max_tries) {
        int mid = (start + end) / 2;

        if (list[mid] == target) {
            printf("Found target value at index %d\n", mid);
            return 0;
        }

        if (list[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        tries++;
    }

    printf("Target value not found in list.\n");
    return 0;
}