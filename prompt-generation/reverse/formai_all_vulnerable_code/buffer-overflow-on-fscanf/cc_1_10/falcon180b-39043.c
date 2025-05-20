//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }

    int i = 0;
    while (i < num_words && fscanf(file, "%s", words[i].word)!= EOF) {
        words[i].length = strlen(words[i].word);
        i++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    int num_words = rand() % MAX_WORDS + 1;
    Word words[MAX_WORDS];
    generate_words(words, num_words);

    printf("Welcome to the Cyberpunk Typing Speed Test!\n\n");
    printf("You will be typing %d words.\n", num_words);

    int correct = 0;
    int incorrect = 0;
    int total_time = 0;

    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
        fflush(stdout);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        total_time += rand() % 100 + 50; // add random delay between words
    }

    double wpm = (double)num_words / (total_time / 60.0);
    printf("\n\nResults:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Words per minute: %.2f\n", wpm);

    return 0;
}