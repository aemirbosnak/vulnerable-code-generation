//FormAI DATASET v1.0 Category: Text Summarizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARAGRAPH 1000
#define MAX_SUMMARY 50

int main() {
    char paragraph[MAX_PARAGRAPH];
    char summary[MAX_SUMMARY] = "";
    int words = 0, sentences = 0;

    printf("Enter a paragraph to summarize: \n");
    fgets(paragraph, MAX_PARAGRAPH, stdin);

    // Counting words and sentences in paragraph
    for(int i = 0; i < strlen(paragraph); i++) {
        if(paragraph[i] == ' ' || paragraph[i] == '\n') {
            words++;
        } else if(paragraph[i] == '.' || paragraph[i] == '?' || paragraph[i] == '!') {
            sentences++;
        }
    }

    // Calculating average words per sentence
    float avg_words = (float)words / (float)sentences;

    // Converting paragraph to summary
    char *tok = strtok(paragraph, " ");
    while(tok != NULL) {
        if(strchr(tok, '.') || strchr(tok, '!') || strchr(tok, '?')) {
            // End of a sentence
            strcat(summary, tok);
            strcat(summary, " ");
            if(words / sentences <= avg_words) {
                // Fewer words than average
                if(strlen(summary) >= MAX_SUMMARY) {
                    break;
                }
            } else {
                // More words than average
                char *end = strrchr(summary, ' ');
                *end = '\0';
                break;
            }
            sentences++;
            words = 0;
        } else {
            strcat(summary, tok);
            strcat(summary, " ");
            words++;
        }
        tok = strtok(NULL, " ");
    }

    printf("Summary: \n%s\n", summary);

    return 0;
}