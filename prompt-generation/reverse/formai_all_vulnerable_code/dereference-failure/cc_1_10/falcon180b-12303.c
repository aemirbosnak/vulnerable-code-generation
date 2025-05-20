//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

struct sentence {
    char sentence[100];
    int length;
};

struct sentence* generate_sentence(int length) {
    struct sentence* sentence = (struct sentence*) malloc(sizeof(struct sentence));
    sentence->length = length;
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        sentence->sentence[i] = c;
    }
    sentence->sentence[length] = '\0';
    return sentence;
}

int main() {
    srand(time(NULL));
    int num_sentences = 10;
    int max_sentence_length = 20;
    int min_sentence_length = 5;
    int total_chars_typed = 0;
    int num_correct_chars = 0;
    int num_incorrect_chars = 0;
    int num_skipped_chars = 0;
    int num_backspaces = 0;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be typing %d sentences.\n", num_sentences);
    printf("Each sentence will be between %d and %d characters long.\n", min_sentence_length, max_sentence_length);
    printf("Press enter to begin:\n");
    getchar();

    for (int i = 0; i < num_sentences; i++) {
        struct sentence* sentence = generate_sentence(rand() % (max_sentence_length - min_sentence_length + 1) + min_sentence_length);
        printf("Sentence %d: %s\n", i+1, sentence->sentence);
        char input[sentence->length];
        int j = 0;
        for (int k = 0; k < strlen(sentence->sentence); k++) {
            char c = toupper(sentence->sentence[k]);
            if (isalpha(c)) {
                input[j++] = c;
            }
        }
        input[j] = '\0';
        total_chars_typed += strlen(input);

        int correct_chars = 0;
        int incorrect_chars = 0;
        int skipped_chars = 0;
        int backspaces = 0;

        printf("Type the sentence:\n");
        for (int k = 0; k < strlen(input); k++) {
            char c = getchar();
            if (c == input[k]) {
                correct_chars++;
            } else if (c!= '\b') {
                incorrect_chars++;
            } else {
                backspaces++;
            }
            if (c!= input[k] && c!= '\b') {
                skipped_chars++;
            }
        }

        num_correct_chars += correct_chars;
        num_incorrect_chars += incorrect_chars;
        num_skipped_chars += skipped_chars;
        num_backspaces += backspaces;

        printf("\n");
    }

    printf("You typed %d characters correctly, %d characters incorrectly, skipped %d characters, and used backspace %d times.\n", num_correct_chars, num_incorrect_chars, num_skipped_chars, num_backspaces);

    return 0;
}