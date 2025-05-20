//FormAI DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 1000

int main() {
    char input[MAX_INPUT_SIZE], output[MAX_OUTPUT_SIZE];

    // Prompt user to enter input text
    printf("Enter the text to be summarized:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove any newline character from input text
    input[strcspn(input, "\r\n")] = 0;

    // Implement text summarization logic
    int i, j, sum_len = 0, num_sentences = 0;
    double avg_len;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '.') {
            num_sentences++;

            // Summarize sentence if too long
            if (sum_len > avg_len) {
                output[j++] = '.';
                output[j++] = '.';
                output[j++] = '.';
            }
            sum_len = 0;
        } else {
            sum_len++;
        }
        output[j++] = input[i];
    }

    // Summarize last sentence if too long
    if (sum_len > avg_len) {
        output[j++] = '.';
        output[j++] = '.';
        output[j++] = '.';
    }

    // Calculate average sentence length
    avg_len = (double) (strlen(input) - num_sentences) / (double) num_sentences;

    // Display summarized text
    printf("\nSummarized text:\n%s\n", output);

    return 0;
}