//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_word(Word *word) {
    const char *vowels = "aeiouAEIOU";
    const char *consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    const char *word_letters = vowels + 5; // skip first 5 vowels
    int i;

    word->length = rand() % 10 + 1;
    for (i = 0; i < word->length; i++) {
        word->word[i] = word_letters[rand() % strlen(word_letters)];
    }
    word->word[word->length] = '\0';
}

int main() {
    int num_words, i, correct_words = 0, total_words = 0;
    Word words[MAX_WORDS];
    char input[MAX_WORD_LENGTH];
    time_t start_time, end_time;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("How many words would you like to type? ");
    scanf("%d", &num_words);

    srand(time(NULL));
    for (i = 0; i < num_words; i++) {
        generate_word(&words[i]);
    }

    start_time = time(NULL);
    for (i = 0; i < num_words; i++) {
        printf("Word %d: %s\n", i + 1, words[i].word);
        fgets(input, MAX_WORD_LENGTH, stdin);
        if (strcmp(words[i].word, input) == 0) {
            correct_words++;
        }
        total_words++;
    }
    end_time = time(NULL);

    printf("\nTest complete!\n");
    printf("You typed %d words correctly out of %d total words.\n", correct_words, total_words);
    printf("Your typing speed is %d words per minute.\n", (int) (total_words / ((end_time - start_time) / 60.0)));

    return 0;
}