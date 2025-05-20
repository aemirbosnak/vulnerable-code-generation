//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>

// Function to convert a string to lowercase
void toLower(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to convert a string to uppercase
void toUpper(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to translate a word from one language to another
void translate(char* word, char* to) {
    char* lang = "en"; // language code for English
    if (strcmp(to, "ru") == 0) { // Russian
        lang = "ru"; // language code for Russian
        toLower(word);
    } else if (strcmp(to, "fr") == 0) { // French
        lang = "fr"; // language code for French
        toUpper(word);
    } else if (strcmp(to, "de") == 0) { // German
        lang = "de"; // language code for German
        toUpper(word);
    } else if (strcmp(to, "es") == 0) { // Spanish
        lang = "es"; // language code for Spanish
        toUpper(word);
    }

    printf("Translated word: %s\n", word);
    printf("Original language: %s\n", lang);
}

int main() {
    char word[100];
    char to[10];
    printf("Enter a word to translate:\n");
    scanf("%s", word);
    printf("Enter the language code:\n");
    scanf("%s", to);
    translate(word, to);
    return 0;
}