//FormAI DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("Hello! I am your happy spell checker!\n");
    printf("Please enter a word: \n");

    char word[100];
    scanf("%s", word);
    int length = strlen(word);
    bool misspelled = false;
    bool allCaps = true;

    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            printf("Sorry, '%s' cannot contain punctuation or numbers.\n", word);
            return 0;
        }
        if (islower(word[i])) {
            allCaps = false;
        }
    }

    if (allCaps) {
        printf("Wow! '%s' is ALL CAPS! Great job!\n", word);
    }

    char dictionary[5][10] = {
        "happy",
        "awesome",
        "fantastic",
        "amazing",
        "wonderful"
    };

    for (int i = 0; i < 5; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            printf("Yay! '%s' is spelled correctly!\n", word);
            return 0;
        }
    }

    misspelled = true;
    printf("Oh no! '%s' is misspelled!\n", word);
    printf("Did you mean one of these words?\n");

    for (int i = 0; i < 5; i++) {
        printf("%s\n", dictionary[i]);
    }

    return 0;
}