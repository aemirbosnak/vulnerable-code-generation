//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define SUMMARY_LENGTH 200

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence* sentences;
    int num_sentences;
} Text;

void initialize_text(Text* text) {
    text->num_sentences = 0;
    text->sentences = NULL;
}

void add_sentence(Text* text, char* sentence) {
    Sentence* new_sentence = malloc(sizeof(Sentence));
    strcpy(new_sentence->sentence, sentence);
    new_sentence->length = strlen(sentence);
    text->sentences = realloc(text->sentences, sizeof(Sentence) * (text->num_sentences + 1));
    text->sentences[text->num_sentences] = *new_sentence;
    text->num_sentences++;
}

void generate_summary(Text* text, char* summary) {
    int i, j, length = 0;
    for (i = 0; i < text->num_sentences; i++) {
        if (length + text->sentences[i].length + 1 <= SUMMARY_LENGTH) {
            strncat(summary, text->sentences[i].sentence, text->sentences[i].length);
            length += text->sentences[i].length;
        }
        else {
            break;
        }
    }
    summary[length] = '\0';
}

int main() {
    Text text;
    initialize_text(&text);

    char input[MAX_SENTENCE_LENGTH];
    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(&text, input);
    }

    char summary[SUMMARY_LENGTH];
    generate_summary(&text, summary);

    printf("Summary:\n%s\n", summary);

    return 0;
}