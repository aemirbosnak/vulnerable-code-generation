//FormAI DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

/* Function to check if a word is spelled correctly */
int spell_check(char *word) {
    /* Trivial example. Only accept words of length 4 that start with 'a' */
    if (strlen(word) == 4 && word[0] == 'a')
        return 1;
    else
        return 0;
}

/* Function to parse a string and extract words */
int parse_string(char *str, char **words) {
    int num_words = 0;
    int word_start = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        if (isspace(str[i]) || ispunct(str[i]) || i == strlen(str)-1) {
            /* We have found the end of a word */
            int word_length;
            if (i == strlen(str)-1)
                word_length = i - word_start + 1;
            else
                word_length = i - word_start;

            char *word = (char*) malloc((word_length+1)*sizeof(char));
            strncpy(word, str+word_start, word_length);
            word[word_length] = '\0';
            words[num_words++] = word;
            word_start = i+1;

            /* Maximum number of words reached, exit loop */
            if (num_words == MAX_NUM_WORDS)
                break;
        }
    }

    return num_words;
}

int main() {
    char input[MAX_WORD_LENGTH*MAX_NUM_WORDS];
    char *words[MAX_NUM_WORDS];
    int num_words, i;

    /* Get input from user */
    printf("Enter text to check spelling:\n");
    scanf("%[^\n]s", input);

    /* Parse input into individual words */
    num_words = parse_string(input, words);

    /* Check each word for spelling errors */
    printf("Spelling errors found:\n");
    for (i = 0; i < num_words; i++) {
        if (!spell_check(words[i]))
            printf("%s\n", words[i]);
    }

    /* Free allocated memory for words */
    for (i = 0; i < num_words; i++)
        free(words[i]);

    return 0;
}