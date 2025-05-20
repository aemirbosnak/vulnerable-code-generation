//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_CHARS 100

typedef struct {
    char *string;
    int length;
} String;

String createString(const char *str) {
    String s;
    s.string = (char *) malloc(strlen(str) + 1);
    strcpy(s.string, str);
    s.length = strlen(s.string);
    return s;
}

void destroyString(String *s) {
    free(s->string);
    s->string = NULL;
    s->length = 0;
}

int compareStrings(String s1, String s2) {
    return strcmp(s1.string, s2.string);
}

void swapStrings(String *s1, String *s2) {
    String temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void quickSort(String *arr, int left, int right, int (*compare)(String, String)) {
    int i = left, j = right;
    String pivot = arr[right];
    String tmp;

    while (i <= j) {
        while (compare(arr[i], pivot) < 0)
            i++;
        while (compare(arr[j], pivot) > 0)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    tmp = arr[i];
    arr[i] = arr[right];
    arr[right] = tmp;
}

int main() {
    String *arr;
    int n, i;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    arr = (String *) malloc(n * sizeof(String));

    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", arr[i].string);
        arr[i].length = strlen(arr[i].string);
    }

    quickSort(arr, 0, n - 1, compareStrings);

    printf("Sorted strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i].string);
    }

    for (i = 0; i < n; i++) {
        destroyString(&arr[i]);
    }
    free(arr);

    return 0;
}