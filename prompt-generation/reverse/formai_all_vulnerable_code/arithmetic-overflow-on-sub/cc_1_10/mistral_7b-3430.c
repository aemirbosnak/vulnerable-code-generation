//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    char name[20];
} Element;

void jokeSort(Element arr[], int n) {
    int i, j, tempData, tempNameLength;
    Element temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].data > arr[j + 1].data) {
                // Swap data
                tempData = arr[j].data;
                arr[j].data = arr[j + 1].data;
                arr[j + 1].data = tempData;

                // Swap names (in a funny way)
                tempNameLength = strlen(arr[j].name);
                strncpy(temp.name, arr[j].name, tempNameLength + 1);
                strncpy(arr[j].name, arr[j + 1].name, tempNameLength + 1);
                strncpy(arr[j + 1].name, temp.name, tempNameLength + 1);
            }
        }
    }
}

int main() {
    Element arr[MAX];
    int n, i;

    printf("Welcome to the Joke Sorting Algorithm!\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the data and name of each element:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %s", &arr[i].data, arr[i].name);
    }

    jokeSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].data, arr[i].name);
    }

    return 0;
}