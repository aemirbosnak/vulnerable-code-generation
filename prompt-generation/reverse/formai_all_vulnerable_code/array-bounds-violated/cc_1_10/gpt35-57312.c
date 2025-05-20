//FormAI DATASET v1.0 Category: Spell checking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1000
#define MAX_WORD_LEN 50

int is_valid_word(char word[]) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

int is_in_dictionary(char word[], char dictionary[][MAX_WORD_LEN], int dict_word_count) {
    for (int i = 0; i < dict_word_count; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_spelling(char text[]) {
    char dictionary[10000][MAX_WORD_LEN];
    int dict_word_count = 0;

    FILE *fp = fopen("dictionary.txt", "r");
    if (!fp) {
        printf("Error: dictionary file not found.\n");
        return;
    }

    char line[MAX_STR_LEN];
    while (fgets(line, MAX_STR_LEN, fp)) {
        int len = strlen(line);
        line[len-1] = '\0';
        if (is_valid_word(line)) {
            strcpy(dictionary[dict_word_count], line);
            dict_word_count++;
        }
    }
    fclose(fp);

    int text_len = strlen(text);
    char current_word[MAX_WORD_LEN] = {0};
    int current_word_len = 0;

    for (int i = 0; i < text_len; i++) {
        if (!isalpha(text[i]) && current_word_len != 0) {
            current_word[current_word_len] = '\0';
            if (!is_in_dictionary(current_word, dictionary, dict_word_count)) {
                printf("Possible misspelled word: %s\n", current_word);
            }
            current_word_len = 0;
        } else if (isalpha(text[i])) {
            current_word[current_word_len] = tolower(text[i]);
            current_word_len++;
        }
    }
}

int main() {
    char text[MAX_STR_LEN];
    printf("Enter some text to check spelling: ");
    fgets(text, MAX_STR_LEN, stdin);

    check_spelling(text);
    return 0;
}