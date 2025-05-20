//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 50
#define MAX_CONSPIRACY_WORDS 10
#define WORD_LIST_SIZE 100

typedef struct {
    char *word;
    int length;
} Word;

typedef struct {
    Word words[MAX_CONSPIRACY_WORDS];
    int num_words;
} Conspiracy;

Word word_list[WORD_LIST_SIZE];
int num_words = 0;

void generate_random_word(char *word, int length) {
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
}

void add_word_to_list(char *word) {
    if (num_words >= WORD_LIST_SIZE) {
        printf("Error: Word list is full.\n");
        return;
    }
    strcpy(word_list[num_words].word, word);
    word_list[num_words].length = strlen(word);
    num_words++;
}

void init_word_list() {
    add_word_to_list("government");
    add_word_to_list("cover-up");
    add_word_to_list("secret");
    add_word_to_list("conspiracy");
    add_word_to_list("hidden");
    add_word_to_list("truth");
    add_word_to_list("evidence");
    add_word_to_list("mystery");
    add_word_to_list("plot");
    add_word_to_list("scheme");
}

void generate_conspiracy(Conspiracy *conspiracy) {
    conspiracy->num_words = rand() % MAX_CONSPIRACY_WORDS + 1;
    for (int i = 0; i < conspiracy->num_words; i++) {
        int word_index = rand() % num_words;
        strcpy(conspiracy->words[i].word, word_list[word_index].word);
        conspiracy->words[i].length = word_list[word_index].length;
    }
}

void print_conspiracy(Conspiracy conspiracy) {
    printf("The ");
    for (int i = 0; i < conspiracy.num_words - 1; i++) {
        printf("%s ", conspiracy.words[i].word);
    }
    printf(" %s is a %s.\n", conspiracy.words[conspiracy.num_words - 1].word, conspiracy.words[0].word);
}

int main() {
    srand(time(NULL));
    init_word_list();
    Conspiracy conspiracy;
    generate_conspiracy(&conspiracy);
    print_conspiracy(conspiracy);
    return 0;
}