//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 20

char *words[MAX_WORDS];
int num_words;

void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_SENTENCE_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        words[num_words++] = strdup(word);
    }

    fclose(file);
}

void generate_sentence(int length) {
    int i;
    for (i = 0; i < length; i++) {
        int word_index = rand() % num_words;
        printf("%s ", words[word_index]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    load_words("words.txt");

    int sentence_length;
    printf("Enter the desired length of the sentence (1-20): ");
    scanf("%d", &sentence_length);

    while (sentence_length < 1 || sentence_length > MAX_SENTENCE_LENGTH) {
        printf("Invalid sentence length. Please enter a number between 1 and %d:\n", MAX_SENTENCE_LENGTH);
        scanf("%d", &sentence_length);
    }

    generate_sentence(sentence_length);

    return 0;
}