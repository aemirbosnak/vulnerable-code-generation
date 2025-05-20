//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 10000
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_LINE_LENGTH];
    int count;
} Word;

typedef struct {
    Word words[MAX_NUM_WORDS];
    int num_words;
} Line;

typedef struct {
    Line lines[MAX_NUM_LINES];
    int num_lines;
} Ebook;

Ebook* create_ebook() {
    Ebook* ebook = (Ebook*) malloc(sizeof(Ebook));
    ebook->num_lines = 0;
    return ebook;
}

void destroy_ebook(Ebook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        for (int j = 0; j < ebook->lines[i].num_words; j++) {
            free(ebook->lines[i].words[j].word);
        }
        free(ebook->lines[i].words);
    }
    free(ebook->lines);
    free(ebook);
}

void add_line(Ebook* ebook, char* line) {
    ebook->lines[ebook->num_lines].num_words = 0;
    char* word = strtok(line, " ");
    while (word!= NULL) {
        Word* new_word = (Word*) malloc(sizeof(Word));
        strcpy(new_word->word, word);
        new_word->count = 1;
        ebook->lines[ebook->num_lines].words[ebook->lines[ebook->num_lines].num_words++] = *new_word;
        free(new_word);
        word = strtok(NULL, " ");
    }
    ebook->num_lines++;
}

void print_ebook(Ebook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        for (int j = 0; j < ebook->lines[i].num_words; j++) {
            printf("%s %d\n", ebook->lines[i].words[j].word, ebook->lines[i].words[j].count);
        }
    }
}

int main() {
    Ebook* ebook = create_ebook();
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(ebook, line);
    }
    print_ebook(ebook);
    destroy_ebook(ebook);
    return 0;
}