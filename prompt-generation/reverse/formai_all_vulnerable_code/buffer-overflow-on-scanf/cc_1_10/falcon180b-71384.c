//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct sentence {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

void add_sentence(Sentence *sentences, int num_sentences, char *text) {
    if (num_sentences >= MAX_SENTENCES) {
        printf("Error: Too many sentences.\n");
        exit(1);
    }

    int length = strlen(text);
    if (length < MIN_SENTENCE_LENGTH) {
        printf("Warning: Sentence is too short: %s\n", text);
        return;
    }

    sentences[num_sentences].length = length;
    strcpy(sentences[num_sentences].text, text);
    num_sentences++;
}

void print_sentences(Sentence *sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i].text);
    }
}

int main() {
    FILE *input_file;
    char input_filename[100];
    char text[1000];
    Sentence sentences[MAX_SENTENCES];
    int num_sentences = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open file '%s'.\n", input_filename);
        exit(1);
    }

    while (fgets(text, sizeof(text), input_file)!= NULL) {
        char *sentence_start = text;
        while (*sentence_start!= '\0') {
            if (*sentence_start == '.' || *sentence_start == '!' || *sentence_start == '?') {
                add_sentence(sentences, num_sentences, sentence_start);
                sentence_start = strchr(sentence_start, '\0') + 1;
            } else {
                sentence_start++;
            }
        }
    }

    fclose(input_file);

    if (num_sentences == 0) {
        printf("Warning: No sentences found in file.\n");
    } else {
        printf("Number of sentences: %d\n", num_sentences);
        print_sentences(sentences, num_sentences);
    }

    return 0;
}