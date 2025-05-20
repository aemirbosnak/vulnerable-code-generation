//FormAI DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program dynamically reads in text from a file and performs various operations on it. */

int main() {
    FILE *file_ptr;
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read;

    // open the file for reading
    file_ptr = fopen("example.txt", "r");
    if (file_ptr == NULL) {
        printf("Error: could not open file.");
        exit(EXIT_FAILURE);
    }

    // read in the file line by line and store it in a dynamic buffer
    while ((read = getline(&buffer, &len, file_ptr)) != -1) {
        // print out the line
        printf("Line read: %s", buffer);

        // count the number of vowels
        int vowel_count = 0;
        for (int i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u') {
                vowel_count++;
            }
        }
        printf("Number of vowels: %d\n", vowel_count);

        // count the number of words
        int word_count = 0;
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            word_count++;
            token = strtok(NULL, " ");
        }
        printf("Number of words: %d\n", word_count);

        // reverse the line
        printf("Reversed line: ");
        for (int i = strlen(buffer) - 1; i >= 0; i--) {
            printf("%c", buffer[i]);
        }
        printf("\n\n");
    }

    // clean up dynamic memory allocation and close the file
    if (buffer != NULL) {
        free(buffer);
    }
    fclose(file_ptr);

    return 0;
}