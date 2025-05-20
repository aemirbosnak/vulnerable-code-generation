//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 1000
#define MAX_VOCABULARY_SIZE 1000

// Function to split a sentence into words
void split_sentence(char sentence[], char words[][MAX_WORD_LENGTH]) {
    int word_count = 0;
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        strcpy(words[word_count], token);
        word_count++;
        if (word_count >= MAX_WORD_LENGTH) {
            break;
        }
        token = strtok(NULL, " ");
    }
}

// Function to translate a word
char* translate_word(char word[], char vocabulary[][MAX_WORD_LENGTH]) {
    int i;
    for (i = 0; i < MAX_VOCABULARY_SIZE; i++) {
        if (strcmp(word, vocabulary[i]) == 0) {
            return vocabulary[i];
        }
    }
    return word; // Word not found in vocabulary
}

// Function to translate a sentence
void translate_sentence(char sentence[], char vocabulary[][MAX_WORD_LENGTH]) {
    char words[MAX_SENTENCE_LENGTH][MAX_WORD_LENGTH];
    split_sentence(sentence, words);
    printf("Translated sentence: ");
    int i;
    for (i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            printf("%s ", translate_word(words[i], vocabulary));
        } else {
            printf("%c ", sentence[i]);
        }
    }
    printf("\n");
}

// Function to load vocabulary from a file
void load_vocabulary(char filename[], char vocabulary[][MAX_WORD_LENGTH]) {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    int i = 0;
    fp = fopen(filename, "r");
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(vocabulary[i], word);
        i++;
        if (i >= MAX_VOCABULARY_SIZE) {
            break;
        }
    }
    fclose(fp);
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char vocabulary[MAX_VOCABULARY_SIZE][MAX_WORD_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    load_vocabulary("vocabulary.txt", vocabulary);
    translate_sentence(sentence, vocabulary);
    return 0;
}