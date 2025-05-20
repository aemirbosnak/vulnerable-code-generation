//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define SUMMARY_LENGTH 100

typedef struct sentence_t {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct summary_t {
    Sentence sentences[SUMMARY_LENGTH];
    int num_sentences;
} Summary;

int generate_summary(const char* input_text, Summary* summary) {
    FILE* input_file = fopen(input_text, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    int num_sentences = 0;
    char sentence_text[MAX_SENTENCE_LENGTH];
    while (fscanf(input_file, "%[^\n]", sentence_text)!= EOF) {
        int sentence_length = strlen(sentence_text);
        if (num_sentences >= SUMMARY_LENGTH) {
            break;
        }
        Sentence sentence = { sentence_text, sentence_length };
        summary->sentences[num_sentences] = sentence;
        num_sentences++;
    }

    fclose(input_file);
    summary->num_sentences = num_sentences;

    return 0;
}

void print_summary(const Summary* summary) {
    for (int i = 0; i < summary->num_sentences; i++) {
        printf("%s\n", summary->sentences[i].text);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s input_file\n", argv[0]);
        return 1;
    }

    Summary summary = { { 0 }, 0 };
    generate_summary(argv[1], &summary);
    print_summary(&summary);

    return 0;
}