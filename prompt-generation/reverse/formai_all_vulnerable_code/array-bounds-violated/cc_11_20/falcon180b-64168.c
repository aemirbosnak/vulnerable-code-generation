//Falcon-180B DATASET v1.0 Category: Text processing ; Style: intelligent
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char *token;
    int count = 0;
    int length = 0;
    int word_count = 0;
    int sentence_count = 0;
    int paragraph_count = 0;

    printf("Enter text:\n");
    fgets(input, MAX_LENGTH, stdin);

    // Count characters, words, sentences, and paragraphs
    for (int i = 0; input[i]!= '\0'; i++) {
        if (isspace(input[i])) {
            if (i == 0 || input[i-1] == '\n') {
                paragraph_count++;
            }
            if (input[i-1] == '.' || input[i-1] == '?' || input[i-1] == '!') {
                sentence_count++;
            }
            word_count++;
        }
        length++;
    }

    // Tokenize input
    char *input_copy = strdup(input);
    token = strtok(input_copy, " \n\t\r\f\v");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            count++;
        }
        token = strtok(NULL, " \n\t\r\f\v");
    }

    // Calculate average word length
    if (word_count > 0) {
        float avg_length = (float)length / word_count;
        printf("Average word length: %.2f\n", avg_length);
    } else {
        printf("No words found.\n");
    }

    // Print results
    printf("Total characters: %d\n", length);
    printf("Total words: %d\n", word_count);
    printf("Total sentences: %d\n", sentence_count);
    printf("Total paragraphs: %d\n", paragraph_count);
    printf("Total unique words: %d\n", count);

    return 0;
}