//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define SUMMARY_LENGTH_PERCENTAGE 50

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
    int total_length;
} Text;

void add_sentence(Text *text, char *sentence) {
    if (text->num_sentences >= MAX_SENTENCE_LENGTH) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }

    int length = strlen(sentence);
    if (length > MAX_SENTENCE_LENGTH) {
        printf("Error: Sentence is too long.\n");
        return;
    }

    text->sentences[text->num_sentences] = (Sentence) {
       .sentence = sentence,
       .length = length
    };

    text->num_sentences++;
    text->total_length += length;
}

void summarize(Text *text, char *summary, int max_summary_length) {
    int summary_length = (int) (SUMMARY_LENGTH_PERCENTAGE / 100.0 * text->total_length);
    if (summary_length > max_summary_length) {
        summary_length = max_summary_length;
    }

    int current_length = 0;
    int num_sentences_included = 0;

    for (int i = 0; i < text->num_sentences; i++) {
        if (current_length + text->sentences[i].length <= summary_length) {
            strcat(summary, text->sentences[i].sentence);
            current_length += text->sentences[i].length;
            num_sentences_included++;
        } else {
            break;
        }
    }

    if (num_sentences_included > 0) {
        summary[current_length] = '\0';
    } else {
        strcpy(summary, "No sentences found.");
    }
}

int main() {
    Text text = { 0 };

    char sentence[MAX_SENTENCE_LENGTH];
    while (fgets(sentence, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(&text, sentence);
    }

    char summary[MAX_SENTENCE_LENGTH];
    summarize(&text, summary, MAX_SENTENCE_LENGTH);

    printf("Summary:\n%s\n", summary);

    return 0;
}