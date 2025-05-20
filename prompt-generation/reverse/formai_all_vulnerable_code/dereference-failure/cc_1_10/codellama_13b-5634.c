//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: detailed
// C Text Summarizer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 100

// Structure to store the text data
typedef struct {
    char* text;
    int length;
} Text;

// Function to get the text from the user
void get_text(Text* text) {
    printf("Enter the text: ");
    fgets(text->text, MAX_SUMMARY_LENGTH, stdin);
    text->length = strlen(text->text);
}

// Function to generate the summary
void generate_summary(Text* text) {
    int i, j, k;
    char* summary = (char*)malloc(MAX_SUMMARY_LENGTH);
    memset(summary, 0, MAX_SUMMARY_LENGTH);

    // Loop through the text and count the frequency of each word
    for (i = 0; i < text->length; i++) {
        if (text->text[i] == ' ') {
            continue;
        }
        for (j = i; j < text->length; j++) {
            if (text->text[j] == ' ') {
                break;
            }
        }
        // Add the word to the summary if it has not been added before
        if (strstr(summary, &text->text[i]) == NULL) {
            strncat(summary, &text->text[i], j - i);
        }
        i = j;
    }

    // Remove the last word if it is a punctuation mark
    if (summary[strlen(summary) - 1] == '.' || summary[strlen(summary) - 1] == '?' || summary[strlen(summary) - 1] == '!') {
        summary[strlen(summary) - 1] = '\0';
    }

    printf("Summary: %s\n", summary);

    free(summary);
}

int main() {
    Text text;
    get_text(&text);
    generate_summary(&text);
    return 0;
}