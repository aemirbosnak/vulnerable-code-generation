//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_LETTERS 20

void translate(char words[][MAX_LETTERS]);

int main() {
    char alienWords[MAX_WORDS][MAX_LETTERS];
    int counter = 0;

    printf("Enter your Alien words: \n");

    while (true) {
        scanf("%s", alienWords[counter]);

        if (strcmp(alienWords[counter], "end") == 0) {
            break;
        }

        counter++;
    }

    translate(alienWords);

    return 0;
}

void translate(char words[][MAX_LETTERS]) {
    printf("\nTranslation Results:\n");

    for (int i = 0; i < MAX_WORDS && strcmp(words[i], "end") != 0; i++) {
        char firstLetter = words[i][0];

        switch (firstLetter) {
            case 'a':
                printf("%s means 'Hello'\n", words[i]);
                break;
            case 'b':
                printf("%s means 'Goodbye'\n", words[i]);
                break;
            case 'c':
                printf("%s means 'Friend'\n", words[i]);
                break;
            case 'd':
                printf("%s means 'Enemy'\n", words[i]);
                break;
            default:
                printf("%s is not recognized\n", words[i]);
        }
    }
}