//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void bucket_sort(char **arr, int n) {
    int i, j, k, count = 0, bucket[MAX] = {0};
    char **temp_arr = NULL;

    temp_arr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        temp_arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
        bucket[arr[i][0]]++;
    }

    for (i = 0; i < MAX; i++) {
        if (bucket[i] > 0) {
            count++;
        }
    }

    arr = (char **)realloc(arr, count * sizeof(char *));

    k = 0;
    for (i = 0; i < MAX; i++) {
        if (bucket[i] > 0) {
            for (j = 0; j < bucket[i]; j++) {
                strcpy(arr[k++], temp_arr[i]);
            }
        }
    }

    free(temp_arr);

    return;
}

int main() {
    char **arr = NULL;
    int n = 0;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    bucket_sort(arr, n);

    printf("Sorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    free(arr);

    return 0;
}