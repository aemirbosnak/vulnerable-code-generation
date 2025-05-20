//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;
int max_word_length;

void generate_words() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }

    num_words = i;
    max_word_length = strlen(words[0]);

    fclose(file);
}

int main() {
    srand(time(NULL));
    generate_words();

    printf("Welcome to the Typing Speed Test\n");
    printf("You will have 60 seconds to type as many words as possible.\n");
    printf("Press ENTER to begin.\n");

    getchar();
    int score = 0;
    int correct_words = 0;

    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (strcmp(input, words[i]) == 0) {
            correct_words++;
        }

        score += strlen(input);
    }

    printf("\nTime's up!\n");

    int wpm = (score / 5) * 60;
    float accuracy = ((float)correct_words / num_words) * 100;

    printf("Your final score is: %d WPM with %.2f%% accuracy\n", wpm, accuracy);

    return 0;
}