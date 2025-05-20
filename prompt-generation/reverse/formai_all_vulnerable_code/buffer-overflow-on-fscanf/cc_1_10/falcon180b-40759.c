//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

bool initWords(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words file.\n");
        return false;
    }

    int count = 0;
    while (fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
        if (count == MAX_WORDS) {
            break;
        }
    }

    fclose(file);
    return true;
}

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    if (!initWords(words)) {
        return 1;
    }

    int score = 0;
    int wordsTyped = 0;
    int totalWords = rand() % MAX_WORDS + 1;

    printf("Welcome to the typing speed test!\n");
    printf("You will type %d words.\n", totalWords);

    for (int i = 0; i < totalWords; i++) {
        int wordIndex = rand() % MAX_WORDS;
        printf("Type the word: %s\n", words[wordIndex].word);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[wordIndex].word) == 0) {
            score++;
        }

        wordsTyped++;
    }

    float accuracy = (float)score / wordsTyped * 100;
    printf("You scored %d out of %d (%.2f%% accuracy)\n", score, wordsTyped, accuracy);

    return 0;
}