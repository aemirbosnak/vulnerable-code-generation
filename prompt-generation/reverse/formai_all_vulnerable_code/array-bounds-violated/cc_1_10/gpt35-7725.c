//FormAI DATASET v1.0 Category: Spell checking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if the character is a letter or not
int is_letter(char c) {
    // Check if it's an uppercase or lowercase letter
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    else
        return 0;
}

// Function to check if the character is a punctuation or not
int is_punct(char c) {
    // Check if it's a punctuation mark
    if (c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':' || c == '-')
        return 1;
    else
        return 0;
}

int main() {
    char input[100];
    char *word;
    int i, j, len, flag;

    // Ask the user to enter a text
    printf("Enter some text: ");
    fgets(input, 100, stdin);

    // Remove new line character from the input
    input[strlen(input) - 1] = '\0';

    // Convert the whole text to lowercase
    for (i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Tokenize the input to get words
    word = strtok(input, " ");

    // Loop through all the words in the input
    while (word != NULL) {
        len = strlen(word);
        flag = 0;

        // Check if the word starts with a capital letter
        if (isupper(word[0])) {
            printf("\n%s\n", word);
            printf("The word \"%s\" starts with a capital letter. ");
            printf("Did you mean \"%c%s\"?\n", tolower(word[0]), &word[1]);
            flag = 1;
        }

        // Check if the word contains any punctuation mark
        for (j = 1; j < len - 1; j++) {
            if (is_punct(word[j])) {
                printf("\n%s\n", word);
                printf("The word \"%s\" contains a punctuation mark. ");
                printf("Did you mean \"%.*s%s\"", j, word, &word[j + 1]);
                flag = 1;
            }
        }

        // Check if the word ends with a punctuation mark
        if (is_punct(word[len - 1])) {
            printf("\n%s\n", word);
            printf("The word \"%s\" ends with a punctuation mark. ");
            printf("Did you mean \"%.*s\"", len - 1, word);
            flag = 1;            
        }

        // Check if the word is misspelled
        if (!flag) {
            printf("\n%s\n", word);
            printf("The word \"%s\" is spelled correctly.\n", word);
        }

        // Move to the next word
        word = strtok(NULL, " ");
    }

    return 0;
}