//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_LENGTH 100000

struct word_entry {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

struct word_entry dictionary[MAX_DICTIONARY_LENGTH];
int num_words = 0;

void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_DICTIONARY_LENGTH) {
            printf("Dictionary is full.\n");
            exit(1);
        }
        strcpy(dictionary[num_words].word, word);
        dictionary[num_words].frequency = 0;
        num_words++;
    }

    fclose(fp);
}

void count_word_frequency(char *text) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            j = 0;
            while (j < num_words && strcmp(dictionary[j].word, &text[i])!= 0) {
                j++;
            }
            if (j < num_words) {
                dictionary[j].frequency++;
            }
        }
    }
}

void print_misspelled_words(char *text) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            j = 0;
            while (j < num_words && strcmp(dictionary[j].word, &text[i])!= 0) {
                j++;
            }
            if (j >= num_words || dictionary[j].frequency == 0) {
                printf("%c", text[i]);
            }
        } else {
            printf("%c", text[i]);
        }
    }
}

int main() {
    load_dictionary("dictionary.txt");

    char text[MAX_WORD_LENGTH];
    printf("Enter text to spell check:\n");
    fgets(text, MAX_WORD_LENGTH, stdin);

    count_word_frequency(text);

    printf("Misspelled words:\n");
    print_misspelled_words(text);

    return 0;
}