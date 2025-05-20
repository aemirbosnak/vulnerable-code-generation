//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 50
#define WORD_LENGTH 10

char words[MAX_WORDS][WORD_LENGTH] = {
    "apple",
    "banana",
    "cherry",
    "date",
    "elderberry",
    "fig",
    "grape",
    "honeydew",
    "kiwi",
    "lemon",
    "mango",
    "nectarine",
    "orange",
    "peach",
    "plum",
    "quince",
    "raspberry",
    "strawberry",
    "tangerine",
    "watermelon",
    "xylophone",
    "yellow",
    "zebra",
    "cat",
    "dog",
    "hamster",
    "parrot",
    "turtle",
    "aardvark",
    "buffalo",
    "cobra",
    "dolphin",
    "elephant",
    "flamingo",
    "giraffe",
    "hippopotamus",
    "iguana",
    "jaguar",
    "kangaroo",
    "lion",
    "monkey",
    "newt",
    "ostrich",
    "penguin",
    "quail",
    "rhinoceros",
    "snail",
    "tiger",
    "unicorn",
    "vulture",
    "whale",
    "xenopus",
    "yak",
    "zebrafish"
};

int main() {
    srand(time(NULL)); // seed the random number generator
    int numWords = rand() % MAX_WORDS + 1; // generate a random number of words between 1 and 50
    char *wordsToType = malloc(numWords * WORD_LENGTH + 1); // allocate memory for the words to type
    int i;
    for (i = 0; i < numWords; i++) {
        int wordIndex = rand() % MAX_WORDS; // generate a random index into the words array
        strncat(wordsToType, words[wordIndex], WORD_LENGTH); // copy the word into the wordsToType string
        strncat(wordsToType, " ", 1); // add a space after each word
    }
    free(wordsToType); // free the memory allocated for the words to type
    return 0;
}