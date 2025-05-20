//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: medieval
/// A medieval C text summarizer

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LEN 80

int main() {
    // Declare variables
    char text[MAX_SENTENCES][MAX_SENTENCE_LEN];
    int sentence_count = 0;
    int i;

    // Get input from user
    printf("Enter a text: ");
    fgets(text[sentence_count], MAX_SENTENCE_LEN, stdin);

    // Remove trailing newline character
    text[sentence_count][strlen(text[sentence_count]) - 1] = '\0';

    // Loop until the user presses enter without inputting text
    while (strlen(text[sentence_count]) > 0) {
        sentence_count++;
        printf("Enter a sentence (press enter to stop): ");
        fgets(text[sentence_count], MAX_SENTENCE_LEN, stdin);
        text[sentence_count][strlen(text[sentence_count]) - 1] = '\0';
    }

    // Sort sentences by length
    for (i = 0; i < sentence_count; i++) {
        int min_index = i;
        int j;
        for (j = i + 1; j < sentence_count; j++) {
            if (strlen(text[j]) < strlen(text[min_index])) {
                min_index = j;
            }
        }
        if (min_index != i) {
            char temp[MAX_SENTENCE_LEN];
            strcpy(temp, text[i]);
            strcpy(text[i], text[min_index]);
            strcpy(text[min_index], temp);
        }
    }

    // Print summary
    printf("Summary:\n");
    for (i = 0; i < sentence_count; i++) {
        printf("%s\n", text[i]);
    }

    return 0;
}