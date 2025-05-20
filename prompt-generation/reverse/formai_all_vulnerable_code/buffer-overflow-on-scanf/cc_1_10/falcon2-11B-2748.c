//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a list of numbers
void print_list(int* list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Function to find the minimum value in a list
int find_min(int* list, int size) {
    int min_val = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i] < min_val) {
            min_val = list[i];
        }
    }
    return min_val;
}

// Function to find the maximum value in a list
int find_max(int* list, int size) {
    int max_val = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i] > max_val) {
            max_val = list[i];
        }
    }
    return max_val;
}

// Function to find the median value in a list
int find_median(int* list, int size) {
    if (size % 2 == 0) {
        int median_val = (find_max(list, size) + find_min(list, size)) / 2;
        return median_val;
    } else {
        return find_max(list, size);
    }
}

int main() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    int* list = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    printf("Minimum value: %d\n", find_min(list, size));
    printf("Maximum value: %d\n", find_max(list, size));
    printf("Median value: %d\n", find_median(list, size));

    free(list);
    return 0;
}