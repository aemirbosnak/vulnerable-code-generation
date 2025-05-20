//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char *search(char *arr, int size, char *key) {
    int i, j;
    for (i = 0; i < size; i++) {
        if (strncmp(arr[i], key, strlen(key)) == 0) {
            return arr[i];
        }
    }
    return NULL;
}

int main() {
    int i, j, n;
    char **arr;
    char key[MAX_SIZE];
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    arr = (char **)malloc(n * sizeof(char *));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
        if (arr[i] == NULL) {
            printf("Memory error\n");
            exit(1);
        }
        printf("Enter string %d: ", i + 1);
        scanf("%s", arr[i]);
    }
    printf("Enter the search key: ");
    scanf("%s", key);
    char *result = search(arr, n, key);
    if (result!= NULL) {
        printf("Found %s at index %d\n", result, index);
    } else {
        printf("Not found\n");
    }
    for (i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}