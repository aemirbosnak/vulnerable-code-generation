//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: interoperable
#include <stdio.h>
#include <time.h>

int main() {
    time_t start, end;
    double time_taken;
    int words_entered, characters_entered;
    char text[1000];

    start = clock();

    printf("Enter text: ");
    gets(text);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    words_entered = words_per_sentence(text);
    characters_entered = characters_per_word(text);

    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Number of words entered: %d\n", words_entered);
    printf("Number of characters entered: %d\n", characters_entered);

    return 0;
}

int words_per_sentence(char *text) {
    int words_entered = 0;
    char *sentence = text;

    while (sentence) {
        sentence = strchr(sentence, '.');
        if (sentence) {
            words_entered++;
            sentence++;
        }
    }

    return words_entered;
}

int characters_per_word(char *text) {
    int characters_entered = 0;
    char *word = text;

    while (word) {
        word = strchr(word, ' ');
        if (word) {
            characters_entered++;
            word++;
        }
    }

    return characters_entered;
}