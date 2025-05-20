//FormAI DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

/*
    This program implements a unique compression algorithm which stores runs of repeated characters as
    a count followed by the character, rather than just a string of repeating characters.
*/

int countRuns(char* string, int len) {
    int count = 1;
    char lastChar = string[0];
    int i;

    for (i = 1; i < len; i++) {
        if (string[i] != lastChar) {
            count++;
            lastChar = string[i];
        }
    }

    return count;
}

char* compress(char* sourceString) {
    int len = strlen(sourceString);
    char* compressedString = malloc(sizeof(char) * (MAX_LEN + 1));
    int i, j;

    for (i = 0; i < len; ) {
        int runCount = 1;
        char currentChar = sourceString[i];

        for (j = i + 1; j < len; j++) {
            if (sourceString[j] != currentChar) {
                break;
            }

            runCount++;
        }

        if (runCount > 1) {
            char runCountStr[5];
            sprintf(runCountStr, "%d", runCount);
            strcat(compressedString, runCountStr);
        }

        char charToAppend[2] = {currentChar, '\0'};
        strcat(compressedString, charToAppend);

        i += runCount;
    }

    return compressedString;
}

int main() {
    char sourceString[MAX_LEN + 1];
    printf("Enter a string to compress: ");
    scanf("%[^\n]", sourceString);

    char* compressedString = compress(sourceString);

    printf("Compressed string: %s\n", compressedString);

    free(compressedString);

    return 0;
}