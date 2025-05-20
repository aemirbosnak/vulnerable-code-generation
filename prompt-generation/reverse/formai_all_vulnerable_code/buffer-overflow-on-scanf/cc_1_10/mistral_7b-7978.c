//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

void print_intro() {
    printf("\n*************************************************\n");
    printf("*                                               *\n");
    printf("*   Welcome to the C Word Count Tool!             *\n");
    printf("*                                               *\n");
    printf("*   This program helps you find the number of     *\n");
    printf("*   occurrences of a specific word in a given text.*\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
}

void read_text(char text[][WORD_LENGTH], int* num_words) {
    char current_word[WORD_LENGTH];
    int count = 0;

    printf("Enter the text (type '.' to stop): \n");

    while (fgets(current_word, WORD_LENGTH, stdin) != NULL) {
        strcpy(text[*num_words], current_word);
        (*num_words)++;

        if (current_word[strlen(current_word) - 1] == '.') {
            break;
        }
    }
}

int count_word_occurrences(char target_word[], char words[][WORD_LENGTH], int num_words) {
    int count = 0;

    for (int i = 0; i < num_words; i++) {
        if (strstr(words[i], target_word) != NULL) {
            count++;
        }
    }

    return count;
}

void print_result(char target_word[], int count) {
    printf("\n*************************************************\n");
    printf("*                                               *\n");
    printf("*   The word '%s' occurs %d times in the text.    *\n", target_word, count);
    printf("*                                               *\n");
    printf("*************************************************\n");
}

int main() {
    char text[MAX_WORDS][WORD_LENGTH];
    int num_words = 0;
    char target_word[WORD_LENGTH];
    int count;

    print_intro();

    read_text(text, &num_words);

    printf("Enter the word to search for: ");
    scanf("%s", target_word);

    count = count_word_occurrences(target_word, text, num_words);

    print_result(target_word, count);

    return 0;
}