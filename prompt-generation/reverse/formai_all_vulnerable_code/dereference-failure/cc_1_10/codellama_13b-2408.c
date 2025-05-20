//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: inquisitive
// Unique C Text Summarizer Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store text
typedef struct {
    char *text;
    int length;
} Text;

// Function to get text from user
void getText(Text *text) {
    printf("Enter text: ");
    text->text = malloc(1000 * sizeof(char));
    fgets(text->text, 1000, stdin);
    text->length = strlen(text->text);
}

// Function to summarize text
void summarizeText(Text text) {
    // Find the most common words in the text
    int count[26] = {0};
    for (int i = 0; i < text.length; i++) {
        if (isalpha(text.text[i])) {
            count[tolower(text.text[i]) - 'a']++;
        }
    }
    // Find the top 5 most common words
    int top5[5] = {0};
    for (int i = 0; i < 5; i++) {
        int max = 0;
        for (int j = 0; j < 26; j++) {
            if (count[j] > max) {
                max = count[j];
                top5[i] = j;
            }
        }
        count[top5[i]] = 0;
    }
    // Print the top 5 most common words
    printf("Top 5 most common words: ");
    for (int i = 0; i < 5; i++) {
        printf("%c, ", top5[i] + 'a');
    }
    printf("\n");
}

int main() {
    Text text;
    getText(&text);
    summarizeText(text);
    return 0;
}