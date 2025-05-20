//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAX_SUMMARY_LEN 100 // Maximum summary length in characters

int main() {
    char text[1000]; // Input text
    char summary[MAX_SUMMARY_LEN]; // Output summary
    int word_count = 0; // Word count in input text
    int summary_len = 0; // Current length of summary
    int i, j;

    // Get input text
    printf("Enter the text to summarize: ");
    fgets(text, sizeof(text), stdin);

    // Count number of words in input text
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            word_count++;
        }
    }

    // Calculate number of words to include in summary
    int summary_word_count = (word_count > 10) ? 10 : word_count;

    // Initialize summary with first word
    for (i = 0; text[i] != ' ' && i < sizeof(summary) - 1; i++) {
        summary[i] = text[i];
        summary_len++;
    }
    summary[i] = '.';
    summary_len++;

    // Find the most important words to include in summary
    for (i = 1; i < summary_word_count; i++) {
        // Find the next space in input text
        while (text[j] != ' ' && text[j] != '\0') {
            j++;
        }
        j++; // Move past the space

        // Find the next word in input text that has not already been included
        int best_start = -1;
        int best_score = -1;
        for (int k = j; text[k] != ' ' && text[k] != '\0'; k++) {
            int score = 0;
            for (int l = 0; l < summary_len; l++) {
                if (l == 0 || summary[l - 1] == ' ') {
                    int m = l;
                    int n = k;
                    while (m < summary_len && n < strlen(text) && summary[m] == text[n]) {
                        m++;
                        n++;
                    }
                    score += m - l;
                }
            }
            if (score > best_score) {
                best_score = score;
                best_start = k;
            }
        }

        // Add the next word to the summary
        for (int k = best_start; text[k] != ' ' && text[k] != '\0' && summary_len < MAX_SUMMARY_LEN - 1; k++) {
            summary[summary_len] = text[k];
            summary_len++;
        }
        summary[summary_len] = '.';
        summary_len++;
    }

    // Print the summary
    printf("Summary: %s\n", summary);

    return 0;
}