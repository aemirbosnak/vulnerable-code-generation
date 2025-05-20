//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100 //Maximum length of each word
#define DICT_SIZE 10000 //Maximum size of the dictionary file

int main() {
    char word[MAX_LEN]; //The word read from the input file
    int num_words = 0; //Number of words checked
    int num_misspelled = 0; //Number of misspelled words

    //Open the dictionary file and read in the words
    char *dictionary[DICT_SIZE];
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        fprintf(stderr, "Error: Unable to open dictionary file.\n");
        exit(1);
    }
    char line[MAX_LEN];
    while (fgets(line, MAX_LEN, dict_file) != NULL && num_words < DICT_SIZE) {
        line[strcspn(line, "\n")] = '\0'; //Remove the newline character at the end
        dictionary[num_words] = malloc(strlen(line) + 1); //Allocate memory for the word
        strcpy(dictionary[num_words], line); //Copy the word into the dictionary
        num_words++;
    }
    fclose(dict_file);

    //Read in the input file and check each word
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Unable to open input file.\n");
        exit(1);
    }
    while (fscanf(input_file, "%s", word) == 1) {
        char *lowercase_word = malloc(strlen(word) + 1); //Allocate memory for the lowercase version of the word
        strcpy(lowercase_word, word);
        for (int i = 0; i < strlen(lowercase_word); i++) {
            lowercase_word[i] = tolower(lowercase_word[i]); //Convert the word to lowercase
        }

        //Check if the word is in the dictionary
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(dictionary[i], lowercase_word) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Misspelled word: %s\n", word);
            num_misspelled++;
        }

        free(lowercase_word); //Free the memory for the lowercase version of the word
    }
    fclose(input_file);

    printf("Checked %d words. Found %d misspelled words.\n", num_words, num_misspelled);

    //Free the memory for the dictionary
    for (int i = 0; i < num_words; i++) {
        free(dictionary[i]);
    }

    return 0;
}