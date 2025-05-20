//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

void init(String *s) {
    s->data = (char *)malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
}

void destroy(String *s) {
    free(s->data);
}

void append(String *s, char c) {
    if (s->size >= MAX_SIZE - 1) {
        printf("Error: String is full.\n");
        exit(1);
    }
    s->data[s->size++] = c;
}

int search(String *s, char *pattern) {
    int i, j;
    int n = strlen(pattern);
    int m = s->size;

    for (i = 0; i <= m - n; i++) {
        for (j = 0; j < n; j++) {
            if (s->data[i + j]!= pattern[j]) {
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }

    return -1;
}

int main() {
    String s;
    char pattern[MAX_SIZE];

    init(&s);

    printf("Enter a string: ");
    scanf("%s", s.data);

    printf("Enter a pattern to search for: ");
    scanf("%s", pattern);

    int index = search(&s, pattern);

    if (index == -1) {
        printf("Pattern not found.\n");
    } else {
        printf("Pattern found at index %d.\n", index);
    }

    destroy(&s);

    return 0;
}