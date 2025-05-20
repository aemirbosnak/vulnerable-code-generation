//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 100
#define MAX_WORDS_PER_SENTENCE 50

struct sentence {
    char words[MAX_SENTENCE_LENGTH];
    int num_words;
    int length;
};

struct summary {
    int num_sentences;
    struct sentence sentences[MAX_SENTENCES];
};

int get_num_words(char* str) {
    int num_words = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        num_words++;
        token = strtok(NULL, " ");
    }
    return num_words;
}

void add_sentence(struct summary* summary, char* str) {
    if (summary->num_sentences >= MAX_SENTENCES) {
        printf("Maximum number of sentences reached.\n");
        return;
    }
    int num_words = get_num_words(str);
    if (num_words > MAX_WORDS_PER_SENTENCE) {
        printf("Sentence contains too many words.\n");
        return;
    }
    struct sentence new_sentence;
    strcpy(new_sentence.words, str);
    new_sentence.num_words = num_words;
    new_sentence.length = strlen(str);
    summary->sentences[summary->num_sentences++] = new_sentence;
}

void print_summary(struct summary* summary) {
    printf("Summary:\n");
    for (int i = 0; i < summary->num_sentences; i++) {
        printf("%s\n", summary->sentences[i].words);
    }
}

int main() {
    struct summary summary;
    char input_buffer[MAX_SENTENCE_LENGTH];
    while (fgets(input_buffer, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(&summary, input_buffer);
    }
    print_summary(&summary);
    return 0;
}