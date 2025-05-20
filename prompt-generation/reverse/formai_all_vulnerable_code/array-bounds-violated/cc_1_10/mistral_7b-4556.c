//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_ALPHABET "XqjK!Z@$%&*()_+|~`"

struct alien_word {
    char *english;
    char *alien;
};

void translate_word(struct alien_word *word) {
    int i;
    for (i = 0; word->english[i] != '\0'; i++) {
        if (isalpha(word->english[i])) {
            word->alien[i] = ALIEN_ALPHABET[(int)toupper((unsigned char)word->english[i]) - 65];
        } else {
            word->alien[i] = word->english[i];
        }
    }
    word->alien[i] = '\0';
}

int main() {
    int num_words;
    int i;
    struct alien_word *words;

    printf("How many English words would you like to translate? ");
    scanf("%d", &num_words);

    words = (struct alien_word *)malloc(num_words * sizeof(struct alien_word));

    for (i = 0; i < num_words; i++) {
        printf("Enter an English word: ");
        words[i].english = (char *)malloc(25 * sizeof(char));
        scanf("%s", words[i].english);

        translate_word(&words[i]);

        printf("The alien translation of %s is %s.\n", words[i].english, words[i].alien);

        free(words[i].english);
    }

    free(words);

    printf("Press any key to continue...");
    getchar();

    return 0;
}

// Alien Translation Table
// English letter -> Alien letter
// A -> X
// B -> q
// C -> j
// D -> K
// E -> !
// F -> Z
// G -> @
// H -> $
// I -> %
// J -> &
// K -> *
// L -> (
// M -> )
// N -> +
// O -> |
// P -> ~
// Q -> `