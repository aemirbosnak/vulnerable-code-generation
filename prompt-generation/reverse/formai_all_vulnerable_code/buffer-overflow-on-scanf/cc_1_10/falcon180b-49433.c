//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Function prototypes
void read_file(FILE *file, char *buffer);
void tokenize_string(char *string, char **tokens);
int count_words(char *string);

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    char buffer[MAX_WORD_LENGTH * 100];
    char *tokens[MAX_WORDS];
    int num_tokens;
    int i, j;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read file into buffer
    read_file(file, buffer);

    // Tokenize buffer into words
    tokenize_string(buffer, tokens);

    // Count number of words
    num_tokens = count_words(buffer);

    // Print number of words
    printf("Number of words: %d\n", num_tokens);

    // Print each word
    for (i = 0; i < num_tokens; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");

    // Close file
    fclose(file);

    return 0;
}

void read_file(FILE *file, char *buffer) {
    int c;
    int index = 0;

    // Read file character by character
    while ((c = fgetc(file))!= EOF) {
        if (index >= MAX_WORD_LENGTH * 100) {
            // Buffer is full, exit loop
            break;
        }
        buffer[index++] = c;
    }

    // Terminate string with null character
    buffer[index] = '\0';
}

void tokenize_string(char *string, char **tokens) {
    int i = 0;
    char *token;

    // Split string into tokens
    token = strtok(string, " \t\n\r\f\v");
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " \t\n\r\f\v");
    }
}

int count_words(char *string) {
    int count = 0;
    char *token;

    // Split string into tokens
    token = strtok(string, " \t\n\r\f\v");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " \t\n\r\f\v");
    }

    return count;
}