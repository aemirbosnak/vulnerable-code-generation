//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MIN_INT (-2147483647)
#define MAX_INT 2147483647

typedef struct {
    int data;
    int index;
} Node;

Node array[SIZE];

void initialize() {
    int i;
    for (i = 0; i < SIZE; i++) {
        array[i].data = rand() % (MAX_INT - MIN_INT + 1) + MIN_INT;
        array[i].index = i;
    }
}

void print_array() {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i].data);
    }
    printf("\n");
}

int unique_search(int target, Node arr[], int len) {
    int start = 0, end = len - 1, mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid].data == target) {
            return arr[mid].index;
        }
        if (arr[mid].data < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int target;
    srand(time(NULL));
    initialize();
    print_array();
    printf("Enter the target value: ");
    scanf("%d", &target);
    int result = unique_search(target, array, SIZE);
    if (result != -1) {
        printf("The target value %d is found at index %d.\n", target, result);
    } else {
        printf("The target value %d is not found in the array.\n", target);
    }
    return 0;
}