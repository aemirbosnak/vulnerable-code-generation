//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Text;

void read_text(Text *text) {
    char input[MAX_SENTENCE_LENGTH];
    printf("Enter text:\n");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);
    int length = strlen(input);
    text->num_sentences = length / MAX_SENTENCE_LENGTH;
    for (int i = 0; i < text->num_sentences; i++) {
        strncpy(text->sentences[i].text, input + i * MAX_SENTENCE_LENGTH, MAX_SENTENCE_LENGTH);
        text->sentences[i].length = strlen(text->sentences[i].text);
    }
}

void generate_summary(Text *text, int num_sentences) {
    char *summary = malloc(num_sentences * MAX_SENTENCE_LENGTH);
    int summary_length = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (summary_length + text->sentences[i].length + 1 <= MAX_SUMMARY_LENGTH) {
            strcat(summary, text->sentences[i].text);
            strcat(summary, " ");
            summary_length += text->sentences[i].length + 1;
        }
    }
    printf("Summary:\n%s\n", summary);
    free(summary);
}

int main() {
    Text text;
    read_text(&text);
    int num_sentences;
    printf("Enter number of sentences in summary:\n");
    scanf("%d", &num_sentences);
    generate_summary(&text, num_sentences);
    return 0;
}