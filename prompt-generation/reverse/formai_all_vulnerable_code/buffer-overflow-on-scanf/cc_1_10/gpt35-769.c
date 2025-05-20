//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Ken Thompson Style C Searching Algorithm

// function to implement the Ken Thompson style searching algorithm
int ken_thompson_search(char* string, char* pattern) {
    char* s = string;
    char* p = pattern;
    char* start = NULL;

    while (*s != '\0') {
        if (*p == '\0') {
            return (int)(start - string);
        }
        if (*s == *p) {
            if (start == NULL) {
                start = s;
            }
            s++;
            p++;
        } else {
            if (start == NULL) {
                s++;
            } else {
                s = start + 1;
                p = pattern;
                start = NULL;
            }
        }
    }
    
    if (*p == '\0') {
        return (int)(start - string);
    }

    return -1;
}

// driver function
int main() {
    char string[100];
    char pattern[100];
    int result;

    printf("Enter a string: ");
    scanf("%s", string);

    printf("Enter a pattern to search: ");
    scanf("%s", pattern);

    result = ken_thompson_search(string, pattern);

    if (result == -1) {
        printf("Pattern not found in the given string.\n");
    } else {
        printf("Pattern found at index %d in the given string.\n", result);
    }

    return 0;
}