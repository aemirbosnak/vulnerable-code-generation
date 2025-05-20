//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

void summarize(char *text, int summary_length) {
    // Get the number of words in the text
    int num_words = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }

    // Calculate the number of words to keep in the summary
    int words_to_keep = summary_length / 2;
    if (words_to_keep > num_words) {
        words_to_keep = num_words;
    }

    // Keep the first words_to_keep words
    char *summary = malloc(summary_length + 1);
    int i = 0;
    word = strtok(text, " ");
    while (word != NULL && i < words_to_keep) {
        strcat(summary, word);
        strcat(summary, " ");
        word = strtok(NULL, " ");
        i++;
    }

    // Add an ellipsis at the end of the summary
    strcat(summary, "...");

    printf("%s\n", summary);
}

int main() {
    char text[MAX_LEN];
    int summary_length;

    printf("Enter a text: ");
    fgets(text, MAX_LEN, stdin);
    printf("Enter a summary length: ");
    scanf("%d", &summary_length);

    summarize(text, summary_length);

    return 0;
}