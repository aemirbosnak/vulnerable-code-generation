//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000
#define MAX_WORDS 100
#define MAX_SENTENCES 10

char words[MAX_WORDS][MAX_LENGTH];
int num_words = 0;

void load_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    char word[MAX_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(file);
}

void generate_sentence() {
    srand(time(NULL));

    char sentence[MAX_LENGTH];
    strcpy(sentence, words[rand() % num_words]);

    int i = strlen(sentence);
    while (i < MAX_LENGTH) {
        int word_index = rand() % num_words;
        while (strlen(words[word_index]) + i >= MAX_LENGTH) {
            word_index = rand() % num_words;
        }

        strncat(sentence, words[word_index], MAX_LENGTH - i);
        i += strlen(words[word_index]) - 1;
    }

    printf("%s\n", sentence);
}

int main() {
    load_words();

    int num_sentences = rand() % MAX_SENTENCES + 1;
    for (int i = 0; i < num_sentences; i++) {
        generate_sentence();
    }

    return 0;
}