//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    int total_words = 0;
    int unique_words = 0;
    char word[MAX_WORD_LENGTH];
    char unique_word[MAX_WORD_LENGTH];

    // Read in the first word
    fscanf(file, "%s", word);

    // Loop through the rest of the words
    while (fscanf(file, "%s", word)!= EOF) {
        total_words++;

        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if word is already in unique_words array
        int found = 0;
        for (int i = 0; i < unique_words; i++) {
            if (strcmp(word, unique_word[i]) == 0) {
                found = 1;
                break;
            }
        }

        // If word is not found, add it to unique_words array
        if (!found) {
            strcpy(unique_word[unique_words], word);
            unique_words++;
        }
    }

    // Print results
    printf("Total words: %d\n", total_words);
    printf("Unique words: %d\n", unique_words);

    // Print unique words
    printf("Unique words:\n");
    for (int i = 0; i < unique_words; i++) {
        printf("%s\n", unique_word[i]);
    }

    // Close file
    fclose(file);

    return 0;
}