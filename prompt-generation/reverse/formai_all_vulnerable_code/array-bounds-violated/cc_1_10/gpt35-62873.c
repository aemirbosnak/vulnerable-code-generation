//FormAI DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function declaration */
void check_spelling(char *dictionary_file, char *input_file);

int main() {
    /* Call the function to check spelling */
    check_spelling("dictionary.txt", "input.txt");
    return 0;
}

void check_spelling(char *dictionary_file, char *input_file) {
    /* Open the dictionary and input file */
    FILE *dict_fp = fopen(dictionary_file, "r");
    FILE *input_fp = fopen(input_file, "r");

    /* Initialize variables */
    char dict_word[100], input_word[100];
    int line_no = 0, char_no = 0, matches = 0, typos = 0;

    /* Loop through each word in the input file */
    while (fscanf(input_fp, "%s", input_word) == 1) {
        /* Convert the word to lowercase */
        for (int i = 0; input_word[i]; i++) {
            input_word[i] = tolower(input_word[i]);
        }

        /* Check if the word is in the dictionary */
        fseek(dict_fp, 0, SEEK_SET);
        while (fscanf(dict_fp, "%s", dict_word) == 1) {
            /* Convert the word to lowercase */
            for (int i = 0; dict_word[i]; i++) {
                dict_word[i] = tolower(dict_word[i]);
            }
            /* Compare the input word with the dictionary word */
            if (strcmp(input_word, dict_word) == 0) {
                matches++;
                break;
            }
        }

        /* If there was no match, print a typo message */
        if (matches == 0) {
            typos++;
            printf("Typo found at line %d, char %d: %s\n", line_no, char_no, input_word);
        }

        /* Update line and char variables */
        char_no += strlen(input_word) + 1;
        if (input_word[strlen(input_word)-1] == '\n') {
            line_no++;
            char_no = 0;
        }
    }

    /* Print summary of typos */
    printf("%d typos found in %d lines\n", typos, line_no+1);

    /* Close the file pointers */
    fclose(dict_fp);
    fclose(input_fp);
}