//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000
#define MAX_SUMMARY_LENGTH 500

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int compare_words(const void *a, const void *b) {
    return ((WordCount *)b)->count - ((WordCount *)a)->count;
}

int main() {
    FILE *file;
    char filePath[100], word[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS] = {{{0}}};
    int wordCount = 0;

    printf("Enter the path of the text file: ");
    scanf("%s", filePath);

    // Open the file for reading
    file = fopen(filePath, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return EXIT_FAILURE;
    }

    // Read words from the file and count their occurrences
    while (fscanf(file, "%49s", word) == 1) {
        to_lower_case(word);
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount].word, word);
            words[wordCount].count = 1;
            wordCount++;
        }
    }

    fclose(file);

    // Sort the WordCount array based on word frequency
    qsort(words, wordCount, sizeof(WordCount), compare_words);

    printf("\n--- Text Summary ---\n\n");

    // Display the most frequent words
    for (int i = 0; i < wordCount && i < 10; i++) {
        printf("Word: '%s', Count: %d\n", words[i].word, words[i].count);
    }

    // Create a simple summary
    char summary[MAX_SUMMARY_LENGTH];
    strcpy(summary, "Summary: ");
    for (int i = 0; i < 10 && i < wordCount; i++) {
        strncat(summary, words[i].word, MAX_WORD_LENGTH);
        strncat(summary, ", ", MAX_SUMMARY_LENGTH - strlen(summary) - 1);
    }

    // Clean up summary string
    if (strlen(summary) > strlen("Summary: ")) {
        summary[strlen(summary) - 2] = '\0';  // Remove trailing comma and space
    }

    printf("\n%s\n", summary);

    return EXIT_SUCCESS;
}