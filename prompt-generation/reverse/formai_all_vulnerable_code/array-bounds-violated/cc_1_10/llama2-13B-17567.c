//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 100
#define MAGIC_NUMBER 42

int main() {
    int sentence_length;
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_SENTENCE_LENGTH];
    int i, j, k;
    float average;
    double sum;

    srand(time(NULL));

    printf("Welcome to the land of random sentences!\n");

    do {
        printf("Please enter a sentence: ");
        fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

        sentence_length = strlen(sentence);

        for (i = 0; i < sentence_length; i++) {
            word[i] = sentence[i];
        }

        word[i] = '\0';

        // Generate a random word to insert into the sentence
        for (j = 0; j < MAGIC_NUMBER; j++) {
            int random_index = rand() % sentence_length;
            word[random_index] = 'A' + (rand() % 26);
        }

        // Calculate the average word length
        average = 0;
        for (k = 0; k < sentence_length; k++) {
            average += strlen(word[k]);
        }
        average /= sentence_length;

        printf("The average word length is %f\n", average);

        // Print the modified sentence
        printf("%s%s%s\n", word, word, word);

    } while (1);

    return 0;
}