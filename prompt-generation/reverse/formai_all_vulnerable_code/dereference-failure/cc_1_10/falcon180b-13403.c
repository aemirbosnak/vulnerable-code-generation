//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 100
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char *text;
    int length;
} Sentence;

Sentence* read_sentences(FILE *file, int *num_sentences) {
    Sentence *sentences = malloc(sizeof(Sentence) * MAX_SENTENCES);
    int sentence_count = 0;
    char ch;
    int curr_sent_length = 0;
    int in_word = 0;
    char curr_word[MAX_SENTENCE_LENGTH];

    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            if (in_word) {
                curr_word[curr_sent_length] = '\0';
                strcat(sentences[sentence_count].text, curr_word);
                curr_sent_length += strlen(curr_word) + 1;
                in_word = 0;
            }
        } else if (!in_word) {
            strcpy(curr_word, &ch);
            in_word = 1;
            curr_sent_length++;
        }

        if (curr_sent_length >= MIN_SENTENCE_LENGTH && sentence_count < MAX_SENTENCES - 1) {
            sentence_count++;
            curr_sent_length = 0;
        }
    }

    if (curr_sent_length >= MIN_SENTENCE_LENGTH) {
        strcpy(sentences[sentence_count].text, curr_word);
        curr_sent_length += strlen(curr_word) + 1;
        sentence_count++;
    }

    *num_sentences = sentence_count;
    return sentences;
}

void free_sentences(Sentence *sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i].text);
    }
    free(sentences);
}

void print_sentence(Sentence sentence) {
    printf("%s\n", sentence.text);
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int num_sentences;
    Sentence *sentences = read_sentences(file, &num_sentences);

    for (int i = 0; i < num_sentences; i++) {
        print_sentence(sentences[i]);
    }

    free_sentences(sentences, num_sentences);
    fclose(file);

    return 0;
}