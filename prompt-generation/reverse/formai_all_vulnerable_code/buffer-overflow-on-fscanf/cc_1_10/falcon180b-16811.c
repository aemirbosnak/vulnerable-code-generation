//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_SENTENCES 50
#define MAX_LENGTH 20

typedef struct {
    char *words[MAX_WORDS];
    int num_words;
} WordList;

void load_words(WordList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_LENGTH];
    int i = 0;

    if (file == NULL) {
        printf("Error loading word list: %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        list->words[i] = strdup(word);
        i++;
    }

    list->num_words = i;
    fclose(file);
}

char *random_word(WordList *list) {
    return list->words[rand() % list->num_words];
}

void generate_sentence(WordList *list, int length, char *sentence) {
    int i = 0;
    char *word;

    for (i = 0; i < length; i++) {
        word = random_word(list);
        strcat(sentence, word);
        strcat(sentence, " ");
    }

    sentence[strlen(sentence) - 1] = '\0'; // remove last space
}

int main() {
    srand(time(NULL));

    WordList word_list;
    load_words(&word_list, "words.txt");

    char sentence[MAX_SENTENCES];
    int length = rand() % MAX_LENGTH + 5;

    generate_sentence(&word_list, length, sentence);

    printf("Random conspiracy theory: %s\n", sentence);

    return 0;
}