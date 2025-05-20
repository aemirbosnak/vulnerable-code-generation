//FormAI DATASET v1.0 Category: Text Summarizer ; Style: romantic
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 1000

void summarize(char *text) {
    char buffer[MAX_WORDS][MAX_WORDS];
    char *word;
    int i, j, freq = 0;
    int total_words = 0;

    // Separate words from the text
    word = strtok(text, " ");

    while (word != NULL) {
        for (i = 0; i < total_words; i++) {
            if (strcmp(buffer[i], word) == 0) {
                freq++;
                break;
            }
        }
        if (i == total_words) {
            strcpy(buffer[total_words], word);
            total_words++;
        }
        word = strtok(NULL, " ");
    }

    printf("The summary of the text is: \n");

    // Print the most frequent words
    for (i = 0; i < total_words; i++) {
        freq = 0;
        for (j = 0; j < total_words; j++) {
            if (strcmp(buffer[i], buffer[j]) == 0) {
                freq++;
            }
        }
        if (freq > 1) {
            printf("%s ", buffer[i]);
        }
    }
}

int main() {
    char text[MAX_WORDS];
    printf("Please enter the text to be summarized:\n");
    scanf("%[^\n]s", text);
    summarize(text);
    return 0;
}