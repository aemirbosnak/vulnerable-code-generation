//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to count words in a sentence
int countWords(char* sentence) {
    int count = 0;
    int len = strlen(sentence);
    char* word = (char*) malloc(len + 1);
    strcpy(word, sentence);

    // Remove leading and trailing white spaces
    while (isspace(*word)) {
        word++;
    }
    while (isspace(*(word + len - 1))) {
        word[len - 1] = '\0';
        len--;
    }

    // Count words
    char* token = strtok(word, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    free(word);
    return count;
}

// Function to count lines in a file
int countLines(FILE* file) {
    int count = 0;
    char ch;

    // Read file until end of file
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    return count;
}

// Function to count characters in a file
int countCharacters(FILE* file) {
    int count = 0;
    char ch;

    // Read file until end of file
    while ((ch = fgetc(file))!= EOF) {
        if (isprint(ch)) {
            count++;
        }
    }

    return count;
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int lines = countLines(file);
    int words = countWords(filename);
    int characters = countCharacters(file);

    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);

    fclose(file);
    return 0;
}