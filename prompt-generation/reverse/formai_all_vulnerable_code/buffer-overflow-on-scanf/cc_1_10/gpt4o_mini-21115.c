//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// A mystical creature that dances with words
void dance_with_words(const char *word, int *count) {
    if (strlen(word) > 0) {
        *count += 1; // Count each word that skips through the forest
        printf("A whisper of the wind carries the word: '%s'\n", word);
    }
}

// The forest of imagination that holds the words
void traverse_forest(FILE *forest, int *word_count) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(forest, "%s", word) != EOF) {
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]); // Paint the words with the brush of lowercase
        }
        dance_with_words(word, word_count); // Call the whimsical dance
    }
}

// The portal that opens the world of words
void open_portal(const char *filename) {
    FILE *forest = fopen(filename, "r");
    if (forest == NULL) {
        printf("The portal to the forest could not be opened...\n");
        exit(EXIT_FAILURE);
    }

    int word_count = 0;
    traverse_forest(forest, &word_count);
    
    printf("In total, the forest is home to %d magical word(s).\n", word_count);
    fclose(forest);
}

// The song of the wind that invites the reader
void invite_reader(char *filename) {
    printf("Welcome, dear wanderer, to the mystical Word Count Tool!\n");
    printf("As the poet longs for words, so shall we count them.\n");
    printf("Enter the filename of the enchanted scroll: ");
    scanf("%s", filename);
}

int main() {
    char filename[MAX_WORD_LENGTH];
    
    invite_reader(filename);
    open_portal(filename);

    // A final farewell as the sun sets in the distance
    printf("As the day ends, remember, every word danced through the air...\n");

    return 0;
}