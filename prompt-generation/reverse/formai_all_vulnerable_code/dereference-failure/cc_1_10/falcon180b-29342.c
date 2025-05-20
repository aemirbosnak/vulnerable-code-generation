//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <float.h>

#define MAX_SIZE 100000000

typedef struct {
    char *data;
    int size;
} String;

int main() {
    String str = {NULL, 0};
    char *buffer = malloc(MAX_SIZE);
    char *ptr = buffer;
    int c;
    int i = 0;

    printf("Enter a string: ");
    while ((c = getchar())!= EOF) {
        if (i >= MAX_SIZE) {
            printf("String too long!\n");
            exit(1);
        }
        if (isprint(c)) {
            *ptr++ = c;
            i++;
        }
    }
    *ptr = '\0';

    str.data = buffer;
    str.size = i;

    printf("Enter a substring: ");
    char *substring = malloc(str.size);
    i = 0;
    while ((c = getchar())!= EOF) {
        if (i >= str.size) {
            printf("Substring too long!\n");
            exit(1);
        }
        if (isprint(c)) {
            *substring++ = c;
            i++;
        }
    }
    *substring = '\0';

    printf("Searching for substring...\n");
    char *found = strstr(str.data, substring);

    if (found == NULL) {
        printf("Substring not found!\n");
    } else {
        printf("Substring found at position %d!\n", found - str.data + 1);
    }

    free(buffer);
    free(substring);

    return 0;
}