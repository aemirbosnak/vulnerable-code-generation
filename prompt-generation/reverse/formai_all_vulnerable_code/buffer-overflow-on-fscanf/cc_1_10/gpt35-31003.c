//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Cyberpunk
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 50000

int main(int argc, char *argv[]) {
    char buffer[MAX_WORD_LENGTH]; // buffer to hold current word
    char words[MAX_WORDS][MAX_WORD_LENGTH]; // array to hold words
    int frequency[MAX_WORDS] = { 0 }; // array to hold frequencies
    int numWords = 0; // total number of words
    
    // open input file
    FILE *file = fopen("cyberpunk_text.txt", "r");
    
    while (fscanf(file, "%s", buffer) == 1) {
        // convert word to lowercase
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = tolower(buffer[i]);
        }

        // remove any non-alphabetic characters from word
        int j = 0;
        for (int i = 0; i < strlen(buffer); i++) {
            if (isalpha(buffer[i])) {
                words[numWords][j] = buffer[i];
                j++;
            }
        }

        // update frequency of current word
        int match = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[numWords], words[i]) == 0) {
                frequency[i]++;
                match = 1;
                break;
            }
        }

        // add new word to array if no match found
        if (!match) {
            numWords++;
        }
    }

    // close input file
    fclose(file);

    // print all words and their respective frequencies
    printf("Word Frequency Counter:\n\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s - %d\n", words[i], frequency[i]);
    }

    // exit program
    return 0;
}