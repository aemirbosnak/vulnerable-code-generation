//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define NUM_WORDS 10

typedef struct {
    char *english;
    char *alien;
} Translation;

int main() {
    Translation words[NUM_WORDS];
    char input[MAX_WORD_LENGTH];

    // Initialize the translation table
    words[0].english = "hello";
    words[0].alien = "\\_/\\_/\\_/\\_/";

    words[1].english = "world";
    words[1].alien = "/\\/\\/\\/\\/\\/\\/\\/\\/\\/";

    words[2].english = "one";
    words[2].alien = "1";

    words[3].english = "two";
    words[3].alien = "2";

    words[4].english = "three";
    words[4].alien = "3";

    words[5].english = "four";
    words[5].alien = "4";

    words[6].english = "five";
    words[6].alien = "5";

    words[7].english = "six";
    words[7].alien = "6";

    words[8].english = "seven";
    words[8].alien = "7";

    words[9].english = "eight";
    words[9].alien = "8";

    words[9].english = "nine";
    words[9].alien = "9";

    // Translate user input
    printf("Enter a word: ");
    scanf("%s", input);

    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcmp(words[i].english, input) == 0) {
            printf("Alien Translation: %s\n", words[i].alien);
            break;
        }
    }

    return 0;
}