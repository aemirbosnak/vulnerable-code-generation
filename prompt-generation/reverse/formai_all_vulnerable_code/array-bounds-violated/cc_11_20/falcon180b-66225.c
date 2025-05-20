//Falcon-180B DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main(int argc, char *argv[]) {
    char filename[MAX_WORD_LENGTH];
    FILE *input_file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    Word words[MAX_WORDS];
    int num_words = 0;
    int i;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        // Remove newline character from end of line
        line[strlen(line) - 1] = '\0';

        // Tokenize line into words
        char *token = strtok(line, " ");
        while (token!= NULL) {
            // Convert word to lowercase
            strcpy(word, token);
            for (i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            // Check if word is already in array
            int found = 0;
            for (i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            // If not found, add to array
            if (!found) {
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
            }

            token = strtok(NULL, " ");
        }
    }

    // Close file
    fclose(input_file);

    // Sort words by count
    for (i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[i].count < words[j].count) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print word count
    printf("Word count:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}