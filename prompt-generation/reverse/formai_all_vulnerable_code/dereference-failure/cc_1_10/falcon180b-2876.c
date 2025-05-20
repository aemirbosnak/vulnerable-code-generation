//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 10

typedef struct {
    char *words[MAX_WORDS];
    int num_words;
} Sentence;

void read_sentence(char sentence[], int max_length);
void tokenize_sentence(Sentence *sentence);
void print_sentence(Sentence sentence);

int main() {
    char input_text[MAX_SENTENCE_LENGTH];
    Sentence sentence;

    printf("Enter a sentence: ");
    fgets(input_text, MAX_SENTENCE_LENGTH, stdin);

    strcpy(sentence.words[0], input_text);
    sentence.num_words = 1;

    tokenize_sentence(&sentence);

    printf("Tokenized sentence:\n");
    print_sentence(sentence);

    return 0;
}

void read_sentence(char sentence[], int max_length) {
    char c;
    int i = 0;

    while ((c = fgetc(stdin))!= '\n') {
        if (i < max_length - 1) {
            sentence[i++] = c;
        } else {
            fprintf(stderr, "Error: Input too long.\n");
            exit(1);
        }
    }

    sentence[i] = '\0';
}

void tokenize_sentence(Sentence *sentence) {
    char *word = strtok(sentence->words[0], ",.?!;:");
    int i = 1;

    while (word!= NULL) {
        if (i >= MAX_WORDS) {
            fprintf(stderr, "Error: Too many words in sentence.\n");
            exit(1);
        }

        strcpy(sentence->words[i], word);
        i++;

        word = strtok(NULL, ",.?!;:");
    }

    sentence->num_words = i;
}

void print_sentence(Sentence sentence) {
    int i;

    for (i = 0; i < sentence.num_words; i++) {
        printf("%s ", sentence.words[i]);
    }

    printf("\n");
}