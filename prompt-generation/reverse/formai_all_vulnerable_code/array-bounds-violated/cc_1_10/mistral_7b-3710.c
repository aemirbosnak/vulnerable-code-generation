//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 50

typedef struct {
    char str[SIZE];
    int is_found;
} Element;

void cSearch(char *haystack, char *needle) {
    Element arr[100];
    int i, j, k, len_needle;

    len_needle = strlen(needle);

    for (i = 0; i < 100; i++) {
        strcpy(arr[i].str, haystack + i * SIZE);
        arr[i].is_found = 0;
    }

    for (i = 0; i < 100 - len_needle; i++) {
        j = i;
        for (k = 0; k < len_needle; k++) {
            if (arr[i + k].str[k] != needle[k]) {
                j = i + k + 1;
                break;
            }
        }

        if (k == len_needle) {
            arr[i].is_found = 1;
            printf("Found at index %d\n", i);
            break;
        }
    }
}

int main() {
    char haystack[1000], needle[10];

    printf("Enter the haystack:\n");
    fgets(haystack, 1000, stdin);

    printf("Enter the needle:\n");
    fgets(needle, SIZE, stdin);

    needle[strlen(needle) - 1] = '\0';

    cSearch(haystack, needle);

    return 0;
}