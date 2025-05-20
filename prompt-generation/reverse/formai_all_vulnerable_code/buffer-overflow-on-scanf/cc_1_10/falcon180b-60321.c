//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_SEARCH_SIZE 100

int main() {
    char arr[MAX_SIZE];
    char search[MAX_SEARCH_SIZE];
    int size, search_size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%s", &arr[i]);
    }

    printf("Enter the size of the search string: ");
    scanf("%d", &search_size);

    printf("Enter the search string: ");
    scanf("%s", &search);

    int index = search_array(arr, search, size);

    if (index == -1) {
        printf("The search string was not found in the array.\n");
    } else {
        printf("The search string was found at index %d.\n", index);
    }

    return 0;
}

int search_array(char arr[], char search[], int size) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < size && j < strlen(search)) {
        if (arr[i] == search[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }

    if (j == strlen(search)) {
        return i - j;
    } else {
        return -1;
    }
}