//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

struct word *words;
int num_words;

void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        struct word *new_word = (struct word *) malloc(sizeof(struct word));
        strcpy(new_word->word, word);
        new_word->count = 0;
        words = (struct word *) realloc(words, sizeof(struct word) * ++num_words);
        words[num_words - 1] = *new_word;
    }

    fclose(file);
}

void count_words(char *text) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            for (j = 0; j < num_words; j++) {
                if (strlen(words[j].word) > 0 && text[i] == toupper(words[j].word[0])) {
                    strcat(words[j].word, &text[i]);
                    words[j].count++;
                    break;
                }
            }
        }
    }
}

void print_results(void) {
    printf("Words found:\n");
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    load_words(argv[1]);
    count_words(argv[2]);
    print_results();

    return 0;
}