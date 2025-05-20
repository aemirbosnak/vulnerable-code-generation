//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove stop words from a string
char *remove_stop_words(char *str) {
    char *stop_words[] = {"a", "an", "the", "and", "or", "but", "for", "nor", "yet", "so"};
    int num_stop_words = sizeof(stop_words) / sizeof(char *);

    char *new_str = malloc(strlen(str) + 1);
    int new_str_len = 0;

    char *token = strtok(str, " ");
    while (token != NULL) {
        int is_stop_word = 0;
        for (int i = 0; i < num_stop_words; i++) {
            if (strcmp(token, stop_words[i]) == 0) {
                is_stop_word = 1;
                break;
            }
        }

        if (!is_stop_word) {
            strcpy(new_str + new_str_len, token);
            new_str_len += strlen(token);
            new_str[new_str_len++] = ' ';
        }

        token = strtok(NULL, " ");
    }

    new_str[new_str_len - 1] = '\0';

    return new_str;
}

// Function to summarize a text
char *summarize_text(char *text, float ratio) {
    // Remove stop words from the text
    char *clean_text = remove_stop_words(text);

    // Create an array of sentences
    char **sentences = malloc(sizeof(char *) * 100);
    int num_sentences = 0;

    char *sentence = strtok(clean_text, ".");
    while (sentence != NULL) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, ".");
    }

    // Calculate the number of sentences to include in the summary
    int num_summary_sentences = (int)(num_sentences * ratio);

    // Create the summary
    char *summary = malloc(sizeof(char) * 1000);
    int summary_len = 0;

    for (int i = 0; i < num_summary_sentences; i++) {
        strcpy(summary + summary_len, sentences[i]);
        summary_len += strlen(sentences[i]);
        summary[summary_len++] = '.';
    }

    summary[summary_len - 1] = '\0';

    free(sentences);
    free(clean_text);

    return summary;
}

int main() {
    // Get the text to be summarized from the user
    char text[1000];
    printf("Enter the text to be summarized: ");
    fgets(text, 1000, stdin);

    // Get the desired summary ratio from the user
    float ratio;
    printf("Enter the desired summary ratio (0.0 to 1.0): ");
    scanf("%f", &ratio);

    // Summarize the text
    char *summary = summarize_text(text, ratio);

    // Print the summary
    printf("Summary: %s\n", summary);

    free(summary);

    return 0;
}