//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct word_t {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void add_word(char* word) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words.\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].count = 1;
    num_words++;
}

void generate_text(int num_words) {
    int total_words = 0;
    while (total_words < num_words) {
        int random_index = rand() % num_words;
        if (words[random_index].count < 1000) {
            words[random_index].count++;
            total_words++;
        }
    }
}

void print_text(int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
    }
}

int main() {
    srand(time(NULL));

    char input[MAX_WORD_LENGTH];
    printf("Enter a word or phrase: ");
    scanf("%s", input);

    char* words_array[MAX_WORDS];
    int num_words_array = 0;

    char* token = strtok(input, " ");
    while (token!= NULL) {
        if (num_words_array >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        strcpy(words_array[num_words_array], token);
        num_words_array++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < num_words_array; i++) {
        add_word(words_array[i]);
    }

    int num_words_to_generate = 100;
    printf("Generating %d words of text...\n", num_words_to_generate);
    generate_text(num_words_to_generate);

    printf("\nGenerated text:\n");
    print_text(num_words_to_generate);

    return 0;
}