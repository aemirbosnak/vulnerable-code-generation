//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALIEN_LANGUAGE_SIZE 26

char* alien_alphabet[ALIEN_LANGUAGE_SIZE] = {
    "blorg",
    "plax",
    "skree",
    "frax",
    "zorg",
    "smee",
    "splam",
    "klar",
    "frooz",
    "snazz",
    "qweez",
    "braxx",
    "glee",
    "xoom",
    "mlax",
    "drax",
    "glip",
    "hroth",
    "kreeb",
    "throx",
    "zar",
    "kloog",
    "splox",
    "yorg",
    "plimp",
    "blaag"
};

char* english_alphabet[ALIEN_LANGUAGE_SIZE] = {
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
};

char* translate_to_alien(char* english_word) {
    int word_length = strlen(english_word);
    char* alien_word = calloc(word_length * 5, sizeof(char));

    for(int i = 0; i < word_length; i++) {
        int alien_index = (int) english_word[i] - 97;
        strcat(alien_word, alien_alphabet[alien_index]);

        if(i != word_length - 1) {
            strcat(alien_word, " ");
        }
    }

    return alien_word;
}

char* translate_to_english(char* alien_word) {
    int word_length = strlen(alien_word);
    char* english_word = calloc(word_length, sizeof(char));

    char* token = strtok(alien_word, " ");
    while(token != NULL) {
        for(int i = 0; i < ALIEN_LANGUAGE_SIZE; i++) {
            if(strcmp(token, alien_alphabet[i]) == 0) {
                strcat(english_word, english_alphabet[i]);
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    return english_word;
}

int main() {
    srand(time(0));

    printf("\nWelcome to the Unique C Alien Language Translator!\n\n");
    printf("Instructions:\n");
    printf("Enter an English word to translate it into Alien language.\n");
    printf("Enter an Alien word to translate it back into English language.\n");
    printf("Enter 'exit' to terminate the program.\n\n");

    while(1) {
        char input[50];
        printf("Enter your word: ");
        scanf("%s", input);

        if(strcmp(input, "exit") == 0) {
            break;
        }

        int mode = rand() % 2;
        char* output;
        if(mode == 0) {
            output = translate_to_alien(input);
            printf("Translation to Alien: %s\n\n", output);
        } else {
            output = translate_to_english(input);
            printf("Translation to English: %s\n\n", output);
        }

        free(output);
    }

    printf("Thanks for using the Unique C Alien Language Translator!\n");
    return 0;
}