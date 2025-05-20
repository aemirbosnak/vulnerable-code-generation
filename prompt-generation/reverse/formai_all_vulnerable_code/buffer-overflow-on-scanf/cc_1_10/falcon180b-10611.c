//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS_PER_SENTENCE 100

typedef struct {
    char word[MAX_SENTENCE_LENGTH];
    int length;
} Word;

typedef struct {
    Word words[MAX_WORDS_PER_SENTENCE];
    int num_words;
} Sentence;

void init_sentence(Sentence *sentence) {
    sentence->num_words = 0;
}

void add_word(Sentence *sentence, const char *word) {
    if (sentence->num_words >= MAX_WORDS_PER_SENTENCE) {
        printf("Error: sentence contains too many words.\n");
        return;
    }

    Word new_word;
    strcpy(new_word.word, word);
    new_word.length = strlen(word);

    sentence->words[sentence->num_words++] = new_word;
}

void print_sentence(Sentence *sentence) {
    for (int i = 0; i < sentence->num_words; i++) {
        printf("%s ", sentence->words[i].word);
    }
    printf("\n");
}

int main() {
    FILE *input_file;
    char filename[MAX_SENTENCE_LENGTH];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    Sentence sentence;
    init_sentence(&sentence);

    char word[MAX_SENTENCE_LENGTH];
    while (fscanf(input_file, "%s", word)!= EOF) {
        add_word(&sentence, word);
    }

    fclose(input_file);

    printf("Original sentence:\n");
    print_sentence(&sentence);

    Sentence summary_sentence;
    init_sentence(&summary_sentence);

    for (int i = 0; i < sentence.num_words; i++) {
        if (sentence.words[i].length > 1) {
            continue;
        }

        Word new_word;
        strcpy(new_word.word, sentence.words[i].word);
        new_word.length = strlen(new_word.word);

        add_word(&summary_sentence, new_word.word);
    }

    printf("Summary sentence:\n");
    print_sentence(&summary_sentence);

    return 0;
}