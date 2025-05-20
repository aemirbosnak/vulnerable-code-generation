//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} word_freq_t;

void print_header()
{
    printf("\n=========================================\n");
    printf(" Welcome to the Happy Word Frequency Counter!\n");
    printf("=========================================\n");
}

void print_footer(int num_words)
{
    printf("\n\n=========================================\n");
    printf(" Total words counted: %d\n", num_words);
    printf(" Thank you for using the Happy Word Frequency Counter!\n");
    printf("=========================================\n\n");
}

void convert_to_lowercase(char *word)
{
    int i;
    int len = strlen(word);

    for (i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

int is_valid_word(char *word)
{
    int i;
    int len = strlen(word);

    // Check for empty string
    if (len == 0) {
        return 0;
    }

    // Check if all characters are alphabetic
    for (i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }

    return 1;
}

int find_word_in_list(word_freq_t *word_list, char *word, int num_words)
{
    int i;
    for (i = 0; i < num_words; i++) {
        if(strcmp(word_list[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

void print_word_list(word_freq_t *word_list, int num_words)
{
    int i;

    printf("\nWord List:\n");

    for (i = 0; i < num_words; i++) {
        printf("%s - %d\n", word_list[i].word, word_list[i].freq);
    }
}

int main()
{
    char input_string[1000];
    char *token;
    word_freq_t word_list[MAX_WORDS];
    int num_words = 0;

    print_header();

    printf("\nEnter a string of words: ");
    scanf("%[^\n]", input_string);
    getchar(); // Consume trailing newline character

    token = strtok(input_string, " ");

    while(token != NULL) {
        convert_to_lowercase(token);

        if (is_valid_word(token)) {
            int index = find_word_in_list(word_list, token, num_words);

            if (index == -1) {
                // Add new word to the list
                strcpy(word_list[num_words].word, token);
                word_list[num_words].freq = 1;
                num_words++;
            } else {
                // Increment word frequency
                word_list[index].freq++;
            }
        }
        token = strtok(NULL, " ");
    }

    print_word_list(word_list, num_words);
    print_footer(num_words);

    return 0;
}