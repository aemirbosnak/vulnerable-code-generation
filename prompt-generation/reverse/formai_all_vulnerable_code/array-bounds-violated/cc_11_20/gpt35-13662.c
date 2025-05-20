//FormAI DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s file_to_check dictionary_file\n", argv[0]);
        return 1;
    }

    FILE *file_to_check = fopen(argv[1], "r");
    FILE *dictionary_file = fopen(argv[2], "r");

    if (!file_to_check) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    if (!dictionary_file) {
        printf("Error opening file %s\n", argv[2]);
        return 1;
    }

    // Read dictionary file
    char **dictionary = malloc(sizeof(char*) * MAX_WORD_LEN);
    int dict_size = 0;

    char tmp_word[MAX_WORD_LEN];
    while (fgets(tmp_word, MAX_WORD_LEN, dictionary_file)) {
        tmp_word[strlen(tmp_word) - 1] = '\0';
        dictionary[dict_size] = malloc(sizeof(char) * strlen(tmp_word) + 1);
        strcpy(dictionary[dict_size], tmp_word);
        dict_size++;
    }

    fclose(dictionary_file);

    // Check file to be checked
    char word[MAX_WORD_LEN];
    int line_num = 1;
    while (fgets(word, MAX_WORD_LEN, file_to_check)) {
        char *pch = strtok(word, " \n\t\r");
        while (pch != NULL) {
            int i;
            for (i = 0; i < strlen(pch); i++) {
                pch[i] = tolower(pch[i]); // convert to lowercase
            }

            int found = 0;
            for (i = 0; i < dict_size; i++) {
                if (strcmp(dictionary[i], pch) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Error: %s on line %d is not spelled correctly.\n", pch, line_num);
            }

            pch = strtok(NULL, " \n\t\r");
        }
        line_num++;
    }

    fclose(file_to_check);

    // Free memory
    int i;
    for (i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}