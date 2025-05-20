//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *input_file;
    char filename[MAX_WORD_LENGTH];
    char ch;
    int i, j, word_count = 0;
    WordFrequency words[MAX_WORDS];

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open input file
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    // Read in words and count frequencies
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            j = 0;
            while (isalpha(ch) && j < MAX_WORD_LENGTH) {
                words[word_count].word[j++] = tolower(ch);
                ch = fgetc(input_file);
            }
            words[word_count].word[j] = '\0';
            words[word_count].count = 1;
            word_count++;
        }
    }

    // Close input file
    fclose(input_file);

    // Sort words by frequency
    for (i = 0; i < word_count - 1; i++) {
        for (j = i + 1; j < word_count; j++) {
            if (words[j].count > words[i].count) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print word frequencies
    printf("Word frequencies:\n");
    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}