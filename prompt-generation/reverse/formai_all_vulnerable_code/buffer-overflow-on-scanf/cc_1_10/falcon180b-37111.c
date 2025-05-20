//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a word exists in the dictionary
bool check_word(char* word, char* dict_file) {
    FILE* dict = fopen(dict_file, "r");
    if (dict == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, 100, dict)!= NULL) {
        char* word_in_dict = strtok(line, " ");
        while (word_in_dict!= NULL) {
            if (strcmp(word, word_in_dict) == 0) {
                fclose(dict);
                return true;
            }
            word_in_dict = strtok(NULL, " ");
        }
    }
    fclose(dict);
    return false;
}

// Function to read a file and check for spelling mistakes
void spell_check(char* file_name, char* dict_file) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, 100, file)!= NULL) {
        int i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                char word[100];
                int j = 0;
                while (isalpha(line[i])) {
                    word[j] = tolower(line[i]);
                    i++;
                    j++;
                }
                word[j] = '\0';
                if (!check_word(word, dict_file)) {
                    printf("Possible spelling mistake: %s\n", word);
                }
            }
            i++;
        }
    }
    fclose(file);
}

int main() {
    char dict_file[100] = "dictionary.txt";
    char file_name[100];
    printf("Enter file name: ");
    scanf("%s", file_name);
    spell_check(file_name, dict_file);
    return 0;
}