//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

// Function to generate a random sentence
void generate_sentence(char *sentence) {
    int i, j, k;
    char *words[MAX_WORDS];
    char *word;
    int word_count = 0;

    // Initialize random seed
    srand(time(NULL));

    // Load words from file
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }

    // Read words into array
    while (fscanf(file, "%s", words[word_count])!= EOF && word_count < MAX_WORDS) {
        word_count++;
    }
    fclose(file);

    // Generate sentence
    for (i = 0; i < MAX_SENTENCE_LENGTH; i++) {
        if (i == 0 || ispunct(sentence[i-1])) {
            word = words[rand() % word_count];
            if (strlen(word) > MAX_WORD_LENGTH) {
                word[MAX_WORD_LENGTH] = '\0';
            }
            strcat(sentence, word);
            strcat(sentence, " ");
            word_count = (word_count + 1) % MAX_WORDS;
        } else {
            sentence[i] = tolower(sentence[i]);
        }
    }

    // Remove trailing space
    sentence[strlen(sentence)-1] = '\0';
}

int main() {
    setlocale(LC_ALL, "");

    // Generate random sentence
    char sentence[MAX_SENTENCE_LENGTH];
    generate_sentence(sentence);

    // Print sentence
    printf("Random sentence: %s\n", sentence);

    return 0;
}