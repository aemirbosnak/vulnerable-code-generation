//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
};

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char filename[MAX_WORD_LENGTH];
    struct word dictionary[MAX_WORDS];
    int num_words = 0;
    int i;

    // Prompt user to enter filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read dictionary from file
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is full.\n");
            return 1;
        }
        strcpy(dictionary[num_words].word, line);
        dictionary[num_words].is_correct = true;
        num_words++;
    }
    fclose(file);

    // Prompt user to enter text to spell check
    printf("Enter text to spell check: ");
    fgets(line, MAX_WORD_LENGTH, stdin);

    // Convert text to lowercase
    for (i = 0; line[i]!= '\0'; i++) {
        line[i] = tolower(line[i]);
    }

    // Split text into words
    char *word = strtok(line, " ");
    while (word!= NULL) {
        int word_length = strlen(word);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Error: word is too long.\n");
            return 1;
        }
        strcpy(dictionary[num_words].word, word);
        dictionary[num_words].is_correct = false;
        num_words++;
        word = strtok(NULL, " ");
    }

    // Check spelling of each word
    for (i = 0; i < num_words; i++) {
        if (dictionary[i].is_correct) {
            printf("%s is spelled correctly.\n", dictionary[i].word);
        } else {
            printf("%s is spelled incorrectly.\n", dictionary[i].word);
        }
    }

    return 0;
}