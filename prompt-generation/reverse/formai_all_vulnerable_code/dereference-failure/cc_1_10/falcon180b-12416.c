//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char* text;
    int length;
} Sentence;

int compare_sentences(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int get_sentence_length(char* sentence) {
    int length = 0;
    while (*sentence++!= '\0') {
        if (isspace(*(sentence - 1))) {
            length++;
        }
    }
    return length;
}

void tokenize_sentences(char* text, Sentence sentences[], int max_sentences) {
    int sentence_count = 0;
    char* current_sentence = strtok(text, ".");
    while (current_sentence!= NULL && sentence_count < max_sentences) {
        int sentence_length = get_sentence_length(current_sentence);
        if (sentence_length >= MIN_SENTENCE_LENGTH) {
            sentences[sentence_count].text = current_sentence;
            sentences[sentence_count].length = sentence_length;
            sentence_count++;
        }
        current_sentence = strtok(NULL, ".");
    }
}

void print_sentences(Sentence sentences[], int count) {
    qsort(sentences, count, sizeof(Sentence), compare_sentences);
    for (int i = 0; i < count; i++) {
        printf("%s\n", sentences[i].text);
    }
}

int main() {
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* text = malloc(file_size + 1);
    fread(text, file_size, 1, file);
    text[file_size] = '\0';

    Sentence sentences[MAX_SENTENCES];
    int sentence_count = 0;

    tokenize_sentences(text, sentences, MAX_SENTENCES);
    print_sentences(sentences, sentence_count);

    free(text);
    fclose(file);

    return 0;
}