#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_SUMMARY_LENGTH 512

typedef struct {
    char word[MAX_INPUT_LENGTH];
    int frequency;
} Word;

int compare(const void *a, const void *b) {
    return ((Word *)b)->frequency - ((Word *)a)->frequency;
}

void summarize(char *input, char *summary, int max_length) {
    // Tokenize input into words
    char *token = strtok(input, " ");
    Word words[100] = {0};
    int word_count = 0;

    while (token != NULL && word_count < 100) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[word_count].word, token);
            words[word_count].frequency = 1;
            word_count++;
        }
        token = strtok(NULL, " ");
    }

    // Sort words by frequency
    qsort(words, word_count, sizeof(Word), compare);

    // Build summary
    int summary_index = 0;
    for (int i = 0; i < word_count && summary_index < max_length; i++) {
        if (strlen(summary) + strlen(words[i].word) + 1 <= max_length) {
            strcat(summary, words[i].word);
            strcat(summary, " ");
            summary_index += strlen(words[i].word) + 1;
        } else {
            break;
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH] = {0};

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    summarize(input, summary, MAX_SUMMARY_LENGTH);

    printf("Summary: %s\n", summary);

    return 0;
}
