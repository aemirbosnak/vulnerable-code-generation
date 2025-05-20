//Falcon-180B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32
#define MAX_FILENAME_LENGTH 256

typedef struct {
    char *filename;
    FILE *file;
    int line_count;
} File;

typedef struct {
    char *word;
    int count;
} Word;

int compare_words(const void *a, const void *b) {
    return strcasecmp(*(char **)a, *(char **)b);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    Word *word_array = NULL;
    int i;

    printf("Enter the filename: ");
    scanf("%s", filename);

    File file = {
       .filename = filename,
       .file = fopen(filename, "r"),
       .line_count = 0
    };

    if (file.file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file.file)!= NULL) {
        file.line_count++;

        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Convert line to lowercase
        for (i = 0; line[i]!= '\0'; i++) {
            line[i] = tolower(line[i]);
        }

        // Tokenize line into words
        char *token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            strcpy(word, token);
            word_array = realloc(word_array, sizeof(Word) * ++word_count);
            word_array[word_count - 1].word = strdup(word);
            word_array[word_count - 1].count = 1;

            token = strtok(NULL, ",.!?;:");
        }
    }

    qsort(word_array, word_count, sizeof(Word), compare_words);

    printf("Total number of lines: %d\n", file.line_count);
    printf("Total number of words: %d\n", word_count);

    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_array[i].word, word_array[i].count);
    }

    free(word_array);
    fclose(file.file);

    return 0;
}