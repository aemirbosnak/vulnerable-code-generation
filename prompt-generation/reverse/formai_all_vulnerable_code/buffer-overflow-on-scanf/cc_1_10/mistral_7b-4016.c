//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMS 100000
#define MIN_ELEM 0
#define MAX_ELEM 1000

typedef struct {
    int data;
    int index;
} Element;

Element arr[MAX_ELEMS];
int target;
int found = -1;
int num_elements = 0;

void generate_random_array(void) {
    int i;

    for (i = 0; i < MAX_ELEMS; i++) {
        arr[i].data = rand() % (MAX_ELEM - MIN_ELEM + 1) + MIN_ELEM;
        arr[i].index = i;
        num_elements++;
    }
}

void print_array(void) {
    int i;

    printf("\nArray elements:\n");
    for (i = 0; i < num_elements; i++) {
        printf("Element %d: %d\n", arr[i].index, arr[i].data);
    }
}

int binary_search(int left, int right) {
    int mid;

    if (right >= left) {
        mid = left + (right - left) / 2;

        if (arr[mid].data == target) {
            found = arr[mid].index;
            return 1;
        }

        if (arr[mid].data < target) {
            return binary_search(mid + 1, right);
        }

        return binary_search(left, mid - 1);
    }

    return -1;
}

int main() {
    srand(time(NULL));

    printf("Enter target element: ");
    scanf("%d", &target);

    generate_random_array();
    print_array();

    clock_t start = clock();
    binary_search(0, num_elements - 1);
    clock_t end = clock();

    if (found != -1) {
        printf("Element %d found at index %d\n", target, found);
        printf("Search time: %.6f ms\n", (end - start) * 1000.0 / CLOCKS_PER_SEC);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}