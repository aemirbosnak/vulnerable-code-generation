//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000  // sets the maximum length of input string

// function prototypes
void translate(char* input, char* output);
int isVowel(char letter);

int main() {
    char input[MAX_LEN], output[MAX_LEN];

    printf("Enter a string in C Cat Language: ");
    fgets(input, MAX_LEN, stdin);

    translate(input, output);

    printf("C Cat translated to English: %s\n", output);

    return 0;
}

// translates a C Cat language string to English
void translate(char* input, char* output) {
    char word[MAX_LEN], translated_word[MAX_LEN];
    int i, j, k, len;

    // parse input string word by word
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            word[j] = '\0';  // terminate current word
            len = strlen(word);

            // translate word by moving first letter to end and adding "meow"
            for (k = 0; k < len-1; k++) {
                translated_word[k] = word[k+1];
            }
            translated_word[len-1] = word[0];
            translated_word[len] = 'm';
            translated_word[len+1] = 'e';
            translated_word[len+2] = 'o';
            translated_word[len+3] = 'w';
            translated_word[len+4] = '\0';

            strcat(output, translated_word);  // add translated word to output string
            strcat(output, " ");  // add space after translated word

            j = 0;  // reset word index
        }
        else {
            word[j++] = input[i];  // add character to current word
        }
    }

    // translate last word in input string
    word[j] = '\0';
    len = strlen(word);

    // translate word by moving first letter to end and adding "meow"
    for (k = 0; k < len-1; k++) {
        translated_word[k] = word[k+1];
    }
    translated_word[len-1] = word[0];
    translated_word[len] = 'm';
    translated_word[len+1] = 'e';
    translated_word[len+2] = 'o';
    translated_word[len+3] = 'w';
    translated_word[len+4] = '\0';

    strcat(output, translated_word);  // add translated word to output string
}

// checks if letter is a vowel
int isVowel(char letter) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int i;

    for (i = 0; i < 5; i++) {
        if (letter == vowels[i]) {
            return 1;
        }
    }

    return 0;
}