//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main(int argc, char *argv[])
{
    char *s, *t;
    int i, j, k, m, n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string 1> <string 2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    s = argv[1];
    t = argv[2];

    m = strlen(s);
    n = strlen(t);

    if (m != n) {
        fprintf(stderr, "Error: Strings must have the same length.\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (s[i] != t[j]) {
                break;
            }
        }
        if (j == n) {
            printf("String 1 is a subsequence of string 2.\n");
            return EXIT_SUCCESS;
        }
    }

    for (i = 0; i < m; i++) {
        for (j = n - 1; j >= 0; j--) {
            if (s[i] != t[j]) {
                break;
            }
        }
        if (j == -1) {
            printf("String 1 is a subsequence of string 2.\n");
            return EXIT_SUCCESS;
        }
    }

    printf("String 1 is not a subsequence of string 2.\n");
    return EXIT_FAILURE;
}