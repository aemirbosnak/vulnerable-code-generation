//Falcon-180B DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000 // Maximum length of a line
#define MAX_WORD 50 // Maximum length of a word

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *file;
    char filename[MAX_LINE];
    char line[MAX_LINE];
    char word[MAX_WORD];
    WordCount word_counts[100]; // Maximum of 100 unique words
    int num_words = 0; // Number of unique words found

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, MAX_LINE, file)!= NULL) {
        // Convert line to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Tokenize line into words
        char *token = strtok(line, ",\t\n");
        while (token!= NULL) {
            // Remove leading/trailing punctuation
            int len = strlen(token);
            if (isalpha(token[0]) || isdigit(token[0])) {
                strcpy(word, token);
            } else {
                strcpy(word, token + 1);
            }
            if (isalpha(word[strlen(word) - 1])) {
                word[strlen(word) - 1] = '\0';
            } else {
                word[strlen(word) - 1] = '.';
            }

            // Count occurrences of word
            WordCount *word_ptr = NULL;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_ptr = &word_counts[i];
                    break;
                }
            }
            if (word_ptr == NULL) {
                if (num_words >= 100) {
                    printf("Error: Too many unique words.\n");
                    exit(1);
                }
                word_ptr = &word_counts[num_words++];
                strcpy(word_ptr->word, word);
                word_ptr->count = 1;
            } else {
                word_ptr->count++;
            }

            token = strtok(NULL, ",\t\n");
        }
    }

    // Print word counts
    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    // Close file
    fclose(file);

    return 0;
}