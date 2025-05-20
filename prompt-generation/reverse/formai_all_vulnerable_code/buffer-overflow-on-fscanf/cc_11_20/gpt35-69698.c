//FormAI DATASET v1.0 Category: Spell checking ; Style: introspective
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* This program checks the spelling of words in a given text file. */

int main(int argc, char* argv[]) {

    FILE* fp;   // File pointer for input text
    char word[100], check[100];   // Word to be checked and the word to check against in the dictionary
    int line_counter = 0, word_counter = 0, wrong_words = 0;   // Counters for lines, words, and wrong words
    int dictionary_size = 0, max_word_length = 0;   // Number of words in dictionary and maximum length of words in dictionary

    // Check if input file is provided as command line argument
    if (argc < 2) {
        printf("Please provide an input file.\n");
        return 1;
    }

    // Open input file in read mode
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    // Open dictionary file and count number of words and maximum word length
    FILE* dict_fp = fopen("dictionary.txt", "r");
    if (dict_fp == NULL) {
        printf("Could not open dictionary file.\n");
        return 1;
    }

    // Count number of words and maximum word length in dictionary file
    char dict_word[100];
    while (fscanf(dict_fp, "%s", dict_word) != EOF) {
        dictionary_size++;
        int len = strlen(dict_word);
        if (len > max_word_length) {
            max_word_length = len;
        }
    }
    printf("Dictionary Size: %d\nMaximum Word Length: %d\n", dictionary_size, max_word_length);

    // Close and reopen dictionary file to reset file pointer
    fclose(dict_fp);
    dict_fp = fopen("dictionary.txt", "r");

    // Keep scanning text file until end of file
    while (fscanf(fp, "%s", word) != EOF) {
        word_counter++;

        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if word is longer than maximum length in dictionary
        if (strlen(word) > max_word_length) {
            printf("Line %d, Word %d: %s\n", line_counter, word_counter, word);
            wrong_words++;
            continue;
        }

        // Check if word is in dictionary
        int found = 0;
        while (fscanf(dict_fp, "%s", check) != EOF) {
            if (strcmp(check, word) == 0) {
                found = 1;
                break;
            }
        }

        // Reset file pointer of dictionary file
        fseek(dict_fp, 0, SEEK_SET);

        // Print wrong words
        if (!found) {
            printf("Line %d, Word %d: %s\n", line_counter, word_counter, word);
            wrong_words++;
        }

        // Check for line break and increment line counter
        if (word[strlen(word)-1] == '\n') {
            line_counter++;
        }
    }

    // Output final result
    printf("Total Lines: %d\nTotal Words: %d\nWrong Words: %d\n", line_counter+1, word_counter, wrong_words);

    // Close files
    fclose(fp);
    fclose(dict_fp);

    return 0;
}