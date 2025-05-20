//FormAI DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 500

/* Compression algorithm function */
void compress(char* str) {

    int i, j, count;
    int n = strlen(str);

    bool compressed = false;

    /* create a character array to store the compressed string */
    char compressed_str[MAX_LEN];

    /* check if compression is possible */
    for (i = 0; i < n - 1; i++) {
        if (str[i] != str[i + 1]) {
            compressed = true;
            break;
        }
    }

    /* if compression is not possible, return the original string */
    if (!compressed) {
        printf("Compression not possible. Original string: %s", str);
        return;
    }

    /* compress the string */
    for (i = 0, j = 0; i < n; i = i + count) {
        count = 1;
        compressed_str[j++] = str[i];

        while (i + count < n && str[i + count] == str[i]) {
            count++;
        }

        /* convert the count to a string and append to the compressed string */
        char buffer[10];
        sprintf(buffer, "%d", count);
        int k;
        for (k = 0; buffer[k]; k++, j++) {
            compressed_str[j] = buffer[k];
        }
    }

    /* terminate the compressed string with null character */
    compressed_str[j] = '\0';

    /* print the compressed string */
    printf("Compressed string: %s\n", compressed_str);
}

/* Main function */
int main() {

    char str[MAX_LEN];

    /* Input string from user */
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    /* remove newline character */
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    /* call compression algorithm function */
    compress(str);

    return 0;
}