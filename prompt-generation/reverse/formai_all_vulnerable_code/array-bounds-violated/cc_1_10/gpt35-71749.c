//FormAI DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

char dictionary[MAX_NUM_WORDS][MAX_WORD_LENGTH];
int num_words = 0;

void read_dictionary() {
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Dictionary file not found\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, dict_file)) {
        // remove newline character from end of word
        int len = strlen(word);
        if (word[len-1] == '\n') {
            word[len-1] = '\0';
        }
        // add word to dictionary
        strcpy(dictionary[num_words++], word);
    }

    fclose(dict_file);  
}

int is_word(char *str) {
    int len = strlen(str);
    // check if string contains only alphabetic characters
    for (int i = 0; i < len; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

int is_in_dictionary(char *str) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(str, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_spelling(char *filename) {
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Input file not found\n");
        exit(1);
    }
    
    char word[MAX_WORD_LENGTH];
    int line_num = 1;
    while (fgets(word, MAX_WORD_LENGTH, input_file)) {
        // remove newline character from end of word
        int len = strlen(word);
        if (word[len-1] == '\n') {
            word[len-1] = '\0';
        }
        // split line into words
        char *token = strtok(word, " ");
        while (token != NULL) {
            if (is_word(token)) {
                if (!is_in_dictionary(token)) {
                    printf("Line %d: %s is not in the dictionary\n", line_num, token);
                }
            } else {
                printf("Line %d: %s is not a valid word\n", line_num, token);
            }
            token = strtok(NULL, " ");
        }
        line_num++;
    }

    fclose(input_file);
}

int main() {
    read_dictionary();
    check_spelling("input.txt");
    return 0;
}