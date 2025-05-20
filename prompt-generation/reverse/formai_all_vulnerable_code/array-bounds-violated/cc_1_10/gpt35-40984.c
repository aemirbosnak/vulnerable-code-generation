//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SENTENCE_SIZE 100

// function prototype
void generate_sentence(char sentence[]);
int calculate_accuracy(char typed[], char sentence[]);

int main() {
    char sentence[SENTENCE_SIZE], typed[SENTENCE_SIZE];
    int i, correct, mistakes, accuracy;
    double time_taken;
    clock_t t;

    // generate a sentence
    generate_sentence(sentence);

    printf("Type the following sentence:\n\n");
    printf("%s\n\n", sentence);

    t = clock(); // start timer

    fgets(typed, SENTENCE_SIZE, stdin); // read typed sentence
    typed[strlen(typed) - 1] = '\0'; // remove newline character

    t = clock() - t; // stop timer
    time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate time taken

    // calculate number of correct and incorrect characters typed
    correct = 0;
    mistakes = 0;
    for (i = 0; i < strlen(typed); i++) {
        if (typed[i] == sentence[i]) {
            correct++;
        } else {
            mistakes++;
        }
    }

    // calculate accuracy percentage
    accuracy = calculate_accuracy(typed, sentence);

    printf("\nResults:\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Accuracy: %d%%\n", accuracy);
    printf("Correct characters: %d\n", correct);
    printf("Mistakes: %d\n", mistakes);

    return 0;
}

// function to generate a random sentence
void generate_sentence(char sentence[]) {
    int i, words;
    char word[10];

    srand(time(NULL)); // initialize random number generator

    words = rand() % 10 + 1; // generate a random number of words (1-10)

    strcpy(sentence, ""); // initialize sentence with an empty string

    for (i = 0; i < words; i++) {
        // generate a random word (3-9 characters long)
        int letters = rand() % 7 + 3;
        int j;
        for (j = 0; j < letters; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[letters] = ' '; // add a space after the word
        word[letters + 1] = '\0'; // add a null terminator
        strcat(sentence, word); // add the word to the sentence
    }

    sentence[strlen(sentence) - 1] = '.'; // replace last space with a period
}

// function to calculate typing accuracy
int calculate_accuracy(char typed[], char sentence[]) {
    int i, correct;
    double accuracy;

    correct = 0;

    for (i = 0; i < strlen(typed); i++) {
        if (typed[i] == sentence[i]) {
            correct++;
        }
    }

    accuracy = (double)correct / strlen(sentence) * 100;

    return (int)accuracy;
}