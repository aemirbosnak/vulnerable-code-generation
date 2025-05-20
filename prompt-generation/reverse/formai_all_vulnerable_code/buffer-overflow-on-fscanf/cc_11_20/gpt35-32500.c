//FormAI DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: spellcheck filename\n");
        return 1;
    }

    char *filename = argv[1];

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return 1;
    }

    // read the dictionary file
    char line[100];
    char **dictionary = malloc(sizeof(char*) * 50000);
    int dict_size = 0;
    while(fscanf(fp, "%s", line) != EOF) {
        // convert the word to lowercase
        for(int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // add the word to the dictionary
        dictionary[dict_size] = strdup(line);
        dict_size++;
    }
    fclose(fp);

    // read the text file and spell check it
    char *text_filename = "example.txt";
    fp = fopen(text_filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", text_filename);
        return 1;
    }

    int line_number = 0;
    while(fgets(line, sizeof(line), fp)) {
        line_number++;

        // check each word in the line
        char *word = strtok(line, " \t\n");
        while(word != NULL) {
            // convert the word to lowercase
            char lowercase[100];
            strcpy(lowercase, word);
            for(int i = 0; i < strlen(lowercase); i++) {
                lowercase[i] = tolower(lowercase[i]);
            }

            // check if the word is in the dictionary
            int found = 0;
            for(int i = 0; i < dict_size; i++) {
                if(strcmp(dictionary[i], lowercase) == 0) {
                    found = 1;
                    break;
                }
            }

            // print an error message if the word is not in the dictionary
            if(!found) {
                printf("Error: Line %d, word \"%s\" is not in the dictionary.\n", line_number, word);
            }

            word = strtok(NULL, " \t\n");
        }

    }
    fclose(fp);

    // free memory
    for(int i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}