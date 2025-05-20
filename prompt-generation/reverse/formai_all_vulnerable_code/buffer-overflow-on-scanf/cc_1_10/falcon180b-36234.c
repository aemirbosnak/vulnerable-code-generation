//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int num_words = 0;
    int word_count[MAX_NUM_WORDS] = {0};

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read words from file
    while (fscanf(file, "%s", word)!= EOF) {
        num_words++;

        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Increment word count
        int index = 0;
        while (index < MAX_NUM_WORDS && word_count[index]!= 0) {
            index++;
        }
        if (index < MAX_NUM_WORDS) {
            word_count[index]++;
        }
    }

    // Print word count
    printf("Total words: %d\n", num_words);
    printf("Word count:\n");
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        if (word_count[i]!= 0) {
            printf("%s: %d\n", i < MAX_WORD_LENGTH? (char*)word_count[i] : (char*)"...", word_count[i]);
        }
    }

    // Close file
    fclose(file);

    return 0;
}