//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10
#define MAX_SENTENCE_LENGTH 100

char dictionary[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void load_dictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(dictionary[i], word);
        i++;
    }
    fclose(fp);
    num_words = i;
}

void generate_sentence(char* sentence, int length) {
    srand(time(NULL));
    int word_index;
    char* word;
    for (int i = 0; i < length; i++) {
        do {
            word_index = rand() % num_words;
            word = dictionary[word_index];
        } while (strlen(word) > MAX_WORD_LENGTH);
        strcat(sentence, word);
        strcat(sentence, " ");
    }
    strcat(sentence, "\n");
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;

    printf("Enter the length of the sentence: ");
    scanf("%d", &length);

    load_dictionary("dictionary.txt");

    generate_sentence(sentence, length);

    printf("Generated sentence:\n%s", sentence);

    return 0;
}