//FormAI DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

/* This function compresses a string using a custom algorithm */
void compress(char *str) {
    char compressed[MAX_SIZE];
    int i, j, k, count;

    i = j = 0;
    while (str[i] != '\0') {
        count = 1;

        /* count consecutive characters */
        while (str[i] == str[i+1] && str[i] != '\0') {
            count++;
            i++;
        }

        /* append compressed character to compressed string */
        compressed[j++] = str[i];

        /* append count of consecutive characters */
        if (count > 1) {
            /* convert count to string and append to compressed string */
            char count_str[10];
            sprintf(count_str, "%d", count);
            for (k = 0; count_str[k] != '\0'; k++) {
                compressed[j++] = count_str[k];
            }
        }

        i++;
    }

    compressed[j] = '\0';

    /* update original string with compressed string */
    i = 0;
    while (compressed[i] != '\0') {
        str[i] = compressed[i];
        i++;
    }

    str[i] = '\0';
}

int main()
{
    char string[MAX_SIZE];

    printf("Enter a string: ");
    fgets(string, MAX_SIZE, stdin);

    /* remove newline character from string */
    if (string[strlen(string)-1] == '\n') {
        string[strlen(string)-1] = '\0';
    }

    compress(string);

    printf("Compressed string: %s\n", string);

    return 0;
}