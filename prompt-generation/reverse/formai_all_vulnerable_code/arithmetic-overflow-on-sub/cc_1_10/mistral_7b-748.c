//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define MAX 100

typedef struct {
    int num;
    char name[20];
} Element;

void print_arr(Element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\n%d. %s: %d", i + 1, arr[i].name, arr[i].num);
    }
}

void happy_bubble_sort(Element arr[], int size) {
    int swapped;
    int j;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j].num > arr[j + 1].num) {
                Element temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                printf("\n%s and %s did a happy swap!", arr[j].name, arr[j + 1].name);
                swapped = 1;

                usleep(500000); // Add a short delay to simulate a happy moment
            }
        }
        if (!swapped) {
            printf("\n%s is happy because the array is already sorted!\n", arr[i].name);
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    Element arr[MAX];
    int size;

    printf("\n%s\n", "------------------------ Happy Bubble Sort ------------------------");

    printf("\n%s\n", "Enter the number of elements:");
    scanf("%d", &size);

    printf("\n%s\n", "Enter names for the elements:");

    for (int i = 0; i < size; i++) {
        scanf("%s", arr[i].name);
        arr[i].num = rand() % 100;
    }

    printf("\n%s\n", "Before sorting:");
    print_arr(arr, size);

    happy_bubble_sort(arr, size);

    printf("\n%s\n", "After sorting:");
    print_arr(arr, size);

    return 0;
}