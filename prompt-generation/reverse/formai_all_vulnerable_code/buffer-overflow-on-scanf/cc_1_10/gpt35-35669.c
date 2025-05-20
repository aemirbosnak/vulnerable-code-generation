//FormAI DATASET v1.0 Category: Text Summarizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_SENTENCES 50
#define MAX_SUMMARY_LENGTH 200

char *summarize(char input[], int max_sentences, int max_summary_length);

int main() {
    char input[MAX_INPUT_LENGTH];
    int max_sentences, max_summary_length;
    
    printf("Please enter the text you would like to summarize (max length %d):\n", MAX_INPUT_LENGTH-1);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    printf("Please enter the maximum number of sentences to include in the summary (max %d):\n", MAX_SENTENCES);
    scanf("%d", &max_sentences);
    
    printf("Please enter the maximum length of the summary (max %d):\n", MAX_SUMMARY_LENGTH);
    scanf("%d", &max_summary_length);
    
    char *summary = summarize(input, max_sentences, max_summary_length);
    printf("\nSummary:\n%s", summary);
    
    free(summary);
    return 0;
}

char *summarize(char input[], int max_sentences, int max_summary_length) {
    int sentence_count = 0, line_count = 0;
    char *sentences[MAX_SENTENCES];
    
    // Split input into sentences and store in array
    char *line = strtok(input, "."); // assume sentences are separated by a period
    while(line != NULL && sentence_count < max_sentences) {
        sentences[sentence_count] = malloc(strlen(line) + 2); // add space for period and null terminator
        snprintf(sentences[sentence_count], strlen(line) + 2, "%s.", line);
        line = strtok(NULL, ".");
        sentence_count++;
    }
    
    // Calculate the total number of characters in the summary
    int summary_length = 0;
    for(int i = 0; i < sentence_count; i++) {
        summary_length += strlen(sentences[i]);
        if(summary_length > max_summary_length) {
            sentence_count = i; // reset sentence count if summary length exceeds limit
            break;
        }
    }
    
    // Construct summary from selected sentences
    char *summary = malloc(summary_length + 1); // add space for null terminator
    for(int i = 0; i < sentence_count; i++) {
        strcat(summary, sentences[i]);
        line_count++;
    }
    
    // If final sentence did not end with a period, append one
    if(summary[strlen(summary)-1] != '.') {
        strcat(summary, ".");
    }
    
    // Free memory allocated for sentences
    for(int i = 0; i < sentence_count; i++) {
        free(sentences[i]);
    }
    
    return summary;
}