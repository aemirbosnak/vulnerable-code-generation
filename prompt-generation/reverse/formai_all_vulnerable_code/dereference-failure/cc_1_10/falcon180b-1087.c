//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Text;

Text *new_text() {
    Text *t = malloc(sizeof(Text));
    t->sentences = malloc(sizeof(Sentence) * MAX_SENTENCES);
    t->num_sentences = 0;
    return t;
}

void free_text(Text *t) {
    for (int i = 0; i < t->num_sentences; i++) {
        free(t->sentences[i].text);
    }
    free(t->sentences);
    free(t);
}

void add_sentence(Text *t, char *s) {
    if (t->num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached\n");
        return;
    }
    t->sentences[t->num_sentences].text = strdup(s);
    t->sentences[t->num_sentences].length = strlen(s);
    t->num_sentences++;
}

void print_text(Text *t) {
    for (int i = 0; i < t->num_sentences; i++) {
        printf("%s\n", t->sentences[i].text);
    }
}

int count_words(char *s) {
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (isspace(s[i])) {
            count++;
        }
    }
    return count + 1;
}

int main() {
    Text *t = new_text();
    char input[MAX_SENTENCE_LENGTH];
    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }
        add_sentence(t, input);
    }
    print_text(t);
    free_text(t);
    return 0;
}