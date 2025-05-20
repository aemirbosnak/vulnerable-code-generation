//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char letter;
    int count;
} LetterCount;

int main() {
    FILE *file;
    char filename[255];
    char buffer[1024];
    char *ptr;
    LetterCount letterCounts[26];
    int i, j;

    // Get the filename from the user.
    printf("Enter the name of the file to analyze: ");
    scanf("%s", filename);

    // Open the file.
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return EXIT_FAILURE;
    }

    // Initialize the letter counts.
    for (i = 0; i < 26; i++) {
        letterCounts[i].letter = 'a' + i;
        letterCounts[i].count = 0;
    }

    // Read the file and count the occurrences of each letter.
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        ptr = buffer;
        while (*ptr != '\0') {
            if (*ptr >= 'a' && *ptr <= 'z') {
                letterCounts[*ptr - 'a'].count++;
            } else if (*ptr >= 'A' && *ptr <= 'Z') {
                letterCounts[*ptr - 'A'].count++;
            }
            ptr++;
        }
    }

    // Print the letter counts.
    printf("\nLetter counts:\n");
    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", letterCounts[i].letter, letterCounts[i].count);
    }

    // Close the file.
    fclose(file);

    return EXIT_SUCCESS;
}