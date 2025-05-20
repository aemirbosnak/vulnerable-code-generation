//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    char summary[1000];
    int count = 0;

    // Get input from user
    printf("Enter a text to summarize: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character at end of input
    text[strcspn(text, "\n")] = '\0';

    // Split input into words
    char *word = strtok(text, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    // Sort words by frequency
    int freq[count];
    for (int i = 0; i < count; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (strcmp(word, summary[j]) == 0) {
                freq[i]++;
            }
        }
    }

    // Find most frequent words
    int max = 0;
    int max_index = 0;
    for (int i = 0; i < count; i++) {
        if (freq[i] > max) {
            max = freq[i];
            max_index = i;
        }
    }

    // Create summary string
    for (int i = 0; i < max; i++) {
        summary[i] = word[i];
    }
    summary[count - 1] = '\0';

    // Print summary
    printf("Summary: %s\n", summary);

    return 0;
}