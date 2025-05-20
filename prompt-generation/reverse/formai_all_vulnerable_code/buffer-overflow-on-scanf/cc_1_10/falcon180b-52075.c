//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int search(char *str, char *pattern, int caseSensitive);

int main() {
    char str[MAX_LENGTH];
    char pattern[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    printf("Enter a pattern to search for: ");
    fgets(pattern, MAX_LENGTH, stdin);

    int caseSensitive = 1;
    while (caseSensitive == 1) {
        printf("Do you want to perform a case-sensitive search? (y/n): ");
        scanf("%s", &caseSensitive);
    }

    int result = search(str, pattern, caseSensitive);

    if (result == -1) {
        printf("Pattern not found.\n");
    } else {
        printf("Pattern found at position %d.\n", result);
    }

    return 0;
}

int search(char *str, char *pattern, int caseSensitive) {
    int lenStr = strlen(str);
    int lenPattern = strlen(pattern);
    int i, j;

    if (lenPattern > lenStr) {
        return -1;
    }

    for (i = 0; i <= lenStr - lenPattern; i++) {
        int match = 1;
        for (j = 0; j < lenPattern; j++) {
            if (caseSensitive && str[i + j]!= pattern[j]) {
                match = 0;
                break;
            } else if (!caseSensitive && tolower(str[i + j])!= tolower(pattern[j])) {
                match = 0;
                break;
            }
        }

        if (match) {
            return i;
        }
    }

    return -1;
}