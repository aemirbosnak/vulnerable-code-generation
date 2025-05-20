//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 20

struct word {
    char *word;
    int count;
};

struct sentence {
    char *sentence;
    int length;
};

void generate_sentence(struct word *words, int num_words, struct sentence *sentence) {
    int i;

    for (i = 0; i < MAX_SENTENCE_LENGTH; i++) {
        sentence->sentence[i] = '\0';
    }

    int current_word_index = rand() % num_words;
    strcat(sentence->sentence, words[current_word_index].word);

    int j;
    for (j = 1; j < MAX_SENTENCE_LENGTH - strlen(sentence->sentence); j++) {
        current_word_index = rand() % num_words;
        strcat(sentence->sentence, " ");
        strcat(sentence->sentence, words[current_word_index].word);
    }

    sentence->length = strlen(sentence->sentence);
}

void generate_words(char *filename, struct word *words, int num_words) {
    FILE *file;
    char line[MAX_WORDS];
    int i;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    i = 0;
    while (fgets(line, MAX_WORDS, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int word_length = strlen(word);

            if (word_length > 0) {
                if (i < num_words) {
                    words[i].word = malloc(word_length * sizeof(char));
                    strcpy(words[i].word, word);
                    words[i].count = 0;
                    i++;
                }
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    int num_words;
    printf("Enter the number of words to generate: ");
    scanf("%d", &num_words);

    char filename[100];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    struct word words[MAX_WORDS];
    generate_words(filename, words, num_words);

    int num_sentences;
    printf("Enter the number of sentences to generate: ");
    scanf("%d", &num_sentences);

    struct sentence sentences[num_sentences];

    int i;
    for (i = 0; i < num_sentences; i++) {
        generate_sentence(words, num_words, &sentences[i]);
        printf("%s\n", sentences[i].sentence);
    }

    return 0;
}