//Falcon-180B DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_NUMBER_OF_WORDS 1000

typedef struct {
    char word[MAX_STRING_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char filename[MAX_STRING_LENGTH];
    char line[MAX_STRING_LENGTH];
    char *word;
    WordCount words[MAX_NUMBER_OF_WORDS];
    int numWords = 0;
    int i;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read file line by line
    while (fgets(line, MAX_STRING_LENGTH, file)!= NULL) {
        // Tokenize line into words
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            // Count the frequency of each word
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            // If word not found, add it to the array
            if (i == numWords) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
                if (numWords == MAX_NUMBER_OF_WORDS) {
                    printf("Error: Maximum number of words exceeded.\n");
                    return 1;
                }
            }
            word = strtok(NULL, ",.!?;:");
        }
    }

    // Close file
    fclose(file);

    // Print word count
    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}