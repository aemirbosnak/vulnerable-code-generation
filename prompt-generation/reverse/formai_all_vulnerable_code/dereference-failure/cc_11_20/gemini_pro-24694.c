//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

int main() {
    char *buf;
    char *p;
    size_t len;

    // Get the input line from the user.
    printf("Enter a line of text: ");
    len = getline(&buf, &len, stdin);
    if (len < 0) {
        perror("getline");
        return 1;
    }

    // Initialize the pointer to the beginning of the line.
    p = buf;

    // Now do some stuff with the data in the input line...
    // ...in order...
    // ...with flow...

    // Process each word in the line.
    while (*p != '\0') {
        // Skip over any whitespace characters.
        while (*p == ' ' || *p == '\t') {
            p++;
        }

        // Check to see if we have reached the end of the line.
        if (*p == '\0') {
            break;
        }

        // The current character is the start of a word.

        // Figure out how long the word is.
        int len = 0;
        while (*p != ' ' && *p != '\t' && *p != '\0') {
            len++;
            p++;
        }

        // Allocate memory for the word.
        char *word = malloc(len + 1);
        if (word == NULL) {
            perror("malloc");
            return 1;
        }

        // Copy the word to the allocated memory.
        memcpy(word, p - len, len);
        word[len] = '\0';

        // If the word is "Dennis", print it out.
        if (strcmp(word, "Dennis") == 0) {
            printf("Dennis! ");
        }

        // Free the memory for the word.
        free(word);
    }

    // Free the memory for the input line.
    free(buf);

    return 0;
}