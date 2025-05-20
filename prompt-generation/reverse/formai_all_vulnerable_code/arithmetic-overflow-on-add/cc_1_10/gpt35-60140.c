//FormAI DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000
#define MAX_SUMMARY 100

void summarize(char *text, char *summary, int max_chars, int max_summary) {
    int i, j, char_count = 0, summary_count = 0;
    char words[MAX_CHARS][MAX_CHARS];
    char temp[MAX_CHARS];

    // Split text into words
    for(i=0; i<strlen(text); i++) {
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            words[char_count][j] = '\0';
            char_count++;
            j = 0;
        }
        else {
            words[char_count][j] = text[i];
            j++;
        }
    }

    // Calculate summary
    for(i=0; i<char_count; i++) {
        if(summary_count + strlen(words[i]) + 1 <= max_summary) {
            strcat(summary, words[i]);
            strcat(summary, " ");
            summary_count += strlen(words[i]) + 1;
        }
    }

    // Remove any trailing spaces
    for(i=strlen(summary)-1; i>=0; i--) {
        if(summary[i] == ' ') {
            summary[i] = '\0';
        }
        else {
            break;
        }
    }

    // Add ellipsis if necessary
    if(strlen(summary) >= max_summary) {
        summary[max_summary-3] = '.';
        summary[max_summary-2] = '.';
        summary[max_summary-1] = '.';
        summary[max_summary] = '\0';
    }
}

int main() {
    char text[MAX_CHARS];
    char summary[MAX_SUMMARY];

    // Read text from user
    printf("Enter text to summarize (max %d characters):\n", MAX_CHARS);
    fgets(text, MAX_CHARS, stdin);

    // Summarize text
    summarize(text, summary, MAX_CHARS, MAX_SUMMARY);

    // Print summary
    printf("Summary:\n%s\n", summary);

    return 0;
}