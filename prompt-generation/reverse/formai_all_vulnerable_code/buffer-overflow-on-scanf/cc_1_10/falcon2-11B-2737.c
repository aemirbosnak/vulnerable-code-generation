//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the dictionary
static const char* DICT[] = {
    "Hello", "Kijug",
    "World", "Zongzong",
    "How", "Kunu",
    "are", "Ayu",
    "you?", "Ugo",
    "I", "Kitu",
    "am", "Zoyu",
    "good", "Goga",
    "!" "Boga"
};

// Function to translate a word
char* translate(char* word) {
    for (int i = 0; i < sizeof(DICT) / sizeof(DICT[0]); i++) {
        if (strcmp(DICT[i], word) == 0) {
            return DICT[i];
        }
    }
    return NULL;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Split the sentence into words
    char* words[strlen(sentence)];
    int word_count = 0;
    char* curr_word = sentence;
    while (*curr_word!= '\0') {
        words[word_count] = curr_word;
        word_count++;
        curr_word++;
    }

    // Translate each word
    char* translated_words[word_count];
    for (int i = 0; i < word_count; i++) {
        translated_words[i] = translate(words[i]);
        if (translated_words[i] == NULL) {
            printf("Translation not found for '%s'.\n", words[i]);
            break;
        }
    }

    // Concatenate the translated words to form the translated sentence
    char* translated_sentence = malloc((word_count + 1) * sizeof(char));
    translated_sentence[0] = '\0';
    for (int i = 0; i < word_count; i++) {
        strcat(translated_sentence, translated_words[i]);
        if (i < word_count - 1) {
            strcat(translated_sentence, " ");
        }
    }

    printf("Translated sentence: %s\n", translated_sentence);

    return 0;
}