//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 100

int main() {

    // Define a surrealist array of words
    char *words[MAX_WORDS] = {"antimatter", "buccaneer", "carousel", "doppelganger", "elephantiasis", 
                              "flamenco", "gobbledygook", "hooligan", "iguana", "juxtapose", 
                              "kangaroo", "loquacious", "mandolin", "nirvana", "orangutan", 
                              "procrastinate", "quipster", "reminisce", "surrealist", "tambourine", 
                              "ubiquitous", "vivacious", "willy-nilly", "xylophone", "yesterday", 
                              "zeppelin"};

    // Initialize the frequency counter array for each word
    int freqs[MAX_WORDS] = {0};

    // Declare other variables necessary
    char current_word[MAX_WORD_LENGTH], c;
    int i, j, k, length;

    // Get the input string from user
    printf("Enter a surreal string:\n");
    scanf("%[^\n]s", current_word);

    // Iterate through string and count word frequencies
    length = strlen(current_word);
    j = 0;
    for (i = 0; i <= length; i++) {
        c = current_word[i];
        if (isalpha(c)) {
            current_word[j++] = tolower(c);
        }
        else if (isspace(c) || c == '\0') {
            current_word[j] = '\0';
            j = 0;
            for (k = 0; k < MAX_WORDS; k++) {
                if (strcmp(current_word, words[k]) == 0) {
                    freqs[k]++;
                    break;
                }
            }
        }
    }

    // Print the word frequencies in a surrealist way
    printf("\nTotal words: %d\n\n", length);
    printf("Word frequencies:\n");
    for (i = 0; i < MAX_WORDS; i++) {
        if (freqs[i] > 0) {
            printf("%d %ss\n", freqs[i], words[i]);
        }
    }

    return 0;
}