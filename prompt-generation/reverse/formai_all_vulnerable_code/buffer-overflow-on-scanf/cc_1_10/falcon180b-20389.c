//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

// Function to split a string into words
void split_string(char* str, char** words) {
    int i = 0;
    char* word = strtok(str, ",.?!;:");
    while (word!= NULL) {
        words[i++] = word;
        word = strtok(NULL, ",.?!;:");
    }
}

// Function to translate a word from English to Cat
void translate_word(char* english_word, char* cat_word) {
    if (strcmp(english_word, "hello") == 0) {
        strcpy(cat_word, "meow");
    } else if (strcmp(english_word, "world") == 0) {
        strcpy(cat_word, "purrld");
    } else {
        strcpy(cat_word, english_word);
        for (int i = 0; i < strlen(english_word); i++) {
            if (english_word[i] == 'l') {
                english_word[i] ='m';
            } else if (english_word[i] == 'o') {
                english_word[i] = 'e';
            }
        }
        strcpy(cat_word, english_word);
    }
}

// Function to translate a sentence from English to Cat
void translate_sentence(char* english_sentence, char* cat_sentence) {
    char* words_english[MAX_WORDS];
    char* words_cat[MAX_WORDS];
    int num_words_english = 0;
    int num_words_cat = 0;

    split_string(english_sentence, words_english);
    num_words_english = strlen(english_sentence) / 2;

    for (int i = 0; i < num_words_english; i++) {
        translate_word(words_english[i], words_cat[i]);
        strcat(cat_sentence, words_cat[i]);
        strcat(cat_sentence, " ");
    }

    strcat(cat_sentence, "\n");
}

int main() {
    char english_sentence[MAX_WORD_LEN * MAX_WORDS];
    char cat_sentence[MAX_WORD_LEN * MAX_WORDS];

    printf("Enter an English sentence: ");
    scanf("%[^\n]", english_sentence);

    translate_sentence(english_sentence, cat_sentence);

    printf("%s", cat_sentence);

    return 0;
}