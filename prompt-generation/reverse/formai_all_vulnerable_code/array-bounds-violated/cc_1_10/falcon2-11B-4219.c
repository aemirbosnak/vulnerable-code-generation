//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Function to generate summary of text
void generate_summary(char* text) {
    // Get length of text
    int length = strlen(text);

    // Array to store frequencies of each word
    int frequencies[256] = {0};

    // Count frequency of each word
    for (int i = 0; i < length; i++) {
        int word_length = strlen(text + i);
        for (int j = 0; j < word_length; j++) {
            frequencies[text[i + j]]++;
        }
    }

    // Sort words by frequency in descending order
    for (int i = 0; i < 256; i++) {
        int count = frequencies[i];
        for (int j = 0; j < count; j++) {
            printf("%c", i);
        }
    }
    printf("\n");

    // Get top 5 most common words
    int top_5 = 5;
    int top_5_count[256] = {0};
    for (int i = 0; i < 256; i++) {
        int count = frequencies[i];
        top_5_count[i] = count;
        if (count > top_5) {
            top_5 = count;
        }
    }

    // Generate summary based on top 5 words
    char summary[length + 1];
    summary[length] = '\0';
    for (int i = 0; i < length; i++) {
        int word_length = strlen(text + i);
        for (int j = 0; j < word_length; j++) {
            if (top_5_count[text[i + j]] > 0) {
                summary[i] = text[i + j];
                top_5_count[text[i + j]]--;
            }
        }
    }

    // Print summary
    printf("Summary: %s\n", summary);
}

// Main function
int main() {
    // Get text from user
    char text[256];
    printf("Enter text: ");
    fgets(text, 256, stdin);

    // Remove newline character
    text[strcspn(text, "\n")] = '\0';

    // Generate summary
    generate_summary(text);

    return 0;
}