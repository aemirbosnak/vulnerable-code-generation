//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 10000
#define MAX_SENTENCES 100

typedef struct {
    char text[MAX_CHARACTERS];
    int num_sentences;
    int sentence_lengths[MAX_SENTENCES];
} Text;

Text read_text(FILE *fp) {
    Text text;
    text.num_sentences = 0;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '.' || c == '?' || c == '!') {
            text.sentence_lengths[text.num_sentences++] = ftell(fp) - 1;
        }
        text.text[ftell(fp) - 1] = c;
    }
    return text;
}

void print_summary(Text text, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        int start = text.sentence_lengths[i] - text.sentence_lengths[0];
        int end = text.sentence_lengths[i];
        printf("%.*s\n", end - start, text.text + start);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    Text text = read_text(fp);
    fclose(fp);

    int num_sentences = text.num_sentences / 2;
    print_summary(text, num_sentences);

    return 0;
}