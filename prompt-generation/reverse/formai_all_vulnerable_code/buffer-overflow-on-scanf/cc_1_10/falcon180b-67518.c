//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

// function to check if a character is a letter
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// function to generate a random word
void generate_word(char *word) {
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word[i] = rand() % 26 + 'a';
    }
    word[i] = '\0';
}

// function to print a word with spaces
void print_word(char *word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        printf("%c", word[i]);
        if (i % 5 == 4) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    char words[MAX_WORDS][MAX_WORD_LENGTH + 1];
    int num_words = 0, num_correct = 0, num_incorrect = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("How many words do you want to type? ");
    scanf("%d", &num_words);

    int i;
    for (i = 0; i < num_words; i++) {
        generate_word(words[i]);
    }

    printf("Type the words as they appear.\n");
    for (i = 0; i < num_words; i++) {
        print_word(words[i]);
        char input[MAX_WORD_LENGTH + 1];
        fgets(input, MAX_WORD_LENGTH + 1, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i]) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }
    }

    printf("You typed %d words correctly and %d words incorrectly.\n", num_correct, num_incorrect);

    return 0;
}