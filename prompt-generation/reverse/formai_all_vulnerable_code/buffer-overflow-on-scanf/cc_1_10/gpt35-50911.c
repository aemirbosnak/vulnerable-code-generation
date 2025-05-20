//FormAI DATASET v1.0 Category: Spell checking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

int get_words(char *filename, char words[MAX_NUM_WORDS][MAX_WORD_LENGTH])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    int num_words = 0;
    char c, str[MAX_WORD_LENGTH];
    int j = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            str[j++] = c;
        }
        else {
            if (j > 0) {
                str[j] = '\0';
                strcpy(words[num_words++], str);
                j = 0;
            }
        }
    }
    fclose(fp);
    
    return num_words;
}

void remove_punctuation(char *word)
{
    int i, j;
    char new_word[MAX_WORD_LENGTH];
    for (i = 0, j = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            new_word[j++] = word[i];
        }
    }
    new_word[j] = '\0';
    strcpy(word, new_word);
}

void to_lower_case(char *word)
{
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }
}

int spell_check(char *filename, char *word)
{
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int num_words = get_words(filename, words);
    int i;
    for (i = 0; i < num_words; i++) {
        remove_punctuation(words[i]);
        to_lower_case(words[i]);
        if (strcmp(word, words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char filename[] = "dictionary.txt";
    char word[MAX_WORD_LENGTH];
    printf("Please enter a word: ");
    scanf("%s", word);
    if (spell_check(filename, word)) {
        printf("The word '%s' is spelled correctly.\n", word);
    }
    else {
        printf("The word '%s' is spelled incorrectly.\n", word);
    }
    
    return 0;
}