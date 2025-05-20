//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 5000

// Function prototypes
void countWords(const char *filename);
int isWhitespace(char ch);
void displayFunnyStatistic(int totalWords, int uniqueWords);

int main(int argc, char *argv[]) {
    // Welcome to our totally non-dramatic word counting tool!
    printf("Welcome to the Super Duper Word Count Tool!\n");
    printf("Where we take your words and count them like they're going out of style!\n");

    // Check if the user provided a file
    if (argc < 2) {
        printf("Whoa there! You forgot to tell me which file to scrutinize.\n");
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    countWords(filename);
    return 0;
}

void countWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("I tried to read your file but found nothing but a black hole. File does not exist!\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    char *words[MAX_WORDS];
    int totalWords = 0;
    int uniqueWords = 0;

    // Read the file and count words
    while (fscanf(file, "%s", word) == 1) {
        // Skip trailing punctuation funny business
        char *ptr = word;
        while (*ptr) {
            if (isWhitespace(*ptr) || (*ptr < 'a' || *ptr > 'z' && *ptr < 'A' || *ptr > 'Z')) {
                *ptr = '\0';
                break;
            }
            ptr++;
        }

        // Don't let our array overflow
        if (totalWords < MAX_WORDS) {
            // Add the word to our array only if it isn't already in there
            for (int i = 0; i < totalWords; i++) {
                if (strcmp(words[i], word) == 0) {
                    break; // It's a repeat, let's ignore it and move on!
                }
            }
            // If it's a new word, add it to our basket
            if (totalWords < MAX_WORDS) {
                words[totalWords++] = strdup(word);
                uniqueWords++;
            }
        }
    }

    fclose(file);

    // Display statistical hilarity
    printf("Total Words: %d\n", totalWords);
    printf("Unique Words: %d\n", uniqueWords);
    
    // Fun statistics!
    displayFunnyStatistic(totalWords, uniqueWords);
    
    // Free allocated memory
    for (int i = 0; i < totalWords; i++) {
        free(words[i]);
    }
}

int isWhitespace(char ch) {
    return (ch == ' ' || ch == '\n' || ch == '\t');
}

void displayFunnyStatistic(int totalWords, int uniqueWords) {
    // Let's add some comedy to the numbers!
    printf("Did you know that if you had one marshmallow for every word you wrote, \n");
    printf("you could build a sugary fortress big enough to fend off two hungry squirrels?\n");
    printf("And that fortress would be %d marshmallows tall!\n", totalWords + uniqueWords);

    if (uniqueWords > totalWords / 2) {
        printf("Congratulations! You're not just a word farmer but a unique word wizard!\n");
    } else {
        printf("It's okay! Quantity over quality, right? We all need to vent sometimes.\n");
    }

    if (totalWords > 0) {
        double ratio = (double)uniqueWords / totalWords * 100;
        printf("That's a %.2f%% uniqueness ratio! Not too shabby for a word slayer!\n", ratio);
    } else {
        printf("Looks like you've written... nothing at all? Did the keyboard bite your fingers?\n");
    }
}