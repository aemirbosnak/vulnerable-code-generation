//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

int main() {

    char filename[100]; // name of file to read
    char *words[MAX_WORD_LENGTH]; // array to store words
    int frequencies[MAX_WORD_LENGTH] = {0}; // array to store word frequencies
    int count = 0; // count of total words
    int i, j; // iterators

    // request file name from user
    printf("Enter file name: ");
    scanf("%s", filename);

    // attempt to open file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // read words from file
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {

        // convert word to lowercase
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // strip punctuation from end of word
        if (ispunct(word[strlen(word) - 1])) {
            word[strlen(word) - 1] = '\0';
        }

        // look for word in array
        int found = 0;
        for (i = 0; i < count; i++) {
            if (strcmp(word, words[i]) == 0) {
                found = 1;
                frequencies[i]++;
                break;
            }
        }

        // add word to array if not found
        if (!found) {
            words[count] = malloc(MAX_WORD_LENGTH * sizeof(char));
            strcpy(words[count], word);
            frequencies[count]++;
            count++;
        }
    }

    // close file
    fclose(file);

    // print word frequencies
    printf("\nWord frequencies:\n");
    for (i = 0; i < count; i++) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }

    // free memory
    for (i = 0; i < count; i++) {
        free(words[i]);
    }

    return 0;
}