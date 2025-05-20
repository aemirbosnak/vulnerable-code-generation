//FormAI DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SENTENCES 1000
#define MAX_CHARACTERS 10000

char* summarize(char* text, int summary_size);

int main() {
    char text[MAX_CHARACTERS];
    printf("Enter your text:\n");
    fgets(text, MAX_CHARACTERS, stdin);
    int summary_size;
    printf("Enter the number of sentences for summary:\n");
    scanf("%d", &summary_size);
    char* summary = summarize(text, summary_size);
    printf("Summary:\n%s", summary);
    free(summary);
    return 0;
}

char* summarize(char* text, int summary_size) {
    char* sentences[MAX_SENTENCES];
    int sentence_count = 0;
    char* sentence = strtok(text, ".!?\n");
    while (sentence != NULL && sentence_count < MAX_SENTENCES) {
        sentences[sentence_count++] = sentence;
        sentence = strtok(NULL, ".!?\n");
    }
    int ranks[MAX_SENTENCES] = {0};
    for (int i = 0; i < sentence_count; i++) {
        char* tokens = strtok(sentences[i], " \t\n");
        while (tokens != NULL) {
            if (strncmp(tokens, "the", 3) == 0 || strncmp(tokens, "a", 1) == 0 || strncmp(tokens, "an", 2) == 0) {
                ranks[i]++;
            }
            tokens = strtok(NULL, " \t\n");
        }
    }
    char* summary = (char*)malloc(MAX_SENTENCES * sizeof(char));
    summary[0] = '\0';
    int sentence_indices[MAX_SENTENCES];
    for (int i = 0; i < sentence_count; i++) {
        sentence_indices[i] = i;
    }
    for (int i = 0; i < sentence_count - 1; i++) {
        for (int j = i + 1; j < sentence_count; j++) {
            if (ranks[sentence_indices[i]] < ranks[sentence_indices[j]]) {
                int temp = sentence_indices[i];
                sentence_indices[i] = sentence_indices[j];
                sentence_indices[j] = temp;
            }
        }
    }
    for (int i = 0; i < summary_size && i < sentence_count; i++) {
        strcat(summary, sentences[sentence_indices[i]]);
        strcat(summary, ". ");
    }
    return summary;
}