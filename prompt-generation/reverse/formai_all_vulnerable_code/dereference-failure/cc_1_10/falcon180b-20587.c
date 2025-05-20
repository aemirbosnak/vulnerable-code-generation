//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int compare_sentences(const void *a, const void *b) {
    const Sentence *sentence_a = (const Sentence *) a;
    const Sentence *sentence_b = (const Sentence *) b;

    return strcmp(sentence_a->text, sentence_b->text);
}

void remove_punctuation(char *text) {
    int i, j;

    for (i = 0, j = 0; text[i]!= '\0'; i++) {
        if (!isspace(text[i]) &&!ispunct(text[i])) {
            text[j++] = tolower(text[i]);
        }
    }

    text[j] = '\0';
}

int main() {
    FILE *input_file;
    char input_text[MAX_SENTENCE_LENGTH * MAX_SENTENCES];
    int input_length;
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
    int i;

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fseek(input_file, 0L, SEEK_END);
    input_length = ftell(input_file);
    rewind(input_file);

    if (fread(input_text, 1, input_length, input_file)!= input_length) {
        printf("Error: Could not read input file.\n");
        exit(1);
    }

    fclose(input_file);

    num_sentences = 0;
    sentences[num_sentences++] = (Sentence) {.text = "",.length = 0 };

    char *token = strtok(input_text, ".");
    while (token!= NULL) {
        if (num_sentences >= MAX_SENTENCES) {
            break;
        }

        remove_punctuation(token);

        if (strlen(token) >= MIN_SENTENCE_LENGTH) {
            strncpy(sentences[num_sentences].text, token, MAX_SENTENCE_LENGTH);
            sentences[num_sentences].length = strlen(token);
            num_sentences++;
        }

        token = strtok(NULL, ".");
    }

    qsort(sentences, num_sentences, sizeof(Sentence), compare_sentences);

    for (i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i].text);
    }

    return 0;
}