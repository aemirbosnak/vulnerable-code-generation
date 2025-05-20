//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

// Function to count words in a string
int countWords(char *str, int *wordCount) {
    int i = 0;
    int inWord = 0;
    while (str[i]) {
        if (isalnum(str[i])) {
            inWord = 1;
        } else if (inWord) {
            inWord = 0;
            (*wordCount)++;
        }
        i++;
    }
    if (inWord) {
        (*wordCount)++;
    }
    return i;
}

// Recursive function to count words in a file
int countFileWords(FILE *file, int *wordCount) {
    char str[MAX_WORD_LENGTH];
    int c;
    int i = 0;
    while ((c = fgetc(file))!= EOF) {
        if (isalnum(c)) {
            str[i++] = c;
        } else {
            str[i] = '\0';
            i = countWords(str, wordCount);
            i = 0;
        }
    }
    str[i] = '\0';
    i = countWords(str, wordCount);
    return i;
}

int main() {
    FILE *file;
    char filename[100];
    int wordCount = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: cannot open file.\n");
        exit(1);
    }

    // Count words in file
    countFileWords(file, &wordCount);

    // Print word count
    printf("Word count: %d\n", wordCount);

    // Close file
    fclose(file);

    return 0;
}