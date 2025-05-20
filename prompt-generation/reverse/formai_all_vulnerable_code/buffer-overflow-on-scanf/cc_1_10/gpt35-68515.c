//FormAI DATASET v1.0 Category: Spell checking ; Style: protected
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 1000

/*
 * This program is a spell checker that reads in a dictionary of words and then checks
 * a given text file to make sure that each word is spelled correctly. The program output
 * the names of any misspelled words detected. 
 */

char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];  // dictionary to store all the words
int dictionary_size;  // number of words in the dictionary

/** This function reads input from the keyboard and stores the dictionary words in the dictionary array. */
void read_dictionary()
{
    char word[MAX_WORD_LENGTH];

    while (scanf("%s", word) != EOF && dictionary_size < MAX_DICTIONARY_WORDS) {
        strcpy(dictionary[dictionary_size], word);
        dictionary_size++;
    }
}

/** This function checks whether a word exists in the dictionary. */
bool is_word_in_dictionary(char word[])
{
    for (int i = 0; i < dictionary_size; ++i) {
        if (strcmp(dictionary[i], word) == 0) {  // compare the word with each word in the dictionary
            return true;
        }
    }

    return false;
}

/** This function checks whether a given character is a letter. */
bool is_letter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/** This function checks whether a given word is spelled correctly. */
bool is_word_spelled_correctly(char word[])
{
    int len = strlen(word);

    /* A word must contain at least one letter */
    if (len == 0) {
        return false;
    }

    /* A word must not be longer than MAX_WORD_LENGTH */
    if (len > MAX_WORD_LENGTH) {
        return false;
    }

    /* A word must contain only letters */
    for (int i = 0; i < len; ++i) {
        if (!is_letter(word[i])) {
            return false;
        }
    }

    /* A word must be in the dictionary */
    if (!is_word_in_dictionary(word)) {
        return false;
    }

    return true;
}

/** This function reads input from a file and checks each word to see if it is spelled correctly. */
void check_spelling(char filename[])
{
    FILE *fp = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];

    while (fscanf(fp, "%s", word) != EOF) {
        if (!is_word_spelled_correctly(word)) {
            printf("Misspelled word: %s\n", word);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <dictionary_file>\n", argv[0]);
        return 1;
    }

    read_dictionary();

    check_spelling(argv[1]);

    return 0;
}