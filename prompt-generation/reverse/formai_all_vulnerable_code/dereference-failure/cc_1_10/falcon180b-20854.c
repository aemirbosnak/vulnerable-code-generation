//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_LENGTH 15

struct word {
    char *text;
    int length;
};

struct word generate_word(void) {
    char *vowels = "aeiouAEIOU";
    char *consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    char *word = malloc(MAX_LENGTH * sizeof(char));
    int length = rand() % (MAX_LENGTH - 3) + 3;
    int i = 0;

    word[i++] = consonants[rand() % strlen(consonants)];
    while (i < length) {
        if (rand() % 2 == 0) {
            word[i++] = consonants[rand() % strlen(consonants)];
        } else {
            word[i++] = vowels[rand() % strlen(vowels)];
        }
    }
    word[i] = '\0';

    struct word result = {word, length};
    return result;
}

int main(void) {
    srand(time(NULL));

    struct word *sentence = malloc(MAX_WORDS * sizeof(struct word));
    int num_words = rand() % (MAX_WORDS - 3) + 3;

    for (int i = 0; i < num_words; i++) {
        sentence[i] = generate_word();
    }

    printf("The ");
    for (int i = 0; i < num_words - 1; i++) {
        printf("%s ", sentence[i].text);
    }
    printf("%s is a %d-letter word.\n", sentence[num_words - 1].text, sentence[num_words - 1].length);

    return 0;
}